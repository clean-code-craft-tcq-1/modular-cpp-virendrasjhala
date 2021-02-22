#pragma once
#include <iostream>
#include <assert.h>

namespace TelecommunicationCableColorCoder
{
	enum MajorColorCables { WHITE, RED, BLACK, YELLOW, VIOLET };
	enum MinorColorCables { BLUE, ORANGE, GREEN, BROWN, SLATE };
	
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
