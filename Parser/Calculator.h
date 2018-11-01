/****************************************************************************
**
** Calculator.h
** �����, ������� ��������� ��������, ��������� �������� �������� ������
**
** �������� ������ ����� �� ������������� � ����� ���������� ����������
** ��������� ������.
**
****************************************************************************/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <stack>
#include <functional>
#include <cmath>
using namespace std;

class Calculator
	{
	vector<string> * _functionsNames;

	vector<function<double(double)>> * _funcs;

	int getFunctionIdNyName(const string & token) const;
	double _xVal = 0;

public:
	Calculator();
	explicit Calculator(const vector<string> & functions);
	~Calculator();

	////////////////////////////////////////////////////////////
	/// \brief ���������, �������� �� ����� ����������
	///
	/// \param funcs - ������ ���������� �� ������� � ����������
	///		   double(double), � ������� ����������� �������,
	///		   ����� ������� ������� � ������� �����
	///
	////////////////////////////////////////////////////////////
	void setFunctions(const vector<function<double(double)>> & funcs);

	////////////////////////////////////////////////////////////
	/// \brief ���������, �������� �� ����� ����������
	///
	/// \param postfixExpression - ��������� � �������� ��������
	///		   ������
	///
	/// \return ����������� ��������, ���������� � ����������
	///		    ���������� ���������
	///
	////////////////////////////////////////////////////////////
	double calculate(const vector<string> & postfixExpression) const;

	void setXVal(double xVal);
	};

#endif //CALCULATOR_H