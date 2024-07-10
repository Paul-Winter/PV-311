#include <iostream>

#include "PhoneBook.hpp"
#include "Abonentrecord.hpp"
#include <fstream>
#include <string>

using namespace std;


int main()
{

    PhoneBook m;
    Abonentrecord q;
    
    m.addAbonent("Anton\0", 123, 123, 123, "qwerty\0");
    m.addAbonent("Andrey\0", 123, 123, 123, "qwerty\0");
    
    PhoneBook w(m);
    //q.setName("q");
    //Abonentrecord w(q);
    //a = m;
    //q.setName("q");
    //w = q;
    //a = m; //перегруженный оператор присваивания
    //m.addAbonent("Andrey\0", 123, 123, 123, "qwerty\0");
    //w.displayAbonent();  // выводит абонентов
    w.dispayAbonents();   //вывод
    //m.write();   // запись
     //m.read();     //чтение
    //m.deleteAbonent1("w\0");   // удаляет абонента по имени
    //m.deleteAbonent(0);   // удаляет абонента по порядковому номеру (от 0 до количества абонентов)
    //m.findAbonent("Anton\0"); // ищет абонента по имени и выводит его данные
    //m.dispayAbonents();    //выводит список всех абонентов

    

   
    
    


    
    


}
