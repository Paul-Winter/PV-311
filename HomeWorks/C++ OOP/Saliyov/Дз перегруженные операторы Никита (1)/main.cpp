#include <iostream>
using namespace std;
class String {
private:
  size_t size;
  char* str;
public:

 String() : String(80)
  {

  }

  String(size_t size) : size{ size }, str{ size == SIZE_MAX ? new char[80] : new char[this->size + 1] }
  {

  }

  explicit String(const char* const str) : String(strnlen(str, SIZE_MAX))
  {
    if (size != SIZE_MAX)
    {
      this->size++;
      strcpy(this->str, str);
    }
  }

  const String operator+ (const String& add)
  {
    String s(this->size + add.size);
    
    strcpy(s.str, this->str);
    
    for (size_t i = size-1; i < this->size + add.size; ++i)
    {
      s.str[i] = add.str[i - this->size + 1];
    }
      
    return s;
  }

  const String &operator= (const String& copy)
  {
    delete str;
    this->size = copy.size;
    this->str = new char[this->size];
    
    return *this;
  }


   bool setString(const char* const str)
  {
    size_t newSize = strnlen(str, SIZE_MAX);

    if (newSize != SIZE_MAX)
    {
      this->size = newSize + 1;
      delete[] this->str;
      this->str = new char[size];
      strcpy(this->str, str);
      return true;
    }
    else
    {
      return false;
    }
  }

  char* const getStr()
  {
    return str;
  }

  void input(const char* const str)
  {
    setString(str);
  }

  void display()
  {
    cout << this->str;
  }


  String(const String& copy) : String (copy.size)
  {
    strcpy(this->str, copy.str);
  }

  ~String()
  {
    delete[] str;
  }

};

int main()
{
  String a("qwer");
  String b{"wew"};
  a + b;
    //a.display();
  String rez = a + b;
  rez.display();
};
