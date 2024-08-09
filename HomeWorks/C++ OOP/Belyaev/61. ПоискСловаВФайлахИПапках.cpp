//ЗАДАНИЕ 1.
//Пользователь вводит путь к папке и искомое слово.
//Программа ищет слово в папке и её подпапках.
//После работы программы формируется отчет с информацией
//о том, где было слово найдено, количество совпадений.
//Добавьте возможность замены или удаления искомого
//слова из файлов.

#include <iostream>
#include <filesystem>
using namespace std;

int findString(std::filesystem::directory_entry dirEntry, char* file_string, int file_size, string fided_string, string string_to_replace, int mode)
{
    int counter = 0;
    int position = 0;
    int m = 0;
    int k = 0;
    int str_comp = 0;
    int str_size = fided_string.length();
    int rep_size = string_to_replace.length();
    
    switch (mode)
    {
    case 1:     //режим обычного поиска, возвращем количество найденных совпадений
        
        for (int i = 0; i < file_size; i++)
        {
            if (file_string[i] == fided_string[m])
            {
                ++str_comp;
                if (str_comp == str_size)
                {
                    m = 0;
                    str_comp = 0;
                    ++counter;
                }
                ++m;
            }
            else
            {
                m = 0;
            }
        }
        
        break;
    case 2:     //режим поиска и замены, возвращаем количество замен

        for (int i = 0; i < file_size; i++)     //сначала ищем искомое слово в массиве символов
        {
            if (file_string[i] == fided_string[m])
            {
                ++str_comp;
                if (str_comp == str_size)
                {
                    m = 0;
                    str_comp = 0;
                    ++counter;
                }
                ++m;
            }
            else
            {
                m = 0;
            }
        }

        if (counter > 0)        //если совпадения найдены, открываем файл на запись
        {
            FILE* out;

            if (fopen_s(&out, dirEntry.path().string().c_str(), "w") != NULL)
            {
                cout << "Can't open file to write!" << endl;
            }
            else
            {
                while ((int)file_string[k] != -1)   //перебираем массив пока не дойдём до признака конца файла
                {
                    position = 0;
                    if (file_string[k] == fided_string[m])
                    {
                        ++str_comp;
                        if (str_comp == str_size)   //если нашли искомое слово,
                        {                           //перемещаем позицию в потоке на начало этого слова
                            m = 0;
                            str_comp = 0;
                            fseek(out, (-str_size) + 1, SEEK_CUR);
                            position = k;
                        }
                        ++m;
                    }
                    else
                    {
                        m = 0;
                    }
                    if (!position)      //если совпадений нет, то посимвольно выводим массив в файл
                    {
                        fputc(file_string[k], out);
                    }
                    else                //если слово нашлось, то на его месте вставляем слово на замену
                    {
                        for (int i = 0; i < rep_size; i++)
                        {
                            fputc(string_to_replace[i], out);
                        }
                    }
                    ++k;
                }
            }
            fclose(out);
        }
        break;
    case 3:     //режим удаления, возвращаем количество удалений

        for (int i = 0; i < file_size; i++)     //сначала ищем искомое слово в массиве символов
        {
            if (file_string[i] == fided_string[m])
            {
                ++str_comp;
                if (str_comp == str_size)
                {
                    m = 0;
                    str_comp = 0;
                    ++counter;
                }
                ++m;
            }
            else
            {
                m = 0;
            }
        }
        
        if (counter > 0)        //если совпадения нашлись, то открываем файл на запись
        {
            FILE* out;

            if (fopen_s(&out, dirEntry.path().string().c_str(), "w") != NULL)
            {
                cout << "Can't open file to write!" << endl;
            }
            else
            {
                 while ((int)file_string[k] != -1)  //посимвольно перебираем массив до признака конца файла
                {
                    position = 0;
                    if (file_string[k] == fided_string[m])
                    {
                        ++str_comp;
                        if (str_comp == str_size)   //если нашли искомое слово,
                        {                           //то смещаем указатель в потоке на начало слова
                            m = 0;
                            str_comp = 0;
                            fseek(out, (- str_size) + 1, SEEK_CUR);
                            position = k;
                        }
                        ++m;
                    }
                    else
                    {
                        m = 0;
                    }
                    if (!position)      //если совпадения нет, посимвольно выводим массив в файл
                    {
                        fputc(file_string[k], out);
                    }
                    ++k;
                }
            }
            fclose(out);
        }
        break;
    default:
        break;
    }
    return counter;
}

int main()
{
    string cur_path = "C:\\Intel\\";
    cout << "Enter path (for example C:\\Intel\\):\n>";
    cin >> cur_path;
    std::filesystem::current_path(cur_path);
    int count = 0;
    FILE* in;
    int file_size = 0;
    char symbol = '\0';
    string fided_string = "ERROR";
    cout << "Enter string to find:\n>";
    cin >> fided_string;
    int coincidences = 0;
    int mode = 1;
    cout << "Choose mode:\n1 - find number of coincidences\n2 - find and replace string\n3 - find and delete string\n>";
    cin >> mode;
    string string_to_replace = "QUESTION";
    if (mode == 2)
    {
        cout << "Enter string to replace\n>";
        cin >> string_to_replace;
    }
    int k = 0;
    string str = "\0";

    cout << "REPORT:" << endl;
    switch (mode)
    {
    case 1:
        cout << "MODE 1 - SIMPLE FINDING" << endl;
        str = " finded ";
        break;
    case 2:
        cout << "MODE 2 - FIND AND REPLACE" << endl;
        str = " replaced ";
        break;
    case 3:
        cout << "MODE 3 - FIND AND DELETE" << endl;
        str = " deleted ";
        break;
    default:
        break;
    }

    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
    for (const auto& dirEntry : recursive_directory_iterator(cur_path))
    {
        if (!dirEntry.is_directory())
        {
            if (string(".txt") == dirEntry.path().filename().extension().string())
            {
                file_size = dirEntry.file_size();
                
                char* file_str = new char[file_size];
                k = 0;
                if (fopen_s(&in, dirEntry.path().string().c_str(), "r") != NULL)
                {
                    cout << "Can't open file to read!" << endl;
                }
                else
                {
                    while (!feof(in))
                    {
                        file_str[k] = fgetc(in);    //посимвольно заолняем буферный массв из текущего файла
                        ++k;
                    }
                }
                fclose(in);
                
                //в зависимости от переданного режима, функция выполняет нужное действие и взвращает число вхождений, замен, удалений
                coincidences = findString(dirEntry, file_str, file_size, fided_string, string_to_replace, mode);
                
                if (coincidences > 0)
                {
                    ++count;
                    cout << "In " << dirEntry.path().string().c_str() << str << coincidences << " coincidences." << endl;
                }
            }
        }
    }
    
    if (count == 0 )
    {
        cout << "String not found!";
    }

    return 0;
}