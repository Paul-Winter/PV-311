// ConsoleApplicationFPKASKPFPSP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Vector2 {
    float x, y;
    Vector2& operator+=(Vector2 const& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2& operator-=(Vector2 const& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};
Vector2 operator+(Vector2 a, Vector2 const& b) {
    // note 'a' is passed by value and thus copied
    a += b;
    return a;
}
Vector2 operator-(Vector2 a, Vector2 const& b) { return a -= b; }