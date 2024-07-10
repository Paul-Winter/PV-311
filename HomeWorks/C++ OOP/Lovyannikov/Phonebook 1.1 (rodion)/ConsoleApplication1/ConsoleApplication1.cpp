#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Abonent.h"
#include <fstream>
#include "Phonebook.h"
using namespace std;
#undef strcpy
#define strcpy(dest, src)

int main()
{
    Abonent a;
    a.SetName("Shlyapa");
    cout << a.GetName() << endl;
    a.SetInfo("Shlyapburg city");
    cout << a.GetInfo() << endl;
    a.SetMobileNumber(1241);
    cout << a.GetMobileNumber() << endl;
    a.SetHomeNumber(125515);
    cout << a.GetHomeNumber() << endl;
    a.SetWorkNumber(1241);
    cout << a.GetWorkNumber() << endl;
    Abonent b("Shlyopa", "Gorod", 909909,1201101,20202);
    cout << endl << endl;
    a.PrintAbonent();
    cout << endl << endl;
    b.PrintAbonent();
    cout << endl << endl;
    bool check = a == b;
    cout << check << endl;
    Abonent c;
    c = b;
    check = c == b;
    cout << check << endl;


    
}
