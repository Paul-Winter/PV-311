//ЗАДАНИЕ 2
//Дан текстовый файл.
//Найти длину самой длинной строки.

#include <iostream>
using namespace std;

int main()
{
    const char* path = "C:\\Intel\\111.txt";
    FILE* in;
    int counter = 0;
    int max = 0;
    int size = 255;
    char* mass = new char[size];


    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            fgets(mass, size, in);
            while (mass[counter] != '\n')       //в каждой считанной сторке файла,
            {
                ++counter;                      //подсчитываем число символов
            }
            if (counter > max)                  //и сравниваем с текущим максимумом
            {
                max = counter;                  //если это число больше, то запоминаем новый
            }
            counter = 0;
        }
        cout << "Max lenght of string in this file: " << max << endl;
    }
    
    return 0;
}