#include "cableColorInterface.h"

namespace news
{
	const char* MajorColorNames[] = {
		"White", "Red", "Black", "Yellow", "Violet"
	};
	int numberOfMajorColors =
		sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
	const char* MinorColorNames[] = {
		"Blue", "Orange", "Green", "Brown", "Slate"
	};
	int numberOfMinorColors =
		sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

}
std::string TelCoColorCoder::ColorPair::ToString() {
	TelCoColorCoder::ColorPair ob;
	std::string colorPairStr = news::MajorColorNames[ob.getMinor()];
	colorPairStr += " ";
	colorPairStr += news::MinorColorNames[ob.getMinor()];
	return colorPairStr;
}
TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
	int zeroBasedPairNumber = pairNumber - 1;
	TelCoColorCoder::MajorColor majorColor1 = (TelCoColorCoder::MajorColor)(zeroBasedPairNumber / news::numberOfMinorColors);
	TelCoColorCoder::MinorColor minorColor2 = (TelCoColorCoder::MinorColor)(zeroBasedPairNumber % news::numberOfMinorColors);
	return TelCoColorCoder::ColorPair(majorColor1, minorColor2);
}
int TelCoColorCoder::GetPairNumberFromColor(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor) {

	return major * news::numberOfMinorColors + minor + 1;
}