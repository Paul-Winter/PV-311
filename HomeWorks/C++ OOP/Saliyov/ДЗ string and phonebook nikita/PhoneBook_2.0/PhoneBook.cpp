//
//  PhoneBook.cpp
//  PhoneBook_2.0
//
//  Created by Nikita on 20.05.2024.
//

#include "PhoneBook.h"
#include "Abonentrecord.h"

PhoneBook::PhoneBook(const size_t abonentRecSize)
{
    abonentRecordSize = abonentRecSize;
    abonentRecordList = new Abonentrecord[abonentRecordSize];
    counter++;
    
};

PhoneBook::~PhoneBook()
{
    delete[] abonentRecordList;
}

;
