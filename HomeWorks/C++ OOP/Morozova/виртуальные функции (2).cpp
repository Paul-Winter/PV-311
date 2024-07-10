// виртуальные функции.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//абстрактный базовый класс
class Employer
{


public:
	string Duty;
	Employer()
	{}
	Employer(string Duty) : Duty{ Duty }
	{}
	virtual void Print() = 0;//чисто виртуальная функция
	 
    virtual ~Employer() 
	{} 

};

class Prezident : public Employer
{

	

public:
	Prezident()
	{}
	Prezident( string Duty) : Employer(Duty)
	{}
	virtual void Print() override
	{
		cout << Duty << " President must rule " << endl;
	}
	~Prezident()
	{}

};

class Manager : public Employer
{
protected:
	int Salary;
public:
	Manager()
	{}
	Manager(string Duty, int Salary): Employer(Duty)
	{
		this->Salary = Salary;
	}
	virtual void Print() override
	{
		cout << Duty << " Manager must sell,  Salary: "<<Salary << endl;
	}

	~Manager()
	{}

};

class Worker : public Manager
{
protected:
	string Uniform;
public:
	Worker()
	{}
	Worker(string Duty, int Salary, string Uniform) : Manager(Duty,Salary)
	{
		this->Uniform = Uniform;
	}
	  virtual void Print() override
	{
		
		cout << Duty << " Work ,  Salary: " <<Salary<< " Uniform: "<<Uniform << endl;
	}
	~Worker()
	{}
};

int main()
{
	Employer* Human;

	Prezident King("Karl |||");
	Human = &King;
	King.Print();

	Manager Sales("Vasya", 200);
	Human = &Sales;
	Sales.Print();
	
	
	Worker Driver("Petya",100,"Yellow");
	Human = &Driver;
	Driver.Print();
	

	
}

