//
//  main.cpp
//  DZ_10
//
//  Created by Jaroslav on 03.07.2024.
//

#include <iostream>
using namespace std;

class Employer
{
public:
    
    virtual void print() =0;
};

class President: public Employer
{
public:
    void print () override
    {
    cout<<"working hard all peasant!"<<endl;;
    }
    
};
class Manager: public Employer
{
public:
    void print() override
    {
    cout<<"working hard all workers!"<<endl;;
    }
    
};
class Worker: public Employer
{
public:
void print() override
    {
    cout<<"yes, of corse!"<<endl;
    }
};
class Cheliki
{
public:
    void print(Employer *say)
    {
    say->print();
    }
};

int main()
{
    President method1;
    Manager method2;
    Worker method3;
    Worker peasant;
    Cheliki everybody;
    //method1.print();
    //method2.print();
    //method3.print();
    everybody.print(&method1);
    
}
