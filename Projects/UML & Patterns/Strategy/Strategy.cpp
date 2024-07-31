#include <iostream>
using namespace std;

class Strategy // Strategy
{
public:
    virtual string Parametr(int Weight,int Max_speed,string Model) = 0;
protected:
    Strategy()
    {};
};

class Vehicle // Context
{
public:
    Vehicle(Strategy* strategy)
    {
        this->strategy = strategy;
    };
    string Moove()
    {
        return strategy->Parametr(Weight, Max_speed, Model);
    };
private:
    Strategy* strategy;
    int Weight;
    int Max_speed;
    string Model;
};

class Bike : public Strategy
{
public:
    Bike() {};
    string Parametr(int Weight, int Max_speed, string Model)
    {
        return "400 kg 250km/h Blackbird\n";
    };
};

class Car : public Strategy
{
public:
    Car() {};
    string Parametr(int Weight, int Max_speed, string Model)
    {
        return "1200 kg 200km/h Vesta\n";
    };
};

class Truck : public Strategy
{
public:
    Truck() {};
    string Parametr(int Weight, int Max_speed, string Model)
    {
        return "4000 kg 60km/h Kamaz\n";
    };
};

//class Bike // ConcreteStrategy
//class Car // ConcreteStrategy
//class Truck // ConcreteStrategy

int main()
{
    Vehicle* Moped = new Vehicle(new Bike);
    Vehicle* Mashina = new Vehicle(new Car);
    Vehicle* Tyagach = new Vehicle(new Truck);

    cout << Moped->Moove();
    cout << Mashina->Moove();
    cout << Tyagach->Moove();  
}
