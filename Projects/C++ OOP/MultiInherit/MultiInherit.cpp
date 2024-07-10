#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

// наследование шаблона класса

template <typename T> class Human 
{
protected:
    T name;
    T brain;
    T idea;
public:
    Human() 
    {
        cout << "Human created" << endl;
    }
    Human(T name, T brain, T idea) : name{ name }, brain{ brain }, idea{ idea }
    {
        cout << "Human created" << endl;
        cout << "Name - " << name << endl;
        cout << "Brain -" << brain << endl;
        cout << "Countity of Ideas - " << idea << endl;
    }
};

class Student : public Human<string>
{
public:
    string name;
    Student() {

    }
    Student(string name) : name{ name }
    {
        cout << "Student created" << endl;
        cout << "Name - " << name << endl;
    }
};


// множественное наследование

class Mother
{
protected:
    string Name;
    int Age;

public:
    Mother()
    {
        cout << "constructor (default) Mother is work " << endl;
    }

    Mother(string Name,int Age ):Name{Name},Age{Age}
    {
        cout << "constructor Mother is work " << endl;
    }
    virtual void display()
    {
        cout << "Name " << Name << "\tAge " << Age << endl;
    }
};

class Father
{
protected:
    int Weight;
    string Color;

public:
    Father()
    {
        cout << "constructor(default) Father is work " << endl;
    }
    Father(int Weight, string Color) :Weight{Weight},Color {Color}
    {
        cout << "constructor Father is work " << endl;
    }
    virtual void display()
    {
        cout << "Weight " << Weight << "\tColor " << Color << endl;
    }
};

class Child : public Father, public Mother
{
    int Lenght;

public:

    Child()
    {
        cout << "constructor Child is work " << endl;
    }
    Child(string Name,int Age,int Lenght,int Weight,string Color) :Father(Weight,Color),Mother(Name,Age)
    {
        this->Lenght = Lenght;                      
    }

    void display() override final
    {
        cout <<"Lenght= "<< Lenght <<"\tWeight= "<< Weight <<"\tColor= "<< Color << "\tName= "<<Name << "\tAge= " << Age << endl;
    }
};

int main()
{
    Mother mom("Mama", 28);
    mom.display();

    Father papa(78, "Red");
    papa.display();

    Child baby("Child", 12, 156, 43, "Ginger");

    Mother* ma = &baby;
    ma->display();

    Father* pa = &baby;
    pa->display();

    baby.display();
}

