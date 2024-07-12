#include "Wallet.h"
#include <iostream>
Wallet::Wallet()
{
}

 Wallet::Wallet(string walletName, map<string, int> walletCurrency, int walletAmountOfMoney) : walletName{ walletName }, Currency{ walletCurrency }, walletAmountOfMoney{ walletAmountOfMoney }
{
}

string Wallet::GetName()
{
	return walletName;
}

void Wallet::SetName(string walletName)
{
	this->walletName = walletName;
}

int Wallet::GetAmountOfMoney()
{
	return walletAmountOfMoney;
}

void Wallet::SetAmountOfMoney(int amountOfMoney)
{
	this->walletAmountOfMoney = amountOfMoney;
}

void Wallet::SetWallet(string walletName, string walletCurrency, int walletAmountOfMoney)
{
	this->walletName = walletName;
	this->walletCurrency.currency[walletCurrency];
	if (walletAmountOfMoney != 0)
	{
		this->walletAmountOfMoney = walletAmountOfMoney * this->walletCurrency.currency[walletCurrency];
	}
	else
	{
		this->walletAmountOfMoney = walletAmountOfMoney;
	}
}



