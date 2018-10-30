#include "StringTokenizer.h"

bool StringTokenizer::isDelimeter(char ch, const string & delimeters)
{
	for (auto delim : delimeters)
	{
		if (ch == delim) return true;
	}
	return false;
}


void StringTokenizer::clearSpaces(string & str) const
{
	for (unsigned short i = 0; i < str.size();)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			str.erase(str.begin() + i);
		}
		else ++i;
	}
}


StringTokenizer::StringTokenizer(const string & delimeters, string str)
{
	_tokens = new list<string>();

	while (!str.empty())
	{
		unsigned int i = 0;
		for (auto ch : str)
		{
			if (isDelimeter(ch, delimeters))
			{
				if (i == 0) ++i;
				break;
			}
			++i;
		}
		string tmp;
		tmp.assign(str.begin(), str.begin() + i);
		_tokens->push_back(tmp);
		str.assign(str.begin() + i, str.end());
	}
}


StringTokenizer::~StringTokenizer()
{
	clearTokens();
}


bool StringTokenizer::hasMoreTokens() const
{
	return !_tokens->empty();
}


string StringTokenizer::nextToken() const
{
	string buff = *_tokens->begin();
	_tokens->erase(_tokens->begin());
	return buff;
}


void StringTokenizer::clearTokens()
{
	if (_tokens == nullptr) return;
	delete _tokens;
	_tokens = nullptr;
}
