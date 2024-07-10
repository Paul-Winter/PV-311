#include <iostream>
#include <string>
using namespace std;

class Drob {
private:
    int chisl;
    int znamen;
    int NOD(int x, int y)
    {
        if (y == 0) return x;
        return NOD(y, x % y);
    }
public:
    void input(int c, int z)
    {
        chisl = c;
        znamen = z;
    }
    void mult(int x)
    {
        chisl *= x;
        cout << "drob:  " << chisl << '/' << znamen << endl;
    }
    void div(int x)
    {
        znamen *= x;
        cout << "drob:  " << chisl << '/' << znamen << endl;

    }

    void sum(int x)
    {
        chisl += (x * znamen);
        cout << "drob:  " << chisl << '/' << znamen << endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        cout << "drob:  " << chisl << '/' << znamen << endl;

    }
    void show()
    {
        cout << "tekushaya drob:  " << chisl << '/' << znamen << endl;
    }
    int peredacha()
    {
        return NOD(chisl, znamen);
    }
    void reduct(int x)
    {
        chisl /= x;
        znamen /= x;
    }

};



int main() {
    int a, b, m;
    char c = 'y';
    cout << "vvedite cheslitel:" << endl;
    cin >> a;
    cout << "vvedite znamenatel:" << endl;
    cin >> b;
    Drob obj;
    obj.input(a, b);
    do {
        obj.reduct(obj.peredacha());
        obj.show();
        cout << "1:Pribavit k drobi chislo" << endl;
        cout << "2:Otniatb ot drobi chislo" << endl;
        cout << "3:Ymnojitb  drobna  chislo" << endl;
        cout << "4:Razdelitb  drob na chislo" << endl;
        cout << "Viberite deystvie" << '\n';
        cin >> m;
        switch (m)
        {
        case 1:
            cout << "Vvedite slagaemoe" << endl;
            cin >> a;
            obj.sum(a);
            break;
        case 2:
            cout << "Vvedite vichitaemoe" << endl;
            cin >> a;
            obj.sub(a);
            break;
        case 3:
            cout << "Vvedite mnojitel" << endl;
            cin >> a;
            obj.mult(a);
            break;
        case 4:
            cout << "Vvedite delitel" << endl;
            cin >> a;
            obj.div(a);
            break;
        default:
            cout << "Viberite pravilno" << endl;
        }
        cout << "prodoljit raboty?(y/n)" << endl;
        cin >> c;
    } while (c != 'n');
    return 0;
}












#pragma once
class PhoneBook
{

    char fio[30];
    long long home_telephone;
    long long work_telephone;
    long long mobile_telephone;
    char more_info[30];

public:

    void add();
    void dell();
    void show();
    void print_all();
    void search();

    PhoneBook();
    ~PhoneBook();
};

//Файл PhoneBook.cpp

#include "PhoneBook.h"
#include<iostream>
#include<conio.h>

using namespace std;

void PhoneBook::add()
{
    cout << "Введите ФИО абонента\n";
    gets(fio);
    cout << "Введите номер домашнего телефона\n";
    cin >> home_telephone;
    cout << "Введите номер рабочего телефона\n";
    cin >> work_telephone;
    cout << "Введите номер мобильного телефона\n";
    cin >> mobile_telephone;
    cout << "Введите дополнительную информацию\n";
    cin.ignore(); gets(more_info);
}
void PhoneBook::show()
{
    cout << "ФИО абонента: "; puts(fio); cout << "\n";
    cout << "Номер домашнего телефона: " << home_telephone << "\n";
    cout << "Номер рабочего телефона: " << work_telephone << "\n";
    cout << "Номер мобильного телефона: " << mobile_telephone << "\n";
    cout << "Дополнительная информация: "; puts(more_info); cout << "\n";
}

PhoneBook Enter(PhoneBook* x, int& n)
{
    cout << "Введите колличество абонентов: ";
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++)
    {
        x[i].add();
    }
    return *x;
}
PhoneBook Add(PhoneBook* x, int& n)
{
    cout << "Введите сколько абонентов нужно добавить: ";
    int m; cin >> m; cin.ignore();
    for (int i = n; i < m; i++)
    {
        x[i].add();
    }n = n + m;
}
PhoneBook Dell(PhoneBook* x, int& n)
{
    cout << "Абонента под каким номером нужно удалить?\n";
    int del; cin >> del;
    for (int i = 0; i < n - 1; i++)
    {
        if (i >= del)
            x[i] = x[i + 1];
    } n = n - 1;
}
void ShowAll(PhoneBook* x, int& n)
{
    for (int i = 0; i < n; i++)
    {
        x[i].show();
    }
}

PhoneBook::PhoneBook()
{
}


PhoneBook::~PhoneBook()
{
}

//Файл Main.cpp

#include"PhoneBook.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

PhoneBook Enter(PhoneBook* x, int& n);
PhoneBook Add(PhoneBook* x, int& n);
PhoneBook Dell(PhoneBook* x, int& n);
void ShowAll(PhoneBook* x, int& n)

PhoneBook* Enter(PhoneBook* x, int& n)
{
    cout << "Введите колличество абонентов: ";
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++)
    {
        x[i].add();
    }
    return *x;
}
PhoneBook Add(PhoneBook* x, int& n)
{
    cout << "Введите сколько абонентов нужно добавить: ";
    int m; cin >> m; cin.ignore();
    for (int i = n; i < m; i++)
    {
        x[i].add();
    }n = n + m;
}
PhoneBook Dell(PhoneBook* x, int& n)
{
    cout << "Абонента под каким номером нужно удалить?\n";
    int del; cin >> del;
    for (int i = 0; i < n - 1; i++)
    {
        if (i >= del)
            x[i] = x[i + 1];
    } n = n - 1;
}
void ShowAll(PhoneBook* x, int& n)
{
    for (int i = 0; i < n; i++)
    {
        x[i].show();
    }
}
void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    PhoneBook* x = new PhoneBook[n];
    Enter(x, n);
    ShowAll(x, n);
    Add(x, n);
    ShowAll(x, n);
}