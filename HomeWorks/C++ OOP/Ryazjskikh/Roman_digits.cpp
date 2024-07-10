// Roman_digits.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
using namespace std;




string ArabictoRomanian(const int& link)
{
    int number = link;
    const int size = 13;


    int Arabian[size] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    string Romanian[size] = { "I" , "IV" , "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };


    int counter = size - 1;
    string result = "";

    while(number>0)

    {
        for (int i = 0; i < size - 1; ++i)
        {
            if (Arabian[counter] > number)
            {
                counter--;
            }
        }
        
        
        string temp = Romanian[counter];
        number -= Arabian[counter];
        result.append(temp);
        //cout << temp << endl;
    }


    
    return result;;
}




int main()
{
   
    int number=0;
    cin>> number;
    cout << "Arabic number: " << number << endl;
    cout <<"Romanian number: " << ArabictoRomanian(number);

    
}
