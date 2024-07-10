#include "abonent.h"

using namespace std;


Abonent::Abonent(const char * const NameNew, uint64_t HomeNumberNew, uint64_t WorkNumberNew, const char * const InformationNew)
    : NameNew{new char[AbonentName_size]}, InformationNew{new char[Information_size]}
{
    strcpy_s(AbonentName,AbonentName_size,NameNew);
    strcpy_s(Information,Information_size,InformationNew);

    HomeNumber=HomeNumberNew;
    WorkNumber=WorkNumberNew;
}

Abonent::Abonent()
{
    AbonentName {new char [AbonentName_size]};
    Information {new char [Information_size]};
}

Abonent::~Abonent()
{
    delete[]AbonentName;
    delete[]Information;
}

void Abonent:: setHomeNum(const uint64_t HomeNumberNew)
{
    HomeNumber=HomeNumberNew;
}

void Abonent:: setWorkNum(const uint64_t WorkNumberNew)
{
    WorkNumber=WorkNumberNew;
}

void Abonent :: setName(const char* const NameNew)
{
    strcpy_s(AbonentName,AbonentName_size,NameNew);
}

void Abonent :: setInf(const char* const InformationNew)
{
    strcpy_s(Information,Information_size,InformationNew);
}

const char* const Abonent :: getName()
{
    return AbonentName;
}

const char* const Abonent::getInf()
{
    return Information;
}

int Abonent:: getHomeNum()
{
    return HomeNumber;
}

int Abonent :: getWorkNum()
{
    return WorkNumber;
}

















