//
//  main.cpp
//  homework 24.06
//
//  Created by Nikita on 24.06.2024.
//

#include <iostream>
using namespace std;

template<typename T>
class MyClass
{
public:
    void input ()
    {
        cout << "Pls, enter quantity elements " << endl;
        cin >> quantity;
        massive[quantity];
    }
    
    void inputt ()
    {
        cout << "Pls, enter massive: " << endl;
    
        for(int i = 0; i < quantity; i++)
        {
            cin >> massive[i];
        }
    }
    
    void show ()
    {
        for(int i = 0; i < quantity; ++i)
        {
            cout << massive[i] << endl;
        }
    }
    
    T *massive;
    T temp;
    T quantity;
};


int main(int argc, const char * argv[]) 
{
    MyClass<size_t> a;
    a.input();
    a.inputt();
    a.show();
}
