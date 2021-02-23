#include "cableColorPlugins.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <map>

void testNumberToColorCablePair(int colorCablePairNumber, TelecommunicationCableColorCoder::MajorColorCables expectedMajorColorCable, TelecommunicationCableColorCoder::MinorColorCables expectedMinorColorCable, std::map<std::string, int>& manual){
	/*test if the inserted number maches to the color cable code or not*/
	TelecommunicationCableColorCoder::CableColors colorCablePairContainer = TelecommunicationCableColorCoder::fetchColorpairFromColorPairNumber(colorCablePairNumber);
	std::string colorOne = (std::string)TelecommunicationCableColorCoder::MajorColorCablesNames[colorCablePairContainer.getMajorColorCables()];
	std::string colorTwo = colorOne +" "+ (std::string)TelecommunicationCableColorCoder::MinorColorCablesNames[colorCablePairContainer.getMinorColorCables()];
	manual.insert(std::pair<std::string, int> (colorTwo.data(), colorCablePairNumber));
	std::cout <<colorCablePairContainer.ToString()<< std::endl;
	//std::cout<< TelecommunicationCableColorCoder::MajorColorCablesNames[colorCablePairContainer.getMajorColorCables()] << " " << TelecommunicationCableColorCoder::MinorColorCablesNames[colorCablePairContainer.getMinorColorCables()] << " ";
	assert(colorCablePairContainer.getMajorColorCables() == expectedMajorColorCable);
	assert(colorCablePairContainer.getMinorColorCables() == expectedMinorColorCable);
}

void testColorCablePairToNumber(TelecommunicationCableColorCoder::MajorColorCables majorColorCable, TelecommunicationCableColorCoder::MinorColorCables minorColorCable, int expectedColorCablePairNumber){
	/*test if the inserted cable color maches to the color cable code or not*/
	int fetchedColorCablePairNumber = TelecommunicationCableColorCoder::fetchColorPairNumberFromColorPair(majorColorCable, minorColorCable);
	//std::cout << fetchedColorCablePairNumber << std::endl;
	assert(fetchedColorCablePairNumber == expectedColorCablePairNumber);
}

int main() {
	std::cout << "reference manual :" << std::endl;
	std::vector<TelecommunicationCableColorCoder::MajorColorCables> Majorcablepair = { TelecommunicationCableColorCoder::WHITE, TelecommunicationCableColorCoder::RED, TelecommunicationCableColorCoder::BLACK, TelecommunicationCableColorCoder::YELLOW, TelecommunicationCableColorCoder::VIOLET };
	std::vector<TelecommunicationCableColorCoder::MinorColorCables> Minorcablepair = { TelecommunicationCableColorCoder::BLUE, TelecommunicationCableColorCoder::ORANGE, TelecommunicationCableColorCoder::GREEN, TelecommunicationCableColorCoder::BROWN, TelecommunicationCableColorCoder::SLATE };
	static int count = 0;
	std::map<std::string, int> manual;
	for (auto MAjorCableIter = 0; MAjorCableIter < Majorcablepair.size(); MAjorCableIter++)
	{
		for (auto MinorCableIter = 0; MinorCableIter < Minorcablepair.size(); MinorCableIter++)
		{
			++count;
			testNumberToColorCablePair(count, Majorcablepair[MAjorCableIter], Minorcablepair[MinorCableIter],manual);
			
			testColorCablePairToNumber(Majorcablepair[MAjorCableIter], Minorcablepair[MinorCableIter], count);
		}
	}
	int colorCode;
	std::cout << "Enter number to check the color pair : ";
	std::cin >> colorCode;
	if(colorCode!=0){ TelecommunicationCableColorCoder::checkColorPair(manual, colorCode); }
	system("pause");
	return 0;
}
