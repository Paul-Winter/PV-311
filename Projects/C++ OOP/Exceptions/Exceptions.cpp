#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	// try
	// throw
	// catch

	//try
	//{
	//	cout << "Before" << endl;
	//	//
	//	//
	//	//
	//	throw (double)40,4;
	//	cout << "After" << endl;
	//	//
	//	//
	//	//
	//}
	//catch (int ex)
	//{
	//	cout << "Exception int\t" << ex << endl;
	//}
	//catch (float ex)
	//{
	//	cout << "Exception float\t" << ex << endl;
	//}
	//catch (...)
	//{
	//	cout << "Exception\t" << endl;
	//}

	try
	{
		int length; 
		cout << "Input length array: ";
		cin >> length;
		/*if ( length <= 0 || length > 10)
		{
			throw "Error length";
		}*/
		double* arr = 0;
		if (!arr)
		{
			throw arr;
		}
			arr = new double[length];
		cout << "Arr created!";
	}
	catch (char* ex)
	{
		cout << ex;
	}
	catch (...)
	{
		cout << "Error length";
	}

}
