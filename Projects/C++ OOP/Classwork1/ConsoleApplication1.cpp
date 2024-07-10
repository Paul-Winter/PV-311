#include <iostream>
#include<string>

#define e endl

using namespace std;


class myClass
{

private:
	int x;
	int y;
	int z;

public:
/*	myClass(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}*/	
	myClass(int x,int y)
	{
		this->x = x;
		this->y = y;

	}
	myClass() : myClass(0, 0) {}

	void display()
	{
		cout << x<<" " << y << endl;
	}
	void setX(int x)
	{
		this->x = x;
	}
	int getX()
	{
		return x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getY()
	{
		return y;
	}
};

int main()
{
	myClass a(1,2);
	a.display();
	myClass b;
	b.display();
	myClass c(a);
	//c.display();
	b = a;
	c.display();
	a.setX(10);
	a.setY(20);
	a.display();
	c.setX(11);
	c.setY(12);
	c.display();
	a.display();
	cout << c.getX() <<" "<< c.getY();
}