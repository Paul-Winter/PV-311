// ЗАДАНИЕ 1
//Написать перегруженные функции (int, double, char) для выполнения следующих задач :
//- Инициализация квадратной матрицы;
//- Вывод матрицы на экран;
//- Определение максимального и минимального элемента на главной диагонали матрицы;
//- Сортировка элементов по возрастанию отдельно для каждой строки матрицы.

#include <iostream>
using namespace std;

int** initialize(int size)
{
    int** mass = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        mass[i] = new int[size];
    }
    return mass;
}

double** initialize(double size)
{
    double** mass = new double* [size];
    for (int i = 0; i < size; ++i)
    {
        mass[i] = new double[size];
    }
    return mass;
}

char** initialize(long size)
{
    char** mass = new char* [size];
    for (int i = 0; i < size; ++i)
    {
        mass[i] = new char[size];
    }
    return mass;
}

void sort(int** mass, int size)
{
    int buf = 0;

    for (int i = 0; i < size; i++)
    {
        int length = size;
        while(length > 0)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (mass[i][j] > mass[i][j + 1])
                {
                    buf = mass[i][j];
                    mass[i][j] = mass[i][j + 1];
                    mass[i][j + 1] = buf;
                }
            }
            --length;
        }
    }
}

void sort(double** mass, int size)
{
    double buf = 0;

    for (int i = 0; i < size; i++)
    {
        int length = size;
        while (length > 0)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (mass[i][j] > mass[i][j + 1])
                {
                    buf = mass[i][j];
                    mass[i][j] = mass[i][j + 1];
                    mass[i][j + 1] = buf;
                }
            }
            --length;
        }
    }
}

void sort(char** mass, int size)
{
    char buf = '\0';

    for (int i = 0; i < size; i++)
    {
        int length = size;
        while (length > 0)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (mass[i][j] > mass[i][j + 1])
                {
                    buf = mass[i][j];
                    mass[i][j] = mass[i][j + 1];
                    mass[i][j + 1] = buf;
                }
            }
            --length;
        }
    }
}

void minmax(int** mass, int size)
{
    int min = mass[0][0];
    int max = mass[0][0];

    for (int i = 0; i < size; i++)
    {
        if (mass[i][i]>max)
        {
            max = mass[i][i];
        }
        if (mass[i][i] < min)
        {
            min = mass[i][i];
        }
    }
    cout << "Main diagonal MIN = " << min << ", MAX = " << max << endl;
}

void minmax(double** mass, int size)
{
    double min = mass[0][0];
    double max = mass[0][0];

    for (int i = 0; i < size; i++)
    {
        if (mass[i][i] > max)
        {
            max = mass[i][i];
        }
        if (mass[i][i] < min)
        {
            min = mass[i][i];
        }
    }
    cout << "Main diagonal MIN=" << min << ", MAX=" << max << endl;
}

void minmax(char** mass, int size)
{
    char min = mass[0][0];
    char max = mass[0][0];

    for (int i = 0; i < size; i++)
    {
        if (mass[i][i] > max)
        {
            max = mass[i][i];
        }
        if (mass[i][i] < min)
        {
            min = mass[i][i];
        }
    }
    cout << "Main diagonal MIN=" << min << ", MAX=" << max << endl;
}

void display(int** mass, int size)
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

void display(double** mass, int size)
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

void display(char** mass, int size)
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

void fill(int** mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mass[i][j] = rand() % 90 + 10;
        }
    }
}

void fill(double** mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mass[i][j] = (rand() % 90 + 12) / 1.1111;
        }
    }
}

void fill(char** mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mass[i][j] = (rand() % 60 + 60);
        }
    }
}

int main()
{
    int size = 10;
    
    cout << "INT:" << endl;
    int** mass = initialize(size);
    fill(mass, size);
    display(mass, size);
    minmax(mass, size);
    sort(mass, size);
    cout << "Sorted INT array:" << endl;
    display(mass, size);

    cout << "DOUBLE:" << endl;
    double** dmass = initialize((double)size);
    fill(dmass, size);
    display(dmass, size);
    minmax(dmass, size);
    sort(dmass, size);
    cout << "Sorted DOUBLE array:" << endl;
    display(dmass, size);

    cout << "CHAR:" << endl;
    char** cmass = initialize((long)size);
    fill(cmass, size);
    display(cmass, size);
    minmax(cmass, size);
    sort(cmass, size);
    cout << "Sorted CHAR array:" << endl;
    display(cmass, size);

    return 0;
}