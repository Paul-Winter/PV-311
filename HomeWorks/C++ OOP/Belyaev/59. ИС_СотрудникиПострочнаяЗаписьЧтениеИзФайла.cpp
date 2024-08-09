//ЗАДАНИЕ 1
//Напишите информационную систему «Сотрудники». Программа должна обеспечивать ввод данных,
//редактирование данных сотрудника, удаление сотрудника, поиск сотрудника по фамилии,
//вывод информации обо всех сотрудниках, указанного возраста, или фамилия которых,
//начинается на указанную букву. Организуйте возможность сохранения найденной информации в файл.
//Также весь список сотрудников сохраняется в файл(при выходе из программы — автоматически,
//в процессе исполнения программы — по команде пользователя).При старте программы происходит
//загрузка списка сотрудников из указанного пользователем файла.

#define _CRT_SECURE_NO_WARNINGS         //блокируем предупреждения при использовании старой библиотеки ctime
#include <ctime> 
#include <iostream>
using namespace std;

struct employee                                         //структура сотрудник (имя, фамилия, д/р)
{
    char* first_name = new char[50];
    char* second_name = new char[50];
    int* birthday = new int[3];

}; employee* employees;

int count_records(const char* path)                     //функция подсчёта записей в файле
{
    int counter = 0;
    FILE* in;
    int string_size = 150;
    char* current_string = new char[string_size];

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            fgets(current_string, string_size, in);
            ++counter;
        }
    }
    fclose(in);
    delete[] current_string;

    return counter - 1;
}

int string_lenght(char* current_string)                 //определение длины строки в char*-массиве
{
    int counter = 0;
    char symbol = '\0';
    while (current_string[counter] != '\0')
    {
        ++counter;
    }

    return counter;
}

char* concatenate_string(char* string1, char* string2)  //слияние двух строк из char*-массивов
{
    int string_lenght1 = string_lenght(string1);
    int string_lenght2 = string_lenght(string2);
    int string_size = string_lenght1 + string_lenght2 + 1;
    char* current_string = new char[string_size];
    for (int i = 0; i < string_size - 1; i++)
    {
        if (i < string_lenght1)
        {
            current_string[i] = string1[i];

        }
        else
        {
            current_string[i] = string2[i - string_lenght1];
        }
    }
    current_string[string_size - 1] = '\0';

    return current_string;
}

employee fill_employee(employee current_employee)       //заполнеие структуры
{
    cout << "Enter first name: ";
    cin >> current_employee.first_name;
    cout << "Enter second name: ";
    cin >> current_employee.second_name;
    cout << "Enter birthday: " << endl;
    cout << "Enter day (1-31): ";
    cin >> current_employee.birthday[0];
    cout << "Enter month (1-12): ";
    cin >> current_employee.birthday[1];
    cout << "Enter year: ";
    cin >> current_employee.birthday[2];

    return current_employee;
}

