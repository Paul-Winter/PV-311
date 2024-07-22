/* 
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай».
С помощью конструктора установить имя каждого животного и его характеристики.
Добавьте механизм виртуального наследования.*/
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pet {
public:
    Pet() = default;
    Pet(string name, string sex, string color, int age, string breed) : name_{ name }, sex_{ sex }, color_{ color }, age_{ age }, breed_{ breed } {}

    virtual ~Pet() {}
    virtual void Sound() = 0 {}
    virtual void DisplayInfo() {
        cout << "Name: "s << name_ << endl;
        cout << "Breed: "s << breed_ << endl;
        cout << "Sex: "s << sex_ << endl;
        cout << "Color: "s << color_ << endl;
        cout << "Age: "s << age_ << endl;
    }

    void SetName(string name) {
        name_ = name;
    }
    void SetSex(string sex) {
        sex_ = sex;
    }
    void SetColor(string color) {
        color_ = color;
    }
    void SetAge(int age) {
        age_ = age;
    }


    string GetName() {
        return name_;
    }
    string GetSex() {
        return sex_;
    }
    string GetColor() {
        return color_;
    }
    int GetAge() {
        return age_;
    }

private:
    string name_;
    string sex_;
    string color_;
    int age_;
    string breed_;
};

class Dog : virtual public Pet {
public:
    Dog() = default;
    Dog(string name, string sex, string color, int age, string breed) : Pet (name, sex, color, age, breed) {
        breed_ = breed;
    }
    ~Dog() {}

    void Sound() {
        cout << "The dog says \"Woof!\""s << endl;
    }

    void SetBreed(string breed) {
        breed_ = breed;
    }

    void DisplayInfo() {
        Pet::DisplayInfo();
    }

private:
    string breed_;
};

class Humster : virtual public Pet {
public:
    Humster() = default;
    Humster(string name, string sex, string color, int age, string breed) : Pet(name, sex, color, age, breed) {
        breed_ = breed;
    }
    ~Humster() {}

    void Sound() {
        cout << "The humster says \"furfurfur!\""s << endl;
    }

    void SetBreed(string breed) {
        breed_ = breed;
    }

    void DisplayInfo() {
        Pet::DisplayInfo();
    }

private:
    string breed_;
};

class Cat : virtual public Pet {
public:
    Cat() = default;
    Cat(string name, string sex, string color, int age, string breed) : Pet(name, sex, color, age, breed) {
        breed_ = breed;
    }
    ~Cat() {}

    void Sound() {
        cout << "The cat says \"Meow-meow!\""s << endl;
    }

    void SetBreed(string breed) {
        breed_ = breed;
    }

    void DisplayInfo() {
        Pet::DisplayInfo();
    }

private:
    string breed_;
};


int main()
{
    setlocale(LC_ALL, "rus");
    Dog dog ("Alex", "male", "black", 3, "staffordshire terrier");
    dog.DisplayInfo();
    dog.Sound();
    cout << endl;
    Cat cat("Murka", "female", "white", 7, "regular");
    cat.DisplayInfo();
    cat.Sound();
    cout << endl;

}
