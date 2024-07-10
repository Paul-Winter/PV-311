// DJO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


using namespace std;

class DJO
{
public:
    
    bool trig;
    
    string setSymbol()
    {
        srand(time(NULL));
        char a[3][3];
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                a[i][j] = rand() % (4 + 1 - 0) + 1;
                cout << a[i][j];
            }
            cout << endl;
        }
        if (a[0][0] == a[0][1] && a[0][0] == a[0][2] || a[1][0] == a[1][1] && a[1][0] == a[1][2] || a[2][0] == a[2][1] && a[2][0] == a[2][2] || a[0][0] == a[1][0] && a[0][0] == a[2][0] || a[0][1] == a[1][1] && a[0][1] == a[2][1] || a[0][2] == a[1][2] && a[0][2] == a[2][2]
          || a[0][0] == a[1][1] && a[0][0] == a[2][2] || a[0][3] == a[1][2] && a[0][3] == a[3][0])
        {
            cout << "WIN";
        } else cout << "You've lost, try again";
     
             return 0;
    }
    
};


int main()
{
    
    DJO a;
    a.setSymbol();

}

