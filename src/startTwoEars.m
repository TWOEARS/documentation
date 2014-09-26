function startTwoEars(configFile)
%STARTTWOEARS sets up the whole Two!Ears model parts

TwoEarsPath = fileparts(mfilename('fullpath'));
TwoEarsPath = [TwoEarsPath, filesep];

addpath(TwoEarsPath);
addpath([TwoEarsPath, 'TwoEarStartup']);
addpath([TwoEarsPath, '..']);

if nargin>0
    if exist(configFile,'file')
        setupPartConfig(configFile);
    else
        error('Config file %s is not a valid file.',configFile);
    end
else
    setupPartConfig([TwoEarsPath, '..', filesep, 'TwoEars.xml']);
end

clear TwoEarsPath;
