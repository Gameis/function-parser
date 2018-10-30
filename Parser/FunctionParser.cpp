#include "FunctionParser.h"

bool FunctionParser::isOperation(const string & token) const
{
	return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

int FunctionParser::getValueOfOperation(const string & operation)
{
	if (operation == "(")
		return 1;
	if (operation == "-" || operation == "+")
		return 2;
	if (operation == "/" || operation == "*")
		return 3;
	if (operation == "^")
		return 4;
	return 0;
}

bool FunctionParser::isFunction(const string & token) const
{
	for (auto & el : *_functions)
	{
		if (el == token) return true;
	}
	return false;
}

bool FunctionParser::isDelimiter(const string & token)
{
	for (auto & el : _delims)
	{
		if (token[0] == el) return true;
	}
	return false;
}

FunctionParser::FunctionParser()
{
	_flag = true;
	_expression = "";
	_parsedExpression = nullptr;
	_functions = nullptr;
}

FunctionParser::~FunctionParser()
{
	if (_parsedExpression != nullptr)
	{
		delete _parsedExpression;
		_parsedExpression = nullptr;
	}
	if (_functions != nullptr)
	{
		delete _functions;
		_functions = nullptr;
	}
}

FunctionParser::FunctionParser(const string & expression, const vector<string> & functions) : FunctionParser()
{
	_expression = expression;
	_functions = new vector<string>(functions);
}

void FunctionParser::setExpression(const string & expression)
{
	_expression = expression;
}

string FunctionParser::getExpression() const
{
	return _expression;
}

vector<string> FunctionParser::getParsedExpression() const
{
	return _parsedExpression == nullptr ? vector<string>() : *_parsedExpression;
}

bool FunctionParser::parseExpression()
{
	if (_expression.empty())
	{
		_flag = false;
		return _flag;
	}
	StringTokenizer * tokens = new StringTokenizer(_delims, _expression);
	_parsedExpression = new vector<string>();
	auto stk = new stack<string>();
	string prev;
	while (tokens->hasMoreTokens())
	{
		string curr = tokens->nextToken();
		if (!tokens->hasMoreTokens() && isOperation(curr))
		{
			_flag = false;
			return _flag;
		}
		if (curr == " " || curr == "\t") continue;
		if (isFunction(curr)) stk->push(curr);
		else if (isDelimiter(curr))
		{
			if (curr == "(") stk->push(curr);
			else if (curr == ")")
			{
				while (!(stk->top() == "("))
				{
					_parsedExpression->push_back(stk->top());
					stk->pop();
					if (stk->empty())
					{
						_flag = false;
						return _flag;
					}
				}
				stk->pop();
				if (!stk->empty() && isFunction(stk->top()))
				{
					_parsedExpression->push_back(stk->top());
					stk->pop();
				}
			}
			else
			{
				if (curr == "-" && (prev.empty() || (isDelimiter(prev) && !(prev == ")"))))
				{
					curr = "u-";
				}
				else
				{
					while (!stk->empty() && (getValueOfOperation(curr) <= getValueOfOperation(stk->top())))
					{
						_parsedExpression->push_back(stk->top());
						stk->pop();
					}
				}
				stk->push(curr);
			}
		}
		else
		{
			_parsedExpression->push_back(curr);
		}
		prev = curr;
	}

	while (!stk->empty())
	{
		if (isOperation(stk->top()))
		{
			_parsedExpression->push_back(stk->top());
			stk->pop();
		}
		else
		{
			_flag = false;
			return _flag;
		}
	}
	_flag = true;
	return _flag;
}
