//ЗАДАНИЕ 6
//Пользователь вводит строку. Определить количество букв, 
//количество цифр и количество остальных символов, присутствующих в строке.


#include <iostream>
#include <string>
using namespace std;

void countSymbol(char* mass, int size)
{
    int counterDigits = 0;
    int counterLetters = 0;
    int counterSymbols = 0;

    int i = 0;
    while (mass[i] != '\0')
    {
        if ((int)mass[i] >= 48 && (int)mass[i] <= 57)
        {
            ++counterDigits;
        }
        else if ((int)mass[i] >= 65 && (int)mass[i] <= 90)
        {
            ++counterLetters;
        }
        else if ((int)mass[i] >= 97 && (int)mass[i] <= 122)
        {
            ++counterLetters;
        }
        else
        {
            ++counterSymbols;
        }
        ++i;
    }
    cout << "Number of digits: " << counterDigits << endl;
    cout << "Number of letters: " << counterLetters << endl;
    cout << "Number of other symbols: " << counterSymbols << endl;
}

int main()
{
    int size = 21;
    char symbol = '\0';
    char* newString = new char[size];
    cout << "Enter your sting (up to 20 symbols): ";
    cin.getline(newString, size);
    countSymbol(newString, size);

    return 0;
}