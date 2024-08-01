//ЗАДАНИЕ 3
//Дана матрица порядка M×N (M строк, N столбцов). 
//Необходимо заполнить ее значениями и написать
//функцию, осуществляющую циклический сдвиг строк
//и/или столбцов массива указанное количество раз
//и в указанную сторону

#include <iostream>
using namespace std;

int** initDMass(int** mass, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeX; i++)
    {
        mass[i] = new int[sizeY];
    }

    return mass;
}

void display(int** mass, int sizeX, int sizeY)
{
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

void fill(int** mass, int sizeX, int sizeY)
{
    srand(time(0));
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            mass[i][j] = rand() % 9 + 1;
        }
    }
}

int** shiftDMass(int** mass, int sizeX, int sizeY, int steps, int direction)
{
    int buf = 0;

    switch (direction)
    {
    case 1:                                 //циклический сдвиг вверх

        cout << "Cyclic upward shift in " << steps << " steps:" << endl;

        for (int tek = 0; tek < steps; tek++)
        {
            for (int j = 0; j < sizeY; ++j)
            {
                buf = mass[0][j];
                for (int i = 0; i < sizeX - 1; ++i)
                {
                    mass[i][j] = mass[i + 1][j];
                }
                mass[sizeX - 1][j] = buf;
            }
        }
        break;

    case 2:                                 //циклический сдвиг вниз

        cout << "Cyclic downward shift in " << steps << " steps:" << endl;

        for (int tek = 0; tek < steps; tek++)
        {
            for (int j = 0; j < sizeY; ++j)
            {
                buf = mass[sizeX - 1][j];
                for (int i = sizeX - 1; i != 0; --i)
                {
                    mass[i][j] = mass[i - 1][j];
                }
                mass[0][j] = buf;
            }
        }
        break;

    case 3:                                 //циклический сдвиг влево

        cout << "Cyclic shift to the left in " << steps << " steps:" << endl;

        for (int tek = 0; tek < steps; tek++)
        {
            for (int i = 0; i < sizeX; ++i)
            {
                buf = mass[i][0];
                for (int j = 0; j < sizeY; ++j)
                {
                    mass[i][j] = mass[i][j + 1];
                }
                mass[i][sizeY - 1] = buf;
            }
        }
        break;

    default:                                //циклический сдвиг вправо

        cout << "Cyclic shift to the right in " << steps << " steps:" << endl;

        for (int tek = 0; tek < steps; tek++)
        {
            for (int i = 0; i < sizeX; ++i)
            {
                buf = mass[i][sizeY - 1];
                for (int j = sizeY - 1; j != -1; --j)
                {
                    mass[i][j] = mass[i][j - 1];
                }
                mass[i][0] = buf;
            }
        }
    }

    return mass;
}

int main()
{
    int sizeX = 10;
    int sizeY = 10;
    int steps = 0;
    int direction = 0;

    int** mass = new int* [sizeX];
    mass = initDMass(mass, sizeX, sizeY);
    fill(mass, sizeX, sizeY);
    cout << "Source array:" << endl;
    display(mass, sizeX, sizeY);

    cout << "Enter direction to shift (1-up, 2-down, 3-left, 4-right): ";
    cin >> direction;
    if (direction < 1 || direction > 4)
    {
        direction = 4;
    }
    cout << "Enter number of steps (1-10): ";
    cin >> steps;
    if (steps < 1 || steps > 10)
    {
        steps = 1;
    }

    cout << "New array:" << endl;
    mass = shiftDMass(mass, sizeX, sizeY, steps, direction);
    display(mass, sizeX, sizeY);

    return 0;
}