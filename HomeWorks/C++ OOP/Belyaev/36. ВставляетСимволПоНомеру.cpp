//ЗАДАНИЕ 3
//Написать функцию, которая вставляет в строку
//в указанную позицию заданный символ.

#include <iostream>
#include <string>
using namespace std;

void insertSymbol(char* mass, int size, int N, char symbol)
{
    if (N > 0 && N < size)
    {
        mass[N - 1] = symbol;
    }
}

int main()
{
    int size = 21;
    int number = 0;
    char symb = '\0';
    char* newString = new char[size];
    cout << "Enter your sting (up to 20 symbols): ";
    cin.getline(newString, size);
    cout << "Enter new symbol to insert: ";
    cin >> symb;
    cout << "Enter number of position where insert new symbol (1-20): ";
    cin >> number;
    insertSymbol(newString, size, number, symb);
    cout << "New sting: " << newString;

    return 0;
}