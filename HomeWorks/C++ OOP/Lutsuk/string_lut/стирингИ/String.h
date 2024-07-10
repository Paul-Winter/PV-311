#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	size_t sizeStr;
public:
	
	String();

	String(const size_t sizeStr);

	String(char* str);
	
	~String();
	
	const char* const getStr();
	const size_t  getSizeStr();

	void setStr(const char* const str);
	void setSizeStr(const size_t sizeStr);

	void Display();
};

