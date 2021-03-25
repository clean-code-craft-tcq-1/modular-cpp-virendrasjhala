#pragma once
class ParameterVerification{

public:
	virtual bool readings_InRange(double value, double nextValue, double maxDelta) = 0;
	virtual bool isParameterValid(double* parameters) = 0;
};

class Parameter_Verification_Interface :public ParameterVerification {

public:
	bool readings_InRange(double value, double nextValue, double maxDelta);
	bool isParameterValid(double* parameters);
	
};

class validation:public Parameter_Verification_Interface {

public:
	bool validateSOCreadings(double* values, int numOfValues);
	bool validateCurrentreadings(double* values, int numOfValues);
};



