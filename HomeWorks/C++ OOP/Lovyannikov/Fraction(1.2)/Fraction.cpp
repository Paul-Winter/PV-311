//
//  Fraction.cpp
//  ДЗ-1 ООП (дробь)
//
//  Created by Rodion Lovyannikov on 19.05.2024.
//

#include "Fraction.hpp"
using namespace std;

void Fraction::setNumerator(float numerator)
{
    this->numerator=numerator;
}
void Fraction::setDenominator(float denominator)
{
        this->denominator=denominator;
}
float Fraction::getNumerator()
{
        return numerator;
}
float Fraction::getDenominator()
{
    return denominator;
}
Fraction::Fraction()
{
}
Fraction::Fraction(float numerartor, float denominator) : numerator{numerartor},denominator{denominator}
{
}
void Fraction::Print()
{
    cout<< numerator/denominator <<endl;
}
Fraction Fraction:: addition(const Fraction& f)
{
            Fraction s;
            s.numerator=(numerator*f.denominator)+(f.numerator*denominator);
            s.denominator=denominator*f.denominator;
    return s;
}
Fraction Fraction:: substruction(const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.denominator)-(f.numerator*denominator);
    s.denominator=denominator*f.denominator;
    return s;
}
Fraction Fraction:: multiplication(const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.numerator);
    s.denominator=denominator*f.denominator;
    return s;
}
Fraction Fraction:: division(const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.denominator);
    s.denominator=denominator*f.numerator;
    return s;
}
Fraction Fraction::operator+ (const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.denominator)+(f.numerator*denominator);
    s.denominator=denominator*f.denominator;
    return s;
}
Fraction Fraction::operator- (const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.denominator)-(f.numerator*denominator);
    s.denominator=denominator*f.denominator;
    return s;
}
Fraction Fraction::operator* (const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.numerator);
    s.denominator=denominator*f.denominator;
    return s;
}
Fraction Fraction::operator/ (const Fraction& f)
{
    Fraction s;
    s.numerator=(numerator*f.denominator);
    s.denominator=denominator*f.numerator;
    return s;
}
void Fraction::operator=(const Fraction& f)
{
    this->numerator=f.numerator;
    this->denominator=f.denominator;
}
bool Fraction::operator==(const Fraction& f)
{
    if(numerator/denominator == f.numerator/f.denominator) return true;
    else return false;
}
bool Fraction::operator>(const Fraction& f)
{
    if(numerator/denominator > f.numerator/f.denominator) return true;
    else return false;
}
bool Fraction::operator<(const Fraction& f)
{
    if(numerator/denominator < f.numerator/f.denominator) return true;
    else return false;
}
bool Fraction::operator>=(const Fraction& f)
{
    if(numerator/denominator > f.numerator/f.denominator || numerator/denominator == f.numerator/f.denominator ) return true;
    else return false;
}
bool Fraction::operator<=(const Fraction& f)
{
    if(numerator/denominator < f.numerator/f.denominator || numerator/denominator == f.numerator/f.denominator ) return true;
    else return false;
}
bool Fraction::operator!=(const Fraction& f)
{
    if(numerator/denominator != f.numerator/f.denominator) return true;
    else return false;
}




void Fraction::PrintInFraction()
{
    cout<<numerator<<endl;
    cout<<"-"s<<endl;
    cout<<denominator<<endl;
}



