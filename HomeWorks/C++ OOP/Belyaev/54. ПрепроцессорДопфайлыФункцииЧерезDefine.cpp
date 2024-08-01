*****************************************************************
файл prog.cpp
*****************************************************************
//ЗАДАНИЕ 1
//Создать проект в котором:
//1. Cоздать три файла : function.h, function.cpp, prog.cpp.
//2. В файле function.cpp необходимо написать следующие функции для работы с массивом данных:
//a) функцию для заполнения массива случайными значениями;
//b) функцию для вывода значений массива на консоль;
//c) функцию для поиска минимального элемента;
//d)функцию для поиска максимального элемента;
//e) функцию для сортировки;
//f) функцию для редактирования значения массива.
//Данные функции необходимо написать для работы с массивом целых, действительных и символьных
//значений. (Для каждого типа написать отдельную функцию).
//3. В файле function.h нужно :
//a) описать прототипы всех функций;
//b) сделать проверку определена ли константа, указывающая на тип данных(#ifdef INTEGER);
//c) создать обобщающие имена функции, которым будет определена функция соответствующего типа в
//зависимости от константы, указанной в файле prog.cpp(# define show ShowInt).
//4. В файле prog.cpp нужно :
//a) в функции main вызвать все функции через переозначеные(обобщенные) имена из файла function.h (show());
//b) определить константу, которая указывает какой тип данных будет использоваться. Например INTEGER —
//целые данные, CHAR — символьные DOUBLE — настоящие(#define INTEGER).
//Имя функциям нужно давать так, чтобы они отвечали своей сути. Например функция для вывода значений 
//массива целых чисел на консоль — ShowArrayInt(). А, когда переопределяем функцию с помощью #define то
//нужно давать общее имя. Например #define ShowArray ShowArrayInt.

#include <iostream>
#include <functional>
#include "function.h"
using namespace std;

int main()
{
    int size = 10;
    int* mass = new int[size];
    double* dmass = new double[size];
    char* cmass = new char[size];
    
#define INTEGER
    
    std::function<int*(int*, int)> ptr_i1 = random_i;
    ptr_i1(mass, size);
    std::function<void (int*, int)> ptr_i2 = show_i;
    ptr_i2(mass, size);
    std::function<void(int*, int)> ptr_i3 = min_i;
    ptr_i3(mass, size);
    std::function<void(int*, int)> ptr_i4 = max_i;
    ptr_i4(mass, size);
    std::function<int* (int*, int)> ptr_i5 = sort_i;
    ptr_i5(mass, size);
    std::function<void(int*, int)> ptr_i6 = show_i;
    ptr_i6(mass, size);
    std::function<int* (int*, int)> ptr_i7 = edit_i;
    ptr_i7(mass, size);
    std::function<void(int*, int)> ptr_i8 = show_i;
    ptr_i8(mass, size);
    
#undef INTEGER

#define DOUBLE

    std::function<double* (double*, int)> ptr_d1 = random_d;
    ptr_d1(dmass, size);
    std::function<void(double*, int)> ptr_d2 = show_d;
    ptr_d2(dmass, size);
    std::function<void(double*, int)> ptr_d3 = min_d;
    ptr_d3(dmass, size);
    std::function<void(double*, int)> ptr_d4 = max_d;
    ptr_d4(dmass, size);
    std::function<double* (double*, int)> ptr_d5 = sort_d;
    ptr_d5(dmass, size);
    std::function<void(double*, int)> ptr_d6 = show_d;
    ptr_d6(dmass, size);
    std::function<double* (double*, int)> ptr_d7 = edit_d;
    ptr_d7(dmass, size);
    std::function<void(double*, int)> ptr_d8 = show_d;
    ptr_d8(dmass, size);

#undef DOUBLE

#define CHAR
    
    std::function<char* (char*, int)> ptr_c1 = random_c;
    ptr_c1(cmass, size);
    std::function<void(char*, int)> ptr_c2 = show_c;
    ptr_c2(cmass, size);
    std::function<void(char*, int)> ptr_c3 = min_c;
    ptr_c3(cmass, size);
    std::function<void(char*, int)> ptr_c4 = max_c;
    ptr_c4(cmass, size);
    std::function<char* (char*, int)> ptr_c5 = sort_c;
    ptr_c5(cmass, size);
    std::function<void(char*, int)> ptr_c6 = show_c;
    ptr_c6(cmass, size);
    std::function<char* (char*, int)> ptr_c7 = edit_c;
    ptr_c7(cmass, size);
    std::function<void(char*, int)> ptr_c8 = show_c;
    ptr_c8(cmass, size);

#undef CHAR

    return 0;
}

*****************************************************************
файл function.h
*****************************************************************
#pragma once

#ifndef INTEGER

int* randomIntArray(int* mass, int size);
void showIntArray(int* mass, int size);
void minIntArray(int* mass, int size);
void maxIntArray(int* mass, int size);
int* sortIntArray(int* mass, int size);
int* editIntArray(int* mass, int size);

