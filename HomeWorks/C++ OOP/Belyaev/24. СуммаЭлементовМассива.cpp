//ЗАДАНИЕ 1
//Поиск суммы элементов массива

#include <iostream>
using namespace std;

void display(int* mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void fill(int* mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 90 + 10;
    }
}

int summ(int* mass, int i, int size)
{
    if (i == size - 1)
        return mass[i];
    else
        return mass[i] + summ(mass, i + 1, size);
}

int main()
{
    int size = 10;
    int* mass = new int [size];
    
    fill(mass, size);
    display(mass, size);
    cout << summ(mass,0, size);

    return 0;
}