
#include <iostream>
#include<string>
#include <sstream>
using namespace std;

string delete_comment(const string & link)
{
    int counter=0;
    
    string str="";
    str=link;
    
    
    
    int index1=(int)str.find("/*");
    int index2=(int)str.find("*/");
    for(int i=index1;i<index2;++i)
    {
        counter++;
    }
    
    
    
    str.erase(index1,counter+2);
    
    string new_str=str;
    int index3=(int)new_str.find("//");
    int index4=(int)new_str.find("\n");
    
    new_str.erase(index3,index4);
    
    return new_str;
}


string find_symbols(const string & link )
{
    string str="";
    str=link;
    size_t size_str=str.size();
    cout<<"size_str="<<size_str<<endl;
    int index_in=0;
    
    string insert_str="";
    cin>>insert_str;
    size_t size_insert=insert_str.size();
    index_in=(int)str.find(insert_str);
    str.erase(index_in,size_insert);
    
   
    cout<<"index_in="<<index_in<<endl;
    insert_str.insert(0,"(");
    insert_str.push_back(')');
    str.insert(index_in,insert_str);
    
    
    
    return str;
}

string find_number_replace(const string & link)
{
    
    string str=link;
    string numbers1="";
    string numbers2="";
    
    size_t index_plus=str.find('+');
    
    for(size_t i=0;i<=index_plus;++i)
    {
       
    if((str[i]>=48&&str[i]<=57)&&(str[i-1]>=48&&str[i-1]<=57))
        {
        numbers1.push_back(str[i-1]);
        }
        
    }
    
        for(size_t i=index_plus;i<str.back();++i)
        {
            if((str[i]>=48&&str[i]<=57)||(str[i+1]>=48&&str[i+1]<=57))
                    
                    {
                        numbers2.push_back(str[i]);
                    }
        }
      
        
    
    cout<<endl;
    
    istringstream istr(numbers1);
    int number1;
       
    istr >> number1;
    cout<<"number="<<number1<<endl;
    cout<<endl;
    
   
    
    stringstream istr2(numbers2);
    int number2;
       
    istr2 >> number2;
    cout<<"number2="<<number2<<endl;
    cout<<endl;
    
    size_t summ=number1+number2;
    cout<<"summ="<<summ<<endl;
    string summ_str="";
    summ_str=to_string(summ);
    
    size_t size_summ_str=summ_str.length();
    cout<<"length="<<size_summ_str<<endl;
    
    
    cout<<"summ_str="<<summ_str<<endl;
    
    size_t index_left=index_plus;
    
    for(size_t i=index_plus-1;i<str.front();--i)
    {
        if((str[i]>=48&&str[i]<=57)&&(str[i-1]>=48&&str[i-1]<=57))
        {
            
            index_left--;
        }
    }
    cout<<endl;
    cout<<"index_left ="<<index_left<<endl;
    
    size_t index_right=index_plus;
    for(size_t i=index_plus+1;i<str.size();++i)
    {
        if((str[i]>=48&&str[i]<=57)||(str[i+1]>=48&&str[i+1]<=57))
        {
            index_right++;
        }
    }
    cout<<endl;
    cout<<"index_right ="<<index_right<<endl;
    
    size_t replace_size=(index_right-index_left)-1;
    str.replace(index_left,replace_size,summ_str);
    
    
    return str;
}

int main()
    {
    string str;
    string file_way;
    str=R"(g2ug13467+52hg4d//*xxxxxxxxx*/AhghfA//)";//xxxxxxxxxxxxxxxxxx)";
    cout<<endl;
    
    
    
    
        //cout<<delete_comment(str)<<endl;
        //cout<<find_symbols(str)<<endl;
        //cout<<find_number_replace(str)<<endl;
    
    }
        
        
    
