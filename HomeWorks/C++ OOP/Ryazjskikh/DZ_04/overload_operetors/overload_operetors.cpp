

#include <iostream>
#include<fstream>
using namespace std;

class point
{
private:

    int x;
    int y;


public:
    point()
    {

    }

    point(int x, int y) : x{ x = 0 }, y{ y = 0 }
    {

    }
    point operator+(const point& link)
    {
        point temp;
        temp.x = this->x + link.x;
        temp.y = this->y + link.y;

        return temp;


    }
    point operator-(const point& link)
    {
        point temp;
        temp.x = this->x - link.x;
        temp.y = this->y - link.y;

        return temp;


    }

    point& operator++ ()
    {
        this->x++;
        this->y = this->y + 1;
        return *this;
    }

    point& operator++ (int)// постфикный
    {
        point temp(*this);
        this->x++;
        this->y++;
        return *this;
    }
    point& operator-- ()
    {
        this->x--;
        this->y = this->y - 1;
        return *this;
    }

    point& operator-- (int)// постфикный
    {
        point temp(*this);
        this->x--;
        this->y--;
        return *this;
    }

    bool operator ==(const point& link)
    {
        if (this->x == link.x && this->y == link.y)
        {
            return true;
        }

        else
        {
            return false;
        }

    }

    bool operator !=(const point& link)
    {
        return this->x != link.x && this->y != link.y;


    }

    bool operator <(const point& link)
    {
        return this->x < link.x && this->y < link.y;


    }

    bool operator >(const point& link)
    {
        return this->x > link.x && this->y > link.y;


    }


    friend ostream& operator<<(ostream& os, const point& pt)
    {
        os << pt.x << " " << pt.y;
        return os;
    }

    friend istream& operator>>(istream& is, point& pt)
    {

        is >> pt.x >> pt.y;
        return is;
    }
    ~point()
    {

    }


    ///     *,/ не вижу смысла писать, все по аналогии
    //      

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    void setX(int value_x)
    {
        this->x = value_x;
    }
    void setY(int value_y)
    {
        this->y = value_y;
    }
    void display_point()
    {
        cout << x << " " << y << endl;
    }



};

class for_overload_index // в этом классе перегружен оператор индексирования []
{
private:

    int mass[5] = { 12,13,14,15,16 };

public:

    int& operator[](int index)
    {
        return mass[index];
    }


};

class myClass///// в этом классе перегружен оператор присваивания
{
private:
    int* data;
    int size;



public:
    myClass(int size)
    {
        this->size = size;
        this->data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }

        cout << "adress " << this << " constructor" << endl;
    }

    myClass(const myClass& link)// явный конструктор копирования
    {
        cout << "adress " << this << " constructor of copy" << endl;
        this->size = link.size;
        this->data = new int[link.size];
        for (int i = 0; i < link.size; ++i)
        {
            this->data[i] = link.data[i];
        }


    }

    myClass& operator= (const myClass& link)
    {
        cout << "adress " << this << " operator=" << endl;
        if (this->data != nullptr)
        {
            delete[] this->data;
        }
        this->size = link.size;
        this->data = new int[link.size];
        for (int i = 0; i < link.size; ++i)
        {
            this->data[i] = link.data[i];
        }
        return *this;


    }



    void display()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }





    void foo(myClass value) //новая переменная, вызвался конструктор копирования  неявно
    {
        cout << " function foo" << endl;
        //cout << value;

    }

    myClass foo2()
    {
        cout << " function foo2" << endl;
        myClass temp(2); ////новая переменная, вызвался конструктор копирования  неявно
        return temp;
    }

    ~myClass()
    {

        cout << "adress " << this << " destructor" << endl;
        delete[] data;
    }






};



int main()
{
    myClass a(10);
    myClass b(a);
    myClass c(0);

    //b = a;
   // a.operator=(b);
    c = b = a;

    // a.display();
     //b.display();
     //c.display();

    point x(10, 20);
    point y(30, 40);
    point z = x + y;
    point w = x - y;



    bool result = x == y;
    cout << "bool result=  " << result << endl;
    bool result2 = x != y;
    cout << "bool result=  " << result2 << endl;


    for_overload_index m;
    cout << "index= " << m[3] << endl;



    string path = "myFile.txt";

    point pt;
    pt.setX(133);
    pt.setY(566);
    cout << "overload << " << pt << endl;

    fstream file;
    file.open(path, fstream::in | fstream::out | fstream::app);
    if (!file.is_open())
    {
        cout << "error opening file!" << endl;
    }
    else
    {
        cout << "file is open!" << endl;
        //file << pt << "\n";

        point p;
        file >> p;
        cout << p << endl;

    }
    file.close();




    /*x.setX(100);
    x.setY(200);
    x.display_point();*/







    // myClass b(2);
     //a.foo(a);
    // a.foo2();




}
