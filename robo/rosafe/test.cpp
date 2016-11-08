#include <memory>
#include <iostream>

#include "matFiles.hpp"
#include "openafe/Processors/inputProc.hpp"
#include "openafe/Processors/preProc.hpp"
#include "openafe/Processors/gammatoneProc.hpp"

using namespace openAFE;
using namespace std;

int main(int argc, char **argv) {

	// Read input from .mat file
	string dataPath("./DEMO_Speech_Anechoic.mat");
	vector <vector<double> > earSignals;
	double fsHz;
	matFiles::readMatFile(dataPath.c_str(), earSignals, &fsHz);

	// Gammaton processor parameters
	filterBankType fb_type = _gammatoneFilterBank;
	double fb_lowFreqHz = 80;
	double fb_highFreqHz = 8000;
	double fb_nERBs = 1;
	uint32_t fb_nChannels = 0;
	double* fb_cfHz = nullptr;
	size_t fb_cfHz_length = 0;
	uint32_t fb_nGamma = 4;
	double fb_bwERBs = 1.0180;

	/// Processor instanciations
	// Input processor
	shared_ptr <InputProc > inputP;
	inputP.reset( new InputProc("input", fsHz, 10 /* bufferSize_s */, false /* doNormalize */) );

	// Pre-processor
	shared_ptr <PreProc > ppP;
	ppP.reset( new PreProc("preProc", inputP ) ); /* default parameters */

	// Gammatone processor
	shared_ptr <GammatoneProc > gtP;
	gtP.reset( new GammatoneProc("gammatoneProc", ppP ,fb_type,
	                            fb_lowFreqHz,
	                            fb_highFreqHz,
	                            fb_nERBs,
	                            fb_nChannels,
	                            fb_cfHz,
	                            fb_cfHz_length,
	                            fb_nGamma,
	                            fb_bwERBs ) );

	/// Successive computations in the tree to obtain the required audio representation
	// First, input Processor
	inputP->processChunk ( earSignals[0].data(), earSignals[0].size(), earSignals[1].data(), earSignals[1].size() );
	inputP->releaseChunk();

	// Then the pre-Processor
	ppP->processChunk ();
	ppP->releaseChunk();

	// And finally, the gammatone Processor
	gtP->processChunk ();
	gtP->releaseChunk();

	/// Outputs are in the lOut and rOut variables
	vector<shared_ptr<twoCTypeBlock<double> > > lOut = gtP->getLeftWholeBufferAccessor();
	vector<shared_ptr<twoCTypeBlock<double> > > rOut = gtP->getRightWholeBufferAccessor();

	// Eventually, write the signals into a .mat file
	matFiles::writeTFSMatFile("out.mat", lOut, rOut, fsHz);


}