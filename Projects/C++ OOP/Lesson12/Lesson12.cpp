#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Student
{
public:
    string name;
};

class Aspirant : public Student
{
public:
    string name;
    int age;
};

int main()
{
    //cout << "STATIC CAST" << endl;
    //double val = 3.2;
    //cout << val << endl;
    //cout << static_cast<int>(val) << endl;
    //cout << (int)val << endl;
    //cout << "_______________________________________" << endl;

    //cout << "DYNAMIC CAST" << endl;
    //Student student;
    //student.name = "Student";
    //cout << student.name << endl;

    //Aspirant aspirant;
    //aspirant.name = "Aspirant";
    //aspirant.age = 23;
    //cout << aspirant.name << "\tAge: " << aspirant.age << endl;

    //cout << dynamic_cast<Student*>(&aspirant) << endl;
    //cout << "_______________________________________" << endl;

    //cout << "CONST CAST" << endl;
    ////const int* v;
    ////int* temp;
    ////temp = const_cast<int*>(v);
    ////*temp = *v++;
    //cout << "_______________________________________" << endl;

    //cout << "REINTREPRET CAST" << endl;
    //int x;
    //const char* str = "dsfsfd";
    //cout << str << endl;
    //x = reinterpret_cast<int>(str);
    //cout << x << endl;
    //cout << "_______________________________________" << endl;


    cout << "_______________________________________" << endl;

    vector<int> vect;
    cout << "Number of elements: " << vect.capacity() << endl;
    cout << "Number of elements in vector: " << vect.size() << endl;
}