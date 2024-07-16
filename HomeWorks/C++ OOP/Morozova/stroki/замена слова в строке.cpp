#include <iostream>
#include <string>
using namespace std;

string Replacement(string word, string sound)
{
    string result = word;
    size_t pos = result.find(sound);
    string temp = "(" + sound + ")";


    while (pos != string::npos)
    {
        result.replace(pos, sound.length(), temp);
        pos = result.find(sound, pos + temp.length());

    }

    return  result;
}


int main()
{
    string g;
    getline(cin, g);
    string f;
    getline(cin, f);
    cout << Replacement(g, f);
}

