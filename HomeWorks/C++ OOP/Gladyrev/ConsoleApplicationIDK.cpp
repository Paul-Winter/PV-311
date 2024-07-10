// ConsoleApplicationIDK.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Person
{
    int id;
    short age;
public:
    std::string name;
    void setAge(short _age) { this->age = _age; }
    short getAge() const;
};

short Person::getAge() const
{
    return this->age;
}

const Person person(20, "Jane");
person.name = "John";    
person.setAge(30);       
std::cout << person.getAge() << std::endl;