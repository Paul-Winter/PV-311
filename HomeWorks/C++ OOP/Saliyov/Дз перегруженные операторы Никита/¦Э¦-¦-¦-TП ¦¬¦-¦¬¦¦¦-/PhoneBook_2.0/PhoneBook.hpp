//
//  PhoneBook.hpp
//  PhoneBook_2.0
//
//  Created by Nikita on 20.05.2024.
//

#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include <stdio.h>
#include <iostream>
#include "Abonentrecord.hpp"
#include "string.h"
#include "fstream"

using namespace std;

class PhoneBook
{
public:
    size_t abonentRecordSize = 100;
    Abonentrecord* abonentRecordList = nullptr;
    
    size_t abonentCounter = 0;
    
    PhoneBook(const size_t abonentRecSize = 100);
    ~PhoneBook();
    
    const PhoneBook &operator= (const PhoneBook& copy)
    {
        this->abonentCounter = copy.abonentCounter;
        delete [] abonentRecordList;
        abonentRecordList = new Abonentrecord[abonentRecordSize];
        for(int i = 0; i < abonentCounter; ++i)
        {
            abonentRecordList[i] = copy.abonentRecordList[i];
        }
        
        return *this;
    }
    
    PhoneBook(const PhoneBook & copy) : PhoneBook(copy.abonentRecordSize)
    {
        this->abonentCounter = copy.abonentCounter;
        for(int i = 0; i < abonentCounter; ++i)
        {
            abonentRecordList[i] = copy.abonentRecordList[i];
        }
    }
   
    
    void addAbonent(const char* const abonentName_f, uint64_t mobileNumber_f = 0,
        uint64_t homeNumber_f = 0, uint64_t workNumber_f = 0, const char* const information_f = nullptr)
    {
        if (abonentCounter < abonentRecordSize)
        {
            abonentRecordList[abonentCounter].setName(abonentName_f);
            abonentRecordList[abonentCounter].setmobNumber(mobileNumber_f);
            abonentRecordList[abonentCounter].sethomeNumber(homeNumber_f);
            abonentRecordList[abonentCounter].setworkNumber(workNumber_f);
            
            if (information_f != nullptr)
            {
                abonentRecordList[abonentCounter].setinformation(information_f);
            }
            ++abonentCounter;
        }
        else
        {
            abonentRecordSize += 100;
            Abonentrecord* temp = new Abonentrecord[abonentRecordSize];
            for (int i = 0; i < abonentRecordSize - 100; ++i)
            {
                temp[i].setName(abonentRecordList[i].getName());
                temp[i].setmobNumber(abonentRecordList[i].getmobNumber());
                temp[i].sethomeNumber(abonentRecordList[i].gethomeNumber());
                temp[i].setworkNumber(abonentRecordList[i].getworkNumber());
                temp[i].setinformation(abonentRecordList[i].getinformation());
    
            }

            delete[] abonentRecordList;
            abonentRecordList = temp;
        }
    }
    
    void findAbonent(const char* const abonentName_find)
    {
        for (int i = 0; i < abonentCounter; ++i)
        {
            const char* temp = abonentRecordList[i].getName();
            if (!strcmp(abonentName_find,temp))
            {
                cout << "A subscriber with the same name has been successfully found. His data: " << endl;
                cout << "Name: " << abonentRecordList[i].getName() << endl;
                cout << "Mobnumber: " << abonentRecordList[i].getmobNumber() << endl;
                cout << "Homenumber: " << abonentRecordList[i].gethomeNumber() << endl;
                cout << "Worknumber: " << abonentRecordList[i].getworkNumber() << endl;
                cout << "Information: " << abonentRecordList[i].getinformation() << endl;
            }
            
        }
    }
    void deleteAbonent(int abonentID)
    {
    
        Abonentrecord* temp = new Abonentrecord[abonentRecordSize];
        
        for (int i = abonentID; i < abonentCounter-1; ++i)
        {
            temp[i].setName(abonentRecordList[i+1].getName());
            temp[i].setmobNumber(abonentRecordList[i+1].getmobNumber());
            temp[i].sethomeNumber(abonentRecordList[i+1].gethomeNumber());
            temp[i].setworkNumber(abonentRecordList[i+1].getworkNumber());
            temp[i].setinformation(abonentRecordList[i+1].getinformation());
        
        }
        for (int i = 0; i < abonentID; ++i)
        {
            temp[i].setName(abonentRecordList[i].getName());
            temp[i].setmobNumber(abonentRecordList[i].getmobNumber());
            temp[i].sethomeNumber(abonentRecordList[i].gethomeNumber());
            temp[i].setworkNumber(abonentRecordList[i].getworkNumber());
            temp[i].setinformation(abonentRecordList[i].getinformation());
        }
        
        abonentCounter--;

        delete[] abonentRecordList;
        abonentRecordList = temp;
    }
    
