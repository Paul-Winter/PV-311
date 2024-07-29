
#include <iostream>
using namespace std;
//int picklescoast = 5;

class Burger {
public:
	string name;
	int price;
	Burger() {}
	Burger(string name) :name{ name }
	{

	}
	~Burger(){}
	virtual string RenameBurger() = 0;
	virtual int Price() = 0;
};

class Cheeseburger : Burger//public
{
public:

	Cheeseburger(): Burger("Cheeseburger")
	{
	}
	int Price() override {
		return price=7;
	}
	
};

class Wopper : Burger//public
{
public:

	Wopper() :Burger("Wopper")
	{
	}

	string RenameBurger() override {
		return name;
	}

	int Price() override {
		return price=9;
	}
	
};

class Decorator : public Burger
{
private:
	Burger* burger;
public:
	Decorator();
	Decorator(Burger* burger) 
	{
		this->burger = burger;
	}

	string RenameBurger() override {
		burger->RenameBurger();
	}

	int Price() override {
		burger->Price();
	}
	void SetBurger(Burger* burger) {
		cout << Price() << endl;
		cout << RenameBurger() << endl;
	}

};

class Pickles : public Decorator
{
public:
	
	Pickles();
	Pickles(Burger* burger);

	void SetBurger(Burger* burger) {
		cout << Price() << endl;
		cout << RenameBurger() << endl;
	}

	int Price() override 
	{
		return this->Price() + 3;
	}
	
	string RenameBurger() override {
		return RenameBurger() + " + Pickles";
	}
};


int main()
{
	Cheeseburger *king();
	Pickles* p();
	
	p->SetBurger((Burger*)king);

	
	


}
