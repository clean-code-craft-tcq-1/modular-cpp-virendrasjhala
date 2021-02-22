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
	int zeroBasedPairNumber = colorCablePairNumber - 1;
    MajorColorCables majorColorCableHandler = (MajorColorCables)(zeroBasedPairNumber / numberOfMinorColorCables);
	MinorColorCables minorColorCableHandler = (MinorColorCables)(zeroBasedPairNumber % numberOfMinorColorCables);
	return CableColors(majorColorCableHandler, minorColorCableHandler);
}
int TelecommunicationCableColorCoder::fetchColorPairNumberFromColorPair(MajorColorCables majorColorCable, MinorColorCables minorColorCable) {

	return majorColorCable * numberOfMinorColorCables + minorColorCable + 1;
}