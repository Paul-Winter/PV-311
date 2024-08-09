//ЗАДАНИЕ 1
//Написать программу «справочник». Создать два одномерных
//массива. Один массив хранит номера мобильных телефонов,
//второй — домашние телефонные номера.
//Реализовать меню для пользователя:
//■ Отсортировать по номерам мобильных
//■ Отсортировать по домашним номерам телефонов;
//■ Вывести пользовательский данные;
//■ Выход.

#include <iostream>
using namespace std;

int main()
{

    srand(time(0));
    
    int size = 5;
    int choise = 1;
    int buf = 0;
    int tek = 0;
    int* mob = new int[size];
    int* dom = new int[size];

    cout << "Mobile numbers:" << "\t" << "Home numbers:" << endl;
    for (int i = 0; i < size; ++i)
    {
        mob[i] = 962400000 + rand() % 10000;
        dom[i] = 865200000 + rand() % 11000;
        cout << mob[i] << "\t" << dom[i] << endl;
    }
          
    while (choise != 0)
    {
        cout << "MENU\n1. Sort by mobile numbers.\n2. Sort by home numbers.\n3. View user data.\n4. Exit.\n>";
        cin >> choise;

        switch (choise)
        {
        case 1:

            for (int i = 0; i < size-1; ++i)
            {
                tek = i + 1;
                while (tek < size)
                {
                    if (mob[i] < mob[tek])
                    {
                        buf = mob[i];
                        mob[i] = mob[tek];
                        mob[tek] = buf;
                    }
                    ++tek;
                }
            }
            break;

        case 2:

            for (int i = 0; i < size-1; ++i)
            {
                tek = i + 1;
                while (tek < size)
                {
                    if (dom[i] < dom[tek])
                    {
                        buf = dom[i];
                        dom[i] = dom[tek];
                        dom[tek] = buf;
                    }
                    ++tek;
                }
            }
            break;

        case 3:

            cout << "Home numbers:" << "\t" << "Mobile numbers:" << endl;
            for (int i = 0; i < size; ++i)
            {
                cout << dom[i] << "\t" << mob[i] << endl;
            }
            break;

        default:

            choise = 0;

        }
    }

    return 0;
}