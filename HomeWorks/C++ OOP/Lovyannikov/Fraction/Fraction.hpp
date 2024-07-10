//
//  Fraction.hpp
//  ДЗ-1 ООП (дробь)
//
//  Created by Rodion Lovyannikov on 19.05.2024.
//
#include <stdio.h>
#include <iostream>
using namespace std;

class Fraction
{
private:
    float numerator;
    float denominator;
public:
    void setNumerator(float numerator);
    void setDenominator(float denominator);
    float getNumerator();
    float getDenominator();
    explicit Fraction(float numerator,float denominator);
    explicit Fraction();
    Fraction addition(const Fraction& f);
    Fraction substruction(const Fraction& f);
    Fraction multiplication(const Fraction& f);
    Fraction division(const Fraction& f);
    Fraction operator+ (const Fraction& f);
    Fraction operator- (const Fraction& f);
    Fraction operator* (const Fraction& f);
    Fraction operator/ (const Fraction& f);
    void operator= (const Fraction& f);
    void Print();
    
};
