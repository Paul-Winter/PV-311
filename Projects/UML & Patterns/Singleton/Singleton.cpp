#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton* Instance;
protected:
    Singleton();
public:
    static Singleton* getInstance();
};

    Singleton* Singleton::Instance = 0;
    Singleton* Singleton::getInstance() 
    {
        if (Instance==0) 
        {
            Instance = new Singleton;
        }
        return Instance;
    }
int main()
{
    Singleton* a = Singleton::getInstance();
    cout << a;
    Singleton* b = Singleton::getInstance();
    //cout << a == b;
}

