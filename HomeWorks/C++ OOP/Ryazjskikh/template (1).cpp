// template.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

template<typename T>
class massive
{
private:
    T size;
    T* mass;

public:
    massive(T size, T mass):size{size},mass{new T[size]} {}   

    void display()
    {
        for (T i = 0; i < size; ++i)
        {
            cout << mass[i]<<" ";
        }
        cout << endl;
    }

    void fill_mass()
    {
        cout << "input massive element: " << endl;
        for (T i = 0; i < size; ++i)
        {
            cin >> mass[i];
        }
    }
   
    T return_minmax_average()
    {
        int select = 0;
        cout << "1-min" << endl;
        cout << "2-max" << endl;
        cout << "3-average" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
        {
            T min = mass[0];
            for (T i = 0; i < size; ++i)
            {
                min = mass[i] < min ? mass[i] : min;
            }
            cout << "min = "<<min << endl;
            return min;
        }
        case 2:
        {
            T max = 0;
            for (T i = 0; i < size; ++i)
            {
                max = max < mass[i] ? mass[i] : max;

            }
            cout << "max = " << max << endl;
            return max;
        }
        case 3:
        {
            T average = 0;
            for (T i = 0; i < size; ++i)
            {
                average += mass[i];

            }
            average = average / size;
            cout << "average = " << average << endl;
            return average;
        }
        }
    }

    ~massive()
    {
        delete[] mass;
    }
};

int main()
{
    int Size;
    cout << "input size of massive" << endl;
    cin >> Size;
    massive<int>a(Size, 0);
    a.fill_mass();
    a.display();
    cout << a.return_minmax_average();    
}