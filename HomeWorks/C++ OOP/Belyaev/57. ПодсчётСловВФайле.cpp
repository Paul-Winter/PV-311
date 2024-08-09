//ЗАДАНИЕ 3
//Дан текстовый файл. Посчитать сколько раз
//в нем встречается заданное пользователем слово.

#include <iostream>
using namespace std;

int main()
{
    const char* path = "C:\\Intel\\111.txt";
    FILE* in;
    int counter = 0;
    int str_counter = 0;
    int coincidence = 0;
    int size = 255;
    char* str = new char[size];
    int symbol;
    cout << "Enter string to find: ";
    cin >> str;
    while (str[counter] != '\0')
    {
        ++counter;
        ++str_counter;
    }
    counter = 0;

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            symbol = fgetc(in);
            if (str[counter] == symbol)
            {
                ++counter;
                if (counter == str_counter)
                {
                    ++coincidence;
                    counter = 0;
                }
            }
            else
            {
                counter = 0;
            }
        }
        cout << "Finded " << coincidence << " coincidences." << endl;
    }

    return 0;
}