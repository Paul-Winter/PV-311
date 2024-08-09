#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Load
{
protected:

	size_t size;
	const char* path;
    Load();

public:

    Load(const char* path);

};

