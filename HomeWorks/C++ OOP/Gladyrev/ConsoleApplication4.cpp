// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	int size;
	int a, b, * mas, x;

	do
	{
		cout << "Размер массива: ";
		cin >> size;
		if (size < 3)
			cout << "Размер не может быть меньше трёх." << endl;
	} while (size < 3);

	mas = new int[size];

	cout << "Введите 2 числа: ";
	cin >> a >> b;

	mas[0] = a <= b ? a : b;
	mas[1] = b >= a ? b : a;
	for (x = 2; x < size; x++)
		mas[x] = mas[x - 1] + mas[x - 2];

	cout << endl;
	for (x = 0; x < size; x++)
		cout << " " << mas[x];
	cout << endl;

	if (mas == (int*) nullptr)
		exit(1);
	delete[] mas;
	mas = (int*) nullptr;

	return 0;
}
