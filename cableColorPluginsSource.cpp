#include "cableColorPlugins.h"

using namespace TelecommunicationCableColorCoder;

std::string CableColors::ToString() {
	TelecommunicationCableColorCoder::CableColors cableColorAccess;
	std::string cableVolume = MajorColorCablesNames[cableColorAccess.getMinorColorCables()];
	cableVolume += " ";
	cableVolume += MinorColorCablesNames[cableColorAccess.getMinorColorCables()];
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
void TelecommunicationCableColorCoder::checkColorPair(std::map<std::string, int> manual , int colorCode)
{
	std::map< std::string, int>::iterator iter;
	for (iter = manual.begin(); iter != manual.end(); iter++)
	{
		if (colorCode == iter->second)
			std::cout << iter->first.data()<<std::endl;
	}
}