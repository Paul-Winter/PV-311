//ЗАДАНИЕ 4
//Нахождение наибольшего общего делителя.

#include <iostream>
using namespace std;

int maxDiv(int n, int m)
{
    if (n == m)
        return n;
    else
        if (n > m)
            return maxDiv(n - m, m);
        else
            return maxDiv(n, m - n);
}

int main()
{
    int n = 0;
    int m = 0;
    cout << "Enter number 1:";
    cin >> n;
    cout << "Enter number 2:";
    cin >> m;
    cout << "MaxDiv = " << maxDiv(n, m);

    return 0;
}