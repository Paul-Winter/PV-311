#include <iostream>
using namespace std;

class Stack 
{
	// сам массив 
	size_t high= 100;
	char* symbol =new char[high];
	//указатель на вершину 
	size_t low = 0;
	int top = low;
	// определить ниж и верх границы 
	
public:
	// конструктор
	Stack();

	// деструктор
	~Stack()
	{
		delete[] symbol;
	}

	// проверочные методы   
	// на полноту
	bool is_full()
	{
		return top==high-1;
	}
	// на пустоту
	bool is_empty()
	{
		return top==low;
	}

	//очистка стека
	void Clear()
	{
		top = low;
	}

	//кол во элементов 
	int displey_elements()
	{
		return top;
	}

	// метод добавляющий элемент
	void push_element(char other)
	{
		if (!is_full()) {
			symbol[top++] = other;
		}
	
	}

	// метод извлекания элемента
	char pop_element()
	{
		if (!is_empty()) {
			return symbol[--top];
		}
		return 0;
	}
};


int main()
{
	Stack a;
	a.push_element('q');
	a.push_element('w');
	a.push_element('e');
	a.push_element('r');
	a.push_element('t');
	a.push_element('y');
	cout << a.displey_elements() << endl;
	cout << a.pop_element();
	cout << a.pop_element();
	cout << a.pop_element();
	cout << a.pop_element();
	cout << a.pop_element();
	cout << a.pop_element();


}
