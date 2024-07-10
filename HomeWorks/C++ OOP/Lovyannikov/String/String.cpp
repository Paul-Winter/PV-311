#include "String.hpp"
String::String() : String(80)
{

}

String::String(const size_t size) : size{ size }, str{new char[size]},realsize{0}
{
    str[0] = '\0';
}

String::String(const char* const str) : size{strnlen(str, SIZE_MAX) }
{
     
    

    if (size != SIZE_MAX)
     {
         this->str = new char[size];
         realsize = size;
     }

     else
     {
         String(80);
     }
}

String::String(const String& f):size{f.size}, str{ new char[f.size] } , realsize{f.realsize}
{
    strcpy_s(this->str, this->size, f.str);
}

void String::zap()
{

    cin.getline(str, size);
}

void String::print()
{
    cout << str << endl;
}

String::~String()
{
    delete[] str;
}