char* int2sring(int number)                                //перевод числа в строку (возвращает char* массив)
{
    int size = 10;
    int counter = 10;
    char* newString = new char[size];
    int buf = 0;
    char buffer = '\0';

    if (number < 2147483648)
    {
        for (int i = 0; i < 10; ++i)
        {
            buf = number;
            number %= 10;
            newString[i] = char(number + 48);
            number = (buf - number) / 10;
        }

        for (int j = 9; j >= 0; --j)
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

        for (int i = 0, j = counter - 1; i <= j; ++i, --j)
        {
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

int string2int(char* str)                                   //перевод строки в число
{
    int counter = 0;
    int number = 0;
    while (str[counter] != '\0')
    {
        ++counter;
    }

    int i = counter - 1;
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

char* string2display(char* string)          //строка из файла в экранное представление
{
    int counter = 0;
    int separator = 0;
    int lenght = string_lenght(string);
    int string_size = 150;
    char* current_string = new char[string_size];

    for (int i = 0; i < lenght; i++)
    {
        if (string[i] == ',')
        {
            ++separator;
            if (separator < 3)
            {
                string[i] = ' ';
            }
            else
            {
                string[i] = '.';
            }
        }
        if (string[i] == '\n')
        {
            current_string[i] = '\0';
            break;
        }
        current_string[i] = string[i];
    }

    return current_string;
}

char* clear_string(char* string, int size)          //очистка строки (char*-массива)
{
    for (int i = 0; i < size; i++)
    {
        string[i] = '\0';
    }
    return string;
}

bool add_employee(employee current_employee, const char* path)  //добавление сотрудника (запись строки в файл)
{
    bool isAdded = false;
    int record_counter = 0;
    record_counter = count_records(path);
    FILE* out;
    int string_size = 150;
    char* current_string = new char[string_size];
    char* comma = new char[2];
    comma[0] = ',';
    comma[1] = '\0';
    char* break_line = new char[2];
    break_line[0] = '\n';
    break_line[1] = '\0';

    if (fopen_s(&out, path, "a") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        current_string = concatenate_string(current_employee.first_name, comma);
        current_string = concatenate_string(current_string, current_employee.second_name);
        current_string = concatenate_string(current_string, comma);
        current_string = concatenate_string(current_string, int2sring(current_employee.birthday[0]));
        current_string = concatenate_string(current_string, comma);
        current_string = concatenate_string(current_string, int2sring(current_employee.birthday[1]));
        current_string = concatenate_string(current_string, comma);
        current_string = concatenate_string(current_string, int2sring(current_employee.birthday[2]));
        current_string = concatenate_string(current_string, break_line);

        fputs(current_string, out);
    }
    fclose(out);

    delete[] current_string;
    delete[] comma;
    delete[] break_line;

    return isAdded;
}

void edit_employee(int number, const char* path)    //редактирование сотрудника (замена строки в файле)
{
    employee current_employee;
    int counter = 0;
    int position = 0;
    position = count_records(path);
    int str_len = 0;
    bool str_end = false;
    FILE* in;
    FILE* out;
    int string_size = 150;
    char** out_file = new char* [position];
    for (int i = 0; i < position; i++)
    {
        out_file[i] = new char[string_size];
    }

    for (int i = 0; i < position; i++)
    {
        for (int j = 0; j < string_size; j++)
        {
            out_file[i][j] = ' ';
        }
    }

    char* current_string = new char[string_size];
    for (int j = 0; j < string_size; j++)
    {
        current_string[j] = ' ';
    }

    char* comma = new char[2];
    comma[0] = ',';
    comma[1] = '\0';
    char* break_line = new char[2];
    break_line[0] = '\n';
    break_line[1] = '\0';

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            for (int i = 0; i < position; i++)
            {
                fgets(current_string, string_size, in);
                str_len = string_lenght(current_string);

                if (current_string[0] != '\0')
                {
                    if (i == number - 1)
                    {
                        cout << "Editing: " << string2display(current_string) << ":" << endl;
                        current_employee = fill_employee(current_employee);
                        current_string = concatenate_string(current_employee.first_name, comma);
                        current_string = concatenate_string(current_string, current_employee.second_name);
                        current_string = concatenate_string(current_string, comma);
                        current_string = concatenate_string(current_string, int2sring(current_employee.birthday[0]));
                        current_string = concatenate_string(current_string, comma);
                        current_string = concatenate_string(current_string, int2sring(current_employee.birthday[1]));
                        current_string = concatenate_string(current_string, comma);
                        current_string = concatenate_string(current_string, int2sring(current_employee.birthday[2]));
                        current_string = concatenate_string(current_string, break_line);
                        str_len = string_lenght(current_string);
                    }
                    
                    for (int j = 0; j < str_len; j++)
                    {
                        out_file[i][j] = current_string[j];
                    }
                    
                    for (int j = str_len; j < string_size; j++)
                    {
                        out_file[i][str_len] = '\0';
                    }
                    
                }
            }
            current_string[0] = '\0';
        }
    }
    fclose(in);

    if (fopen_s(&out, path, "w") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        for (int i = 0; i < position; i++)
        {
            fputs(out_file[i], out);
        }
    }
    fclose(out);

    current_string = nullptr;

    for (int i = 0; i < position; i++)
    {
        delete[] out_file[i];
    }
    delete[] out_file;
    delete[] current_string;
    delete[] comma;
    delete[] break_line;

    system("pause");
}

void delete_employee(int number, const char* path)      //удаление строки из файла
{
    int counter = 0;
    int position = 0;
    position = count_records(path);
    int str_len = 0;
    bool str_end = false;
    FILE* in;
    FILE* out;
    int string_size = 150;
    char** out_file = new char* [position];
    for (int i = 0; i < position; i++)
    {
        out_file[i] = new char[string_size];
    }

    for (int i = 0; i < position; i++)
    {
        for (int j = 0; j < string_size; j++)
        {
            out_file[i][j] = ' ';
        }
    }

    char* current_string = new char[string_size];
    for (int j = 0; j < string_size; j++)
    {
        current_string[j] = ' ';
    }

    char* comma = new char[2];
    comma[0] = ',';
    comma[1] = '\0';
    char* break_line = new char[2];
    break_line[0] = '\n';
    break_line[1] = '\0';

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            for (int i = 0; i < position; i++)
            {
                fgets(current_string, string_size, in);
                str_len = string_lenght(current_string);

                if (current_string[0] != '\0')
                {
                    if (i != number - 1)
                    {
                        for (int j = 0; j < str_len; j++)
                        {
                            out_file[i][j] = current_string[j];
                        }

                        for (int j = str_len; j < string_size; j++)
                        {
                            out_file[i][str_len] = '\0';
                        }
                    }
                }
            }
            current_string[0] = '\0';
        }
    }
    fclose(in);


    if (fopen_s(&out, path, "w") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        for (int i = 0; i < position; i++)
        {
            if (out_file[i][0] != ' ')
            {
                fputs(out_file[i], out);
            }
        }
    }
    fclose(out);

    current_string = nullptr;

    for (int i = 0; i < position; i++)
    {
        delete[] out_file[i];
    }
    delete[] out_file;
    delete[] current_string;
    delete[] comma;
    delete[] break_line;

    system("pause");
}

