// римские цуифры.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include<map>//словарь - массив, где есть пара(ключ,значение)
using namespace std;

string intToRoman(int num)
{
	map<int, string > romanMap =
	{
		{1000,"M"},{900,"CM"},{500,"D"}, {400,"CD"},
		{100,"C"},{90,"XC"},{50,"L"},{40, "XL"},
		{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},
		{1,"I"}
	};
	string result;
	for (auto i = romanMap.rbegin(); i != romanMap.rend(); ++i)//начиная от начала словаря, заканчивая концом словаря, пока i не равно словарю увеличивая на один
	{
		while (num >= i->first)//first - ключ, пока наше значение больше чем ключ
		{
			result += i->second;//second-значение
			num -= i->first;
		}
	}
		return result;
}		


int main()
{
	string input;
	cout << " Enter the number (up to 4000)";
	cin >> input;
	int number = stoi(input);
	cout << intToRoman(number);
}

