#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File
{
protected:
	const string _path = "file.txt";
public:
	File();

	void WriteFile(string nameWallet, string valute, int amountOfMoney);

	void WriteFile(string nameCard, string valute, string cardType, int amountOfMoney, int creditLimit);
	void ReadFile();
};

