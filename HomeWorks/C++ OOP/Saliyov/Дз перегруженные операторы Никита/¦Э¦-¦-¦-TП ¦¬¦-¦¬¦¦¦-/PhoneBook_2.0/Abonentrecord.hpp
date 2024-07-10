//
//  Abonentrecord.hpp
//  PhoneBook_2.0
//
//  Created by Nikita on 20.05.2024.
//

#ifndef Abonentrecord_hpp
#define Abonentrecord_hpp

#include <stdio.h>
//#include "PhoneBook.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class Abonentrecord
{
public:
    const size_t  maxSizeAbonentName = 128;
    const size_t maxSizeInformation = 1024;
    char* abonentName = nullptr;
    uint64_t mobileNumber;
    uint64_t homeNumber;
    uint64_t workNumber;
    char* information = nullptr;

    Abonentrecord();
    
    Abonentrecord(const char* const abonentName_f, uint64_t mobileNumber_f = 0,
        uint64_t homeNumber_f = 0, uint64_t workNumber_f = 0, const char* const information_f = nullptr);
    
    
    Abonentrecord(const Abonentrecord & copy) : Abonentrecord (copy.abonentName, copy.mobileNumber, copy.homeNumber, copy.workNumber, copy.information)
    {
        
    }
    
    const Abonentrecord &operator= (const Abonentrecord &copy)
    {
        delete [] abonentName;
        delete [] information;
        this->abonentName = new char[maxSizeAbonentName];
        strcpy(this->abonentName, copy.abonentName);
        this->information = new char[maxSizeInformation];
        strcpy(this->information,copy.information);
        this->mobileNumber = copy.mobileNumber;
        this->homeNumber = copy.homeNumber;
        this->workNumber = copy.workNumber;
        
        return *this;
    }

    ~Abonentrecord();

    void setName(const char* const abonentName_f);
    char* setName1(const char* const abonentName_f);
    void setinformation(const char* const information_f);
    
    void setmobNumber(uint64_t mobileNumber_f);
    void sethomeNumber(uint64_t homeNumber_f);
    void setworkNumber(uint64_t workNumber_f);
    const char* const getName();
    const char* const getinformation();
    uint64_t getmobNumber();
    uint64_t gethomeNumber();
    uint64_t getworkNumber();
    void displayAbonent();

    //void findAbonent(char* abonentName_find);
};


#endif /* Abonentrecord_hpp */
