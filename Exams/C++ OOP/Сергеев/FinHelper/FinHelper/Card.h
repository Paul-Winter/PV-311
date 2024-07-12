#pragma once
#include "Wallet.h"

class Card : public Wallet
{
protected:
	string cardType;
	int cardLimit = 0;
public:
	Card();

	Card(string cardName, map<string, int> cardCurrency, int cardAmountOfMoney, string cardType, int cardLimit);

	string GetCardType();

	void SetCardType(string cardType);

	int  GetCardLimit();

	void SetCardLimit(int cardLimit);

	void SetCard(string cardName, string cardCurrency, string cardType, int cardLimit, int cardAmountOfMoney = 0);
};
