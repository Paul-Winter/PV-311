#include <iostream>

#define SIMPLE

using namespace std;

class Shape { //Форма
public:
    Shape() {
        id_ = total_++;
    }
    virtual void draw() = 0;
protected:
    int id_;
    static int total_;
};
int Shape::total_ = 0;

class Circle : public Shape { //Окружность
public:
    void draw() override {
        cout << "circle " << this->id_ << ": draw" << endl;
    }
};
class Square : public Shape { //Квадрат
public:
    void draw() override {
        cout << "square " << this->id_ << ": draw" << endl;
    }
};
class Ellipse : public Shape { //Элипс
public:
    void draw() override {
        cout << "ellipse " << this->id_ << ": draw" << endl;
    }
};
class Rectangle : public Shape { //Прямоугольник
public:
    void draw() override {
        cout << "rectangle " << this->id_ << ": draw" << endl;
    }
};

class Factory {
public:
    virtual Shape* createCurvedInstance() = 0; //Ellipse и Circle
    virtual Shape* createStraightInstance() = 0; //Rectangle и Square 
};

class SimpleShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() override {
        return new Circle;
    }
    Shape* createStraightInstance() override {
        return new Square;
    }
};
class RobustShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() {
        return new Ellipse;
    }
    Shape* createStraightInstance() {
        return new Rectangle;
    }
};

int main() {
#ifdef SIMPLE
    Factory* factory = new SimpleShapeFactory;
    Shape* shapes[3];

    shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Circle;
    shapes[1] = factory->createStraightInstance(); // shapes[1] = new Square;
    shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Circle;

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
    }

#elif ROBUST
    Factory* factory = new RobustShapeFactory;

    Shape* shapes[3];

    shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
    shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
    shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
    }
#endif
    
}