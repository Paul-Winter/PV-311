//ЗАДАНИЕ 1
//Написать функцию, которая удаляет из строки символ с заданным номером.

#include <iostream>
#include <string>
using namespace std;

void delSymbol(char* mass, int size, int N)
{
    if (N > 0 && N < size)
    {
        for (int i = N - 1; i < size; i++)
        {
            if (mass[i] != '\0')
            {
                mass[i] = mass[i + 1];
            }
        }
    }
}

int main()
{
    int size = 21;
    int number = 0;
    char* newString = new char [size];
    cout << "Enter your sting (up to 20 symbols): ";
    cin.getline(newString, size);
    cout << "Enter number of symbol to delete (1-20): ";
    cin >> number;
    delSymbol(newString, size, number);
    cout << "New sting: " << newString;

    return 0;
}