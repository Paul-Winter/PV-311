//
//  main.cpp
//  DZ08
//
//  Created by Jaroslav on 25.06.2024.
//

#include <iostream>
using namespace std;

class Student
{
protected:
    
    int Age;
    string Name;
    
    
public:

    Student()
    {cout<<"empty"<<endl;}
    
    
    
    Student(int Age,string Name):Age{Age},Name{Name}
    {
    
    }
    void display()
    {
    cout<<"Age: "<<Age<<" Name: "<<Name;
    cout<<endl;
    }
   
    ~Student()
    {}
    
    
};

class Aspirant:protected Student
{
    protected:
    
    string Dissertacia;
    
public:

    Aspirant (int Age,string Name,string Dissertacia):Student(Age,Name)
    {
    this->Dissertacia=Dissertacia;
    
    }
    Aspirant()
    {cout<<"empty"<<endl;}
    
    
    
    void display()
    {
    cout<<"Age: "<<Age<<" Name: "<<Name<<endl<<"Topic of dissertacia: "<<Dissertacia;
    cout<<endl;
    }
    
    ~Aspirant()
    {}
    
};

class Professor:protected Aspirant
{
private:
    string Cafedra;
    
public:
    Professor()
    {cout<<"empty"<<endl;}
    
    Professor(int Age,string Name,string Dissertacia,string Cafedra):Aspirant(Age,Name,Dissertacia)
    {
    this->Cafedra=Cafedra;
    }
    void display()
    {
    
    
    cout<<"Age: "<<Age<<" Name: "<<Name<<endl<<"Topic of dissertacia: "<<Dissertacia<<" cafedra: "<<Cafedra;
    cout<<endl;
    }
    ~Professor()
    {}
    
};
void display_all()
{
    Student a;
    a.display();
    Aspirant b;
    b.display();
    Professor c;
    c.display();
}


int main()
{
    Student a(24,"Evlampiy");
    Aspirant b(32,"Sysoy Kalistratovitch ","Vvedenie v proctologiyu");
    Professor c(60,"Alkid Egorovitch Smorchkov","Zanimatelnaya Proctologia","Analitica");
    a.display();
    b.display();
    c.display();
    //display_all();
    
    
    
    
   
}
