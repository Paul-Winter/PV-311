//ЗАДАНИЕ 3
//В квадратной таблице обменяйте местами элементы строки и столбца,
//на пересечении которых находится минимальный из положительных элементов.

#include <iostream>
using namespace std;

void d_display(int** mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int buf = 0;
    int size = 6;
    int** dmass = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        dmass[i] = new int[size];
    }

    int max = 0;
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            dmass[i][j] = rand() % 71 - 35;     //заполняем массив чслами от -35 до 35
            if (max < dmass[i][j])
            {
                max = dmass[i][j];              //при этом находим максимальное значение
            }
        }
    }

    d_display(dmass, size);

    int min_i = 0;
    int min_j = 0;
    int min = max;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (dmass[i][j] < min && dmass[i][j] >= 0)
            {
                min = dmass[i][j];              //запоминаем минимальное значение и индексы элемента
                min_i = i;
                min_j = j;
            }
        }
    }
    cout << "Finded MIN = " << min << " in " << min_i + 1 << " row, and " << min_j + 1 << " col." << endl;
    
    for (int i = 0; i < size; ++i)              //меняем элементы строки и столбца (элемент строки затирает элемент столбца на пересечении)
    {                                           
        if (min_i != i)
        {
            buf = dmass[min_i][i];
            dmass[min_i][i] = dmass[i][min_j];
            dmass[i][min_j] = buf;
        }
        else
        {
            dmass[min_i][i] = min;
        }
    }

    d_display(dmass, size);

    return 0;
}