#include "cableColorPlugins.h"
#include <assert.h>
#include <iostream>
void testNumberToPair(int colorCablePairNumber, TelecommunicationCableColorCoder::MajorColorCables expectedMajorColorCable, TelecommunicationCableColorCoder::MinorColorCables expectedMinorColorCable)
{
	TelecommunicationCableColorCoder::CableColors colorCablePairContainer = TelecommunicationCableColorCoder::fetchColorpairFromColorPairNumber(colorCablePairNumber);
	//std::cout << "Got pair " << colorCablePairContainer.ToString()<< std::endl;
	std::cout << "Got pair " << TelecommunicationCableColorCoder::MajorColorCablesNames[colorCablePairContainer.getMajorColorCables()] << " " << TelecommunicationCableColorCoder::MinorColorCablesNames[colorCablePairContainer.getMinorColorCables()] << std::endl;
	assert(colorCablePairContainer.getMajorColorCables() == expectedMajorColorCable);
	assert(colorCablePairContainer.getMinorColorCables() == expectedMinorColorCable);
}
void testPairToNumber(TelecommunicationCableColorCoder::MajorColorCables majorColorCable, TelecommunicationCableColorCoder::MinorColorCables minorColorCable, int expectedColorCablePairNumber)
{
	int fetchedColorCablePairNumber = TelecommunicationCableColorCoder::fetchColorPairNumberFromColorPair(majorColorCable, minorColorCable);
	std::cout << "Got pair number " << fetchedColorCablePairNumber << std::endl;
	assert(fetchedColorCablePairNumber == expectedColorCablePairNumber);
}
int main() {
	testNumberToPair(4, TelecommunicationCableColorCoder::WHITE, TelecommunicationCableColorCoder::BROWN);
	testNumberToPair(5, TelecommunicationCableColorCoder::WHITE, TelecommunicationCableColorCoder::SLATE);

	testPairToNumber(TelecommunicationCableColorCoder::BLACK, TelecommunicationCableColorCoder::ORANGE, 12);
	testPairToNumber(TelecommunicationCableColorCoder::VIOLET, TelecommunicationCableColorCoder::SLATE, 25);
	system("pause");
	return 0;
}
