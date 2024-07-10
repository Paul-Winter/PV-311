// queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Queue
{
public:
    
    // максимальный размер
    int max_size;

    // фактический размер
    size_t cur_size;

    // сама очередь
    char* massive = new char[max_size];

    // добавление в очередь
    void add(char s)
    {
        if (!is_full())
        {
            massive[cur_size++] = s;
        }
        
    }
    
    // удаление из очереди
    char ex()
    {
        if (!is_empty())
        {
            char temp = massive[0];
            for (int i = 1; i < cur_size; i++)
            {
                massive[i - 1] = massive[i];
            }
            cur_size--;
            return temp;
        } else return 0;

    }

    void Clear()
    {
        cur_size = 0;
    }
    
    // вывод всех стоящих в очереди
    void display()
    {
        for (int i = 0; i < cur_size; i++)
        {
            cout << massive[i] << endl;
        }
    }

    //проверка на пустоту
    bool is_empty()
    {
        return cur_size == 0;
    }
    
    //проверка на заполненнсть
    bool is_full()
    {
        return cur_size == max_size;
    }

    Queue(int max_size)
    {
        this->max_size = max_size;
    };
    ~Queue()
    {
        delete[] massive;
    };

};

int main()
{
    Queue a(3);
    a.add('q');
    a.add('w');
    a.add('e');
    cout << a.ex();
    cout << a.ex();
    cout << a.ex();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