int ageСalculation(int y)               //функция, получив год рождения, возвращает возраст
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 0;
    currentYear = 1900 + ltm->tm_year;

    return currentYear - y;
}

bool find_by_age(int number, const char* path)  //ищет совпадение по возрасту
{
    bool finded = false;
    int counter = 0;
    int str_len = 0;
    int separator = 0;
    int record_counter = 0;
    record_counter = count_records(path);
    int k = 0;
    FILE* in;
    int string_size = 150;
    char* current_string = new char[string_size];
    char* year = new char[4];

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            for (int i = 0; i < record_counter; i++)
            {
                fgets(current_string, string_size, in);
                str_len = string_lenght(current_string);

                if (current_string[0] != '\0')
                {
                    k = 0;
                    for (int j = 0; j < str_len; j++)
                    {
                        if (current_string[j] == ',')
                        {
                            ++separator;
                        }
                        if (separator == 4 && current_string[j] != ',' && current_string[j] != '\n')
                        {
                            year[k] = current_string[j];
                            ++k;
                        }
                    }
                    year[k] = '\0';

                    if (ageСalculation(string2int(year)) == number)
                    {
                        cout << string2display(current_string) << endl;
                        finded = true;
                        system("pause");
                    }

                    separator = 0;
                    year = clear_string(year, 4);
                    current_string = clear_string(current_string, string_size);
                }
            }
            current_string[0] = '\0';
        }
    }
    fclose(in);

    delete[] current_string;
    delete[] year;

    return finded;
}

bool find_by_letter(char symbol, const char* path)  //поиск по первой букве фамилии
{
    bool finded = false;
    int counter = 0;
    int str_len = 0;
    int separator = 0;
    int record_counter = 0;
    record_counter = count_records(path);
    int k = 0;
    FILE* in;
    int string_size = 150;
    char* current_string = new char[string_size];
    char* second_name = new char[10];

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            for (int i = 0; i < record_counter; i++)
            {
                fgets(current_string, string_size, in);
                str_len = string_lenght(current_string);

                if (current_string[0] != '\0')
                {
                    k = 0;
                    for (int j = 0; j < str_len; j++)
                    {
                        if (current_string[j] == ',')
                        {
                            ++separator;
                        }
                        if (separator == 1 && current_string[j] != ',')
                        {
                            second_name[k] = current_string[j];
                            ++k;
                        }
                    }
                    second_name[k] = '\0';

                    if (second_name[0] == symbol)
                    {
                        cout << string2display(current_string) << endl;
                        finded = true;
                        system("pause");
                    }
                    separator = 0;
                    second_name = clear_string(second_name, 10);
                    current_string = clear_string(current_string, string_size);
                }
            }
            current_string[0] = '\0';
        }
    }
    fclose(in);

    delete[] current_string;
    delete[] second_name;

    return finded;
}

