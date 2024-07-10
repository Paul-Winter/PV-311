//
//  main.cpp
//  Animals
//
//  Created by Jaroslav on 29.06.2024.
//

#include <iostream>
using namespace std;


class Dog
{
protected:
    string Name="";
    int Age;
public:
    Dog()
    {}
    Dog(string Name,int Age):Name{Name},Age{Age}
    {
    
    }
    
    virtual void print_Name()
    {
    cout<<"name creatures: "<<Name<<" || "<<"Age: "<<Age<<endl;
    }
    
    
};

class Cat: protected Dog
{
protected:
    string Color="";
public:
    Cat()
    {}
    Cat(string Name,int Age,string Color): Dog(Name,Age)
    {
    this->Color=Color;
    }
     void print_Name()override
    {
    cout<<"name creatures: "<<Name<<" || "<<"Color: " <<Color<<" || "<<"Age : "<<Age<<endl;
    }
    
};

class Parrot:protected Cat
{
protected:
    int size;
public:
    Parrot()
    {}
    Parrot(string Name,int Age,string Color,int size):Cat(Name,Age,Color)
    {
    this->size=size;
    }
    virtual void print_Name()override
   {
   cout<<"name creatures: "<<Name<<" || "<<"Color: "<<Color<<" || "<<"Age : "<<Age<<" || "<<"Size: "<<size<<endl;
   }
    
    
};

int main()
{
    Dog a("Barbos",10);
    Cat b("Murzik",7,"gray");
    Parrot c("Kesha",3,"white",50);
    Cat* Name=&b;
    Dog* Name2=&a;
    Parrot* Name3=&c;
    Name->print_Name();
    Name2->print_Name();
    Name3->print_Name();
   
}

