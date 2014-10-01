function partPath = readPathConfig( rcXmlFileName, tagname )
%READPARTCONFIG returns the path for the specififed Two!Ears part
%
% readPartConfig( configXmlFile, partName ) returns the path for the Two!Ears
% software part partName as specified in the configXmlFile.

rcXml = xmlread( rcXmlFileName );

try
    partPath = char( rcXml.getElementsByTagName( tagname ).item(0).getFirstChild.getData );
catch ME
    error('Your definition of the Two!Ears pathes in %s uses the wrong tag names.',rcXmlFileName);
end
