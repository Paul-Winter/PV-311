#pragma once
#ifndef ABONENT_H
#define ABONENT_H
#include <iostream>
#include <cstring>
using namespace std;

class Abonent {
    char* AbonentName = nullptr;
    char* Information = nullptr;
    const size_t AbonentName_size = 256;
    const size_t Information_size = 1024;
    uint64_t HomeNumber;
    uint64_t WorkNumber;

    public:
    Abonent();
    //set, копирует строку, через stpcpy_s, а так же другие параметры
    Abonent(const char* const NameNew, uint64_t HomeNumberNew=0, uint64_t WorkNumberNew=0,const char* const InformationNew);
    ~Abonent();
    explicit Abonent(const Abonent& copy);
    Abonent& operator=(const Abonent& s);

    void setHomeNum(const uint64_t HomeNumberNew);
    void setWorkNum(const uint64_t WorkNumberNew);
    void setName(const char* const NameNew);
    void setInf(const char* const InformationNew);
    const char* const getName();
    const char* const getInf();
    int getHomeNum();
    int getWorkNum();
};
#endif // ABONENT_H
