#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;

String::String() : String(80)
{

}

String::String(const size_t sizeStr) : sizeStr{ sizeStr }
{
	str = new char[sizeStr];
}

 String::String(char* str) : str{new char[sizeStr]}
{

	if (sizeStr != sizeof(size_t))
	{
		++sizeStr;
		str = new char[sizeStr];
	}

}

String::~String()
{
	delete[] str;
}

const char* const String::getStr() 
{
	return str;
}

size_t const String::getSizeStr() 
{
	return sizeStr;
}

void String::setStr(const char* const str) {
	
	for (int i = 0; i < sizeStr; ++i) {
		this->str[i] = str[i];
	}
}

void String::setSizeStr(const size_t const sizeStr)
{
	this->sizeStr = sizeStr;
}

void String::Display() {
	
	cout << this->str;
	cout << endl;
}



