#include "Model.h"


void Model::drvWork()
	{
	_drv->setDistributionRange(_view->getDistribRange());
	_view->printDistribRange(_drv->getCurrentDistribRange());
	_view->setColor(YELLOW_C, YELLOW_C);
	_view->print(string("=============================================================="));
	_view->setColor(YELLOW_C);
	_view->print(string("Expectation: "), _drv->getMathExpectation());
	_view->print(string("Dispersion: "), _drv->getDispersion());
	_view->print(string("RMS deviation: "), _drv->getRmsDeviation());
	for (int i = 0; i < 4; ++i)
		{
		_view->print(string("Initial moment of the ") + char(i + 1 + '0') + string(" order: "), _drv->getInitialMoment(i + 1));
		}
	_view->setColor(YELLOW_C, YELLOW_C);
	_view->print(string("=============================================================="));
	_view->setColor(YELLOW_C);
	}


void Model::expressionWork()
	{
	_view->setColor(YELLOW_C, YELLOW_C);
	_view->print(string("=============================================================="));
	_view->setColor(YELLOW_C);
	bool parsed = false;
	do
		{
		_funcParser->setExpression(_view->getExpression());
		parsed = _funcParser->parseExpression();
		if(!parsed)
			{
			_view->pError();
			_view->setColor(RED_C);
			_view->print(string("Invalid expression"));
			_view->setColor(YELLOW_C);
			}
		}
	while ( !parsed );
	vector<string> tmp = _funcParser->getParsedExpression();
	_view->print("Postfix Polish notation:");
	_view->print(tmp);

	double x = _view->getX();
	for ( auto & el : tmp )
		{
		if(el == "x")
			{
			el = to_string(x);
			}
		}
	const double answer = _calc->calculate(tmp);
	_view->print(string("Y: "), answer);
	_view->setColor(YELLOW_C, YELLOW_C);
	_view->print(string("=============================================================="));
	_view->setColor(YELLOW_C);
	}


Model::Model()
	{
	_view = new View();
	_drv = new DRVCalc();
	_saver = new Saver();

	_functionNames = new vector<string>
		{
			"sin","cos","tan","ctan", "asin", "acos","atan","actan", "sqrt", "cbrt", "abs"
		};
	_funcs = new vector<function<double(double)>>
		{
			[](const double x) {return sin(x); },
			[](const double x) {return cos(x); },
			[](const double x) {return tan(x); },
			[](const double x) {return 1 / tan(x); },
			[](const double x) {return asin(x); },
			[](const double x) {return acos(x); },
			[](const double x) {return atan(x); },
			[](const double x) {return PI / 2 - atan(x); },
			[](const double x) {return sqrt(x); },
			[](const double x) {return cbrt(x); },
			[](const double x) {return fabs(x); },
		};

	_calc = new Calculator(*_functionNames);
	_calc->setFunctions(*_funcs);

	_funcParser = new FunctionParser(*_functionNames);
	}


Model::~Model()
{
	delete _view;
	delete _calc;
	delete _drv;
	delete _funcParser;
	delete _saver;
	delete _funcs;
	delete _functionNames;
}


int Model::exec()
	{
	char prmptRes = '-';
	do
		{
		_view->printMenu();
		prmptRes = _view->promptActivity();
		switch ( prmptRes )
			{
			case '1':
				{
				expressionWork();
				break;
				}
			case '2':
				{
				drvWork();
				break;
				}
			case '0':
				{
				break;
				}
			default:
				{
				_view->pError();
				break;
				}
			}
		}
	while ( prmptRes != '0' );
	return _status;
	}
