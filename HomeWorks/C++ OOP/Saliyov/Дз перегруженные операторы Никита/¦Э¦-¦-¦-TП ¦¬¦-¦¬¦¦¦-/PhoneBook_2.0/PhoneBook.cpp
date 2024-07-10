//
//  PhoneBook.cpp
//  PhoneBook_2.0
//
//  Created by Nikita on 20.05.2024.
//

#include "PhoneBook.hpp"
#include "Abonentrecord.hpp"

PhoneBook::PhoneBook(const size_t abonentRecSize)
{
    abonentRecordSize = abonentRecSize;
    abonentRecordList = new Abonentrecord[abonentRecordSize];
    
};

PhoneBook::~PhoneBook()
{
    delete[] abonentRecordList;
}

;
