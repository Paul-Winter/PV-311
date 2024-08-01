//ЗАДАНИЕ 1
//Написать калькулятор, используя указатели на функцию в формате std::function

#include <functional>
#include <iostream>
using namespace std;

int addition(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

int main()
{
    function<int(int, int)> ptr_add = addition;     //объявляем указатель на функцию сложения
    function<int(int, int)> ptr_sub = subtract;     //объявляем указатель на функцию вычитания
    function<int(int, int)> ptr_mlt = multiply;     //объявляем указатель на функцию умножения 
    function<int(int, int)> ptr_div = division;     //объявляем указатель на функцию деления

    int x = 0;
    int y = 0;
    int operation = 4;

    cout << "******* Calculator *******" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Division" << endl;
    cout << "Your choise (1-4): ";
    cin >> operation;
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;

    switch (operation)
    {
        case 1:
        {
            cout << "Result of addition is: " << ptr_add(x, y) << endl;      //вывод результата обращения через указатель к функции сложения
            break;
        }
        case 2:
        {
            cout << "Result of subtract is: " << ptr_sub(x, y) << endl;      //вывод результата обращения через указатель к функции вычитания
            break;
        }
        case 3:
        {
            cout << "Result of multiply is: " << ptr_mlt(x, y) << endl;      //вывод результата обращения через указатель к функции умножения 
            break;
        }
        default:
        {
            cout << "Result of division is: " << ptr_div(x, y) << endl;      //вывод результата обращения через указатель к функции деления
        }
    }

    return 0;
}