    void deleteAbonent1(const char* const abonentName_delete)
    {

        Abonentrecord* temp1 = new Abonentrecord[abonentRecordSize];
        
        for (int i = 0; i < abonentCounter-1; ++i)
        {
            const char* temp = abonentRecordList[i].getName();
            if (!strcmp(abonentName_delete, temp)) {
    
                temp1[i].setName(abonentRecordList[i + 1].getName());
                temp1[i].setmobNumber(abonentRecordList[i + 1].getmobNumber());
                temp1[i].sethomeNumber(abonentRecordList[i + 1].gethomeNumber());
                temp1[i].setworkNumber(abonentRecordList[i + 1].getworkNumber());
                temp1[i].setinformation(abonentRecordList[i + 1].getinformation());

                for (int j = 0; j < i; ++j)
                {
                    temp1[j].setName(abonentRecordList[j].getName());
                    temp1[j].setmobNumber(abonentRecordList[j].getmobNumber());
                    temp1[j].sethomeNumber(abonentRecordList[j].gethomeNumber());
                    temp1[j].setworkNumber(abonentRecordList[j].getworkNumber());
                    temp1[j].setinformation(abonentRecordList[j].getinformation());
                }
            }
        }
        
        abonentCounter--;
        delete[] abonentRecordList;
        abonentRecordList = temp1;
    }
    
    void dispayAbonents()
    {
        for (int i = 0; i < abonentCounter; ++i)
        {
            
            cout << "Name: " << abonentRecordList[i].getName() << endl;
            cout << "Mobnumber: " << abonentRecordList[i].getmobNumber() << endl;
            cout << "Homenumber: " << abonentRecordList[i].gethomeNumber() << endl;
            cout << "Worknumber: " << abonentRecordList[i].getworkNumber() << endl;
            cout << "Information: " << abonentRecordList[i].getinformation() << endl << endl;
        }
    }
    
     bool write ()
     {

        const char* path = "myFile.txt";
        fstream fout;
        fout.open(path, ios::out | ios::binary);

            if (!fout.is_open())    // Á‡ÔËÒ¸
            {
                cout << "Error!" << endl;
                return false;
            }
            else
            {
                cout << "File is open!" << endl;
                fout.write((char*)&abonentCounter, sizeof(abonentCounter));
                return true;
                uint64_t mN, hN, wN;
                for (int i = 0; i < abonentCounter; ++i)
                {
                    mN = abonentRecordList[i].getmobNumber();
                    wN = abonentRecordList[i].getworkNumber();
                    hN = abonentRecordList[i].gethomeNumber();
                    fout.write((char*)abonentRecordList[i].getName(), 128);
                    fout.write((char*)&mN, sizeof(uint64_t));
                    fout.write((char*)&wN, sizeof(uint64_t));
                    fout.write((char*)&hN, sizeof(uint64_t));
                    fout.write((char*)abonentRecordList[i].getinformation(), 1024);
                }
            }
         fout.close();
    }
    
     
     bool read() {
         fstream fin;
         const char* path = "myFile.txt";
         fin.open(path);

         if (!fin.is_open())   //˜ÚÂÌËÂ
         {
             cout << "Error!" << endl;
             return false;
         }
         else
         {
             return true;
             cout << "File is Open!" << endl;
             fin.read((char*)&abonentCounter, sizeof(abonentCounter));
             for (int i = 0; i < abonentCounter; ++i)
             {
                 uint64_t mN, wN, hN;
                 char* Name = (char*)abonentRecordList[i].getName();
                 char* Info = (char*)abonentRecordList[i].getinformation();
                 mN = abonentRecordList[i].getmobNumber();
                 wN = abonentRecordList[i].getworkNumber();
                 hN = abonentRecordList[i].gethomeNumber();

                 fin.read((char*)Name, 128);
                 fin.read((char*)&mN, sizeof(uint64_t));
                 fin.read((char*)&wN, sizeof(uint64_t));
                 fin.read((char*)&hN, sizeof(uint64_t));
                 fin.read((char*)Info, 1024);

                 abonentRecordList[i].setName(Name);
                 abonentRecordList[i].setmobNumber(mN);
                 abonentRecordList[i].sethomeNumber(hN);
                 abonentRecordList[i].setworkNumber(wN);
                 abonentRecordList[i].setinformation(Info);

             }
             dispayAbonents();
         }
         fin.close();

     }
     };



#endif /* PhoneBook_hpp */
