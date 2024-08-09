//ЗАДАНИЕ 2
//Написать функцию, которая удаляет из строки
//все вхождения в нее заданного символа.

#include <iostream>
#include <string>
using namespace std;

void delSymbol(char* mass, int size, char symbol)
{
    int i = 0;
    while (mass[i] != '\0')
    {
        if (mass[i] == symbol)
        {
            for (int j = i; j < size; j++)
            {
                if (mass[j] != '\0')
                {
                    mass[j] = mass[j + 1];
                }
            }
        }
        ++i;
    }
}

int main()
{
    int size = 21;
    char symbol = '\0';
    char* newString = new char[size];
    cout << "Enter your sting (up to 20 symbols): ";
    cin.getline(newString, size);
    cout << "Enter symbol to delete: ";
    cin >> symbol;
    delSymbol(newString, size, symbol);
    cout << "New sting: " << newString;

    return 0;
}