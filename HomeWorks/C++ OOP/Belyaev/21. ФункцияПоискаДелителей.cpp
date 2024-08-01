//ЗАДАНИЕ 3
//Число называется совершенным, если сумма всех его делителей равна ему самому.
//Напишите функцию поиска таких чисел во введенном интервале.

#include <iostream>
using namespace std;

void perfect(int first, int second)
{
    bool find = false;
    int sum = 0;

    for (int i = first; i <= second; i++)
    {
        sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
                sum = sum + j;
        }
        if (sum == i)
        {
            find = true;
            cout << "Perfect number: " << i << endl;
        }
    }
    if (!find)
    {
        cout << "Do not find perfect number!";
    }
}
int main()
{
    int f = 0;
    int s = 0;

    cout << "Enter first number: ";
    cin >> f;
    cout << "Enter second number: ";
    cin >> s;

    perfect(f, s);

    return 0;
}