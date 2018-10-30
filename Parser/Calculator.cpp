#include "Calculator.h"


int Calculator::getFunctionIdNyName(const string & token) const
{
	unsigned short i = 0;
	for (auto & el : *_functionsNames)
	{
		if (el == token) return i;
		++i;
	}
	return -1;
}


Calculator::Calculator()
{
	_functionsNames = nullptr;
	_funcs = nullptr;
}


Calculator::Calculator(const vector<string> & functions) : Calculator()
{
	_functionsNames = new vector<string>(functions);
}


Calculator::~Calculator()
{
	if (_functionsNames != nullptr)
	{
		delete _functionsNames;
		_functionsNames = nullptr;
	}
	if(_funcs != nullptr)
	{
		delete _funcs;
		_funcs = nullptr;
	}
}


void Calculator::setFunctions(const vector<function<double(double)>> & funcs)
{
	_funcs = new vector<function<double(double)>>(funcs);
}


double Calculator::calculate(const vector<string> & postfixExpression) const
{
	auto stk = new stack<double>();
	char * useless;
	for (auto & el : postfixExpression)
	{
		if (el == "^")
		{
			const double exp = stk->top();
			stk->pop();
			const double num = stk->top();
			stk->pop();
			stk->push(pow(num, exp));
		}
		else if (el == "+")
		{
			const double second = stk->top();
			stk->pop();
			const double first = stk->top();
			stk->pop();
			stk->push(first + second);
		}
		else if (el == "-")
		{
			const double second = stk->top();
			stk->pop();
			const double first = stk->top();
			stk->pop();
			stk->push(first - second);
		}
		else if (el == "*")
		{
			const double second = stk->top();
			stk->pop();
			const double first = stk->top();
			stk->pop();
			stk->push(first * second);
		}
		else if (el == "/")
		{
			const double second = stk->top();
			stk->pop();
			const double first = stk->top();
			stk->pop();
			stk->push(first / second);
		}
		else if (el == "u-")
		{
			const double tmp = -stk->top();
			stk->pop();
			stk->push(tmp);
		}
		else
		{
			const int id = getFunctionIdNyName(el);
			if (id != -1)
			{
				const double num = stk->top();
				stk->pop();
				stk->push(_funcs->at(id)(num));
			}
			else
			{
				stk->push(strtod(el.c_str(), &useless));
			}
		}
	}
	return stk->top();
}
