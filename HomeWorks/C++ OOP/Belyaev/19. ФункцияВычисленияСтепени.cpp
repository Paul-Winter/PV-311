//ЗАДАНИЕ 1
//Написать функцию, которая принимает два
//параметра: основание степени и показатель степени, и
//вычисляет степень числа на основе полученных данных.

#include <iostream>
using namespace std;

int degree(int bas, int exp)
{
    int res = 1;
    for (int i = 1; i <= exp; i++)
    {
        res *= bas;
    }
    return res;
}

int main()
{
    int bas = 0;
    int exp = 0;

    cout << "Enter base: ";
    cin >> bas;
    cout << "Enter exponent : ";
    cin >> exp;

    cout << "Result: " << degree(bas,exp);
}