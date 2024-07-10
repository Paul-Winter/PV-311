#include <iostream>

#include "PhoneBook.h"
#include "Abonentrecord.h"
#include <fstream>
#include <string>
#include <iostream>


using namespace std;


int main()
{
   
    setlocale(LC_ALL, "Russian");
    PhoneBook a;
    int choice;
    do {
        cout << "Здравствуйте, Вас приветствует телефонная книга!" << endl;
        
        cout << "Пожалуйста, введите цифру желаемого действия" << endl;
        cout << "1 - добавить абонента" << endl;
        cout << "2 - поиск абонента по имени" << endl;
        cout << "3 - удаление абонента по порядковому номеру (начиная с 0)" << endl;
        cout << "4 - удаление абонента по имени" << endl;
        cout << "5 - вывод всех абонентов" << endl;
        cout << "6 - показать общее количество телефонных книг" << endl;
        cout << "7 - показать общее количество абонентов" << endl;
        cout << "0 - выход" << endl;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                cout << "Введите имя абонента: ";
                string str;
                cin >> str;
                char *cstr = new char[str.length() + 1];
                strcpy(cstr, str.c_str());
                cout << "Введите мобильный номер телефона: ";
                uint64_t Mnum;
                cin >> Mnum;
                cout << "Введите домашний номер телефона: ";
                uint64_t Hnum;
                cin >> Hnum;
                cout << "Введите рабочий номер телефона: ";
                uint64_t Wnum;
                cin >> Wnum;
                cout << "Введите доп. информацию: ";
                string info;
                char *info_ = new char[info.length() + 1];
                cin >> info;
                strcpy(info_,info.c_str());
                a.addAbonent(cstr, Mnum, Hnum,Wnum,info_);
                cout << "Отлично, абонент добавлен!" << endl << endl;
                delete [] info_;
                delete [] cstr;
                break;
            }
            case 2:
            {
                cout << "Введите имя абонента, которого хотите найти: ";
                string str;
                cin >> str;
                char *cstr = new char[str.length() + 1];
                strcpy(cstr, str.c_str());
                a.findAbonent(cstr);
                break;
            }
            case 3:
            {
                cout << "Введите порядковый номер абонента, которого хотите удалить (начиная с 0) ";
                int abID;
                cin >> abID;
                a.deleteAbonent(abID);
                break;
            }
            case 4:
            {
                cout << "Введите имя абонента, которого хотите удалить: ";
                string str;
                cin >> str;
                char *cstr = new char[str.length() + 1];
                strcpy(cstr, str.c_str());
                a.deleteAbonent1(cstr);
                break;
            }
            case 5: a.dispayAbonents();
                break;
            case 6: cout << a.counter << endl;
                break;
            case 7: cout << a.abonentCounter << endl;
                break;
            default: cout << "Введите правильное число!" << endl;
        }
    } while (choice);
        
    
    
     // PhoneBook m;
    
    //Abonentrecord q;
    
   // m.addAbonent("Anton\0", 123, 123, 123, "qwerty\0");
    //m.addAbonent("Andrey\0", 123, 123, 123, "qwerty\0");
    
    //PhoneBook w(m);
    //q.setName("q");
    //Abonentrecord w(q);
    //a = m;
    //q.setName("q");
    //w = q;
    //a = m; //перегруженный оператор присваивания
    //m.addAbonent("Andrey\0", 123, 123, 123, "qwerty\0");
    //w.displayAbonent();  // выводит абонентов
    //w.dispayAbonents();   //вывод
    //cout << w.counter;   // статический счетчик телефонных книг
    //m.write();   // запись
     //m.read();     //чтение
    //m.deleteAbonent1("w\0");   // удаляет абонента по имени
    //m.deleteAbonent(0);   // удаляет абонента по порядковому номеру (от 0 до количества абонентов)
    //m.findAbonent("Anton\0"); // ищет абонента по имени и выводит его данные
    //m.dispayAbonents();    //выводит список всех абонентов

   

   
    
    


    
    


}