bool find_by_second_name(char* second_name, const char* path)   //поиск по фамилии
{
    bool finded = false;
    bool compare = false;
    int counter = 0;
    int str_len = 0;
    int separator = 0;
    int record_counter = 0;
    record_counter = count_records(path);
    int k = 0;
    int m = 0;
    FILE* in;
    int string_size = 150;
    char* current_string = new char[string_size];
    char* sec_nam = new char[10];

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            for (int i = 0; i < record_counter; i++)
            {
                fgets(current_string, string_size, in);
                str_len = string_lenght(current_string);

                if (current_string[0] != '\0')
                {
                    k = 0;
                    for (int j = 0; j < str_len; j++)
                    {
                        if (current_string[j] == ',')
                        {
                            ++separator;
                        }
                        if (separator == 1 && current_string[j] != ',')
                        {
                            sec_nam[k] = current_string[j];
                            ++k;
                        }
                    }
                    sec_nam[k] = '\0';

                    compare = false;
                    m = 0;
                    for (int l = 0; l <= k; l++)
                    {
                        if (sec_nam[l] == second_name[l])
                        {
                            compare = true;
                            ++m;
                        }
                        else
                        {
                            compare = false;
                        }
                    }

                    if (compare && m - 1 == k)
                    {
                        cout << string2display(current_string) << endl;
                        finded = true;
                        system("pause");
                    }
                    separator = 0;
                    sec_nam = clear_string(sec_nam, 10);
                    current_string = clear_string(current_string, string_size);
                }
            }
            current_string[0] = '\0';
        }
    }
    fclose(in);
    
    delete[] current_string;
    delete[] sec_nam;

    return finded;
}

void display_employees(const char* path)        //вывод списка сотрудников при чтении из файла
{
    int counter = 0;
    int position = 0;
    FILE* in;
    int string_size = 150;
    char* current_string = new char[string_size];

    if (fopen_s(&in, path, "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            fgets(current_string, string_size, in);
            ++counter;
            if (current_string[0] != '\0')
            {
                cout << counter << ". " << string2display(current_string) << endl;
                current_string[0] = '\0';
            }
        }
    }
    fclose(in);
    delete[] current_string;
    system("pause");
}

int menu(const char* path)                  //основное меню
{
    system("cls");
    int cont = 0;

    while (cont < 1 || cont > 8)
    {
        cout << "- EMPLOYEES -" << endl;
        cout << "1. Add new employee." << endl;
        cout << "2. Edit employee." << endl;
        cout << "3. Delete employee." << endl;
        cout << "4. List all employees(" << count_records(path) << ")." << endl;
        cout << "5. Find by age." << endl;
        cout << "6. Find by first letter of second name." << endl;
        cout << "7. Find by second name." << endl;
        cout << "8. Quit." << endl;
        cout << "Your choise(1-8): ";
        cin >> cont;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return cont;
}

int main()
{
    const char* path = "C:\\Intel\\employees.txt";
    int user_choise = 0;
    int k = 0;
    char symbol = '\0';
    bool finded = false;
    char* second_name = new char[10];
    int record_counter = 0;
    record_counter = count_records(path);
    employee current_employee;

    while (user_choise != 8)                     //пока не выбран выход - выводим меню
    {
        user_choise = menu(path);

        switch (user_choise)
        {
        case 1:
            current_employee = fill_employee(current_employee);
            add_employee(current_employee, path);
            break;
        case 2:
            if (count_records(path) < 1)
            {
                cout << "Employees is absent!" << endl;
                system("pause");
            }
            else
            {
                display_employees(path);
                cout << "Enter number of employee to edit(1-" << count_records(path) << "):";
                cin >> k;
                edit_employee(k, path);
            }
            break;
        case 3:
            if (count_records(path) < 1)
            {
                cout << "Employees is absent!" << endl;
                system("pause");
            }
            else
            {
                display_employees(path);
                cout << "Enter number of employee to delete(1-" << count_records(path) << "):";
                cin >> k;
                delete_employee(k, path);
            }
            break;
        case 4:
            if (count_records(path) < 1)
            {
                cout << "Employees is absent!" << endl;
                system("pause");
            }
            else
            {
                display_employees(path);
            }
            break;
        case 5:
            if (count_records(path) < 1)
            {
                cout << "Employees is absent!" << endl;
                system("pause");
            }
            else
            {
                cout << "Enter age of employee to find(1-100):";
                cin >> k;
                finded = find_by_age(k, path);
                if (!finded)
                {
                    cout << "Don't find employee with this age!" << endl;
                    system("pause");
                }
            }
            break;
        case 6:
            if (count_records(path) < 1)
            {
                cout << "Employees is absent!" << endl;
                system("pause");
            }
            else
            {
                cout << "Enter first letter to find:";
                cin >> symbol;
                finded = find_by_letter(symbol, path);
                if (!finded)
                {
                    cout << "Don't find employee where second name starts on this letter!" << endl;
                    system("pause");
                }
            }
            break;
        case 7:
            if (count_records(path) < 1)
            {
                cout << "Employees is absent!" << endl;
                system("pause");
            }
            else
            {
                cout << "Enter second name to find:";
                cin >> second_name;
                finded = find_by_second_name(second_name, path);
                if (!finded)
                {
                    cout << "Don't find employee with this second name!" << endl;
                    system("pause");
                }
            }
            break;
        default:
            user_choise = 8;
        }
    }

    return 0;
}