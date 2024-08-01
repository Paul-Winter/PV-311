//ЗАДАНИЕ 5
// Написать функцию, которая определяет, является ли «счастливым» шестизначное число.

#include <iostream>
using namespace std;

bool lucky(int a)
{
	int sum1, sum2;
	sum1 = a / 100000 + (a / 10000 % 10) + (a / 1000 % 10);
	sum2 = a / 100 % 10 + (a / 10 % 10) + a % 10;
	return (sum1 == sum2);
}

int main()
{
	for (int i = 100000; i < 1000000; i++)
	{
		if (lucky(i))
		{
			cout << "Number " << i << " is luky!" << endl;
		}
	}
}