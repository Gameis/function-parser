/****************************************************************************
**
** stringtokenizer.h
** «аголовочный файл, в котором находитс€ класс дл€ разделени€ строки по
** определенным сиволам
**
** »змен€ть данный класс не рекомендуетс€ в цел€х сохранени€ корректной
** обработки данных.
**
****************************************************************************/


#ifndef MYSTRINGTOKENIZER_H
#define MYSTRINGTOKENIZER_H

#include <string>
#include <list>

using namespace std;

class StringTokenizer
{
private:
	list<string> * _tokens;

	bool isDelimeter(char ch, const string & delimeters);
	void clearSpaces(string & str) const;
public:
	StringTokenizer(const string & delimeters, string str);
	~StringTokenizer();

	bool hasMoreTokens() const;
	string nextToken() const;
	void clearTokens();
};

#endif // MYSTRINGTOKENIZER_H