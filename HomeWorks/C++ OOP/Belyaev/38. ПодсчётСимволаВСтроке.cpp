//ЗАДАНИЕ 5
//Пользователь вводит строку символов и искомый символ,
//посчитать сколько раз он встречается в строке.

#include <iostream>
#include <string>
using namespace std;

int countSymbol(char* mass, int size, char symbol)
{
    int counter = 0;
    int i = 0;
    while (mass[i] != '\0')
    {
        if (mass[i] == symbol)
        {
            ++counter;
        }
        ++i;
    }
    return counter;
}

int main()
{
    int size = 21;
    char symbol = '\0';
    char* newString = new char[size];
    cout << "Enter your sting (up to 20 symbols): ";
    cin.getline(newString, size);
    cout << "Enter symbol to count: ";
    cin >> symbol;
    cout << "Counts symbols \"" << symbol << "\" in this string is: " << countSymbol(newString, size, symbol);
    
    return 0;
}