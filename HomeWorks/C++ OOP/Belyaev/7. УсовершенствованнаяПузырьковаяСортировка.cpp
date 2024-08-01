//ЗАДАНИЕ 2
//Написать программу, реализующую сортировку массива с
//помощью усовершенствованной сортировки пузырьковым методом.
//Усовершенствование состоит в том, чтобы анализировать
//количество перестановок на каждом шагу, если это количество
//равно нулю, то продолжать сортировку нет смысла — массив отсортирован.

#include <iostream>
using namespace std;

int main()
{

    srand(time(0));

    int size = 10;
    int buf = 0;
    int num = 0;
    int* mass = new int[size];

    for (int i = 0; i < size; ++i)
    {
        mass[i] = 1 + rand() % 100;
        cout << mass[i] << "\t";
    }
    
    for (int i = 0; i < size; ++i)
    {
        num = 0;
        for (int j = 0; j < size-1; ++j)
        {
            if (mass[j] > mass[j+1])
            {
                buf = mass[j];
                mass[j] = mass[j+1];
                mass[j+1] = buf;
                ++num;
            }
        }
        if (num == 0)
        {
            cout << "\nMassive sorted at " << i << " steps." << endl;
            i = size;
        }
    }
    
    for (int i = 0; i < size; ++i)
    {
        cout << mass[i] << "\t";
    }

    return 0;
}