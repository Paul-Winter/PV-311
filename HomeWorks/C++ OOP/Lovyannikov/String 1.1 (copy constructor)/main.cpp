#include <iostream>
#include <iomanip>
#include "String.hpp"
using namespace std;

int main(int argc, const char * argv[]) 
{
    String a;

    a.zap();
    a.print();

    String b = a;

    b.print();
    String c;
    c.copy(b);
    c.print();
    
}
