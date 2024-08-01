//ЗАДАНИЕ 1
//Составьте программу, меняющую местами элементы матрицы симметрично диагонали.

#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    int size = 6;                           //устанавливаем размерность
    int dsize = 6;                          //двумерного массива 6х6
    int buf = 0;                            //буферная переменная

    int** dMass = new int* [size];          //инициализируем двумерный массив
    for (int i = 0; i < size; ++i)
    {
        dMass[i] = new int[dsize];
    }

    for (int i = 0; i < size; ++i)          //заполняем двумерный массив случайными числами
    {
        for (int j = 0; j < dsize; ++j)
        {
            dMass[i][j] = 10 + rand() % 89; //для наглядности - двузначными
            cout << dMass[i][j] << " ";     
        }
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i < size; ++i)          //в этих циклах происходит обмен элементами
    {
        for (int j = 0; j < dsize; ++j)
        {
            if (i != j)                     //диагональ не трогаем
            {
                buf = dMass[j][i];
                dMass[j][i] = dMass[i][j];
                dMass[i][j] = buf;
            }
        }
    }

    for (int i = 0; i < size; ++i)          //вывод результатов
    {
        for (int j = 0; j < dsize; ++j)
        {
            cout << dMass[j][i] << " ";    
        }
        cout << endl;
    }

    return 0;
}
