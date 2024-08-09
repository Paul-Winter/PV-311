//ЗАДАНИЕ 1
//Дана шахматная доска размером 8×8 и шахматный конь. Программа должна
//запросить у пользователя координаты клетки поля и поставить туда коня.
//Задача программы найти и вывести путь коня, при котором он обойдет все
//клетки доски, становясь в каждую клетку только один раз. 
//(Так как процесс отыскания пути для разных начальных клеток может затянуться,
//то рекомендуется сначала опробовать задачу на поле размером 6×6).
//В программе необходимо использовать рекурсию.

#include <iostream>
using namespace std;

void display(int** mass, int size)          //вывод доски на экран
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

bool isIcan(int** mass, int size, int x, int y)             //проверяем - можно-ли становиться в эту клетку
{
    if ((x > 0 && x <= size) && (y > 0 && y <= size))
    {
        if (mass[x - 1][y - 1] == 0)
        {
            return true;
        }
    }
    return false;
}

bool isOwer(int** mass, int size)               //проверяем - всё-ли пройдено           
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mass[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int countSteps(int** mass, int size, int x, int y)      //считаем число возможных шагов из даной клетки
{
    int counts = 0;

    for (int direction = 1; direction < 9; direction++)
    {
        int buf_x = x;
        int buf_y = y;

        switch (direction)
        {
        case 1:         //вверх-влево
            x -= 2;
            --y;
            break;
        case 2:         //вверх-вправо
            x -= 2;
            ++y;
            break;
        case 3:         //вниз-влево
            x += 2;
            --y;
            break;
        case 4:         //вниз-вправо
            x += 2;
            ++y;
            break;
        case 5:         //влево-вверх
            --x;
            y -= 2;
            break;
        case 6:         //влево-вниз
            ++x;
            y -= 2;
            break;
        case 7:         //вправо-вверх
            --x;
            y += 2;
            break;
        case 8:         //вправо-вниз
            ++x;
            y += 2;
        }
        if (isIcan(mass, size, x, y))
        {
            ++counts;
        }
        x = buf_x;
        y = buf_y;
    }
    return counts;
}

int** nextStep(int** mass, int size, int** steps, int x, int y)     //заполняем вспомогательный массив
{
    for (int direction = 1; direction < 9; direction++)     
    {
        int buf_x = x;
        int buf_y = y;
        
        switch (direction)
        {
        case 1:         //вверх-влево
            x -= 2;
            --y;
            break;
        case 2:         //вверх-вправо
            x -= 2;
            ++y;
            break;
        case 3:         //вниз-влево
            x += 2;
            --y;
            break;
        case 4:         //вниз-вправо
            x += 2;
            ++y;
            break;
        case 5:         //влево-вверх
            --x;
            y -= 2;
            break;
        case 6:         //влево-вниз
            ++x;
            y -= 2;
            break;
        case 7:         //вправо-вверх
            --x;
            y += 2;
            break;
        case 8:         //вправо-вниз
            ++x;
            y += 2;
        }
        steps[direction - 1][0] = x;
        steps[direction - 1][1] = y;
        if (isIcan(mass, size, x, y))
        {
            steps[direction - 1][2] = 1;
            steps[direction - 1][3] = countSteps(mass, size, x, y);
        }
        else
        {
            steps[direction - 1][2] = 0;
            steps[direction - 1][3] = 0;
        }
        x = buf_x;
        y = buf_y;
    }
    return steps;                   
}

int game(int** mass, int size, int** steps, int x, int y, int counter)
{
    int min = 8;
    int min_index = 0;

    if (!isOwer(mass, size))                            //продолжаем, пока все клетки не пройдены
    {
        steps = nextStep(mass, size, steps, x, y);      //сначала ищем все возможные ходы
        for (int i = 0; i < 8; i++)
        {
            if (steps[i][3] < min && steps[i][2] == 1)
            {
                min = steps[i][3];                  
                min_index = i;                          //выбираем тот, из которого меньше всего возможных ходов
            }
        }
        ++counter;
        x = steps[min_index][0];
        y = steps[min_index][1];
        mass[x - 1][y - 1] = 1;                         //ставим коня в новую клетку
        cout << counter << " step (" << x << "," << y << ")\n";
        display(mass, size);                            //выводим новое состояние доски
        game(mass, size, steps, x, y, counter);         //рекурсия
    }
    else                                                //если не пройденных клеток не осталось - выходим
    {
        return counter;
    }
}

int main()
{
    int x = 0;                          //строка
    int y = 0;                          //столбец
    int size = 8;                       //размерность доски
    int counter = 0;                    //счётчик ходов
    
    cout << "Enter dimension chess board (default 8):";     //устанавливаем размерность доски
    cin >> size;
    
    int** board = new int* [size];      //создаём доску    
    for (int i = 0; i < size; ++i)
    {
        board[i] = new int[size];
    }
    for (int i = 0; i < size; ++i)      //инициализируем её нулями
    {
        for (int j = 0; j < size; ++j)
        {
            board[i][j] = 0;
        }
    }

    int** steps = new int* [4];         //массив для расчёта координат ходов (8-строк для каждого направления)
    for (int i = 0; i < 8; ++i)         //[0] столбец - для координат по х
    {                                   //[1] столбец - для координат по y
        steps[i] = new int[8];          //[2] столбец - признак возможности хода (0 или 1)
    }                                   //[3] столбец - количество возможных ходов из данной клетки

    cout << "Chess board " << size << "x" << size << ". Enter coordinates of horse (x,y):" << endl;
    bool trigger = true;
    while (trigger)
    {
        cout << "x=";
        cin >> x;
        cout << "y=";
        cin >> y;
        if ((x > 0 && x <= size) && (y > 0 && y <= size))
        {
            trigger = false;
        }
        else
        {
            cout << "Incorrect coordinates! Try again:\n";
        }
    }
    
    board[x - 1][y - 1] = 1;            //устанавливаем коня в указанных координатах
    display(board, size);               //выводим исходное положение

    cout << "Finded " << game(board, size, steps, x, y, counter) << " moves.";            //вызов рекурсивной функции
    
    return 0;
}