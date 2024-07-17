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

void Wallet::PayDay(string name, int payDay)
{
	cout << "Switch volute: \n 1. - rubble \n 2. - dollar \n 3. - euro  ";
	int a = 0;
	cin >> a;
	switch(a)
	{
		case 1:
			//здесь костыль
			//walletAmountOfMoney += payDay * currency["rubble"];
			payDay = payDay * currency["ruble"] + walletAmountOfMoney;
			SetAmountOfMoney(payDay);
			break;
		case 2:
			payDay = payDay * currency["dollar"] + walletAmountOfMoney;
			SetAmountOfMoney(payDay);
			break;
		case 3:
			payDay = payDay * currency["euro"] + walletAmountOfMoney;
			SetAmountOfMoney(payDay);
			break;
	}
			cout << "Name: " << name << "\t Amount of money: " << walletAmountOfMoney << endl;
}