#define random_i randomIntArray;
#define show_i showIntArray;
#define min_i minIntArray;
#define max_i maxIntArray;
#define sort_i sortIntArray;
#define edit_i editIntArray;

#endif

#ifndef DOUBLE

double* randomDoubleArray(double* dmass, int size);
void showDoubleArray(double* mass, int size);
void minDoubleArray(double* mass, int size);
void maxDoubleArray(double* mass, int size);
double* sortDoubleArray(double* mass, int size);
double* editDoubleArray(double* mass, int size);

#define random_d randomDoubleArray;
#define show_d showDoubleArray;
#define min_d minDoubleArray;
#define max_d maxDoubleArray;
#define sort_d sortDoubleArray;
#define edit_d editDoubleArray;

#endif

#ifndef CHAR

char* randomCharArray(char* mass, int size);
void showCharArray(char* mass, int size);
void minCharArray(char* mass, int size);
void maxCharArray(char* mass, int size);
char* sortCharArray(char* mass, int size);
char* editCharArray(char* mass, int size);

#define random_c randomCharArray;
#define show_c showCharArray;
#define min_c minCharArray;
#define max_c maxCharArray;
#define sort_c sortCharArray;
#define edit_c editCharArray;

#endif

*****************************************************************
файл function.cpp
*****************************************************************
#include <iostream>
#include "function.h"
using namespace std;

int* randomIntArray(int* mass, int size)
{
    cout << "Filling int array random numbers..." << endl;
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 90;
    }
    return mass;
}

void showIntArray(int* mass, int size)
{
    cout << "Int array: ";
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void minIntArray(int* mass, int size)
{
    int minimum = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (mass[i] < minimum)
        {
            minimum = mass[i];
        }
    }
    cout << "Min element of int array = " << minimum << endl;
}

void maxIntArray(int* mass, int size)
{
    int maximum = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (mass[i] > maximum)
        {
            maximum = mass[i];
        }
    }
    cout << "Max element of int array = " << maximum << endl;
}

int* sortIntArray(int* mass, int size)
{
    cout << "Sorting int array..." << endl;
    int buf = 0;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (mass[j] > mass[j + 1])
            {
                buf = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = buf;
            }
        }
    }
    return mass;
}

int* editIntArray(int* mass, int size)
{
    int ind = 0;
    cout << "Enter index of element to edition (0-" << size - 1 << "): ";
    cin >> ind;
    cout << "Enter new int number: ";
    cin >> mass[ind];
    return mass;
}

double* randomDoubleArray(double* mass, int size)
{
    cout << "\nFilling double array random numbers..." << endl;
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        mass[i] = (rand() % 90 + 12) / 1.1111;
    }
    return mass;
}

void showDoubleArray(double* mass, int size)
{
    cout << "Double array: ";
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void minDoubleArray(double* mass, int size)
{
    double minimum = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (mass[i] < minimum)
        {
            minimum = mass[i];
        }
    }
    cout << "Min element of double array = " << minimum << endl;
}

void maxDoubleArray(double* mass, int size)
{
    double maximum = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (mass[i] > maximum)
        {
            maximum = mass[i];
        }
    }
    cout << "Max element of double array = " << maximum << endl;
}

double* sortDoubleArray(double* mass, int size)
{
    cout << "Sorting double array..." << endl;
    double buf = 0;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (mass[j] > mass[j + 1])
            {
                buf = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = buf;
            }
        }
    }
    return mass;
}

double* editDoubleArray(double* mass, int size)
{
    int ind = 0;
    cout << "Enter index of element to edition (0-" << size - 1 << "): ";
    cin >> ind;
    cout << "Enter new double number: ";
    cin >> mass[ind];
    return mass;
}

char* randomCharArray(char* mass, int size)
{
    cout << "\nFilling char array random symbols..." << endl;
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 90 + 33;
    }
    return mass;
}

void showCharArray(char* mass, int size)
{
    cout << "Char array: ";
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void minCharArray(char* mass, int size)
{
    char minimum = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (mass[i] < minimum)
        {
            minimum = mass[i];
        }
    }
    cout << "Min element of char array = " << minimum << endl;
}

void maxCharArray(char* mass, int size)
{
    char maximum = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (mass[i] > maximum)
        {
            maximum = mass[i];
        }
    }
    cout << "Max element of char array = " << maximum << endl;
}

char* sortCharArray(char* mass, int size)
{
    cout << "Sorting char array..." << endl;
    char buf = 0;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (mass[j] > mass[j + 1])
            {
                buf = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = buf;
            }
        }
    }
    return mass;
}

char* editCharArray(char* mass, int size)
{
    int ind = 0;
    cout << "Enter index of element to edition (0-" << size - 1 << "): ";
    cin >> ind;
    cout << "Enter new char symbol: ";
    cin >> mass[ind];
    return mass;
}