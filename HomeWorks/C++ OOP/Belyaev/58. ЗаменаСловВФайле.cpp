//ЗАДАНИЕ 4
//Дан текстовый файл. Найти и заменить в нем заданное слово.
//Что искать и на что заменять определяется пользователем.

#include <iostream>
using namespace std;

int count_symbols(const char* path)                     //функция подсчёта символов в файле
{
    int counter = 0;
    FILE* in;

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            fgetc(in);
            ++counter;
        }
    }
    fclose(in);
    
    return counter;
}

char* load_file(char* mass, const char* path)           //функция посимвольной загрузки в динамический массив
{
    int counter = 0;
    FILE* in;

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            mass[counter] = fgetc(in);
            ++counter;
        }
    }
    fclose(in);

    return mass;
}

int find_string(char* mass, int size, char* string_to_find, int counter_find)
{                                                       //функция поиска искомой строки (возвращает её начальную позицию)
    int position = 0;
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (mass[i] == string_to_find[counter])
        {
            if (counter + 1 == counter_find)
            {
                position = i - counter;
            }
            ++counter;
        }
        else
        {
            counter = 0;
        }
    }

    return position;
}

int main()
{
    const char* path = "C:\\Intel\\111.txt";            //путь к файлу
    FILE* out;
    int counter_find = 0;                               //счётчик количества символов в искомой строке
    int counter_replace = 0;                            //счётчик количества символов в заменяемой строке
    int begin_position = 0;                             //позиция начала замены
    int size = 255;
    int file_size = 0;
    char* string_to_find = new char[size];              //искомая строка
    char* string_to_replace = new char[size];           //строка на замену
       
    cout << "Enter string to find: ";
    cin >> string_to_find;                              //запрос искомой строки
    while (string_to_find[counter_find] != '\0')
    {
        ++counter_find;
    }
    cout << "Enter string to replace: ";
    cin >> string_to_replace;                           //запрос строки на замену
    while (string_to_replace[counter_replace] != '\0')
    {
        ++counter_replace;
    }

    file_size = count_symbols(path);                    //получаем количество символов в файле,
    char* file_as_string = new char[file_size];         //и создаём массив символов этого размера,
    file_as_string = load_file(file_as_string, path);   //в который посимвольно загружаем данные из файла
    
                                                        //определяем позицию начала замены
    begin_position = find_string(file_as_string, file_size, string_to_find, counter_find);
    if (begin_position != 0)
    {
        if (fopen_s(&out, path, "w") != NULL)           //открываем тот же файл на запись
        {
            cout << "Can't open file to read!" << endl;
        }
        else
        {
            for (int i = 0; i < begin_position; i++)    
            {
                putc(file_as_string[i], out);           //сначала в новый файл записываем посимвольно то, что идёт до искомой строки
            }
            for (int i = 0; i < counter_replace; i++)
            {
                putc(string_to_replace[i], out);        //потом, записываем строку на замену
            }
            for (int i = begin_position + counter_find; i < file_size-1; i++)
            {
                putc(file_as_string[i],out);            //а теперь записываем то, что оставалось после искомой строки
            }
        }
    }
    else
    {
        cout << "This string (" << string_to_find << ") don't finded!" << endl;
    }

    return 0;
}