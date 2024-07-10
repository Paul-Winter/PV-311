//
//  main.cpp
//  ДЗ-1 ООП (дробь)
//
//  Created by Rodion Lovyannikov on 16.05.2024.
//

#include <iostream>
#include "Fraction.hpp"
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) 
{
    setlocale(LC_ALL, "rus");
    cout<<fixed<<setprecision(5);
    Fraction a(2, 3);
    Fraction b(3, 5);
    Fraction rez;
    rez = a + b;
    rez.Print();
    rez=a-b;
    rez.Print();
    rez=a*b;
    rez.Print();
    rez=a/b;
    rez.Print();
    bool rezult;
    rezult = a==b;
    cout<<rezult<<endl;
    Fraction x(3,5);
    Fraction y(3,5);
    rezult = x==y;
    cout<<rezult<<endl;
    
}
