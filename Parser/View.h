#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

enum ConsoleColor {
	BLACK_C = 0,
	BLUE_C = 1,
	GREEN_C = 2,
	CYAN_C = 3,
	RED_C = 4,
	MAGENTA_C = 5,
	BROWN_C = 6,
	LIGHT_GRAY_C = 7,
	DARK_GRAY_C = 8,
	LIGHT_BLUE_C = 9,
	LIGHT_GREEN_C = 10,
	LIGHT_CYAN_C = 11,
	LIGHT_RED_C = 12,
	LIGHT_MAGENTA_C = 13,
	YELLOW_C = 14,
	WHITE_C = 15
};

class View
	{
private:
	HANDLE _hConsole;
public:
	View();
	
	void printMenu() const;
	void setColor(const int32_t font, const int32_t bg = BLACK_C) const;
	char promptActivity() const;

	void pError() const;

	vector<pair<double, double>> getDistribRange() const;

	double getDoubleNumber() const;

	void printDistribRange(const vector<pair<double, double>> & dr) const;

	void print(const string & context, const double value) const;

	void print(const string& context) const;

	void print(const vector<string> & context, char delim = ' ') const;

	string getExpression();

	double getX() const;
	};
