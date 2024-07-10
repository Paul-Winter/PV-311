#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class String
{
private:

    size_t size = 0;
    char* str = nullptr;
    size_t realsize = 0;

public:

    String();
    String(const size_t size);
    String(const char* const str);
    String(const String& f);
    ~String();
   
    void copy(const String& f);
    void zap();
    void print();




};
