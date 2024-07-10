//
//  main.cpp
//  ыфвыфв
//
//  Created by Rodion Lovyannikov on 12.06.2024.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string ArrabianToRomanian(const int& f)
{
    int number = f;
    string romanian;
    int counter = 12;
    vector<pair<int, string> > numbers {{1,"I"},{4,"IV"} ,{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90," XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
    while (number>0)
    {
        while(numbers[counter].first>number)
        {
            --counter;
        }        
        number-= numbers[counter].first;
        romanian+= numbers[counter].second;
    }
    return romanian;
}


int main()
{
    int n;
    cin>>n;
    cout<<ArrabianToRomanian(n)<<endl;  
}
