#include <iostream>
using namespace std;

template<typename S>
class massive
{
private:
    S size;
    S* arr;

public:
    massive(S size, S mass):size{size},arr{new S[size]}{}
    void display(){
        for (S i = 0; i < size; ++i)
        {
            cout << arr[i]<<" ";
        }
        cout << endl;
    }
    void fill_mass(){
        cout << "input massive element: " << endl;
        for (S i = 0; i < size; ++i)
        {
            cin >> arr[i];
        }
    }
    S return_minmax_average(){
        int select = 0;
        cout << "1-min" << endl;
        cout << "2-max" << endl;
        cout << "3-average" << endl;
        cin >> select;
        switch (select){
        case 1:{
            S min = arr[0];
            for (S i = 0; i < size; ++i){
                min = arr[i] < min ? arr[i] : min;
            }
            cout << "min = "<<min << endl;
            return min;
        }
        case 2:{
            S max = 0;
            for (S i = 0; i < size; ++i){
                max = max < arr[i] ? arr[i] : max;
            }
            cout << "max = " << max << endl;
            return max;

        }
        case 3:{
            S average = 0;
            for (S i = 0; i < size; ++i){
                average += arr[i];
            }
            average = average / size;
            cout << "average = " << average << endl;
            return average;
        }
        }
    }
    ~massive(){
        delete[] arr;
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
