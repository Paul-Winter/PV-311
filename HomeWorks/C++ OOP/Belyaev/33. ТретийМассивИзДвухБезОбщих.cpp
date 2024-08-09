//ЗАДАНИЕ 2
//Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
//Необходимо создать третий массив минимально возможного размера,
//в котором нужно собрать элементы массивов A и B,
//которые не являются общими для них, без повторений.

#include <iostream>
using namespace std;

void display(int* mass, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void fill(int* mass, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 20;
    }
}

int isPresent(int* mass, int size, int number)  //функция, возвращающая количество вхождений в массив, передаваемого ей значения number
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (mass[i] == number)
        {
            ++counter;
        }
    }
    return counter;
}

int main()
{
    cout << "For optimal results try M=15, N=10\n" << endl;

    int M = 0;
    cout << "Enter size A: M=";
    cin >> M;
    int sizeA = M;
    int* massA = new int[sizeA];
    fill(massA, sizeA);
    cout << "Array A:" << endl;
    display(massA, sizeA);
    cout << endl;

    int N = 0;
    cout << "Enter size B: N=";
    cin >> N;
    int sizeB = N;
    int* massB = new int[sizeB];
    fill(massB, sizeB);
    cout << "Array B:" << endl;
    display(massB, sizeB);
    cout << endl;

    int count_p = 0;                        //счётчик повторений значений в массиве А
    int count_v = 0;                        //счётчик повторений значений из массива А, в массиве B

    for (int i = 0; i < sizeA; i++)         //определяем минимально возможную размерность третьего массива по массиву А
    {
        for (int j = i; j < sizeA; j++)     //ищем повторяющиеся значения в массиве A, чтобы их исключить
        {
            if (massA[i] == massA[j])
            {
                ++count_p;
            }
        }

        if (count_p < 2)                    //теперь ищем совпадения в массиве В
        {
            if (isPresent(massB, sizeB, massA[i]) == 0)
            {
                ++count_v;
            }
        }
        count_p = 0;
    }

    for (int i = 0; i < sizeB; i++)         //продолжаем определять минимально возможную размерность третьего массива по массиву В
    {
        for (int j = i; j < sizeB; j++)     //ищем повторяющиеся значения в массиве B, чтобы их исключить
        {
            if (massB[i] == massB[j])
            {
                ++count_p;
            }
        }

        if (count_p < 2)                    //теперь ищем совпадения в массиве A
        {
            if (isPresent(massA, sizeA, massB[i]) == 0)
            {
                ++count_v;
            }
        }
        count_p = 0;
    }

    int* massC = new int[count_v];          //создаём третий массив
    int count_m = 0;                        //счётчик для его элементов

    for (int i = 0; i < sizeA; i++)         //заполняем результирующий массив условленными значениями из массива А
    {
        for (int j = i; j < sizeA; j++)
        {
            if (massA[i] == massA[j])
            {
                ++count_p;
            }
        }

        if (count_p < 2)
        {
            if (isPresent(massB, sizeB, massA[i]) == 0)
            {
                massC[count_m] = massA[i];
                ++count_m;
            }
        }
        count_p = 0;
    }
    
    for (int i = 0; i < sizeB; i++)         //продолжаем заполнять результирующий массив условленными значениями из массива В
    {
        for (int j = i; j < sizeB; j++)
        {
            if (massB[i] == massB[j])
            {
                ++count_p;
            }
        }

        if (count_p < 2)
        {
            if (isPresent(massA, sizeA, massB[i]) == 0)
            {
                massC[count_m] = massB[i];
                ++count_m;
            }
        }
        count_p = 0;
    }
    
    cout << "Result array C[" << count_v << "]:" << endl;
    display(massC, count_v);
    
    return 0;
}