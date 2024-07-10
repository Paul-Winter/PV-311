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

const char* const Abonentrecord::getName() const
{
    return abonentName;
}

const char* const Abonentrecord::getinformation() const
{
    return information;
}

uint64_t Abonentrecord::getmobNumber() const
{
    return mobileNumber;
}

uint64_t Abonentrecord::gethomeNumber() const
{
    return homeNumber;
}

uint64_t Abonentrecord::getworkNumber() const
{
    return workNumber;
}

void Abonentrecord::setName(const char* abonentName)
{
    strcpy(this->abonentName, abonentName);
}

void Abonentrecord::setinformation(const char* information)
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

bool Abonentrecord::operator== (const Abonentrecord &f)
{
    if (!strcmp(this->abonentName, f.abonentName) && !strcmp(this->information, f.information) && this->mobileNumber == f.mobileNumber && this->homeNumber == f.homeNumber && this->workNumber == f.workNumber)
    {
        return true;
    }else return false;	
  
}

bool Abonentrecord::operator!= (const Abonentrecord &f)
{
    if (!strcmp(this->abonentName, f.abonentName) && !strcmp(this->information, f.information) && this->mobileNumber == f.mobileNumber && this->homeNumber == f.homeNumber && this->workNumber == f.workNumber)
    {
        return false;
    }else return true;
  
}

bool Abonentrecord::operator< (const Abonentrecord &f)
{
    if (this->mobileNumber < f.mobileNumber)
    {
        return true;
    }else return false;
  
}

bool Abonentrecord::operator> (const Abonentrecord &f)
{
    if (this->mobileNumber > f.mobileNumber)
    {
        return true;
    }else return false;
  
}
