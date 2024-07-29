
#include <iostream>
using namespace std;

template<typename T>
class intager {
public:
	T size;
	T* mass;
	intager() : size{ 10 }, mass{ new T[size] }
	{}
	intager(T size) : size{ size }, mass{ new T[size] }
	{}

	T* fillmass() {
		for (size_t i = 0; i < size; ++i)
		{
			cout << "Input elemant №" << i + 1 << " :";
			cin >> mass[i];
		}
		return mass;
	}

	void display() {
		for (size_t i = 0; i < size; ++i) {
			cout << mass[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	int b = 10;
	intager<int> a(10);
	a.fillmass();
	a.display();
}

