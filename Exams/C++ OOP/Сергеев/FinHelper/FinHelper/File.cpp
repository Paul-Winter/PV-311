#include "File.h"

File::File()
{
}

void File::WriteFile(string nameWallet, string valute, int amountOfMoney)
{
	std::ofstream out;
	out.open(_path, std::ios::app);
	if (out.is_open())
	{
		out << "Name: " << nameWallet << " Wallet amount of money:" << amountOfMoney << " " << valute << endl;
		cout << "Writing success!" << endl;
	}
	else
	{
		std::cout << "Writing wrong, file is not open";
	}
	out.close();
}
void File::ReadFile()
{
	string line;
	std::ifstream in;
	in.open(_path);
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
		//while (!in.eof())
		//{
		//	//чтение очередного значения из потока F в переменную a
		//	in >> line;
		//	//вывод значения переменной a на экран
		//	cout << line <<endl;
		//}
	}
	in.close();
}

void File::WriteFile(string nameCard, string valute, string cardType, int amountOfMoney, int creditLimit=0)
{
	std::ofstream out;
	out.open(_path, std::ios::app);
	if (out.is_open())
	{
		if (cardType == "debet")
		{
			out << "Name: " << nameCard << " Card type: " << cardType << " Wallet amount of money:" << amountOfMoney << " " << valute << endl;
			cout << "Writing success!" << endl;
		}
		else
		{
			out << "Name: " << nameCard << " Card type: " << cardType << " Wallet amount of money:" << amountOfMoney << " " << valute << " Credit limit: " << creditLimit << endl;
			cout << "Writing success!" << endl;
		}
	}
	out.close();
}
