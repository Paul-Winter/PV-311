//ЗАДАНИЕ 1
//Создайте структуру, описывающую комплексное число.
//Реализуйте арифметические операции с комплексными числами:
//сумму, разность, умножение, деление.

#include <iostream>
using namespace std;

struct complex
{
	double Re;
	double Im;

	void fill()
	{
		cout << "Enter the real part of the complex number: ";
		cin >> Re;
		cout << "Enter the imaginary part of the complex number: ";
		cin >> Im;
	}
	
	void display()
	{
		cout << Re;
		if (Im >= 0)
			cout << "+" << Im << "i" << endl;
		else
			cout << Im << "i" << endl;
	}
};

complex sum(complex number1, complex number2)
{
	complex number3;
	number3.Re = number1.Re + number2.Re;
	number3.Im = number1.Im + number2.Im;

	return number3;
}

complex difference(complex number1, complex number2)
{
	complex number3;
	number3.Re = number1.Re - number2.Re;
	number3.Im = number1.Im - number2.Im;

	return number3;
}

complex multiplication(complex number1, complex number2)
{
	complex number3;
	number3.Re = number1.Re * number2.Re - number1.Im * number2.Im;
	number3.Im = number1.Im * number2.Re + number1.Re * number2.Im;

	return number3;
}

complex division(complex number1, complex number2)
{
	complex number3;
	number3.Re = (number1.Re * number2.Re + number1.Im * number2.Im) / (number2.Re * number2.Re + number2.Im * number2.Im);
	number3.Im = (number1.Im * number2.Re - number1.Re * number2.Im) / (number2.Re * number2.Re + number2.Im * number2.Im);

	return number3;
}

int main()
{
	complex c_number1, c_number2, c_number3;

	c_number1.fill();
	c_number1.display();

	c_number2.fill();
	c_number2.display();
	
	c_number3 = sum(c_number1, c_number2);
	cout << "Sum of this complex numbers: ";
	c_number3.display();

	c_number3 = difference(c_number1, c_number2);
	cout << "Difference of this complex numbers: ";
	c_number3.display();

	c_number3 = multiplication(c_number1, c_number2);
	cout << "Multiplication of this complex numbers: ";
	c_number3.display();
	
	c_number3 = division(c_number1, c_number2);
	cout << "Division of this complex numbers: ";
	c_number3.display();

	return 0;
}