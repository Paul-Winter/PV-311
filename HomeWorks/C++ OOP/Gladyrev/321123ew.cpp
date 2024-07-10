
#include <iostream>

class Number
{
public:
    Number();
    ~Number();
    void setNumber(int n) {
        number = n;
    }

    int getNumber() {
        return number;
    }
    Number operator*(Number n2) {
        Number temp;
        temp.number = number * n2.number;
        return temp;
    }


private:
    int number;
};