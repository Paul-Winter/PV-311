#include <iostream>
#include "Wallet.h"
#include "Card.h"
#include "File.h"

using namespace std;

int main()
{
    File f;
    string name;
    string cardType;
    int valute;
    int credit = 0;
    //Create Wallet
    Wallet w;
    //`<--  Определение переменных для записи 
    //--!>
    w.SetWallet("Qivi", "ruble", 200);
    w.GetWallet();

    // запись в файл
    name = w.GetName();
    valute = w.GetAmountOfMoney();
    f.WriteFile(name, "rub", valute);
    
    //Print Valute
    Currency cur;
    cur.GetAllCurrency();
    
    //Create Card (debt)
    Card card;
    card.SetCard("SberBank", "ruble", "debet", 100);
    card.GetCard();
    
    //Запись в файл
    name = card.GetName();
    valute = card.GetAmountOfMoney();
    cardType = card.GetCardType();
    f.WriteFile(name, "ruble", cardType, valute, credit) ;

    // Create card (credit)
    card.SetCard("VTB", "ruble", "debet", 100, 15000);

    // Запись в файл

    name = card.GetName();
    valute = card.GetAmountOfMoney();
    cardType = card.GetCardType();
    credit = card.GetCardLimit();
    f.WriteFile(name, "ruble", cardType, valute, credit) ;

    card.PayDay("SberBank", 400);
    f.WriteFile(name, "ruble", cardType, valute, credit) ;
    card.GetCard();

    f.ReadFile();

}
