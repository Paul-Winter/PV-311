#include <string>
#include <iostream>
using namespace std;

string evaluateExpression(string text) 
{
    string result = text;
    string separators = "+-";
    size_t pos = 0;//указатель на первый элемент

    while (result.find_first_of("+-") != string::npos)//пока
    {
        pos = result.find_first_of("+-");

        char action = result[pos];

        string subtext1 = result.substr(0, pos);//находим цифры до знака
        string subtext2 = result.substr(pos + 1);//находим цифры

        size_t start = subtext1.find_last_of(" ") + 1;
        size_t end = subtext2.find_first_of(" ") + 1;
        int number1 = stoi(subtext1.substr(start));
        int number2 = stoi(subtext2.substr(0, end));

        if (action == '+') {
            result.replace(start, pos + end - start, to_string(number1 + number2));
        }
        else {
            result.replace(start, pos + end - start, to_string(number1 - number2));
        }
        pos = end + 1;
    }
    return result;
}


int main()
{
    string text;
    getline(cin, text);
    cout << evaluateExpression(text);
}
