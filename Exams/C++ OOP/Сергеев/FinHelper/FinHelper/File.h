#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File
{
protected:
	const string _path = "\\FinHelper\\FinHelper\\x64\\Debug\\file.txt";
	string text;

	void WriteFile();
};

