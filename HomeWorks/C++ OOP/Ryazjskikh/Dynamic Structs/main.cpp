//
//  main.cpp
//  DZ07
//
//  Created by Jaroslav on 22.06.2024.
//

#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;


string random_symbols()
{    
    int n=0;
    char a[1]={'0'};
    for (int i=33;i<42;++i)
    {
        n=(33+rand()%10)-1;
        if (n==35||n==36||n==37||n==38)
        {
            a[0]=(char)n;
        }
    }
    
    string b= " ";
    b[0]=a[0];
    return b;   
}

string fill_str()
{
    string str="[][][][]";
    
    str.insert(1,(random_symbols()));
    str.insert(4,(random_symbols()));
    str.insert(7,(random_symbols()));
    str.insert(10,(random_symbols()));    
    
    return str;
}

string one_hand_bandit()
{
    string display=" ";
    display.insert(0,fill_str());
    display.insert(12,"\n");
    display.insert(13,fill_str());
    display.insert(26,"\n");
    display.insert(27,fill_str());
    //display.insert(40,"\n");
    //display.insert(41,fill_str());
    
    return display;
}

bool analizing(const string & link)
{
    bool result=0;
    if(link[1]==link[4]==link[7]==link[10])
        {
        cout<<"YOU WIN!!!"<<endl;
        }
    else
        {cout<<"you loose!";}    
    
    return result;
}


int main()
{
    setlocale(LC_ALL,"RUS");
    srand((int)time(0));
    string print=one_hand_bandit();

    cout<<print;
    analizing(print);
    
    cout<<endl;   
}
