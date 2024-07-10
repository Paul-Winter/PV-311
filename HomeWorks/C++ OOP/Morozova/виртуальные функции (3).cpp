// виртуальные функции.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

namespace Person
{
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
	{
		cout << "Prezident deleted" << endl;
	}
	void Point() //внутри функции находится только передача информации об ошибке
	{
		throw "Point Error";//генерирует исключение
	}

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
	void Sell() noexcept
	{
		cout << " More Sell" << endl;
	}
	double Divide(int a, int b)
	{
		if (b)
			return a / b;
		throw " Division by zero!";
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
	  void Work()//генерация исключения внутри  функции
	  {
		  int a, b;

		  try
		  {
			  cout << "Input a: \n";
			  cin >> a;
			  cout << "Input b: \n";
			  cin >> b;
			  if (b == 0)
				  throw "Division zerro\n ";
		  }
		  catch (char* s)
		  {
			  cout << "Error<" << s;
		  }
	  }
	  
	~Worker()
	{}
};
}
using namespace Person;

int main()
{
	Employer* Human;

    Prezident King("Karl |||");
	Human = &King;
	King.Print();
	try //инструкции, которые могут вызвать исключение
	{
		Prezident King("Karl |||");//если в блоке создаются оъекты, то вызывается деструктор
		King.Point();
	}
	catch (const char* error)//объявление исключения
	{
		cout << error << endl;//обработка исключения
	}
	cout << endl;
	

	Manager Sales("Vasya", 200);
	Human = &Sales;
	Sales.Print();
	cout<< endl;
	int x{ 100 };
	int y{};
	try
	{
		Manager Sales("Vasya", 200);
		Sales.Divide(x, y);
		
	}
	catch (...)
	{
		cout << " Error" << endl;
	}
	
	
	Worker Driver("Petya",100,"Yellow");
	Human = &Driver;
	Driver.Print();
	
	cout << endl;

	Driver.Work();
	

	
}

