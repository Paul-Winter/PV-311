//ЗАДАНИЕ 3.
//Шифр Цезаря — один из древнейших шифров.
//При шифровании каждый символ заменяется другим,
//отстоящим от него в алфавите на фиксированное число позиций.
//Пример
//■ Шифрование с использованием ключа : 3.
//■ Оригинальный текст : Съешь же ещё этих мягких
//французских булок, да выпей чаю.
//■ Шифрованный текст : Фэзыя йз зьи ахлш пвёнлш
//чугрщцкфнлш дцосн, жг еютзм ъгб.
//■ Дан текстовый файл.Зашифровать его, используя
//шифр Цезаря. Результат записать в другой файл.

#include <iostream>
using namespace std;

char encryption(char symbol, int offset)
{
	int symbol_code = 0;
	symbol_code = (int)symbol;

	if (symbol_code >64 && symbol_code < 91)
	{
		symbol_code += offset;
		
		if (symbol_code > 90)
		{
			symbol_code -= 26;
		}
	}

	if ((int)symbol > 96 && (int)symbol < 123)
	{
		symbol_code += offset;
		if (symbol_code > 122)
		{
			symbol_code -= 26;
		}
	}

    return (char)symbol_code;
}

int main()
{
	const char* source_path = "C:\\Intel\\source.txt";
	const char* result_path = "C:\\Intel\\result.txt";
	FILE* source;
	FILE* result;
	int current_symbol = 0;
	int offset = 0;

	cout << "-CODE OF CAESAR-\nEnter offset (1-26):\n>";
	cin >> offset;

	if (fopen_s(&source, source_path, "r") != NULL)
	{
		cout << "Can't open file " << source_path << " to read!" << endl;
	}
	else
	{
		if (fopen_s(&result, result_path, "w") != NULL)
		{
			cout << "Can't open file " << result_path << " to write!" << endl;
		}
		else
		{
			while (!feof(source))					//посимвольно перебираем до конца файла
			{
				current_symbol = fgetc(source);
				if ((int)current_symbol != -1)
				{
					fputc(encryption(current_symbol, offset), result);
				}
			}
		}
		fclose(result);
	}
	fclose(source);
	
	cout << "Done." << endl;

    return 0;
}