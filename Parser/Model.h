#pragma once
#define PI 3.1415926
#include "DRVCalc.h"
#include "Calculator.h"
#include "FunctionParser.h"
#include "Saver.h"
#include "View.h"
class Model
	{
private:
	DRVCalc * _drv;
	Calculator * _calc;
	FunctionParser * _funcParser;
	Saver * _saver;
	View * _view;

	vector<string> * _functionNames;
	vector<function<double(double)>> * _funcs;

	uint16_t _status = 0;

	void drvWork();

	void expressionWork();
public:
	Model();
	~Model();

	int exec();
	};

