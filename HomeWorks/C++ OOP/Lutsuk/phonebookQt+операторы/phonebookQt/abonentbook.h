#pragma once

#ifndef ABONENTBOOK_H
#define ABONENTBOOK_H
#include <iostream>
#include "abonent.h"

class AbonentBook : Abonent
{
    size_t AbBook_Size=100;
    Abonent* AbBook{new Abonent[AbBook_Size]};
    size_t AbonCounter=0;

public:

    AbonentBook(const size_t AbBook_Size);
    AbonentBook();
    ~AbonentBook();
    explicit AbonentBook(const AbonentBook& copy);
    AbonentBook operator +(const AbonentBook second);
    AbonentBook& operator =(const AbonentBook &s);
    bool operator < (const Abonent& s);
    bool operator > (const AbonentBook& s);


    void setSize(const size_t Ab_SizeBuf);
    const size_t getSize();
    Abonent* setAbBook(const Abonent* const AbBookBuf);
    void getAbBook();
    void AddAbonent(const chsr*  const AbonentName, const char* const Information,
    const size_t HomeNumber, const size_t WorkNumber);
    explicit void findAbon(const char* const AbonentNameFind);
    explicit void deleteAbon(const char * const AbonentNameDel);
    void displayAbon(const char* const NameDisplay);
    size_t getAbonCounter() const;
    void setAbonCounter(size_t newAbonCounter);
};

#endif // ABONENTBOOK_H
