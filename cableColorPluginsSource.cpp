#include "cableColorPlugins.h"

using namespace TelecommunicationCableColorCoder;

std::string CableColors::ToString() {
	TelecommunicationCableColorCoder::CableColors cableColorAccess;
	std::string cableVolume = TelecommunicationCableColorCoder::MajorColorCablesNames[majorColor];
	cableVolume += " ";
	cableVolume += TelecommunicationCableColorCoder::MinorColorCablesNames[minorColor];
	return cableVolume;
}

CableColors TelecommunicationCableColorCoder::fetchColorpairFromColorPairNumber(int colorCablePairNumber) {
	/*fetch cable color pair from cable color code*/
	int zeroBasedPairNumber = colorCablePairNumber - 1;
    MajorColorCables majorColorCableHandler = (MajorColorCables)(zeroBasedPairNumber / numberOfMinorColorCables);
	MinorColorCables minorColorCableHandler = (MinorColorCables)(zeroBasedPairNumber % numberOfMinorColorCables);
	return CableColors(majorColorCableHandler, minorColorCableHandler);
}
int TelecommunicationCableColorCoder::fetchColorPairNumberFromColorPair(MajorColorCables majorColorCable, MinorColorCables minorColorCable) {
	/*fetch cable color code from cable color pair*/
	return majorColorCable * numberOfMinorColorCables + minorColorCable + 1;
}

void TelecommunicationCableColorCoder::printUserManualForColorCablePair(int colorCablePairNumber, TelecommunicationCableColorCoder::MajorColorCables expectedMajorColorCable, TelecommunicationCableColorCoder::MinorColorCables expectedMinorColorCable, std::map<std::string, int>& manual) {
	TelecommunicationCableColorCoder::CableColors colorCablePairContainerFormanual = TelecommunicationCableColorCoder::fetchColorpairFromColorPairNumber(colorCablePairNumber);
	manual.insert(std::pair<std::string, int>(colorCablePairContainerFormanual.ToString().data(), colorCablePairNumber));
	std::cout<< colorCablePairContainerFormanual.ToString().data() << " "<< colorCablePairNumber <<std::endl;
}

std::string TelecommunicationCableColorCoder::checkColorPair(std::map<std::string, int> manual , int colorCode)
{
	std::map< std::string, int>::iterator iter;
	for (iter = manual.begin(); iter != manual.end(); iter++)
	{
		if (colorCode == iter->second)
			return iter->first.data();
	}
}