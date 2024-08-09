//ЗАДАНИЕ 2.
//Дан текстовый файл. Необходимо создать новый файл и записать
//в него следующую статистику по исходному файлу:
//■ Количество символов;
//■ Количество строк;
//■ Количество гласных букв;
//■ Количество согласных букв;
//■ Количество цифр.

#include <iostream>
using namespace std;

struct file_info
{
	int number_of_symbols = 0;		//количество символов
	int number_of_strings = 0;		//количество строк
	int number_of_vowels = 0;		//количество гласных
	int number_of_consonant = 0;	//количество согласных
	int number_of_digit = 0;		//количество цифр
	
}; file_info f_info;

char* NumberToString(int number)				//переводит число в строку и возвращает её в char-массиве
{
	int size = 10;
	int counter = 10;
	char* newString = new char[size];
	int buf = 0;
	char buffer = '\0';

	if (number < 2147483648)
	{
		for (int i = 0; i < 10; ++i)            //с младшего разряда получаем по одной цифре,
		{                                       //переводим в символ и записываем в строковый массив
			buf = number;
			number %= 10;
			newString[i] = char(number + 48);
			number = (buf - number) / 10;
		}

		for (int j = 9; j >= 0; --j)            //считаем сколько определилось разрядов
		{
			if ((int)newString[j] == 48)
			{
				--counter;
			}
			else
			{
				break;
			}
		}

		for (int i = 0, j = counter - 1; i <= j; ++i, --j)      //переворачиваем массив
		{                                                       //для правильного расположения символов
			buffer = newString[i];
			newString[i] = newString[j];
			newString[j] = buffer;
		}
		newString[counter] = '\0';
		return newString;
	}
	else
	{
		cout << "Wrong parametr!" << endl;
		return nullptr;
	}
}

char* string2char(string str)		//возвращет char-массив из переданной строки
{
	int counter = 0;
	char* cur_str = new char[255];
	while (str[counter] != '\0')
	{
		cur_str[counter] = str[counter];
		++counter;
	}
	cur_str[counter] = '\0';
	return cur_str;
}

int main()
{
	const char* source_path = "C:\\Intel\\source.txt";
	const char* result_path = "C:\\Intel\\result.txt";
	FILE* source;
	FILE* result;
	int current_symbol = 0;
	file_info info;
	int vowels[7]{ 1,5,9,10,15,21,25 };
	int consonant[19]{ 2,3,4,6,7,8,11,12,13,14,16,17,18,19,20,22,23,24,26 };
		
	if (fopen_s(&source, source_path, "r") != NULL)
	{
		cout << "Can't open file " << source_path << " to read!" << endl;
	}
	else
	{
		while (!feof(source))					//посимвольно перебираем до конца файла
		{
			current_symbol = fgetc(source);
			++info.number_of_symbols;			//считаем символы
			
			for (int i = 0; i < 7; i++)
			{
				if ((int)current_symbol == vowels[i] + 64 || (int)current_symbol == vowels[i] + 96)
				{
					++info.number_of_vowels;	//считаем гласные
				}
			}

			for (int i = 0; i < 19; i++)
			{
				if ((int)current_symbol == consonant[i] + 64 || (int)current_symbol == consonant[i] + 96)
				{
					++info.number_of_consonant;	//считаем согласные
				}
			}

			if ((int)current_symbol > 47 && (int)current_symbol < 58)
			{
				++info.number_of_digit;			//считаем цифры
			}
		}
		fseek(source, 0, SEEK_SET);				//возвращаемся в начало потока
		char* current_string = new char[255];
		while (!feof(source))					//теперь считываем файл построчно
		{
			fgets(current_string, 255, source);
			++info.number_of_strings;			//считаем строки
		}
		delete[] current_string;
	}

	//пишем результаты в файл
	if (fopen_s(&result, result_path, "w") != NULL)
	{
		cout << "Can't open file " << result_path << " to write!" << endl;
	}
	else
	{
		fputs(string2char("Number of symbols: " + (string)NumberToString(info.number_of_symbols)), result);
		fputc('\n',result);
		fputs(string2char("Number of strings: " + (string)NumberToString(info.number_of_strings)), result);
		fputc('\n', result);
		fputs(string2char("Number of vowels: " + (string)NumberToString(info.number_of_vowels)), result);
		fputc('\n', result);
		fputs(string2char("Number of consonant: " + (string)NumberToString(info.number_of_consonant)), result);
		fputc('\n', result);
		fputs(string2char("Number of digits: " + (string)NumberToString(info.number_of_digit)), result);
	}
	fclose(result);
	
	//вывод результатов
	cout << "Reading file " << result_path << ":" << endl;
	if (fopen_s(&result, result_path, "r") != NULL)
	{
		cout << "Can't open file " << result_path << " to write!" << endl;
	}
	else
	{
		char* current_string = new char[255];
		while (!feof(result))
		{
			cout << fgets(current_string, 255, result);
		}
		delete[] current_string;
	}
	fclose(result);
	cout << "\nDone." << endl;
	
	return 0;
}