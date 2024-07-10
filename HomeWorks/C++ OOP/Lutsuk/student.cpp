#include <iostream>

using namespace std;

class Student
{
protected:
	int Age;
	string nameID;

public:
	Student()
	{}
	Student(string name, int age) : nameID{name}, Age{age}
	{
		cout << "Studient name: " << name << " Age: " << age << endl;
	}

};

class aspirante : protected Student
{
protected:
	string Dissertation;
public:
	aspirante()
	{
	}
	aspirante(string name, int age, string theme) : Student(name,age), Dissertation{theme}
	{
	cout << "Aspirante name: " << name << " Age: " << age << " Diplom's theme : " << theme << endl;
	}
};







int main()
{
	setlocale(LC_ALL, "rus");
	Student Fernando("fernando alonso", 45);
	Fernando.display();

	aspirante lapooh("lapooh", 48, "Выпригивающий из тостера хлеб, как причина инфаркта у котов: уголовно-правовая хар-ка и проблемы квалификации.")
		lapooh.display();
}

