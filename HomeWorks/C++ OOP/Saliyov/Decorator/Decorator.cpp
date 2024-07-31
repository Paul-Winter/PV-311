#include <iostream>
using namespace std;
class Burger
{
public:
   string name; 
   virtual int Price() = 0;
   Burger(string name)
   {
       this->name = name;
   };
   Burger()
   {};
    
private:
    
};
class DoubleBurger : Burger
{
private:

public:
    DoubleBurger(string name)
    {
        this->name = "DoubleBurger";
    };
    
    int Price()  override
    {
        return 7;
    };

};

class CheeseBurger : Burger
{
public:
    CheeseBurger(string name)
    {
        this->name = "CheeseBurger";
    };
   
   int Price() override
   {
       return 3;
   };
};
class BurgerDecorator : Burger
{
public:
    //Burger burger;
    int Price() = 0;  
    BurgerDecorator(Burger burger, string name) : Burger (name)
    {
        //this->burger = burger;
    };
};
class Sauce : BurgerDecorator
{
public:
    int Price() override
    {
       //return burger.Price() + saucecoast;
    };
};

class Sauce : BurgerDecorator
{
public:
    int Price() override
    {
        //return burger.Price() + saucecoast;
    };
};
int main()

{
    std::cout << "Hello World!\n";
}
