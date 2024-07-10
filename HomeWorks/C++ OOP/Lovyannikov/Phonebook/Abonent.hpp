#pragma once
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
#undef strcpy
#define strcpy(dest, src)


class Abonent
{
private:
    const size_t name_size=128;
    const size_t info_size=1024;
    char* name = nullptr;
    char* info = nullptr;
    size_t mobile_number;
    size_t home_number;
    size_t work_number;
public:
    explicit Abonent(const char* const name,const char* const info,
                     size_t mobile_number,size_t home_number,size_t work_number);
    Abonent(const char* const name,const char* const info,
            size_t mobile_number,size_t home_number);
    Abonent(const char* const name,const char* const info,
            size_t mobile_number);
    Abonent(const char* const name,const char* const info);
    Abonent(const char* const name,int mobile_number);
    Abonent(const char* const name);
    Abonent();
    
    ~Abonent();
    void PrintAbonent();
    
    void SetName(const char* name);
    void SetInfo(const char* info);
    
    void SetMobileNumber(size_t mobile_number);
    void SetHomeNumber(size_t home_number);
    void SetWorkNumber(size_t work_number);
    
    char* GetName();
    const char* GetName() const;
    char* GetInfo();
    const char* GetInfo() const;
    
    size_t GetMobileNumber();
    size_t GetHomeNumber();
    size_t GetWorkNumber();
    size_t GetMobileNumber()const;
    size_t GetHomeNumber()const;
    size_t GetWorkNumber()const;
};

