#pragma once

#ifndef ABONENTBOOK_H
#define ABONENTBOOK_H
#include "abonent.h"

class AbonentBook : Abonent
{
    size_t AbBook_Size=100;
    Abonent* AbBook{new Abonent[AbBook_Size]};

public:
    size_t AbonCounter=0;
    AbonentBook(const size_t AbBook_Size);

    AbonentBook();

    ~AbonentBook();

    AbonentBook(AbonentBook &Copy):Abonent(Copy) {
        strcpy_s(AbonentName,AbonentName_size,Copy.AbonentName);
        strcpy_s(Information,Information_size,Copy.Information);
        HomeNumber=Copy.HomeNumber;
        WorkNumber=Copy.WorkNumber;
    }

    void setSize(const size_t Ab_SizeBuf);

    const size_t getSize();

    Abonent* setAbBook(const Abonent* const AbBookBuf);

    void getAbBook();

    void AddAbonent(const char*  const AbonentName, const char* const Information,
    const size_t HomeNumber, const size_t WorkNumber);

    void findAbon(const char* const AbonentNameFind);
    void deleteAbon(const char * const AbonentNameDel);
    void displayAbon(const char* const NameDisplay);
};

#endif // ABONENTBOOK_H
