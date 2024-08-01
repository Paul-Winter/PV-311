//ЗАДАНИЕ 1
//Дополните свою библиотеку функций реализациями нижеследующих функций:
//■ int mystrcmp(const char* str1, const char* str2); —
//функция сравнивает две строки, и, если строки равны
//возвращает 0, если первая строка больше второй, то возвращает 1, иначе –1.
//■ int StringToNumber(char* str); — функция конвертирует строку в число и возвращает это число.
//■ char* NumberToString(int number); — функция конвертирует число в строку и 
//возвращает указатель на эту строку.
//■ char* Uppercase(char* str1); — функция преобразует строку в верхний регистр.
//■ char* Lowercase(char* str1); — функция преобразует строку в нижний регистр.
//■ char* mystrrev(char* str); — функция реверсирует строку и возвращает указатель на новую строку.

#include <iostream>
#include <string>
using namespace std;

int mystrcmp(const char* str1, const char* str2)
{
    int counterFirst = 0;
    int counterSecond = 0;
    while (str1[counterFirst] != '\0')
    {
        ++counterFirst;
    }
    while (str2[counterSecond] != '\0')
    {
        ++counterSecond;
    }
    if (counterFirst == counterSecond)
    {
        return 0;
    }
    else if (counterFirst > counterSecond)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int StringToNumber(char* str)
{
    int counter = 0;
    int number = 0;
    while (str[counter] != '\0')
    {
        ++counter;
    }
    
    int i = counter-1;
    int r = 1;
    while (i > -1)
    {
        switch (r)
        {
        case 1:
        {
            number += (int)str[i] - 48;
            break;
        }
        case 2:
        {
            number += ((int)str[i] - 48) * 10;
            break;
        }
        case 3:
        {
            number += ((int)str[i] - 48) * 100;
            break;
        }
        case 4:
        {
            number += ((int)str[i] - 48) * 1000;
            break;
        }
        case 5:
        {
            number += ((int)str[i] - 48) * 10000;
            break;
        }
        case 6:
        {
            number += ((int)str[i] - 48) * 100000;
            break;
        }
        case 7:
        {
            number += ((int)str[i] - 48) * 1000000;
            break;
        }
        case 8:
        {
            number += ((int)str[i] - 48) * 10000000;
            break;
        }
        default:
        {
            number += ((int)str[i] - 48) * 100000000;
        }
        }
        --i;
        ++r;
    }
    return number;
}

char* NumberToString(int number)
{
    int size = 10;
    int counter = 10;
    char* newString = new char[size];
    int buf = 0;
    char buffer = '\0';

    if (number < 2147483648)
    {
        for (int i = 0; i < 10; ++i)            //с младшего разряда получаем по одной цифре,
        {                                       //переводим в символ и записываем в строковый массив
            buf = number;
            number %= 10;
            newString[i] = char(number + 48);
            number = (buf - number) / 10;
        }
        
        for (int j = 9; j >= 0; --j)            //считаем сколько определилось разрядов
        {
            if ((int)newString[j] == 48)
            {
                --counter;
            } 
            else
            {
                break;
            }
        }

        for (int i = 0, j = counter - 1; i <= j; ++i, --j)      //переворачиваем массив
        {                                                       //для правильного расположения символов
            buffer = newString[i];
            newString[i] = newString[j];
            newString[j] = buffer;
        }
        newString[counter] = '\0';
        return newString;
    }
    else
    {
        cout << "Wrong parametr!" << endl;
        return nullptr;
    }
}

char* Uppercase(char* str1)
{
    int counter = 0;
    while (str1[counter] != '\0')
    {
        if ((int)str1[counter] > 96 && (int)str1[counter] < 123 )
        {
            str1[counter] = char((int)str1[counter] - 32);
        }
        ++counter;
    }

    return str1;
}

char* Lowercase(char* str1)
{
    int counter = 0;
    while (str1[counter] != '\0')
    {
        if ((int)str1[counter] > 64 && (int)str1[counter] < 91)
        {
            str1[counter] = char((int)str1[counter] + 32);
        }
        ++counter;
    }

    return str1;
}

char* mystrrev(char* str)
{
    int counter = 0;
    char buffer = '\0';

    while (str[counter] != '\0')
    {
        ++counter;
    }
    for (int i = 0, j = counter - 1; i <= j; ++i, --j)
    {
        buffer = str[i];
        str[i] = str[j];
        str[j] = buffer;
    }
    str[counter] = '\0';
    return str;
}

int main()
{
    int k = 0;
    int number = 0;
    int size = 255;
    
    char* newString1 = new char[size];
    cout << "Enter first string: ";
    cin.getline(newString1, size);
    char* newString2 = new char[size];
    cout << "Enter second string: ";
    cin.getline(newString2, size);
    k = mystrcmp(newString1, newString2);
    if (k == 0)
    {
        cout << "This strings is equal!" << endl;
    }
    else if (k > 0)
    {
        cout << "First string more then second!" << endl;
    }
    else
    {
        cout << "Secong string more then first!" << endl;
    }
    
    char* newString3 = new char[size];
    cout << "Enter string of digits (from 0 to 9, but maximum 9 digits!): ";
    cin.getline(newString3, size);
    cout << newString3 << "+1=" << StringToNumber(newString3) + 1 << endl;
    
    cout << "Enter number (up to 2 147 483 647): ";
    cin >> number;
    cout << NumberToString(number) << endl;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка потока ввода (чтобы сработал следующий getline)

    char* newString4 = new char[size];
    cout << "Enter string with lowercase letters: ";
    cin.getline(newString4, size);
    cout << "New string: " << Uppercase(newString4) << endl;

    char* newString5 = new char[size];
    cout << "Enter string with uppercase letters: ";
    cin.getline(newString5, size);
    cout << "New string: " << Lowercase(newString5) << endl;

    char* newString6 = new char[size];
    cout << "Enter string to reverse: ";
    cin.getline(newString6, size);
    cout << "New string: " << mystrrev(newString6) << endl;

    return 0;
}