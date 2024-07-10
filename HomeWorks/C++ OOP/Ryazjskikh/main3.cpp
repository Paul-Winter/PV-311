//
//  main.cpp
//  DZ_11
//
//  Created by Jaroslav on 04.07.2024.
//

#include <iostream>
#include<fstream>
using namespace std;
namespace Animals
{
    class Home_animal
    {
    public:
    
    virtual void print() =0;
    };
    
    class Age_animals
    {
    public:
    int Age;
    Age_animals(){}
    Age_animals(int Age):Age{Age}
    {}
    
    };
    
    class Dog: public Home_animal,public Age_animals
    {
    
    public:
    Dog(int Age):Age_animals(Age)
    {}
    virtual void print () //override
    {
    
    try
        {
        if(Age<0)
            {
            cout<<"Age<0"<<endl;
            throw Age;
            }
        }
    catch(const int &ex)
        {
        cout<<"cutched invalid Age: "<<Age<<endl;
        
        }
    cout<<"GAV-GAV"<<endl;
    cout<<"Age animal: "<<Age<<endl;
    }
    
    };
    class Cat: public Home_animal,public Age_animals
    {
    public:
    Cat(int Age):Age_animals(Age)
    {}
    void print() override
    {
    try
        {
        if(Age<0)
            {
            cout<<"Age<0"<<endl;
            throw Age;
            }
        }
    catch(const int &ex)
        {
        cout<<"cutched invalid Age: "<<Age<<endl;
        
        }
    cout<<"MEOW-MEOW"<<endl;
    cout<<"Age animal: "<<Age<<endl;
    }
    
    };
    
    class Parrot: public Home_animal,public Age_animals
    {
    public:
    Parrot(int Age):Age_animals(Age)
    {}
    void print() override
    {
    try
        {
        if(Age<0)
            {
            cout<<"Age<0"<<endl;
            throw Age;
            }
        }
    catch(const int &ex)
        {
        cout<<"cutched invalid Age: "<<Age<<endl;
        
        }
    cout<<"PIASTRY-PIASTRY"<<endl;
    cout<<"Age animal: "<<Age<<endl;
    }
    };
    
    class All_animals:public Age_animals
    {
    public:
    All_animals(int Age):Age_animals(Age){}
    
    void print(Home_animal *say)
    {
    say->print();
    
    
    }
    
    };
}
    int main()
    {
   Animals:: Dog method1(10);
   Animals:: Cat method2(-8);
   Animals:: Parrot method3(-3);
    //Worker peasant;
  Animals::  All_animals everybody(0);
    //method1.print();
    //method2.print();
    //method3.print();
    everybody.print(&method2);
    
    }
    
