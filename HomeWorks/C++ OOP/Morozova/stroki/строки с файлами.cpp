// строки с файлами.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//6. Полное имя (путь) файла
//Написать функцию, которая принимает путь файла
//и возвращает :
//a) Путь без имени файла(если пути не было — вывести
//пустую строку);
//b) Имя последней папки в пути;
//c) Имя файла с расширением, но без пути;
//d) Расширение имени файла;
//e) Имя файла без пути и без расширения.
//Например, из строки ”C : \Step\С++lesson_03\Docs\
//Less03.docx” должно получиться :
//a) “C:\Step\С++lesson_03\Docs”;
//b)“Docs”;
//c) “Less03.docx”;
//d) ”.docx”;
//e) ”Less03”.
//
#include <iostream>
#include <string>
using namespace std;

string File(string path,char mode)//путь и  режим
{
	size_t lastSeporation = path.find_last_of('\\');//специальный тип данных для индексов наших стринг,он будет находить наш последний слэш
	string withoutFile = path.substr(0, lastSeporation);
	size_t Seporation = withoutFile.find_last_of('\\');//предпоследний слэш
	size_t lastDot = path.find_last_of('.');//find_last_of- найти последний
	switch (mode)
	{
	case 'a':
		if (lastSeporation == string::npos)//если слэша нет, мы возвращаем ничего
		{
			return"";
		}
		return path.substr(0, lastSeporation);//строка перед последним слэш
		break;
	case 'b':
		if (lastSeporation == string::npos)//если слэша нет, мы возвращаем ничего
		{
			return"";
		}
		
		if (Seporation == string::npos)
		{
			return withoutFile;
		}
		return withoutFile.substr(Seporation+1);//с чего начинается
		break;
	case 'c':
		if (lastDot == string::npos)//если точки нет, мы возвращаем ничего
		{
			return"";
		}
		return path.substr( lastSeporation +1);//строка после последним слэш
		break;
	case 'd':
		if (lastDot == string::npos)//если nточки нет, мы возвращаем ничего
		{
			return"";
		}
		return path.substr(lastDot);//строка после точки
		break;
	case 'e':
		if (lastDot == string::npos)//если точки нет, мы возвращаем ничего
		{
			return"";
		}
		return path.substr(lastSeporation + 1, path.length()-lastDot );//строка после последним слэш и точкой
		break;//substr - метод строки, к-ый берет либо 1 либо 2 аргумента

	}
}


int main()
{
	string str;
	char mode;
	cin >> str;
	cin >> mode;
	cout << File(str, mode);
}

