// виртуальные функции.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//абстрактный базовый класс
class Pets
{

	
public:
	string title;
	Pets()
	{}
	Pets(string title) : title{title}
	{}
	virtual void Speak() = 0;//чисто виртуальная функция
	~Pets()
	{}
};

class Dog : public Pets
{
public:
	Dog()
	{}
	Dog(string title) : Pets(title)
	{}
	virtual void Speak()
	{
		cout << title << " say: 'gav-gav' " << endl;
	}
	~Dog()
	{}

};

class Cat : public Pets
{
public:
	Cat()
	{}
	Cat(string title): Pets(title)
	{}
	virtual void Speak()
	{
		cout << title << " say: 'miy-miy' " << endl;
	}

	~Cat()
	{}

};

class Lion : public Cat
{
protected:
	string color;
public:
	Lion()
	{}
	Lion(string title, string color) : Cat(title)
	{
		this->color = color;
	}
	 void Speak() 
	{
		
		cout << title << " color: " << color << " say: 'rrrrrr' " << endl;
	}
	~Lion()
	{}
};

int main()
{
	Pets* a;

	Dog b("Marta");
	a = &b;
	b.Speak();

	Cat c("Myrka");
	a = &c;
	c.Speak();
	
	
	Lion k("Simba","orange");
	a = &k;
	k.Speak();
	c = k;
	c.Speak();
	
}

