#include <iostream>
#include <fstream>

using namespace std;

class Chel
{

private:

	size_t sizeName;
	char* Name;
	int Age;
	int Weight;


public:

	Chel(const char* const Name, int Age, int Weight) : sizeName{ strnlen(Name,SIZE_MAX) + 1 }, Name{ new char[sizeName] }, Age{ Age }, Weight{ Weight }
	{
		if (this->sizeName > 0 && this->sizeName < SIZE_MAX)
		{
			
			this->Name = new char[this->sizeName];
			
			strcpy_s(this->Name, sizeName, Name);
		}

	}
	Chel(const char* const Name, int Age) : Chel(Name, Age, 0)
	{

	}
	Chel(const char* const Name) :Chel(Name, 0, 0)
	{

	}
	Chel() :Chel("\0", 0, 0)
	{

	}

	const char* const getName()
	{
		return Name;
	}
	int getAge()
	{
		return Age;
	}
	int getWeight()
	{
		return Weight;
	}
	size_t getSizeName()
	{
		return sizeName;
	}

	void setName(const char* const Name)
	{
		size_t newSize = strnlen (Name,SIZE_MAX) + 1;

		if (newSize > 0 && newSize < SIZE_MAX)
		{
			delete[] this->Name;
			this->Name = new char[newSize];
			this->sizeName = newSize;
			strcpy_s(this->Name, newSize, Name);
		}
	}
	void setAge(int Age)
	{
		this->Age = Age;
	}
	void setWeight(int Weight)
	{
		this->Weight = Weight;
	}

	Chel(const Chel& value) : Chel(value.Name,value.Age,value.Weight){}

	const Chel& operator= (const Chel& value)
	{
		size_t newSize = strnlen(value.Name, SIZE_MAX) + 1;

		if (newSize > 0 && newSize < SIZE_MAX)
		{
			delete[] this->Name;
			this->Name = new char[newSize];
			this->sizeName = newSize;
			strcpy_s(this->Name, newSize, value.Name);
		}
		
		this->Age = Age;
		this->Weight = Weight;

		return *this;
	}

	void PrintChel()
	{
		cout << "Name-" << Name << endl;
		cout << "Age-" << Age << endl;
		cout << "Weight-" << Weight << endl;		
	}
};

class ChelBase:Chel
{
private:
	size_t sizeChelmass;
	Chel* mass;
	size_t count;

public:
	ChelBase (size_t sizeChelmass = 100)
		: mass{ new Chel[sizeChelmass > 0 && sizeChelmass < SIZE_MAX ? sizeChelmass : 100 ] } , count{0}
	{}
	ChelBase(const ChelBase& value) : ChelBase (value.sizeChelmass)
	{
		if (mass != nullptr)
		{
			for (size_t i = 0; i < value.sizeChelmass; ++i)
			{
				this->mass[i] = value.mass[i];
			}
		}
	}

	const ChelBase& operator= (const ChelBase& value)
	{
		if (mass != nullptr)
		{
			delete[] mass;

			for (size_t i = 0; i < value.sizeChelmass; ++i)
			{
				//mass[i].setName(value.mass[i].getName());
				this->mass[i] = value.mass[i];
			}
		}
	}

	void AddChel(const char* const Name, int Age, int Weight)
	{
		if (count < sizeChelmass)
		{
			mass[count].setName(Name);
			mass[count].setAge(Age);
			mass[count].setWeight(Weight);
			++count;
		}
		else
		{
			sizeChelmass = sizeChelmass * 2;
			Chel* temp = new Chel[sizeChelmass];
			for (size_t i = 0; i < sizeChelmass/2; ++i)
			{
				temp[i] = mass[i];
			}

			delete[] mass;
			temp = mass;

			mass[count].setName(Name);
			mass[count].setAge(Age);
			mass[count].setWeight(Weight);
			++count;
		}
	}

	size_t Find(const char* const Name)
	{
		size_t temp_size = strnlen(Name, SIZE_MAX);

		for (size_t i = 0; i < count; ++i)
		{
			if (this->mass[i].getSizeName() == temp_size)
			{
				if (strncmp(Name, this->mass[i].getName(), temp_size) == 0)
				{
					return i;
				}
			}
		}

		return SIZE_MAX;
	}

	size_t Del(const char* const Name)
	{

		size_t findRes = Find(Name);
		if (findRes != SIZE_MAX)
		{
			if (findRes == count - 1)
			{
				mass[findRes].setName("\0");
				mass[findRes].setAge(0);
				mass[findRes].setWeight(0);

				--count;

				return findRes;
			}

			for (size_t i = findRes; i < count-1; ++i)
			{
				mass[i] = mass[i + 1];
			}
			mass[count - 1].setName("\0");
			mass[count - 1].setAge(0);
			mass[count - 1].setWeight(0);

			--count;
			return findRes;
		}
		
		return SIZE_MAX;
	}
	void Display()
	{
		for (int i = 0; i < count; ++i)
		{
			mass[i].PrintChel();
		}
	}

	bool write()
	{
		ofstream file;
		file.open("Chel.txt", ios::out | ios::binary);
		//file.write("D:\\по_программированию\\класс_библиотека\\библиотека\\f.txt", ios::in );
		int Age;
		int Weight;
		if (file.is_open())
		{
			file.write((char*)&count, sizeof(count));
			for (int i = 0; i < count; i++)
			{
				file.write(mass[i].getName(), 32);
				
				Age = mass[i].getAge();
				file.write((char*)&Age, sizeof(int));
				Weight = mass[i].getWeight();
				file.write((char*)&Weight, sizeof(int));
			}
			file.close();
			cout << "Writing complete!"s << endl << endl;
			return true;
		}
		else
		{
			cout << "Writing not complete!"s << endl << endl;
			return false;
		}

	}

	bool read()
	{
		ifstream file;
		file.open("Chel.txt", ios::in | ios::binary);
		int Age;
		int Weight;
		if (file.is_open())
		{
			cout << "File is open. " << endl << endl;
			file.read((char*)&count, sizeof(int));
			for (size_t i = 0; i < count; ++i)
			{
				file.read((char*)mass[i].getName(), 32);

				Age = mass[i].getAge();
				file.read((char*)&Age, sizeof(int));
				Weight = mass[i].getWeight();
				file.read((char*)&Weight, sizeof(int));
				
			}
			file.close();
			return true;
		}
		else
		{
			cout << "File corrupted. " << endl << endl;
			return false;
		}
	}





};


int main()
{
	//Chel a("dggghf");
	//Chel b("");
	

	//cout << b.getName();


	//a.setName("hjbh");


	//ChelBase a;

	//ChelBase b;

	//a = b;
	Chel a;

	ChelBase chel;
	chel.AddChel("Sysoy", 23, 57);
	chel.AddChel("Brother_of_Sysoy", 33, 48);
	//a.PrintChel();
	chel.Display();
	chel.write();
	chel.read();

	

}