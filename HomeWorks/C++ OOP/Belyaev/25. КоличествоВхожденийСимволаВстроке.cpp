//ЗАДАНИЕ 2
//Подсчет количества вхождений заданного символа в строке

#include <iostream>
using namespace std;

void display(char* mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mass[i];
    }
    cout << endl;
}

void fill(char* mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 90 + 32;
    }
}

int count(char* mass, char c, int i, int size)
{
    if (i == size - 1)
        return 0;
    else
    {
        if (c == mass[i])                           // если символ найден
            return count(mass, c, i + 1, size) + 1; // увеличить количество найденных символов на 1
        else
            return count(mass, c, i + 1, size);     // иначе, перейти к обработке следующего символа
    }
}

int main()
{
    char symbol = '\0';
    int size = 150;
    char* mass = new char[size];

    fill(mass, size);
    display(mass, size);
    cout << "Enter symbol:";
    cin >> symbol;
    cout << "Symbol " << symbol << " finded in this text: " << count(mass, symbol, 0, size) << " times.";

    return 0;
}