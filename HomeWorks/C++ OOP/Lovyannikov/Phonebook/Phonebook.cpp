#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Abonent.hpp"
#include <fstream>
#include "Phonebook.hpp"
using namespace std;
#undef strcpy
#define strcpy(dest, src)
Phonebook::Phonebook(const size_t PhonebookSize)
{
    this->PhonebookSize=PhonebookSize;
    abonentList=new Abonent[PhonebookSize];
}
Phonebook::~Phonebook()
{
    delete [] abonentList;
}
void Phonebook::AddAbonent(const Abonent &f)
{
    if(abonentCounter<PhonebookSize)
    {
        abonentList[abonentCounter].SetName(f.GetInfo());
        if(f.GetInfo()!=nullptr)
        {
            abonentList[abonentCounter].SetInfo(f.GetInfo());
        }
        abonentList[abonentCounter].SetMobileNumber(f.GetMobileNumber());
        abonentList[abonentCounter].SetHomeNumber(f.GetHomeNumber());
        abonentList[abonentCounter].SetWorkNumber(f.GetWorkNumber());
        ++abonentCounter;
    }
    else
    {
        PhonebookSize+=100;
        Abonent* temp=new Abonent[PhonebookSize];
        for(int i=0;i<PhonebookSize-100;++i)
        {
            temp[i].SetName(abonentList[i].GetName());
            temp[i].SetInfo(abonentList[i].GetInfo());
            temp[i].SetMobileNumber(abonentList[i].GetMobileNumber());
            temp[i].SetHomeNumber(abonentList[i].GetHomeNumber());
            temp[i].SetWorkNumber(abonentList[i].GetWorkNumber());
        }
        delete [] abonentList;
        abonentList = temp;
    }
}
void Phonebook::FindAbonent(const char* const name)
{
    for(int i = 0;i<abonentCounter;++i)
    {
        const char* tempName = abonentList[i].GetName();
        if(strcmp(name, tempName)==0)
        {
            cout<<"We found smth!"s<<endl;
            cout<<"Name: "s<<abonentList[i].GetName()<<endl;
            cout<<"Info: "s<<abonentList[i].GetInfo()<<endl;
            cout<<"Mobile number: "s<<abonentList[i].GetMobileNumber()<<endl;
            cout<<"Home number: "s<<abonentList[i].GetHomeNumber()<<endl;
            cout<<"Work number: "s<<abonentList[i].GetWorkNumber()<<endl;
        }
    }
}
void Phonebook::DeleteAbonent(int abonentId)
{
    Abonent* temp = new Abonent[PhonebookSize];
    for(int i=0;i<abonentId;++i)
    {
        temp[i].SetName(abonentList[i].GetName());
        temp[i].SetInfo(abonentList[i].GetInfo());
        temp[i].SetMobileNumber(abonentList[i].GetMobileNumber());
        temp[i].SetHomeNumber(abonentList[i].GetHomeNumber());
        temp[i].SetWorkNumber(abonentList[i].GetWorkNumber());
    }
    for(int i = abonentId;i<PhonebookSize-1;++i)
    {
        temp[i].SetName(abonentList[i+1].GetName());
        temp[i].SetInfo(abonentList[i+1].GetInfo());
        temp[i].SetMobileNumber(abonentList[i+1].GetMobileNumber());
        temp[i].SetHomeNumber(abonentList[i+1].GetHomeNumber());
        temp[i].SetWorkNumber(abonentList[i+1].GetWorkNumber());
    }
    delete [] abonentList;
    abonentList = temp;
}
void Phonebook::DisplayAbonent()
{
    for(int i=0;i<abonentCounter;++i)
    {
        cout<<"Name: "s<<abonentList[i].GetName()<<endl;
        cout<<"Info: "s<<abonentList[i].GetInfo()<<endl;
        cout<<"Mobile number: "s<<abonentList[i].GetMobileNumber()<<endl;
        cout<<"Home number: "s<<abonentList[i].GetHomeNumber()<<endl;
        cout<<"Work number: "s<<abonentList[i].GetWorkNumber()<<endl<<endl;
    }
}
bool Phonebook::write()
{
    ofstream file;
    file.open("Phonebook.txt");
    if(!file.is_open())
    {
        cout<<"File corrupted!"s<<endl;
        return false;
    }
    else
    {
        size_t mobile_number, home_number, work_number;
        for(int i =0;i<abonentCounter;++i)
        {
            mobile_number = abonentList[i].GetMobileNumber();
            home_number = abonentList[i].GetHomeNumber();
            work_number = abonentList[i].GetWorkNumber();
            file.write((char*)abonentList[i].GetName(),128);
            file.write((char*)abonentList[i].GetInfo(),1024);
            file.write((char*)&mobile_number,sizeof(size_t));
            file.write((char*)&home_number,sizeof(size_t));
            file.write((char*)&work_number, sizeof(size_t));
        }
        file.close();
        cout<<"Writing complete!"s<<endl<<endl;
        return true;
    }
}
bool Phonebook::read()
{
    ifstream file;
    file.open("Phonebook.txt");
    if(!file.is_open())
    {
        cout<<"File corrupted!"s<<endl;
        return false;
    }
    else
    {
        size_t mobile_number, home_number, work_number;
        for(int i =0;i<abonentCounter;++i)
        {
            mobile_number = abonentList[i].GetMobileNumber();
            home_number = abonentList[i].GetHomeNumber();
            work_number = abonentList[i].GetWorkNumber();
            file.read((char*)abonentList[i].GetName(),128);
            file.read((char*)abonentList[i].GetInfo(),1024);
            file.read((char*)&mobile_number,sizeof(size_t));
            file.read((char*)&home_number,sizeof(size_t));
            file.read((char*)&work_number, sizeof(size_t));
        }
        DisplayAbonent();
        file.close();
        cout<<"Reading complete!"s<<endl<<endl;
        return true;
    }
}
