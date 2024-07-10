// func_.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
template <class T>
T koren(T a, T b)
{
    // T x;
    // a*x = b;
    // b = 0 -a*x;
    // b = -a*x;
    // -a*x = b;
    // a*x = -b;
    // x = -b /a;
    return -b / a;
}

template <class T>
const double* const square(T a, T b, T c)
{
    double D;
    D = b * b - 4 * a * c;
    if (D <= 0)
    {
        return nullptr;
    }

    double* answer = new double[2];
    answer[0] = (-b + sqrt(D)) / (2 * a);
    answer[1] = (-b - sqrt(D)) / (2 * a);

    return answer;
}


template <class T>
T middle(T* massive, size_t size)
{
    T temp = 0;
    for (size_t i = 0; i < size; ++i)
    {
        temp += massive[i];
    }

    return temp / size;
}

template <class T>
T mini(T a, T b)
{
    

    return a < b ? a : b;
}

template <class T>
T maxi(T a, T b)
{


    return a > b ? a : b;
}

int main()
{
    cout << maxi(1, 2);
}

