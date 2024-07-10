#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Abonent.hpp"
#include <fstream>
#include "Phonebook.hpp"
using namespace std;
#undef strcpy
#define strcpy(dest, src)

int main()
{
    Abonent Petrov("Petrov Ivan",9099900);
    Abonent Ivanov("Ivanov Petr","Stavropol, st.Lenina 333",555555,305060);
    Phonebook List;
    List.AddAbonent(Petrov);
    List.AddAbonent(Ivanov);
    
    List.DisplayAbonent();
    
    return 0;
}
