
#include <iostream>
#include<string>
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
    
    /*for(size_t i=0;i<size_str;++i)
    {
        if(str[i]==insert_str[0]&&str[i+1]==insert_str[1]&&str[i+2]==insert_str[2])
        {
            cout<<"found!"<<" "<<insert_str<<endl;
            
            
        }
    }*/
    cout<<"index_in="<<index_in<<endl;
    insert_str.insert(0,"(");
    insert_str.push_back(')');
    str.insert(index_in,insert_str);
    
    
    
   // cout<<"find="<<find_str.find(str)<<endl;
    
   // str.insert(5,insert_str);
    
    
    
    
    return str;
}

int main()
{
    string str;
    str=R"(gughgd/*xxxxxxxxx*/AhghfA//xxxxxxxxxxxxxxxxxx)";
                
    //cout<<delete_comment(str)<<endl;
    cout<<find_symbols(str)<<endl;
    
    
/*string text = "slovo”;
string text_copy="";
for(auto& x : text)
    {
        text_copy+=x;
    }
cout<<text_copy<<endl;*/
    
    
    
}
