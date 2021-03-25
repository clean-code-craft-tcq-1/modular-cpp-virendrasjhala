#include "cableColorPlugins.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <map>

void testNumberToColorCablePair(int colorCablePairNumber, TelecommunicationCableColorCoder::MajorColorCables expectedMajorColorCable, TelecommunicationCableColorCoder::MinorColorCables expectedMinorColorCable){
	/*test if the inserted number maches to the color cable code or not*/
	TelecommunicationCableColorCoder::CableColors colorCablePairContainer = TelecommunicationCableColorCoder::fetchColorpairFromColorPairNumber(colorCablePairNumber);
	std::cout <<" got color pair : "<<colorCablePairContainer.ToString().data()<< std::endl;
	assert(colorCablePairContainer.getMajorColorCables() == expectedMajorColorCable);
	assert(colorCablePairContainer.getMinorColorCables() == expectedMinorColorCable);
}

void testColorCablePairToNumber(TelecommunicationCableColorCoder::MajorColorCables majorColorCable, TelecommunicationCableColorCoder::MinorColorCables minorColorCable, int expectedColorCablePairNumber){
	/*test if the inserted cable color maches to the color cable code or not*/
	int fetchedColorCablePairNumber = TelecommunicationCableColorCoder::fetchColorPairNumberFromColorPair(majorColorCable, minorColorCable);
	std::cout << "got color number : "<<fetchedColorCablePairNumber << std::endl;
	assert(fetchedColorCablePairNumber == expectedColorCablePairNumber);
}

int main() {
	std::cout << "Reference manual :" << std::endl;
	std::vector<TelecommunicationCableColorCoder::MajorColorCables> Majorcablepair = { TelecommunicationCableColorCoder::WHITE, TelecommunicationCableColorCoder::RED, TelecommunicationCableColorCoder::BLACK, TelecommunicationCableColorCoder::YELLOW, TelecommunicationCableColorCoder::VIOLET };
	std::vector<TelecommunicationCableColorCoder::MinorColorCables> Minorcablepair = { TelecommunicationCableColorCoder::BLUE, TelecommunicationCableColorCoder::ORANGE, TelecommunicationCableColorCoder::GREEN, TelecommunicationCableColorCoder::BROWN, TelecommunicationCableColorCoder::SLATE };
	static int count = 0;
	std::map<std::string, int> manual;
	for (auto MAjorCableIter = 0; MAjorCableIter < Majorcablepair.size(); MAjorCableIter++)
	{
		for (auto MinorCableIter = 0; MinorCableIter < Minorcablepair.size(); MinorCableIter++)
		{
			++count;
			printUserManualForColorCablePair(count, Majorcablepair[MAjorCableIter], Minorcablepair[MinorCableIter],manual);	
		}
	}
	std::cout << "test for TelecommunicationCableColorPair :" << std::endl;
	testNumberToColorCablePair(4, TelecommunicationCableColorCoder::WHITE, TelecommunicationCableColorCoder::BROWN);
	testNumberToColorCablePair(5, TelecommunicationCableColorCoder::WHITE, TelecommunicationCableColorCoder::SLATE);

	testColorCablePairToNumber(TelecommunicationCableColorCoder::BLACK, TelecommunicationCableColorCoder::ORANGE, 12);
	testColorCablePairToNumber(TelecommunicationCableColorCoder::VIOLET, TelecommunicationCableColorCoder::SLATE, 25);
	int colorCode=0;
	std::cout << "Enter number to check the color pair : ";
	//std::cin >> colorCode;
	if(colorCode!=0){ std::cout<<TelecommunicationCableColorCoder::checkColorPair(manual, colorCode).data()<<std::endl; }
	return 0;
}
