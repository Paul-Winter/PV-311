//
//  Abonentrecord.cpp
//  PhoneBook_2.0
//
//  Created by Nikita on 20.05.2024.
//

#include "Abonentrecord.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <fstream>

Abonentrecord::Abonentrecord() : Abonentrecord (" ", 0, 0, 0, " ")
{

    
}

Abonentrecord::Abonentrecord(const char* const abonentName,
        uint64_t mobileNumber, uint64_t homeNumber,
                             uint64_t workNumber, const char* const information) : abonentName{ new char[maxSizeAbonentName] }, mobileNumber {mobileNumber}, homeNumber {homeNumber}, workNumber {workNumber}, information {new char[maxSizeInformation]}
{
    
    strcpy(this->abonentName, abonentName);
    //this->information = new char[maxSizeInformation];

    if (information != nullptr)
    {
        strcpy(this->information,information);
    }
}

Abonentrecord::~Abonentrecord()
{
    delete [] abonentName;
    delete [] information;
}

void Abonentrecord::setmobNumber(uint64_t mobileNumber)
{
    this->mobileNumber = mobileNumber;
}

void Abonentrecord::sethomeNumber(uint64_t homeNumber)
{
    this->homeNumber = homeNumber;
}

void Abonentrecord::setworkNumber(uint64_t workNumber)
{
    this->workNumber = workNumber;
}

const char* const Abonentrecord::getName()
{
    return abonentName;
}

const char* const Abonentrecord::getinformation()
{
    return information;
}

uint64_t Abonentrecord::getmobNumber()
{
    return mobileNumber;
}

uint64_t Abonentrecord::gethomeNumber()
{
    return homeNumber;
}

uint64_t Abonentrecord::getworkNumber()
{
    return workNumber;
}

void Abonentrecord::setName(const char* const abonentName)
{
    strcpy(this->abonentName, abonentName);
}
char* Abonentrecord::setName1(const char* const abonentName)
{
    strcpy(this->abonentName, abonentName);

    return this->abonentName;
}

void Abonentrecord::setinformation(const char* const information)
{
    strcpy (this->information, information);
}

void Abonentrecord::displayAbonent()
{
    cout << abonentName << endl;
    cout << mobileNumber << endl;
    cout << homeNumber << endl;
    cout << workNumber << endl;
    cout << information << endl;
}
