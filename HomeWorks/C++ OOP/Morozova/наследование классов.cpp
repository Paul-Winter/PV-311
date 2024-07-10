// наследование классов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Student
{
protected:
        int age;
        string name;
public:
    Student()
    {
        
    }
     Student(int age, string name) : age{ age }, name{ name }
    {}
     void Display()
     {
         cout << "Age " << age << " Name " << name << endl;

     }
     ~Student()
     {}


};

class Aspirant : protected Student
{
protected:
    string diss;
public:
    Aspirant()
    {

    }
    Aspirant(int age, string name, string diss) : Student(age, name)
    {
        this->diss = diss;
    }

    void Display()
    {
        cout << "Age " << age << " Name " << name << " Dissertacia " << diss << endl;
    }
    ~Aspirant()
    {}
};



int main()
{
    Student n(20,"Dida");
    n.Display();
    Aspirant i(34,"Viva","Gemmolog");
    i.Display();
    

    
}

