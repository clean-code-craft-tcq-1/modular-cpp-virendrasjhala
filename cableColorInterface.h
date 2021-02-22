#pragma once
#include <iostream>
#include <assert.h>

namespace TelCoColorCoder
{
	enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
	enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

	class ColorPair {
	private:
		MajorColor majorColor;
		MinorColor minorColor;
	public:
		ColorPair() {}
		ColorPair(MajorColor major, MinorColor minor) :
			majorColor(major), minorColor(minor)
		{}
		MajorColor getMajor() {
			return majorColor;
		}
		MinorColor getMinor() {
			return minorColor;
		}
		std::string ToString();
	};
	
	ColorPair GetColorFromPairNumber(int pairNumber);

	int GetPairNumberFromColor(MajorColor major, MinorColor minor);
}
