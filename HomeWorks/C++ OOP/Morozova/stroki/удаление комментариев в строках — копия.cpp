// удаление комментариев в строках.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

string removeComments(const string& text)
{
    int size = 0;
    string result;

    if(!text.empty())
    {
        size = text.size();
    for (size_t i = 0; i < size; ++i)
    {
        if(text[i]=='/' && text[i+1]=='/')
        {
        i++;
            continue;
        }
        if (text[i]=='/' && text[i+1]=='*')
        {
        i++;
            continue;
        }
        if (text[i] == '*' && text[i + 1] == '/')
        {
        i++;
            continue;
        }
        else
        {
            result += text[i];
        }
    }
    }
        return result;

}

int main()
{
    string text = "int main() //Print Hello World; /* uhjiojhjij */ Whicher";
    cout << removeComments(text);
}

