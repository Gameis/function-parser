#ifndef SAVER_H
#define SAVER_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Saver
	{
	ofstream * _writer;
public:
	Saver();
	~Saver();

	void save(const string & path, const vector<string> & data, char delim = ' ') const;
	void save(const string & path, const string & data) const;
	};

#endif //SAVER_H