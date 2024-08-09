//ЗАДАНИЕ 2
//Составьте программу циклической перестановки столбцов двумерного массива К,
//при которой i-й столбец становится i+1-м, а последний столбец становится первым.

#include <iostream>
using namespace std;

void d_fill(int** mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mass[i][j] = rand() % 100;
        }
    }
}
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
    cout << endl;
}

int main()
{
    int buf = 0;
    int size = 7;
    int** dmass = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        dmass[i] = new int[size];
    }

    d_fill(dmass, size);
    d_display(dmass, size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j >= 0; --j)
        {
            if (j == size - 1)              //когда столбец последний,
            {
                buf = dmass[i][j];          //запоминаем его значение
            }

            dmass[i][j] = dmass[i][j - 1];  //обмениваемся значениями между столбцами

            if (j == 0)                     //когда столбец первый,
            {
                dmass[i][j] = buf;          //вставляем значение из запомненного
            }
        }
    }

    d_display(dmass, size);

    return 0;
}