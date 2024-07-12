
#include "Card.h"

Card::Card()
{
}

Card::Card(string cardName, map<string, int> cardCurrency, int cardAmountOfMoney, string cardType, int cardLimit)
{
	this->walletName = cardName;
	this->walletCurrency = cardCurrency;
	this->walletAmountOfMoney = cardAmountOfMoney;
	this->cardType = cardType;
	this->cardLimit = cardLimit;
}


string Card::GetCardType()
{
	return cardType;
}

void Card::SetCardType(string cardType)
{
	this->cardType = cardType;
}

int Card::GetCardLimit()
{
	return cardLimit;
}

void Card::SetCardLimit(int cardLimit)
{
	this->cardLimit = cardLimit;
}

void Card::SetCard(string cardName, string cardCurrency, string cardType, int cardLimit, int cardAmountOfMoney)
{
	this->walletName = cardName;
	this->walletCurrency.currency[cardCurrency];

	if (cardAmountOfMoney != 0)
	{
		this->walletAmountOfMoney = walletAmountOfMoney * this->walletCurrency.currency[cardCurrency];
	}
	else
	{
		this->walletAmountOfMoney = cardAmountOfMoney;
	}

	if (cardType == "credit")
	{
		this->cardLimit = cardLimit;
	}
}


