// DSAW.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class ErkarTiv
{
public:
    char a[10000];
    void operator=(char*);
    ErkarTiv operator+(ErkarTiv&);
};
int main()
{
    ErkarTiv x;
    ErkarTiv y;
    ErkarTiv z;
    x = y + z;
    cout << x;
    return 0;
}
void ErkarTiv::operator=(char* t)
{
    strcpy_s(a, t);

}
ErkarTiv ErkarTiv::operator+(ErkarTiv& d)
{
    ErkarTiv x;
    x = a;
    ErkuToxGumarel(x.a, d.a);
    return x;
}