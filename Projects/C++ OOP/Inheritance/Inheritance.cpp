#include <iostream>
#include <string.h>
using namespace std;

// aggregation
class Point
{
protected:
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
        cout << "\ncreate Point\n" << endl;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    ~Point()
    {
        cout << "\ndelete Point\n" << endl;
    }

    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    Point GetPoint()
    {
        return Point(x, y);
    }

    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }
    void SetPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void PointInfo()
    {
        cout << "X = " << x << "\tY = " << y << endl;
    }
};

class Figure : protected Point
{
protected:
    int count;
    string color;

public:
    //Point point;
    Figure()
    {
        cout << "\ncreate Figure\n" << endl;
    }
    Figure(int count, string color, int x, int y)
    {
        this->count = count;
        this->color = color;
        //point.SetX(x);
        //point.SetY(y);
    }
    ~Figure()
    {
        cout << "\ndelete Figure\n" << endl;
    }
    void FigureInfo()
    {
        cout << "Count = " << count << "\tColor is " << color << endl;
    }
};

class Image : public Figure
{
    int r;
    int g;
    int b;

public:
    Image()
    {
        cout << "\ncreate Image\n" << endl;
    }
    ~Image()
    {
        cout << "\ndelete Image\n" << endl;
    }
};

int main()
{
    Figure triangle(3, "Red", 12, 15);
    triangle.FigureInfo();
    triangle.SetPoint(10, 12);
    cout << "\n\n" << endl;
    cout << "X = " << triangle.x << "\tY = " << triangle.GetY() << endl;

    //triangle.point.PointInfo();

    /*Image image;
    image.~Image();*/
}

