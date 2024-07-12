#pragma once
#include<map>
#include <string>

class Currency
{
public:
	std::map<std::string, int> currency
	{
		{"ruble", 1},
		{"euro", 120},
		{"dollar", 100}
	};
public:
	Currency();

	Currency(std::map<std::string, int>currency);

	void GetAllCurrency();
};