#pragma once
#include <iostream>
#include <assert.h>

namespace TelecommunicationCableColorCoder
{
	enum MajorColorCables { WHITE, RED, BLACK, YELLOW, VIOLET };
	enum MinorColorCables { BLUE, ORANGE, GREEN, BROWN, SLATE };
	
	static char* MajorColorCablesNames[] = {
		"White", "Red", "Black", "Yellow", "Violet"
	};
	static int numberOfMajorColorCables = 
		sizeof(MajorColorCablesNames) / sizeof(MajorColorCablesNames[0]);

	static const char* MinorColorCablesNames[] = {
		"Blue", "Orange", "Green", "Brown", "Slate"
	};
	static int numberOfMinorColorCables = 
		sizeof(MinorColorCablesNames) / sizeof(MinorColorCablesNames[0]);

	class CableColors{
	private:
		MajorColorCables majorColor;
		MinorColorCables minorColor;
	public:
		CableColors() {}
		CableColors(MajorColorCables major, MinorColorCables minor) :
			majorColor(major), minorColor(minor)
		{}
		MajorColorCables getMajorColorCables() {
			return majorColor;
		}
		MinorColorCables getMinorColorCables() {
			return minorColor;
		}
		std::string ToString();
	};
	CableColors fetchColorpairFromColorPairNumber(int pairNumber);
	int fetchColorPairNumberFromColorPair(MajorColorCables major, MinorColorCables minor);
}
