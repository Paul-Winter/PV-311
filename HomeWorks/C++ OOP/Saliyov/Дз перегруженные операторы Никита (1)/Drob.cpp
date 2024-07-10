//
//  main.cpp
//  dz_01.05
//
//  Created by Nikita on 01.05.2024.
//

#include <iostream>
using namespace std;
class Fraction {
public:

    int x;
    int y;

    void setX(int x)
    {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    void setXY(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    

    Fraction adding(const Fraction& f)
    {
        Fraction s;
        s.x = (x * f.y) + (f.x * y);
        s.y = y * f.y;

        return s;
    }
    Fraction subtraction(const Fraction& f)
    {
        Fraction s;
        s.x = (x * f.y) - (f.x * y);
        s.y = y * f.y;

        return s;
    };
    Fraction multiplication(const Fraction& f)
    {
        Fraction s;
        s.x = x * f.x;
        s.y = y * f.y;

        return s;
    };
    Fraction division(const Fraction& f)
    {
        Fraction s;
        s.x = x * f.y;
        s.y = y * f.x;

        return s;
    };

    Fraction operator+ (const Fraction& f)
    {
        Fraction s;
        s.x = (x * f.y) + (f.x * y);
        s.y = y * f.y;

        return s;
    }

     Fraction operator* (const Fraction& f)
    {
        Fraction s;
        s.x = x * f.x;
        s.y = y * f.y;

        return s;
    }
   
    Fraction operator/ (const Fraction& f)
    {
        Fraction s;
        s.x = x * f.y;
        s.y = y * f.x;

        return s;
    }

    Fraction operator= (const Fraction &f) 
    {
      
         this->x = f.x;
         this->y = f.y;

         return *this;
    }

    void print()
    {
        cout << x << " " << y;
    }

};



int main(int argc, const char* argv[])
{
    Fraction a1;
    Fraction a2;
    Fraction rez;


    a1.setXY(1, 2);
    a2.setXY(1, 2);
    
    rez = a1 + a2;
    rez = a1 = a2;
    rez.print();
    //rez.setXY (a1.adding(a2)); //сложение
    // rez.setXY (a1.subtraction(a2)); //вычитание
    //rez.setXY (a1.multiplication(a2)); //умножение
   // rez.setXY (a1.division(a2)); //деление
    //rez.print();

    






}