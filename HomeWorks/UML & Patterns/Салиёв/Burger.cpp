
#include <iostream>
#include <memory>
using namespace std;
class Additives
{
public:
    virtual void additive() = 0;
    virtual int check() = 0;
    virtual ~Additives() {}; 
};

class Onion : public Additives
{
public:
    void additive() override
    {
        cout << "with additive onion" << endl;      
    }
    int check() override {return 2;}; 
};

class CookBurger 
{
public:
    virtual void cook() = 0;
    virtual ~CookBurger()
    {};
};

class DoubleBurger : public CookBurger
{ 
    unique_ptr<Additives> s;
    
public:
    DoubleBurger(unique_ptr<Additives> addptr) : s{addptr.release()}
    {}
    void cook() override
    {    
        cout << "cook doubleburger " << endl;
        s->additive();
    }
    ~DoubleBurger()
    {
        cout << "Your check is: " << s->check() + 5 << "$" << endl;
    }
};
int main()
{
     DoubleBurger a (make_unique<Onion>());
     a.cook();
}

