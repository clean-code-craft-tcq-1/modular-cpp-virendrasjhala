#include "sensor-validate.h"
#include"iostream"
#define nullptr NULL

bool Parameter_Verification_Interface::readings_InRange(double value, double nextValue, double maxDelta) {
	if (nextValue - value > maxDelta) {
		return false;
	}
	return true;
}
bool Parameter_Verification_Interface::isParameterValid(double* parameters) {
	if (parameters == nullptr) {
		return false;
	}
	return true;
}
bool validation::validateSOCreadings(double* values, int numOfValues) {
	validation Check_soc;
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!Check_soc.readings_InRange(values[i], values[i + 1], 0.05)) {
			return false;
		}
	}
	return true;
}
bool validation::validateCurrentreadings(double* values, int numOfValues) {
	validation check_current;
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!check_current.readings_InRange(values[i], values[i + 1], 0.1)) {
			return false;
		}
	}
	return true;
}
