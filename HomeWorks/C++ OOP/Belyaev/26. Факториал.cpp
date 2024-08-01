//ЗАДАНИЕ 3
//нахождениt факториала числа – n!

#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1)
        return 1;                   // условие завершения рекурсивного процесса
    else
        return n * fact(n - 1);     // переход к предыдущему числу n-1
}

int main()
{
    int n = 0;
    cout << "Enter number:";
    cin >> n;
    cout << "Factorial " << n << "! = " << fact(n);

    return 0;
}