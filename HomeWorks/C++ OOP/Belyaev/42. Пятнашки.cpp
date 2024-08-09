//ЗАДАНИЕ 2
//Написать игру «Пятнашки».

#include <iostream>
using namespace std;

void display(int** mass, int size)          //вывод доски на экран
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
}

int findN(int** mass, int size, int number)         //функция возвращает количество вхождения заданного числа в данны массив
{
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (mass[i][j] == number)
            {
                ++counter;
            }
        }
    }
    return counter;
}

void fill(int** mass, int size)             //функция заполняет поля в случайном порядке
{
    int k = 0;
    srand(time(0));
    for (int i = 0; i < size; ++i)          //заполнили случайными числами от 0 до 15
    {
        for (int j = 0; j < size; ++j)
        {
            mass[i][j] = rand() % 16;
        }
    }
    
    for (int i = 0; i < size; ++i)          //там где числа задублировались, ставим -1
    {
        for (int j = 0; j < size; ++j)
        {
            if (findN(mass, size, mass[i][j]) > 1)
            {
                mass[i][j] = -1;
            }
        }
    }
    
    while (k < 16)                          //там где были -1 ставим недостающие числа
    {
        if (findN(mass, size, k) < 1)
        {
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (mass[i][j] == -1)
                    {
                        mass[i][j] = k;
                        i = size;
                        j = size;
                    }
                }
            }
        }
        ++k;
    }
}

void fill2(int** mass, int size)            //функция создаёт ситуацию за ход до окончания игры
{
    int k = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mass[i][j] = k;
            ++k;
        }
    }
    mass[3][3] = 15;
    mass[3][2] = 0;
}

bool isOver(int** mass, int size)               //функция проверяет состояние когда всё сложено
{
    int p = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (p == 15 && mass[3][3] == 0)
            {
                return true;
            }
            if (mass[i][j] == p)
            {
                ++p;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

bool isIcan(int** mass, int size, int* step)        //функция проверяет можно ли сделать ход, по введёным игроком параметрам
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mass[i][j] == step[0])
            {
                if (step[1] == 8)                   //вверх
                {
                    if ((i - 1) > -1)
                    {
                        if (mass[i - 1][j] == 0)
                        {
                            return true;
                        }
                    }
                }
                if (step[1] == 2)                   //вниз
                {
                    if ((i + 1) < 4)
                    {
                        if (mass[i + 1][j] == 0)
                        {
                            return true;
                        }
                    }
                }
                if (step[1] == 4)                   //влево
                {
                    if ((j - 1) > -1)
                    {
                        if (mass[i][j - 1] == 0)
                        {
                            return true;
                        }
                    }
                }
                if (step[1] == 6)                   //вправо
                {
                    if ((j + 1) < 4)
                    {
                        if (mass[i][j + 1] == 0)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool replase(int** mass, int size, int* step)       //функция меняет местами выбранные числа
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mass[i][j] == step[0])
            {
                if (step[1] == 8)                   //обмен местами с верхним значением
                {
                    mass[i - 1][j] = step[0];
                    mass[i][j] = 0;
                    return true;
                }
                if (step[1] == 2)                   //обмен местами с нижним значением
                {
                    mass[i + 1][j] = step[0];
                    mass[i][j] = 0;
                    return true;
                }
                if (step[1] == 4)                   //обмен местами с левым значением
                {
                    mass[i][j - 1] = step[0];
                    mass[i][j] = 0;
                    return true;
                }
                if (step[1] == 6)                   //обмен местами с правым значением
                {
                    mass[i][j + 1] = step[0];
                    mass[i][j] = 0;
                    return true;
                }
            }
        }
    }
    return false;
}

int game(int** mass, int size, int* step, int counter)
{
    int number = 0;
    int direction = 0;

    if (!isOver(mass, size))                                                            //если не на своих местах
    {
        bool trigger = true;
        while (trigger)
        {
            cout << "Step " << counter << ". That's the number to be move? (1-15): ";   //запрашиваем число, которое будем перемещать
            cin >> number;

            cout << "Direction? (8 - up, 4 - left, 6 - right, 2 - down): ";             //запрашиваем направление
            cin >> direction;
            cout << endl;

            if ((number >= 1 && number <= 15))                                          //проверка на корректность введённых данных
            {
                if ((direction == 2) || (direction == 4) || (direction == 6) || (direction == 8))
                {
                    step[0] = number;
                    step[1] = direction;
                    if (!isIcan(mass, size, step))                                      //если не можем встать по введённым данных, повторяем ввод
                    {
                        cout << "Incorrect direction! Try again:\n";
                    }
                    else
                    {
                        trigger = false;
                    }
                }
                else
                {
                    cout << "Incorrect direction! Try again:\n";
                }
            }
            else
            {
                cout << "Incorrect nuber! Try again:\n";
            }
        }

        replase(mass, size, step);                                  //меняем числа местами
        display(mass, size);                                        //выводим новое состояние доски
        ++counter;
        game(mass, size, step, counter);                            //рекурсия
    }
    else
    {
        return --counter;
    }
}

int main()
{
    int size = 4;                       //размерность доски
    int counter = 1;                    //счётчик ходов
       
    int* step = new int[2];             //ход - число и направление
    int** board = new int* [size];      //создаём доску    
    for (int i = 0; i < size; ++i)
    {
        board[i] = new int[size];
    }
    fill(board, size);                  //заполняем в случайном порядке
    //fill2(board, size);               //инициализируем ситуацию за ход до завершения
    display(board, size);               //выводим исходное состояние

    cout << "You win at " << game(board, size, step, counter) << " steps.";     //вызов рекурсивной функции

	return 0;
}