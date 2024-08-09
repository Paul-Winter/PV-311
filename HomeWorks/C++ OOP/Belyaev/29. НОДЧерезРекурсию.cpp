//ЗАДАНИЕ 2
//Написать рекурсивную функцию нахождения
//наибольшего общего делителя двух целых чисел.

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a = 0;
    int b = 0;

    cout << "Enter number 1: ";
    cin >> a;
    cout << "Enter number 2: ";
    cin >> b;
    cout << "GCD = " << gcd(a, b);
    
    return 0;
}