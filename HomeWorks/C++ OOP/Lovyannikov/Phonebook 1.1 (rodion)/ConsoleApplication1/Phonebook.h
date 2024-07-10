#pragma once
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Abonent.h"
#include <fstream>
using namespace std;
#undef strcpy
#define strcpy(dest, src)

class Phonebook : Abonent
{
private:

public:
    Abonent* abonentList;
    size_t PhonebookSize = 100;
    size_t abonentCounter = 0;

    Phonebook(const size_t PhonebookSize = 100);
    ~Phonebook();

    void AddAbonent(const Abonent& f);
    void FindAbonent(const char* const name);
    void DeleteAbonent(int abonentId);
    void DisplayAbonent();
    bool write();
    bool read();
};
