// nasledovanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Vehicle
{
public:

    int weight;
    Vehicle() : Vehicle(weight) {};
    Vehicle(int weight)
    {
        this->weight = weight;
    }
    
    void disp()
    {
        cout << "This is Vehicle!" << endl;
        cout << "Weight: " << this->weight;
    }
   
};

class Car : public Vehicle
{
   
    public:
        int wheels;
       
        
        Car(int weight, int wheels) : Vehicle(weight)
        {
           
            this->wheels = wheels;
        }
        void disp()
        {
            cout << "This car! " << endl;
            cout << "Wheels " << this->wheels << endl;
            cout << "Weight: " << this->weight << endl;
        }
       
};

class Sedan : public Car
{
     
public:
    int passengers;
    Sedan(int weight, int wheels, int passengers) : Car(weight, wheels) {
       
        
        this->wheels = wheels;
        this->passengers = passengers;
        this->weight = weight;
       ;
    };
    void disp()
    {
        cout << "This sedan!" << endl;
        cout << "Wheels " << this->wheels << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "Passengers: " << this->passengers << endl;
     }
};
class Motorcycle : public Vehicle
{
private:
};

class Boat : public Vehicle
{
 private:
};


int main()
{
    Vehicle* a;

    Sedan w(1,2,2);
    w.disp();
     
    a =& w;
    a->disp();
}

