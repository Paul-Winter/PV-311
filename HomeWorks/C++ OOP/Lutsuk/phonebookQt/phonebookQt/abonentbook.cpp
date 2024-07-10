#include "abonentbook.h"

AbonentBook::AbonentBook()
{

}

AbonentBook::AbonentBook(const size_t AbBook_Size) : AbBook{new Abonent[AbBook_Size]}
{

}

AbonentBook::AbonentBook() : AbBook{new Abonent[AbBook_Size]}
{

}

AbonentBook::~AbonentBook(){
    delete[] AbBook;
}

size_t AbonentBook::getAbonCounter() const
{
    return AbonCounter;
}

void AbonentBook::setAbCounter(const size_t AbonCounter)
{
    return AbonCounter;
}

void AbonentBook::setSize(const size_t Ab_SizeBuf)
{
    AbBook_Size=Ab_SizeBuf;
}

const size_t AbonentBook::getSize(){
    return AbBook_Size;
}

Abonent *AbonentBook::setAbBook(const Abonent * const AbBookBuf)
{
    return AbBook;

}
void AbonentBook::setAbonCounter(size_t newAbonCounter)
{
    AbonCounter = newAbonCounter;
}

void AbonentBook::getAbBook(){
    Abonent.getInf();
    Abonent.getName();
    Abonent.getWorkNum();
    Abonent.getHomeNum();
}

void AbonentBook::AddAbonent(const chsr * const AbonentName, const char * const Information, const uint64_t HomeNumber, const uint64_t WorkNumber) : AbonentName{new char[AbonentName_size]},
    Information{new char[Information_size]}
{
    if(AbonCounter<AbBook_Size)
    {
        AbBook[AbonCounter].setName(AbonentName);
        AbBook[AbonCounter].setInf(Information);
        AbBook[AbonCounter].setHomeNum(HomeNumber);
        AbBook[AbonCounter].setWorkNum(WorkNumber);
        ++AbonCounter;
    }
    else{
        AbBook_Size+=100;
        Abonent* temp { new Abonent[AbBook_Size]};
        for(size_t i=0;i<AbonCounter;++i){
            temp[i].setName(AbBook[i].getName());
            temp[i].setInf(AbBook[i].getInf());
            temp[i].setHomeNum(AbBook[i].getHomeNum());
            temp[i].setWorkNum(AbBook[i].getWorkNum());
        }
        delete[] AbBook;
        AbBook=temp;
    }

}

explicit void AbonentBook::findAbon(const char * const AbonentNameFind)
{
    for(size_t i=0;i<AbonCounter;++i){
        if(strcmp(AbonentNameFind,AbBook[i].AbonentName)!=0)
        {

            cout<<"Name: "<<AbBook[i].AbonentName<<endl;
            cout<<"Information: "<<AbBook[i].Information<<endl;
            cout<<"Home Number: "<<AbBook[i].HomeNumber<<endl;
            cout<<"Work Number: "<<AbBook[i].WorkNumber<<endl;

        }
    }
}

explicit void AbonentBook::deleteAbon(const char * const AbonentNameDel)
{
    for(size_t i=0;i<AbonCounter;++i){
        if(strcmp(AbonentNameDel,AbBook[i].AbonentName)!=0)
        {
            cout<<"Name: "<<AbBook[i].AbonentName<<endl;
            cout<<"Information: "<<AbBook[i].Information<<endl;
            cout<<"Home Number: "<<AbBook[i].HomeNumber<<endl;
            cout<<"Work Number: "<<AbBook[i].WorkNumber<<endl;

            delete[] AbBook[i].AbonentName;
            delete[] AbBook[i].Information;
            delete[] AbBook[i].HomeNumber;
            delete[] AbBook[i].WorkNumber;

            --AbonCounter;

            Abonent* temp{new Abonent[AbBook_Size]};
            for(size_t j=0;j<i;++j)
            {
                strcpy_s(AbBook[j].AbonentName,AbonentName_size,temp[j].AbonentName);
                strcpy_s(AbBook[j].Information,AbonentName_size,temp[j].Information);
                temp[j].HomeNumber=AbBook[j].HomeNumber;
                temp[j].WorkNumber=AbBook[j].WorkNumber;
            }
            for(size_t j =i+1;j<AbonCounter;++j)
            {
                strcpy_s(AbBook[j].AbonentName,AbonentName_size,temp[j].AbonentName);
                strcpy_s(AbBook[j].Information,AbonentName_size,temp[j].Information);
                temp[j].HomeNumber=AbBook[j].HomeNumber;
                temp[j].WorkNumber=AbBook[j].WorkNumber;
            }

        }
    }
    delete[] AbBook;
    AbBook=temp;
}

void AbonentBook::displayAbon(const char * const NameDisplay){
    if(strcmp(AbonentNameDel,AbBook[i].AbonentName)!=0)
    {
        cout<<"Name: "<<AbBook[i].AbonentName<<endl;
        cout<<"Information: "<<AbBook[i].Information<<endl;
        cout<<"Home Number: "<<AbBook[i].HomeNumber<<endl;
        cout<<"Work Number: "<<AbBook[i].WorkNumber<<endl;
    }
}


