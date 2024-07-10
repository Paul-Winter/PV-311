//
//  main.cpp
//  String_2
//
//  Created by Jaroslav on 16.06.2024.
//

#include <iostream>
#include<string>

using namespace std;


string path_separate(const string & link, int choice)
{
    string str=link;
    string result;
    if (str.size() == 0)
    {
        str=nullptr;
    }
    
    size_t index1 = str.find_last_of('\\');
    size_t index2 = str.find_last_of('\\', index1-1);
    
    
    
    switch (choice)
    {
    case 0: 
        {
            if (index1 != -1) result.append(str, 0, index1+1);
            break;
            
        }
    case 1:
        {
            result.append(str, index1 + 1);
            break;
        }
    case 2:
        {
            result.append(str, str.find_last_of('.') + 1);
            break;
        }
    case 3:
        {
            result.append(str, index1 + 1, str.find_last_of('.')-index1-1);
            break;
        }
    case 4:
        {
            result.append(str, index2 + 1, index1 - index2 - 1);
            break;
        }
    case 5:
        {
            result.append(str, 0, str.find_last_of('.')); result.append(".docx"); 
            break;
        }
    default:
            ;
    }
    return result;
}
 
 

int main()
{
    string str=R"(C:\Step\С++lesson_03\Docs\Less03.docx,4334)";
    
   
    int choice=0;
    while(choice<6)
    {
        cin>>choice;
        cout<<path_separate(str,choice)<<endl;
    }

  
}
