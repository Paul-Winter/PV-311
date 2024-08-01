//ЗАДАНИЕ 1
//Дан текстовый файл. Удалить из него последнюю строку.
//Результат записать в другой файл.

#include <iostream>
using namespace std;

int main()
{
    const char* path = "C:\\Intel\\111.txt";
    const char* path2 = "C:\\Intel\\222.txt";
    FILE* in;
    FILE* out;
    int counter = 0;
    int counter2 = 0;
    int size = 255;
    char* mass = new char[size];


    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))               //открываем цикл для подсчёта количества строк в файле
        {
            fgets(mass, size,in);
            ++counter;
        }
        fseek(in, 0, SEEK_SET);         //возвращаем указатель в начало файла
        if (fopen_s(&out, path2, "w") != NULL)
        {
            cout << "Can't open file to write!" << endl;
        }
        else
        {
            while (counter2 < counter - 1)
            {
                fgets(mass, size, in);  //снова читаем строки из файла и записываем их в новый, 
                fputs(mass, out);       //пока их количество не станет на 1 меньше чем в исходном файле
                ++counter2;             
            }
        }
    }

    return 0;
}