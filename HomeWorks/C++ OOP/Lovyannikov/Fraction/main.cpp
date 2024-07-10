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
    cout<<fixed<<setprecision(3);
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
    
}
