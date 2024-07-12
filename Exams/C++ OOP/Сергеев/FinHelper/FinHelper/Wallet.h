#pragma once
#include <string>
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
		return _wallet;
	}

	void SetWallet(string walletName, string walletCurrency, int walletAmountOfMoney = 0);



};

