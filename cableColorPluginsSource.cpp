#include "cableColorPlugins.h"
#include<iostream>
namespace availableCableColorPackage{
	const char* MajorColorCablesNames[] = {
		"White", "Red", "Black", "Yellow", "Violet"
	};
	int numberOfMajorColorCables =
		sizeof(MajorColorCablesNames) / sizeof(MajorColorCablesNames[0]);

	const char* MinorColorCablesNames[] = {
		"Blue", "Orange", "Green", "Brown", "Slate"
	};
	int numberOfMinorColorCables =
		sizeof(MinorColorCablesNames) / sizeof(MinorColorCablesNames[0]);
}
std::string TelecommunicationCableColorCoder::CableColors::ToString() {
	TelecommunicationCableColorCoder::CableColors cableColorAccess;
	std::string cableVolume = availableCableColorPackage::MajorColorCablesNames[cableColorAccess.getMinorColorCables()];
	cableVolume += " ";
	cableVolume += availableCableColorPackage::MinorColorCablesNames[cableColorAccess.getMinorColorCables()];
	return cableVolume;
}
TelecommunicationCableColorCoder::CableColors TelecommunicationCableColorCoder::fetchColorpairFromColorPairNumber(int colorCablePairNumber) {
	int zeroBasedPairNumber = colorCablePairNumber - 1;
	TelecommunicationCableColorCoder::MajorColorCables majorColorCableHandler = (TelecommunicationCableColorCoder::MajorColorCables)(zeroBasedPairNumber / availableCableColorPackage::numberOfMinorColorCables);
	TelecommunicationCableColorCoder::MinorColorCables minorColorCableHandler = (TelecommunicationCableColorCoder::MinorColorCables)(zeroBasedPairNumber % availableCableColorPackage::numberOfMinorColorCables);
	return TelecommunicationCableColorCoder::CableColors(majorColorCableHandler, minorColorCableHandler);
}
int TelecommunicationCableColorCoder::fetchColorPairNumberFromColorPair(TelecommunicationCableColorCoder::MajorColorCables majorColorCable, TelecommunicationCableColorCoder::MinorColorCables minorColorCable) {

	return majorColorCable * availableCableColorPackage::numberOfMinorColorCables + minorColorCable + 1;
}