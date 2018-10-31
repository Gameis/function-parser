#include "Saver.h"



Saver::Saver()
	{
	_writer = new ofstream();
	}


Saver::~Saver()
	{
	delete _writer;
	_writer = nullptr;
	}


void Saver::save(const string & path, const vector<string> & data, const char delim) const
	{
	_writer->open(path);
	for(auto i = data.begin(); i != data.end(); ++i)
		{
		*_writer << *i;
		if(i != (data.end() - 1))
			{
			*_writer << delim;
			}
		}
	_writer->close();
	}


void Saver::save(const string & path, const string & data) const
	{
	_writer->open(path);
	*_writer << data;
	_writer->close();
	}
