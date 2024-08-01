//ЗАДАНИЕ 5
//Подсчет количества элементов массива, больших заданного числа.

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
        mass[i] = rand() % 99;
    }
}

int count(int* mass, int size, int num, int i)
{
    if (i == size)
        return 0;                                           // условие окончания рекурсивного процесса
    else
    {
        if (num < mass[i])
            return count(mass, size, num, i + 1) + 1;       // добавить 1 к результату, и перейти далее
        else
            return count(mass, size, num, i + 1);           // перейти к следующему элементу массива
    }
    cout << i;
}

int main()
{
    int num = 0;
    int size = 10;
    int* mass = new int[size];

    fill(mass, size);
    display(mass, size);
    cout << "Enter number:";
    cin >> num;
    cout << "Count nubers more then " << num << " is " << count(mass, size - 1, num, 0);

    return 0;
}