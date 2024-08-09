//ЗАДАНИЕ 2
//Описать структуру Man (Фамилия, Имя, Возраст, Дата рождения).
//Создать массив, предусмотреть:
//■ Вывод информации с сортировкой по фамилии или имени;
//■ Вывод списка именинников месяца с указанием даты рождения;
//■ Изменение размеров массива при добавлении и удалении записей;
//■ Поиск по фамилии и имени;
//■ Редактирование записи.

#define _CRT_SECURE_NO_WARNINGS         //блокируем предупреждения при использовании старой библиотеки ctime
#include <ctime>                        //подключаем библиотеку для работы с датами
#include <iostream>
using namespace std;

extern int num = 1;                     //счётчик элементов массива структур

struct man
{
    string first_name = "\0";
    string second_name = "\0";
    int age = 0;
    int* birthday = new int[3];

}; man* mans;

int ageСalculation(int y)               //функция, получив год рождения, возвращает возраст
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 0;
    //int currentMonth = 0;
    //int currentDay = 0;
    //int currentHour = 0;
    //int currentMin = 0;
    //int currentSec = 0;

    currentYear =  1900 + ltm->tm_year;
    //currentMonth =  1 + ltm->tm_mon;
    //currentDay = ltm->tm_mday;
    //currentHour = 1 + ltm->tm_hour;
    //currentMin = 1 + ltm->tm_min;
    //currentSec = 1 + ltm->tm_sec;

    return currentYear - y;
}

man* fill(man* mans, int N)             //функция заполнения текущего (N) элемента массива структур
{
    cout << num << " man: " << endl;
    cout << "Enter first name: ";
    cin >> mans[N - 1].first_name;
    cout << "Enter second name: ";
    cin >> mans[N - 1].second_name;
    cout << "Enter birthday: " << endl;
    cout << "Enter day (1-31): ";
    cin >> mans[N - 1].birthday[0];
    cout << "Enter month (1-12): ";
    cin >> mans[N - 1].birthday[1];
    cout << "Enter year: ";
    cin >> mans[N - 1].birthday[2];
    mans[N - 1].age = ageСalculation(mans[N - 1].birthday[2]);

    return mans;
}

man* add(man* mans)                     //функция добывления нового элемента в массив структур
{
    man* buf = new man[num];            //создаём новый массив, размером на 1 больше текущего

    for (int i = 0; i < num - 1; i++)   //копируем в новый массив элементы из старого
    {
        buf[i] = mans[i];
    }

    buf = fill(buf, num);               //заполняем последний (пустой) элемент нового массива
    delete[] mans;                      //старый массив удаляем
    ++num;                              //увеличиваем счётчик элементов массива
    return buf;                         //возвращаем новый массив
}

man* del(man* mans, int k)              //функция удаления выбранного (k) элемента из массива структур
{
    int counter = 0;
    man* buf = new man[num - 1];        //создаём новый массив, размером на 1 меньше текущего

    for (int i = 0; i < num - 1; i++)   //копируем в новый массив элементы из старого кроме ненужного
    {
        if (k != i)
        {
            buf[counter] = mans[i];
            ++counter;
        }
    }

    delete[] mans;                      //старый массив удаляем
    --num;                              //уменьшаем счётчик элементов массива
    return buf;                         //возвращаем новый массив
}

void display(man* mans, int M)          //функция вывода элементов массива структур
{
    if (M == 0)
    {
        for (int i = 0; i < num - 1; i++)
        {
            cout << i + 1 << " man:" << endl;
            cout << "First name: " << mans[i].first_name << endl;
            cout << "Second name: " << mans[i].second_name << endl;
            cout << "Age: " << mans[i].age << endl;
            cout << "Birthday: " << mans[i].birthday[0] << "." << mans[i].birthday[1] << "." << mans[i].birthday[2] << endl;
        }
    }
    else                                //если передавался месяц рождения, выводим именинников
    {
        for (int i = 0; i < num - 1; i++)
        {
            if (M == mans[i].birthday[1])   
            {
                cout << i + 1 << " man:" << endl;
                cout << "First name: " << mans[i].first_name << endl;
                cout << "Second name: " << mans[i].second_name << endl;
                cout << "Age: " << mans[i].age << endl;
                cout << "Birthday: " << mans[i].birthday[0] << "." << mans[i].birthday[1] << "." << mans[i].birthday[2] << endl;
            }
        }
    }
    
    system("pause");
}

void searchByFirstName(man* mans, string FirstName)     //ищем по имени
{
    int counter = 0;

    for (int i = 0; i < num; i++)
    {
        if (mans[i].first_name == FirstName)
        {
            ++counter;
            cout << "Finded man " << i + 1 << ": " << endl;
            cout << "First name: " << mans[i].first_name << endl;
            cout << "Second name: " << mans[i].second_name << endl;
            cout << "Age: " << mans[i].age << endl;
            cout << "Birthday: " << mans[i].birthday[0] << "." << mans[i].birthday[1] << "." << mans[i].birthday[2] << endl;
        }
    }
    if (counter == 0)
    {
        cout << "Don't find man with first name: " << FirstName << endl;
    }

    system("pause");
}

