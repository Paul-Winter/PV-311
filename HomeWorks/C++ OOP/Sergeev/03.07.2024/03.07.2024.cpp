
#include <iostream>

using namespace std;

class Student
{
protected:
    string name;
    int age;
public:

    Student()
    {}
    Student(string name, int age) : name{ name }, age{age}
    {}
    void Speak()
    {
        cout << "student_name: " << name << "\n student_age: " << age << endl << endl;
    }

};

class Aspirant : Student
{
    string kafedra;

public:

    Aspirant()
    {
    }

    Aspirant(string kafedra, string name, int age) :Student(name,age), kafedra{kafedra}
    {}

    void Speak()
    {
        cout << "aspirant_name: " << name << "\naspirant_age: " << age << "\nkafedra: "<< kafedra << endl;
    }
    ~Aspirant()
    {
    }
};


int main()
{
    Student stud("Wassyly", 18);
    stud.Speak();

    Aspirant asp("Biohazard", "Vassyly Borisovich", 35);
    asp.Speak();

}