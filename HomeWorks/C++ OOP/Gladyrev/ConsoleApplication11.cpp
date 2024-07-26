#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student();
	Student(string name, string surname, int year, int endyear);
	Student(Student& other);
	~Student();
	void get();
	void set();
private:
	string name;
	string surname;
	int year;
	int endyear;

};

Student::Student(string name, string surname, int year, int endyear) :name(name), surname(surname), year(year), endyear(endyear) {}
Student::Student() = default;
Student::~Student() = default;
Student::Student(Student& other) : name(other.name), surname(other.surname), year(other.year), endyear(other.endyear) {}

void Student::get()
{
	cout << " " << name << " " << surname << " " << year << " " << endyear << endl;
}
void Student::set()
{
	cout << "введите имя\n" << "введите фамилию\n" << "введите год поступления\n" << "введите год окончания учебы";
	cin >> name >> surname >> year >> endyear;
}

class Aspirant : public Student
{
public:
	Aspirant();
	Aspirant(string name, string surname, int year, int endyear, string theme, int start, int finish);
	~Aspirant();
	void set_i();
	void get_i();
private:
	string theme;
	int start;
	int finish;
};

Aspirant::Aspirant(string name, string surname, int year, int endyear, string theme, int start, int finish) :Student(name, surname, year, endyear), theme(theme), start(start), finish(finish) {}

Aspirant::Aspirant() :Student() {}

void Aspirant::set_i()
{
	set();
	cin >> theme >> start >> finish;
}

void Aspirant::get_i()
{
	get();
	cout << start << " " << finish << " " << theme << " " << endl;
}
Aspirant::~Aspirant() = default;

int main()
{
	Student a;
	a.set();
	a.get();

	return 0;

}