void searchBySecondName(man* mans, string SecondName)   //ищем по фамилии
{
    int counter = 0;

    for (int i = 0; i < num; i++)
    {
        if (mans[i].second_name == SecondName)
        {
            ++counter;
            cout << "Finded man " << i + 1 << ": " << endl;
            cout << "First name: " << mans[i].first_name << endl;
            cout << "Second name: " << mans[i].second_name << endl;
            cout << "Age: " << mans[i].age << endl;
            cout << "Birthday: " << mans[i].birthday[0] << "." << mans[i].birthday[1] << "." << mans[i].birthday[2] << endl;
        }
    }
    if (counter == 0)
    {
        cout << "Don't find man with second name: " << SecondName << endl;
    }
    
    system("pause");
}

void sortByFirstName(man* mans)             //сортировка по имени
{
    int counter = 0;
    int size = 0;
    size = num - 1;
    man buf;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (mans[j].first_name > mans[j + 1].first_name)
            {
                buf.first_name = mans[j].first_name;
                buf.second_name = mans[j].second_name;
                buf.age = mans[j].age;
                buf.birthday = mans[j].birthday;
                
                mans[j].first_name = mans[j + 1].first_name;
                mans[j].second_name = mans[j + 1].second_name;
                mans[j].age = mans[j + 1].age;
                mans[j].birthday = mans[j + 1].birthday;

                mans[j + 1].first_name = buf.first_name;
                mans[j + 1].second_name = buf.second_name;
                mans[j + 1].age = buf.age;
                mans[j + 1].birthday = buf.birthday;
            }
        }
    }
}

void sortBySecondName(man* mans)            //сортировка по фамилии
{
    int counter = 0;
    int size = 0;
    size = num - 1;
    man buf;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (mans[j].second_name > mans[j + 1].second_name)
            {
                buf.first_name = mans[j].first_name;
                buf.second_name = mans[j].second_name;
                buf.age = mans[j].age;
                buf.birthday = mans[j].birthday;

                mans[j].first_name = mans[j + 1].first_name;
                mans[j].second_name = mans[j + 1].second_name;
                mans[j].age = mans[j + 1].age;
                mans[j].birthday = mans[j + 1].birthday;

                mans[j + 1].first_name = buf.first_name;
                mans[j + 1].second_name = buf.second_name;
                mans[j + 1].age = buf.age;
                mans[j + 1].birthday = buf.birthday;
            }
        }
    }
}

void edit(man* mans, int number)            //получив номер элемента, редактируем его
{
    cout << "Editing " << number << " man: " << endl;
    cout << "Old first name: " << mans[number - 1].first_name << ", enter new first name: ";
    cin >> mans[number - 1].first_name;
    cout << "Old second name: " << mans[number - 1].second_name << ", enter new second name: ";
    cin >> mans[number - 1].second_name;
    cout << "Old birthday: " << mans[number - 1].birthday[0] << "." << mans[number - 1].birthday[1] << "." << mans[number - 1].birthday[2];
    cout << ", enter new birthday: " << endl;
    cout << "Enter day (1-31): ";
    cin >> mans[number - 1].birthday[0];
    cout << "\nEnter month (1-12): ";
    cin >> mans[number - 1].birthday[1];
    cout << "\nEnter year: ";
    cin >> mans[number - 1].birthday[2];
    mans[number - 1].age = ageСalculation(mans[number - 1].birthday[2]);
}

int menu()
{
    system("cls");
    int cont = -1;
    while (cont == -1)
    {
        cout << "- MAN'S -" << endl;
        cout << "1. Add new man." << endl;
        cout << "2. Delete man." << endl;
        cout << "3. List all." << endl;
        cout << "4. Sort by first name." << endl;
        cout << "5. Sort by second name." << endl;
        cout << "6. Find by first name." << endl;
        cout << "7. Find by second name." << endl;
        cout << "8. List of birthday people in whis mounth." << endl;
        cout << "9. Edit man." << endl;
        cout << "0. Quit." << endl;
        cout << "Your choise(1-9): ";
        cin >> cont;
    }
    return cont;
}

int main()
{
    int k = 0;
    int choise = -1;
    string FirstName = " ";
    string SecondName = " ";
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentMonth = 0;
    currentMonth =  1 + ltm->tm_mon;

    mans = new man[num];

    while (choise != 0)                     //пока не выбран выход - выводим меню
    {
        choise = menu();

        switch (choise)
        {
        case 1:
            if (num != 1)
            {
                mans = add(mans);
            }
            else
            {
                mans = fill(mans, num);
                ++num;
            }
            break;
        case 2:
            display(mans, 0);
            cout << "Enter number of man to delete: ";
            cin >> k;
            mans = del(mans, k - 1);
            break;
        case 3:
            display(mans, 0);
            break;
        case 4:
            sortByFirstName(mans);
            display(mans, 0);
            break;
        case 5:
            sortBySecondName(mans);
            display(mans, 0);
            break;
        case 6:
            cout << "Enter first name to search: ";
            cin >> FirstName;
            searchByFirstName(mans, FirstName);
            break;
        case 7:
            cout << "Enter second name to search: ";
            cin >> SecondName;
            searchBySecondName(mans, SecondName);
            break;
        case 8:
            cout << "List of birthday people in whis mounth: " << endl;
            display(mans, currentMonth);
            break;
        case 9:
            display(mans, 0);
            cout << "Enter number of man to edit: ";
            cin >> k;
            edit(mans, k);
            break;
        default:
            choise = 0;
        }
    }
    return 0;
}