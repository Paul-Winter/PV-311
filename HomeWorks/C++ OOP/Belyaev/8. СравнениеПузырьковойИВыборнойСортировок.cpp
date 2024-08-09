//ЗАДАНИЕ 4
//Написать программу, которая сравнивает число перестановок элементов
//при использовании сортировки «пузырьком» (усовершенствованная версия задания 2) и методом
//выбора. Выполнить ее тестирование на разных 10 массивах,
//содержащих 1000 случайных элементов, вычислить среднее
//число перестановок для каждого метода после тестирования

#include <iostream>
using namespace std;

int main()
{

    srand(time(0));

    int size = 1000;
    int buf = 0;
    int num = 0;
    int puz = 0;
    int vib = 0;
    int min = 0;
    
    for (int k = 1; k != 10; k++)           //в этом цикле создаём 10 массивов по 1000 элементов
    {
        int* mass = new int[size];
        int* copy = new int[size];              

        for (int i = 0; i < size; ++i)
        {
            mass[i] = 1 + rand() % 1000;    //для чистоты эксперемента
            copy[i] = mass[i];              //создаём полную копию исходного массива, чтобы обрабатывать тот же набор чисел
        }

        //перестановка пузырьком
        for (int i = 0; i < size; ++i)
        {
            num = 0;
            for (int j = 0; j < size - 1; ++j)
            {
                if (mass[j] > mass[j + 1])
                {
                    buf = mass[j];
                    mass[j] = mass[j + 1];
                    mass[j + 1] = buf;
                    ++num;
                    ++puz;                  //считаем перестановки пузырьковым методом
                }
            }
            if (num == 0)
            {
                i = size;
            }
        }

        //перестановка выбором
        for (int i = 0; i < size; ++i)
        {
            min = i;
            for (int j = i + 1; j < size; ++j)
            {

                if (copy[j] < copy[min])
                {
                    buf = copy[min];
                    copy[min] = copy[j];
                    copy[j] = buf;
                    ++vib;                  //считаем перестановки методом выбора
                }
            }
        }
    }
    
    cout << "Srednee chislo perestanovok PUZYRKOM = " << puz / 10 << endl;
    cout << "Srednee chislo perestanovok VIBOROM = " << vib / 10 << endl;
    
    return 0;
}