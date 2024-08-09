//ЗАДАНИЕ 1.
//Дано два текстовых файла. Выяснить, совпадают ли их строки.
//Если нет, то вывести несовпадающую строку из каждого файла.

#include <iostream>
using namespace std;

struct file_info
{
	int max_lenght_string = 0;	//максимальная длина строки в файле
	int max_number_string = 0;	//количество строк в файле

}; file_info f_info;

file_info maxString(const char* path)	//функция возвращает информацию о файле (макс.длина строки и кол-во строк)
{
	file_info f_info;
	FILE* in;
	int counter_lenght = 0;
	int counter_number = 0;
	int max_string = 0;
	char current_symbol = '\0';

	if (fopen_s(&in, path, "r") != NULL)
	{
		cout << "Can't open file to read!" << endl;
	}
	else
	{
		while (!feof(in))
		{
			current_symbol = fgetc(in);
			if (current_symbol != '\n')
			{
				++counter_lenght;
			}
			else
			{
				if (counter_lenght > max_string)
				{
					max_string = counter_lenght;
					counter_lenght = 0;
				}
			}
		}
		fseek(in, 0, SEEK_SET);
		char* current_string = new char[max_string];
		while (!feof(in))
		{
			fgets(current_string, max_string,in);
			++counter_number;
		}
	}
	fclose(in);
	
	f_info.max_lenght_string = max_string;
	f_info.max_number_string = counter_number;
	
	return f_info;
}

int string_lenght(char* current_string)             //функция возвращает длину строки из char*-массива
{
	int counter = 0;
	char symbol = '\0';
	while (current_string[counter] != '\0')
	{
		++counter;
	}

	return counter;
}

bool string_compare(char* string1, char* string2)   //функция возвращает истину, если строки из char-массивов равны
{
	bool equal = false;
	int counter = 0;
	int str_len = 0;

	if (string_lenght(string1) == string_lenght(string2))
	{
		str_len = string_lenght(string1);

		for (int i = 0; i < str_len; i++)
		{
			if (string1[i] == string2[i])
			{
				++counter;
			}
		}
		if (str_len == counter)
		{
			bool equal = true;
			return equal;
		}
	}

	return equal;
}

char* clearString(char* current_string)		//функция очищает строку в char-массиве
{
	int len = string_lenght(current_string);
	for (int i = 0; i < len; i++)
	{
		current_string[i] = '\0';
	}
	return current_string;
}

char* delEndLine(char* current_string)		//функция удаляет символ переноса строки (для наглядности при выводе)
{
	int len = string_lenght(current_string);
	
	if (current_string[len - 1] == '\n')
	{
		current_string[len - 1] = '\0';
	}

	return current_string;
}

int main()
{
	const char* source_path = "C:\\Intel\\source.txt";
	const char* result_path = "C:\\Intel\\result.txt";
	FILE* source;
	FILE* result;
	FILE* current;

	int source_counter = 0;
	int result_counter = 0;
	int string_size = 0;
	char current_symbol = '\0';
	file_info source_info;
	file_info result_info;
	int string_counter = 0;

	//считаем максимальную длину строки в файлах
	source_info = maxString(source_path);
	result_info = maxString(result_path);
	if (source_info.max_lenght_string > result_info.max_lenght_string)
	{
		string_size = source_info.max_lenght_string;
	}
	else
	{
		string_size = result_info.max_lenght_string;
	}
	char* souce_string = new char[string_size];
	char* result_string = new char[string_size];

	//открываем на чтение оба файла и в зависимости от того у кого количество строк больше, начинаем их сравнивать
	if (fopen_s(&source, source_path, "r") != NULL)
	{
		cout << "Can't open file " << source_path << " to read!" << endl;
	}
	else
	{
		if (fopen_s(&result, result_path, "r") != NULL)
		{
			cout << "Can't open file " << result_path << " to read!" << endl;
		}
		else
		{
			if (source_info.max_number_string > result_info.max_number_string)
			{
				while (!feof(source))
				{
					++string_counter;
					fgets(souce_string, string_size, source);
					souce_string = delEndLine(souce_string);
					fgets(result_string, string_size, result);
					result_string = delEndLine(result_string);
					if (!string_compare(souce_string, result_string))
					{
						cout << string_counter << ". " <<souce_string << "<>" << result_string << endl;
					}
					souce_string = clearString(souce_string);
					result_string = clearString(result_string);
				}
			}
			else
			{
				while (!feof(result))
				{
					++string_counter;
					fgets(souce_string, string_size, source);
					souce_string = delEndLine(souce_string);
					fgets(result_string, string_size, result);
					result_string = delEndLine(result_string);
					if (!string_compare(souce_string, result_string))
					{
						cout << string_counter << ". " << souce_string << " <> " << result_string << endl;
					}
					souce_string = clearString(souce_string);
					result_string = clearString(result_string);
				}
			}
		}
		fclose(result);
	}
	fclose(source);

	cout << "Done." << endl;

	return 0;
}
