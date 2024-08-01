//ЗАДАНИЕ 1
//Необходимо отсортировать первые две трети массива в порядке возрастания,
//если среднее арифметическое больше 0, иначе - лишь первую треть.
//Остальное не сортировать, а выстроить в обратном порядке.

#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void boobleSort(int* mass, int lenght)
{
    int buf = 0;

    for (int j = lenght - 1; j > 0; --j)
    {
        for (int i = 0; i < j; ++i)
        {
            if (mass[i] > mass[i + 1])
            {
                buf = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = buf;
            }
        }
    }
}

void my_swap(int* i, int* j)
{
    int buf = *i;
    *i = *j;
    *j = buf;
}

int main()
{
    srand(time(0));

    int lenght = 20;
    int middleArithmethic = 0;
    int* mass = new int[lenght];

    for (int i = 0; i < lenght; ++i)
    {
        mass[i] = rand() % 101 - 50;
        Sleep(10);
        cout << mass[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < lenght; ++i)
    {
        middleArithmethic += mass[i];
    }

    if ((middleArithmethic / lenght) > 0)
    {
        cout << "2/3" << endl;
        boobleSort(mass, ((lenght / 3) * 2));

        for (int i = ((lenght / 3) * 2), j = lenght - 1; i <= j; ++i, --j)  //j=lenght исправлено на j=lenght-1
        {                                                                   //и i != j на i <= j
            my_swap(&mass[i], &mass[j]);
        }
    }
    else
    {
        cout << "1/3" << endl;
        boobleSort(mass, (lenght / 3));

        for (int i = (lenght / 3), j = lenght - 1; i <= j; ++i, --j)        //j=lenght исправлено на j=lenght-1
        {                                                                   //и i != j на i <= j
            my_swap(&mass[i], &mass[j]);
        }
    }


    for (int i = 0; i < lenght; ++i)
    {
        cout << mass[i] << " ";
    }




}