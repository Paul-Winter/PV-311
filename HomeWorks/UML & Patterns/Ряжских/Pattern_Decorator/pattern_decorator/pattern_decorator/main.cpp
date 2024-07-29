//
//  main.cpp
//  pattern_decorator
//
//  Created by Jaroslav on 28.07.2024.
//

#include <iostream>
#include <memory>
using namespace std;

class Additive
{
public:
    virtual void additive_for_burger()=0;
    virtual ~Additive()
        {

        };
};

class spicedAdditive : public Additive
{
public:
    void additive_for_burger ()override
    {
        cout<<"been added cook burger spiced souce"  << endl;
    }

};

class HolopenioAdditive : public Additive
{
public:
    void additive_for_burger ()override
    {
        cout<<"been added cook burger holopenio"  << endl;
    }

};
class CheeseAdditive : public Additive
{
public:
    void additive_for_burger ()override
    {
        cout<<"been added cook burger cheese"  << endl;
    }

};

class Barbeque_souceAdditive : public Additive
{
public:
    void additive_for_burger ()override
    {
        cout<<"been added cook burger barbeque souce"  << endl;
    }

};

class OnionAdditive : public Additive
{
public:
    void additive_for_burger ()override
    {
        cout<<"been added cook burger onion"  << endl;
    }

};

class Marinaded_cucumberAdditive : public Additive
{
public:
    void additive_for_burger ()override
    {
        cout<<"been added cook burger marinaded cucumber "  << endl;
    }

};


class CookBurger // based class for base
{
public:
    virtual void cook ()=0;
    virtual ~CookBurger()
        {

        };
};

class SimpleBurger : public CookBurger
{
    unique_ptr<Additive> Add_some_ingridient; // указатель на базовый класс Additive(добавки)

public:
    SimpleBurger(unique_ptr<Additive> addptr) : Add_some_ingridient{addptr.release()}//функция relise возвращает внутренний  указатель из addptr в Add_some_ingridient
    {

    }

    void cook()override
    {
        cout<<"cook burger with meet" << endl;
        Add_some_ingridient->additive_for_burger();
    }
};

class FishBurger : public CookBurger
{unique_ptr<Additive> Add_some_ingridient; // указатель на базовый класс Additive(добавки)
    
public:
    FishBurger(unique_ptr<Additive> addptr) : Add_some_ingridient{addptr.release()}//функция relise возвращает внутренний  указатель из addptr в Add_some_ingridient
    {

    }

    void cook()override
    {
        cout<<"cook burger with fish" << endl;
        Add_some_ingridient->additive_for_burger();
    }
    
};
class ChickenBurger : public CookBurger
{unique_ptr<Additive> Add_some_ingridient; // указатель на базовый класс Additive(добавки)
    
public:
    ChickenBurger(unique_ptr<Additive> addptr) : Add_some_ingridient{addptr.release()}//функция relise возвращает внутренний  указатель из addptr в Add_some_ingridient
    {

    }

    void cook()override
    {
        cout<<"cook burger with chicken" << endl;
        Add_some_ingridient->additive_for_burger();
    }
    
};








int main()
{
    SimpleBurger burger1(make_unique<HolopenioAdditive>());
    SimpleBurger burger2(make_unique<OnionAdditive>());
    SimpleBurger burger3(make_unique<CheeseAdditive>());
    FishBurger burger(make_unique<OnionAdditive>());
    ChickenBurger burger0 (make_unique<HolopenioAdditive>());
    ChickenBurger burger4 (make_unique<Barbeque_souceAdditive>());
    FishBurger burger5 (make_unique<Marinaded_cucumberAdditive>());
    
    burger1.cook();
    burger2.cook();
    burger.cook();
    burger0.cook();
    burger3.cook();
    burger4.cook();
    burger5.cook();

    return 0;
}



