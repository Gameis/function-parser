#include "View.h"


View::View()
	{
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	}


void View::printMenu() const
	{
	setColor(GREEN_C);
	cout << "\t\t---Main menu---" << endl;
	}


void View::setColor(const int32_t font, const int32_t  bg) const
	{
	SetConsoleTextAttribute(_hConsole, static_cast<WORD>((bg << 4) | font));
	}


char View::promptActivity() const
	{
	setColor(YELLOW_C);
	cout << "\t1 - Find value of function by the x" << endl;
	cout << "\t2 - Find numeric properties of DRV" << endl;
	cout << "\t3 - Find numeric differination of function" << endl;
	cout << "\t0 - Exit" << endl;
	string result;
	getline(cin, result);
	if (result.size() > 1) return '\0';
	return result[0];
	}


void View::pError() const
	{
	setColor(BLACK_C, RED_C);
	cout << "#---Error---#" << endl;
	setColor(YELLOW_C);
	}


vector<pair<double, double>> View::getDistribRange() const
	{
	vector<pair<double, double>> distribRange;
	string buff;
	char * useless;
	int size;
	do
		{
		cout << "Input amount of elements: ";
		getline(cin, buff);

		size = strtol(buff.c_str(), &useless, 10);
		if (size <= 0) pError();
		}
	while ( size <= 0 );
	
	distribRange.resize(size);
	int i = 0;
	for(auto & el : distribRange)
		{
		cout << "Input x" << i << ": ";
		el.first = getDoubleNumber();
		do
			{
			cout << "Input p" << i << ": ";
			el.second = getDoubleNumber();
			}
		while ( el.second <= 0 || el.second >= 1 );
		++i;
		}
	return distribRange;
	}


double View::getDoubleNumber() const
	{
	string buff;
	char * useless;
	getline(cin, buff);
	return strtod(buff.c_str(), &useless);
	}


void View::printDistribRange(const vector<pair<double, double>> & dr) const
	{
	setColor(YELLOW_C, YELLOW_C);
	cout << "==============================================================" << endl;
	setColor(YELLOW_C);
	cout << "Distribution range:" << endl;
	cout.width(5);
	cout << "x|";
	int size = 0;
	for (auto & el : dr)
	{
		cout.width(15);
		cout << el.first << '|';
		++size;
	}
	cout << endl;
	cout << "-----";
	for(int i = 0; i < size; ++i)
		{
		for(int j = 0; j < 15;++j)
			{
			cout << '-';
			}
		}
	cout << endl;
	cout.width(5);
	cout << "p|";
	for (auto & el : dr)
		{
		cout.width(15);
		cout << el.second << '|';
		}
	cout << endl;
	setColor(YELLOW_C, YELLOW_C);
	cout << "==============================================================" << endl;
	setColor(YELLOW_C);
	}


void View::print(const string & context, const double value) const
	{
	cout << context << value << endl;
	}


void View::print(const string & context) const
	{
	cout << context << endl;
	}


void View::print(const vector<string> & context, char delim) const
	{
	for(auto i = context.begin(); i != context.end();++i)
		{
		cout << *i;
		if(i!= (context.end() - 1))
			{
			cout << delim;
			}
		}
	cout << endl;
	}


string View::getExpression() const
	{
	cout << "Input expression: ";
	string buff;
	getline(cin, buff);
	return buff;
	}


double View::getX() const
	{
	cout << "Input x: ";
	return getDoubleNumber();
	}


