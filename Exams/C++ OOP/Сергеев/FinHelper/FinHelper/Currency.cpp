#include "Currency.h"
#include <iostream>
#include <map>

Currency::Currency()
{
}

Currency::Currency(std::map<std::string, int>currency) : currency{ currency}
{
}


void Currency::GetAllCurrency()
{
	for (auto &element : currency)
		std::cout << element.first << " " << element.second << std::endl;
}


