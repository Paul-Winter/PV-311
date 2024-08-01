//ЗАДАНИЕ 1
//Дан текстовый файл. Необходимо создать новый файл,
//убрав из него все неприемлемые слова.
//Список неприемлемых слов находится в другом файле.

#include <iostream>
using namespace std;

int string_lenght(char* current_string)             //функция возвращает длину строки из char*-массива
{
    int counter = 0;
    char symbol = '\0';
    while (current_string[counter] != '\0')
    {
        ++counter;
    }

    return counter;
}

bool string_compare(char* string1, char* string2)   //функция возвращает истину, если строки из char-массивов равны
{
    bool equal = false;
    int counter = 0;
    int str_len = 0;

    if (string_lenght(string1) == string_lenght(string2))
    {
        str_len = string_lenght(string1);

        for (int i = 0; i < str_len; i++)
        {
            if (string1[i] == string2[i])
            {
                ++counter;
            }
        }
        if (str_len == counter)
        {
            bool equal = true;
            return equal;
        }
    }

    return equal;
}

int main()
{
    const char* source_path = "C:\\Intel\\source.txt";
    const char* result_path = "C:\\Intel\\result.txt";
    const char* filtr_path3 = "C:\\Intel\\filtr.txt";
    FILE* source;
    FILE* result;
    FILE* filtr;
    bool end_string = false;
    bool finded = false;
    int filtr_size = 0;
    int result_size = 0;
    int str_len = 0;
    int symbol_counter = 0;
    int delete_counter = 0;
    char current_symbol = '\0';
    int string_size = 255;
    char* current_string = new char[string_size];
    char* current_word = new char[string_size];

    //считаем количество фильтр-слов из файла
    int counter = 0;
    if (fopen_s(&filtr, filtr_path3, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(filtr))
        {
            fgets(current_string, string_size, filtr);
            ++counter;
        }
    }
    fclose(filtr);
    filtr_size = counter;

    //создаём массив для фильтр-слов
    char** file_filtr = new char* [filtr_size];
    for (int i = 0; i < filtr_size; i++)
    {
        file_filtr[i] = new char[string_size];
    }

    //считывание слов из фильтр-файла в фильтр-массив
    counter = 0;
    if (fopen_s(&filtr, filtr_path3, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(filtr))
        {
            fgets(current_string, string_size, filtr);
            end_string = false;
            for (int j = 0; j < string_size; j++)
            {
                if (current_string[j] == '\n')
                {
                    end_string = true;
                }

                if (!end_string)
                {
                    file_filtr[counter][j] = current_string[j];
                }
                else
                {
                    file_filtr[counter][j] = '\0';
                }
            }
            ++counter;
        }
    }
    fclose(filtr);

    counter = 0;
    if (fopen_s(&result, result_path, "w") != NULL)     //открываем на запись выходной файл
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        if (fopen_s(&source, source_path, "r") != NULL) //начинаем читать исходный файл
        {
            cout << "Can't open file to read!" << endl;
        }
        else
        {
            while (!feof(source))
            {
                current_symbol = fgetc(source);         //посимвольно 

                if (current_symbol != ' ' && current_symbol != '\n' && current_symbol != '\t' && (int)current_symbol != -1) //проверяем не является ли полученный символ разделеитем слов
                {
                    current_string[symbol_counter] = current_symbol;    //если это не разделитель, то посимвольно собираем слово из файла до разделителя
                    ++symbol_counter;
                }
                else
                {
                    current_string[symbol_counter] = '\0';
                    finded = false;

                    for (int i = 0; i < filtr_size; i++)        //в цикле сравниваем текущее слово из файла, с фильтр-словами
                    {
                        if (string_compare(current_string, file_filtr[i]))
                        {
                            finded = true;
                            ++delete_counter;
                        }
                    }

                    if (!finded)                        //если слова нет в списке фильтра, то выводим его в новый файл
                    {
                        fputs(current_string, result);
                    }
                    if ((int)current_symbol != -1)      //вставляем полученный разделитель, пока это не символ конца файла
                    {
                        fputc(current_symbol, result);
                    }
                    
                    symbol_counter = 0;
                }
            }
        }
        fclose(source);
    }
    fclose(result);

    cout << "Done.\nFinded and deleted " << delete_counter << " words." << endl;

    return 0;
}