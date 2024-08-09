//ЗАДАНИЕ 4
//Создайте двумерный массив целых чисел. Удалите из него строку и столбец,
//на пересечении которых расположен минимальный элемент.

#include <iostream>
using namespace std;

void d_display(int** mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

void d_fill(int** mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mass[i][j] = rand() % 90 + 10;     //заполняем массив двузначными для наглядности
        }
    }
}

int main()
{
    int buf = 0;
    int size = 10;
    int min = 0;
    int min_i = 0;
    int min_j = 0;

    int** dmass = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        dmass[i] = new int[size];
    }
    
    d_fill(dmass, size);
    d_display(dmass, size);

    min = dmass[min_i][min_j];
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (dmass[i][j] < min)
            {
                min = dmass[i][j];              //запоминаем минимальное значение и индексы элемента
                min_i = i;
                min_j = j;
            }
        }
    }
    cout << "Finded MIN = " << min << " in " << min_i + 1 << " row, and " << min_j + 1 << " col.\n" << endl;

    for (int i = 0; i < size; ++i)              //сначала удаляем столбец
    {
        for (int j = min_j; j <= size - 1; ++j)
        {
            if (j == size - 1)
            {
                dmass[i][j] = 0;
            }
            else
            {
                dmass[i][j] = dmass[i][j + 1];
            }
        }
    }
    
    for (int i = min_i; i < size; ++i)          //теперь удаляем строку
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == size - 1)
            {
                dmass[i][j] = 0;
            }
            else
            {
                dmass[i][j] = dmass[i + 1][j];
            }
        }
    }
    
    cout << "Array after transformation:" << endl;
    d_display(dmass, size-1);

    return 0;
}