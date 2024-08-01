#include <iostream>
using namespace std;

class Strategy
{
public:
    virtual string doAction(int weight, int speed, string model) = 0;
    Strategy()
    {};
};

class Vehicle //Context
{

private:
    Strategy* strategy;
    int weight;
    int speed;
    string model;

public:
    Vehicle(Strategy* strategy)
    {
        this->weight = weight;
        this->speed = speed;
        this->model = model;
        this->strategy = strategy;
    }
    string Moove()
    {
        return strategy->doAction(weight, speed, model);
    }

};

//Concret Strategies
class Bike : public Strategy
{
public:
    Bike()
    {}
    string doAction(int weight, int speed, string model)
    {
        return "300kg, 200km, bike";
    }
};

class Car : public Strategy
{
public:
    Car()
    {}
    string doAction(int weight, int speed, string model)
    {
        return "400kg, 250km, car";
    }
};

class Truck : public Strategy
{
public:
    Truck()
    {}
    string doAction(int weight, int speed, string model)
    {
        return "500kg, 150km, truck";
    }
};

int main()
{
    
    Vehicle* moto = new Vehicle(new Bike());
    Vehicle* small_car = new Vehicle(new Car());
    Vehicle* big_car = new Vehicle(new Truck());

    cout << moto->Moove();
    cout << '\n';
    cout << small_car->Moove();
    cout << '\n';
    cout << big_car->Moove();

    return 0;
}