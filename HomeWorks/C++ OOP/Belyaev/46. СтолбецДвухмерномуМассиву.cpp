//ЗАДАНИЕ 1.
//Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.

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

void delDMass(int** mass, int sizeX)
{
    for (int i = 0; i < sizeX; i++)
    {
        delete[] mass[i];
    }
    delete[] mass;
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

int** insertColumn(int** mass, int sizeX, int sizeY, int N)
{

    int** newMass = new int* [sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        newMass[i] = new int[sizeY + 1];
    }
    
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0, k = 0; j < sizeY + 1; j++, k++)
        {
            if (k == N - 1)
            {
                newMass[i][k] = 0;
                --j;
            }
            else
            {
                newMass[i][k] = mass[i][j];
            }
        }
    }
    delDMass(mass, sizeX);

    return newMass;
}

int main()
{
    int number = 0;
    int sizeX = 10;
    int sizeY = 10;
    int** mass = new int* [sizeX];
    mass = initDMass(mass, sizeX, sizeY);
    
    fill(mass, sizeX, sizeY);
    cout << "Source array:" << endl;
    display(mass, sizeX, sizeY);
    cout << "Enter number of new column (1..10): ";
    cin >> number;

    cout << "New array:" << endl;
    mass = insertColumn(mass, sizeX, sizeY, number);
    display(mass, sizeX, sizeY + 1);

    return 0;
}