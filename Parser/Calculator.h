/****************************************************************************
**
** Calculator.h
**  ласс, который вычисл€ет значение, использу€ обратную польскую запись
**
** »змен€ть данный класс не рекомендуетс€ в цел€х сохранени€ корректной
** обработки данных.
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
	/// \brief ѕровер€ет, €вл€етс€ ли токен оператором
	///
	/// \param funcs - массив указателей на функции с сигнатурой
	///		   double(double), в которых содержатьс€ функции,
	///		   имена которых описаны в массиве строк
	///
	////////////////////////////////////////////////////////////
	void setFunctions(const vector<function<double(double)>> & funcs);

	////////////////////////////////////////////////////////////
	/// \brief ѕровер€ет, €вл€етс€ ли токен оператором
	///
	/// \param postfixExpression - выражение в обратной польской
	///		   записи
	///
	/// \return вычисл€емое значение, полученное в результате
	///		    вычислени€ выражени€
	///
	////////////////////////////////////////////////////////////
	double calculate(const vector<string> & postfixExpression) const;

	void setXVal(double xVal);
	};

#endif //CALCULATOR_H