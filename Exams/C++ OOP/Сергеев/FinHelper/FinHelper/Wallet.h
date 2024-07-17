#pragma once
#include <string>
#include <iostream>
#include "Currency.h"

using namespace std;

class Wallet : public Currency
{
protected:

	string walletName;
	int walletAmountOfMoney=0;

public:
	Currency walletCurrency;
	
	Wallet();

	Wallet(string walletName, map<string, int> walletCurrency, int walletAmountOfMoney = 0);

	string GetName();
	
	void SetName(string name);

	int GetAmountOfMoney();

	void SetAmountOfMoney(int amountOfMoney);

	Wallet GetWallet()
	{
		Wallet _wallet;
		std::cout << "Wallet name: " << walletName
			<< "\nwallet amount of money: " << walletAmountOfMoney
			<< " rub" << endl;
		return _wallet;
	}

	void SetWallet(string walletName, string walletCurrency, int walletAmountOfMoney = 0);

	void PayDay(string name, int payDay);

};

