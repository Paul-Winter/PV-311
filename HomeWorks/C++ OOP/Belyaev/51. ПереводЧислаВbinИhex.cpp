//ЗАДАНИЕ 1.
//ДОПИШИТЕ СВОЮ ФУНКЦИЮ ПО ПЕРЕВОДУ В 16РИЧНОЕ ЗНАЧЕНИЕ :

#include <iostream>
using namespace std;

namespace my
{
    typedef unsigned char byte;
}

union myUnion
{
    unsigned int number;
    my::byte u[4];
};

char num2symb(int number)
{
    char symbol = '\0';
    
    switch (number)
    {
    case 0:
        symbol = '0';
        break;
    case 1:
        symbol = '1';
        break;
    case 2:
        symbol = '2';
        break;
    case 3:
        symbol = '3';
        break;
    case 4:
        symbol = '4';
        break;
    case 5:
        symbol = '5';
        break;
    case 6:
        symbol = '6';
        break;
    case 7:
        symbol = '7';
        break;
    case 8:
        symbol = '8';
        break;
    case 9:
        symbol = '9';
        break;
    case 10:
        symbol = 'A';
        break;
    case 11:
        symbol = 'B';
        break;
    case 12:
        symbol = 'C';
        break;
    case 13:
        symbol = 'D';
        break;
    case 14:
        symbol = 'E';
        break;
    case 15:
        symbol = 'F';
        break;
    }
   
    return symbol;
}

void dec2hex(myUnion N)
{
    int counter = 0;
    int symb1 = 0;
    int symb2 = 0;
    int buf = 0;
    char* hex = new char[8];
    
    cout << "hex: ";

    for (int i = 3; i >= 0; --i)
    {
        symb1 = (int)N.u[i];
        symb1 /= 16;
        buf = symb1 * 16;
        symb2 = (int)N.u[i] - buf;
        hex[counter] = num2symb(symb1);
        hex[counter + 1] = num2symb(symb2);
        ++counter;
        ++counter;
    }
    counter = 0;
    for (int i = 0; i < 8; i++)
    {
        if (hex[i] != '0')
        {
            ++counter;
        }
        if (counter != 0)
        {
            cout << hex[i];
        }
    }
}

bool* dec2bin(unsigned int num)
{
    bool* bin = new bool[sizeof(num) * 8];
    unsigned int buf = 0;

    for (int i = (sizeof(num) * 8); i >= 0; --i)
    {
        buf = num;
        num /= 2;
        bin[i] = buf % 2;
    }

    return bin;
}

void display(bool* mass, int size)
{
    int counter = 0;
    cout << "bin: ";

    for (int i = 0; i <= size; i++)
    {
        if (mass[i] == 1)
        {
            ++counter;
        }
        if (counter != 0)
        {
            cout << mass[i];
        }
    }
    cout << endl;
}

int main()
{
    myUnion one;

    cout << "Enter decimal number: ";
    cin >> one.number;

    cout << "bytes: " << (int)one.u[3] << " " << (int)one.u[2] << " " << (int)one.u[1] << " " << (int)one.u[0] << endl;
    display(dec2bin(one.number), (sizeof(one.number) * 8));
    dec2hex(one);
    
    return 0;
}
