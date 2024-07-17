
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

Card Card::GetCard()
{
	{
		Card _card;
		std::cout << "Wallet name: " << walletName
			<< "\nwallet amount of money: " << walletAmountOfMoney << " rub"
			<< "\ncard type: " << cardType
			<< "\ncard limit: " << cardLimit << endl;
		return _card;
	}
}

void Card::SetCard(string cardName, string cardCurrency, string cardType, int cardAmountOfMoney, int cardLimit)
{
	this->walletName = cardName;
	this->walletCurrency.currency[cardCurrency];
	this->cardType = cardType;

	if (cardType == "credit")
	{
		this->cardLimit = cardLimit;
	}
	else
		this->cardLimit = 0;

	if (cardAmountOfMoney != 0)
	{
		this->walletAmountOfMoney = cardAmountOfMoney * this->walletCurrency.currency[cardCurrency];
	}
	else
	{
		this->walletAmountOfMoney = cardAmountOfMoney;
	}

}


