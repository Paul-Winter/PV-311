#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Abonent.h"
using namespace std;
Abonent::Abonent(const char* const name, const char* const info,
    size_t mobile_number, size_t home_number, size_t work_number) : name{ new char[name_size] }, info{ new char[info_size] }, mobile_number{ mobile_number }, home_number{ home_number }, work_number{ work_number }
{
    if (name != nullptr) {
        strcpy_s(this->name,name_size, name);
    }
    else {
        this->name = nullptr;
    }
    if (info != nullptr) {
        strcpy_s(this->info,info_size, info);
    }
    else {
        this->info = nullptr;
    }
}
Abonent::Abonent(const char* const name, const char* const info,
    size_t mobile_number, size_t home_number) : Abonent(name, info, mobile_number, home_number, 0)
{}
Abonent::Abonent(const char* const name, const char* const info,
    size_t mobile_number) : Abonent(name, info, mobile_number, 0, 0)
{}
Abonent::Abonent(const char* const name, const char* const info) : Abonent(name, info, 0, 0, 0)
{}
Abonent::Abonent(const char* const name, int mobile_number) : Abonent(name, nullptr, mobile_number, 0, 0)
{}
Abonent::Abonent(const char* const name) : Abonent(name, nullptr, 0, 0, 0)
{}
Abonent::Abonent()
{
    name = new char[name_size];
    info = new char[info_size];
}
Abonent::~Abonent()
{
    delete[] name;
    delete[] info;
}
void Abonent::PrintAbonent()
{
    {
        cout << "Name - "s << name << "\nInfo - "s << info << "\nMobile number: "s
            << mobile_number << "\nHome number: "s << home_number << "\nWork number: "s << work_number << endl;
    }
}
void Abonent::SetName(const char* name)
{
    if (name != nullptr)
    {
        strcpy_s(this->name, name_size, name);
    }
    else {
        this->name = nullptr;
    }
}
void Abonent::SetInfo(const char* info)
{
    if (info != nullptr)
    {
        strcpy_s(this->info, info_size, info);
    }
    else
    {
        this->info = nullptr;
    }
}
void Abonent::SetMobileNumber(size_t mobile_number)
{
    this->mobile_number = mobile_number;
}
void Abonent::SetHomeNumber(size_t home_number)
{
    this->home_number = home_number;
}
void Abonent::SetWorkNumber(size_t work_number)
{
    this->work_number = work_number;
}
char* Abonent::GetName()
{
    return name;
}
const char* Abonent::GetName() const
{
    return name;
}
char* Abonent::GetInfo()
{
    return info;
}
const char* Abonent::GetInfo() const
{
    return info;
}
size_t Abonent::GetMobileNumber()
{
    return mobile_number;
}
size_t Abonent::GetHomeNumber()
{
    return home_number;
}
size_t Abonent::GetWorkNumber()
{
    return work_number;
}
size_t Abonent::GetMobileNumber()const
{
    return mobile_number;
}
size_t Abonent::GetHomeNumber()const
{
    return home_number;
}
size_t Abonent::GetWorkNumber()const
{
    return work_number;
}

const Abonent& Abonent::operator=(const Abonent& f)
{
    delete[] this->name;
    delete[] this->info;
    this->name = new char[name_size];
    this->info = new char[info_size];
    // TODO strcpy
    this->name = f.name;
    this->info = f.info;
    this->mobile_number = f.mobile_number;
    this->home_number = f.home_number;
    this->work_number = f.work_number;
    
    return *this;
}

bool Abonent::operator==(const Abonent& f)
{
    if (this->name == f.name && this->info == f.info && 
        this->mobile_number == f.mobile_number &&
        this->home_number == f.home_number &&
        this->work_number == f.work_number)
    {
        return true;
    }
    else
    {
        return false;
    }
}






