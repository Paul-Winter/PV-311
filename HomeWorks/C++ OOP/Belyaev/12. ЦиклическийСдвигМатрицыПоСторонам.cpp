#include <iostream>
using namespace std;

int main()
{
    //ЗАДАНИЕ 3

    srand(time(0));
    int size = 6;                           //устанавливаем размерность
    int dsize = 6;                          //двумерного массива 6х6
    int shift = 0;                          //сдвиг
    int vector = 0;                         //направление
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
            dMass[i][j] = 1 + rand() % 100; 
            cout << dMass[i][j] << "\t";    //вывод значений элементов
        }
        cout << endl;
    }
    
    cout << "Enter vector (1-up, 2-down, 3-left, 4-right): ";
    cin >> vector;
    if (vector < 1 || shift > 4)
    {
        vector = 4;
    }
    
    cout << "Enter shift (1-6): ";
    cin >> shift;
    if (shift < 1 || shift > size)
    {
        shift = 1;
    }
        
    switch (vector)
    {
    case 1:                                 //циклический сдвиг вверх

        cout << "Cycle shift up at " << shift << " steps:" << endl;

        for (int tek = 0; tek < shift; tek++)
        {
            for (int j = 0; j < dsize; ++j)
            {
                buf = dMass[0][j];
                for (int i = 0; i < size - 1; ++i)
                {
                    dMass[i][j] = dMass[i + 1][j];
                }
                dMass[size - 1][j] = buf;
            }
        }
        break;

    case 2:                                 //циклический сдвиг вниз
        
        cout << "Cycle shift down at " << shift << " steps:" << endl;

        for (int tek = 0; tek < shift; tek++)
        {
            for (int j = 0; j < dsize; ++j)
            {
                buf = dMass[size - 1][j];
                for (int i = size - 1; i != 0; --i)
                {
                    dMass[i][j] = dMass[i - 1][j];
                }
                dMass[0][j] = buf;
            }
        }
        break;

    case 3:                                 //циклический сдвиг влево
        
        cout << "Cycle shift left at " << shift << " steps:" << endl;

        for (int tek = 0; tek < shift; tek++)
        {
            for (int i = 0; i < size; ++i)
            {
                buf = dMass[i][0];
                for (int j = 0; j < dsize; ++j)
                {
                    dMass[i][j] = dMass[i][j + 1];
                }
                dMass[i][dsize - 1] = buf;
            }
        }
        break;

    default:                                //циклический сдвиг вправо
       
        cout << "Cycle shift right at " << shift << " steps:" << endl;

        for (int tek = 0; tek < shift; tek++)
        {
            for (int i = 0; i < size; ++i)
            {
                buf = dMass[i][dsize - 1];
                for (int j = dsize - 1; j != -1; --j)
                {
                    dMass[i][j] = dMass[i][j - 1];
                }
                dMass[i][0] = buf;
            }
        }
    }
    
    for (int i = 0; i < size; ++i)          //вывод результатов
    {
        for (int j = 0; j < dsize; ++j)
        {
           cout << dMass[i][j] << "\t";    
        }
        cout << endl;
    }

    return 0;
}