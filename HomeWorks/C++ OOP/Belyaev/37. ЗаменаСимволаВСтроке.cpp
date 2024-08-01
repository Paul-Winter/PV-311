//ЗАДАНИЕ 4
//Написать программу, которая заменяет все
//символы точки «.» в строке, введенной пользователем,
//на символы восклицательного знака «!».

#include <iostream>
#include <string>
using namespace std;

void changePoint(char* mass, int size)
{
    int i = 0;
    while (mass[i] != '\0')
    {
        if (mass[i] == '.')
        {
            mass[i] = '!';
        }
        ++i;
    }
}

int main()
{
    int size = 21;
    char* newString = new char[size];
    cout << "Enter your sting (up to 20 symbols): ";
    cin.getline(newString, size);
    changePoint(newString, size);
    cout << "New sting: " << newString;

    return 0;
}