//ЗАДАНИЕ 2
//Написать функцию, которая получает в качестве параметров 2 целых числа
//и возвращает сумму чисел из диапазона между ними.

#include <iostream>
using namespace std;

int between(int first, int second)
{
    int res = 0;
    for (int i = first + 1; i < second; i++)
    {
        res += i;
    }

    return res;
}
int main()
{
    int f = 0;
    int s = 0;

    cout << "Enter first number: ";
    cin >> f;
    cout << "Enter second number: ";
    cin >> s;

    cout << "Result: " << between(f,s);
}