//ЗАДАНИЕ 2
//Необходимо поменять горизонтали с вертикалями массива 5*10,
//т.е. сделать его 10*5 и считать не по строкам, а по столбцам

#include <iostream>
#include <ctime>

using namespace std;

void display(int** mass, int lenght_horizontal, int lenght_vertical)
{
    for (int i = 0; i < lenght_horizontal; ++i)
    {
        for (int j = 0; j < lenght_vertical; ++j)
        {
            cout << mass[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    srand(time(0));

    int lenght_horizontal_one = 10;                     //было 5
    int lenght_vertical_one = 5;                        //было 10
    int** one_mass = new int* [lenght_horizontal_one];

    int lenght_horizontal_two = 5;
    int lenght_vertical_two = 5;
    int** two_mass = new int* [lenght_horizontal_two];

    //Создание массивов в оперативной памяти (в куче)
    for (int i = 0; i < lenght_horizontal_one; ++i)
    {
        one_mass[i] = new int[lenght_vertical_one];
    }
    for (int i = 0; i < lenght_horizontal_two; ++i)
    {
        two_mass[i] = new int[lenght_vertical_two];
    }

    //Инициализация первого массива случайными числами
    for (int i = 0; i < lenght_horizontal_one; ++i)
    {
        for (int j = 0; j < lenght_vertical_one; ++j)
        {
            one_mass[i][j] = rand() % 51;
        }
    }

    display(one_mass, lenght_horizontal_one, lenght_vertical_one);

    for (int i = 0, l = 0; l < lenght_horizontal_one; l += 2, ++i)  //было (int i = 0; i < lenght_vertical_two; ++i)
    {
        for (int j = 0; j < lenght_horizontal_two; ++j)             //было (int j = 0, l = 0; l < lenght_horizontal_one; l += 2, ++j)
        {
            two_mass[i][j] = one_mass[l][j] + one_mass[l + 1][j];   //было two_mass[i][j] = one_mass[i][l] + one_mass[i][l + 1];
        }
    }

    display(two_mass, lenght_horizontal_two, lenght_vertical_two);
}