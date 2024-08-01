//ЗАДАНИЕ 3.
//Написать игру «Крестики-нолики».

#include <iostream>
using namespace std;

void display(char** mass, int size)          //вывод доски на экран
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

char isOwer(char** mass, int size)  //проверяем есть ли уже три подряд и наличие свободных полей, а также ничью
{                                   //возвращает 0 - если есть три поля с 0, Х - если три поля с Х, . - если есть ходы, пробел - если ничья               
    int p = 0;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (mass[i][j] == '.')
            {
                ++p;
            }
        }
    }
        
    for (int i = 1; i < 4; i++)
    {
        if ((mass[i][1] == '0') && (mass[i][2] == '0') && (mass[i][3] == '0'))
        {
            return '0';
        }
    }
    for (int i = 1; i < 4; i++)
    {
        if ((mass[i][1] == 'X') && (mass[i][2] == 'X') && (mass[i][3] == 'X'))
        {
            return 'X';
        }
    }

    for (int j = 1; j < 4; j++)
    {
        if ((mass[1][j] == '0') && (mass[2][j] == '0') && (mass[3][j] == '0'))
        {
            return '0';
        }
    }
    for (int j = 1; j < 4; j++)
    {
        if ((mass[1][j] == 'X') && (mass[2][j] == 'X') && (mass[3][j] == 'X'))
        {
            return 'X';
        }
    }

    if ((mass[1][1] == '0') && (mass[2][2] == '0') && (mass[3][3] == '0'))
    {
        return '0';
    }
    if ((mass[3][1] == '0') && (mass[2][2] == '0') && (mass[1][3] == '0'))
    {
        return '0';
    }
    if ((mass[1][1] == 'X') && (mass[2][2] == 'X') && (mass[3][3] == 'X'))
    {
        return 'X';
    }
    if ((mass[3][1] == 'X') && (mass[2][2] == 'X') && (mass[1][3] == 'X'))
    {
        return 'X';
    }

    if (p != 0)
    {
        return '.';
    }
    else
    {
        return ' ';
    }
}

int* move(char** mass, int size, int* step, char symbol)        //функция проверки на два подряд (возвращает координаты третьего)
{
    for (int i = 1; i < 4; i++)
    {
        if ((mass[i][1] == symbol) && (mass[i][2] == symbol) && (mass[i][3] == '.'))
        {
            step[0] = i;
            step[1] = 3;
        }
        if ((mass[i][2] == symbol) && (mass[i][3] == symbol) && (mass[i][1] == '.'))
        {
            step[0] = i;
            step[1] = 1;
        }
        if ((mass[i][1] == symbol) && (mass[i][3] == symbol) && (mass[i][2] == '.'))
        {
            step[0] = i;
            step[1] = 2;
        }
    }
    for (int j = 1; j < 4; j++)
    {
        if ((mass[1][j] == symbol) && (mass[2][j] == symbol) && (mass[3][j] == '.'))
        {
            step[0] = 3;
            step[1] = j;
        }
        if ((mass[2][j] == symbol) && (mass[3][j] == symbol) && (mass[1][j] == '.'))
        {
            step[0] = 1;
            step[1] = j;
        }
        if ((mass[1][j] == symbol) && (mass[3][j] == symbol) && (mass[2][j] == '.'))
        {
            step[0] = 2;
            step[1] = j;
        }
    }
    if ((mass[1][1] == symbol) && (mass[2][2] == symbol) && (mass[3][3] == '.'))
    {
        step[0] = 3;
        step[1] = 3;
    }
    if ((mass[2][2] == symbol) && (mass[3][3] == symbol) && (mass[1][1] == '.'))
    {
        step[0] = 1;
        step[1] = 1;
    }
    if ((mass[1][1] == symbol) && (mass[3][3] == symbol) && (mass[2][2] == '.'))
    {
        step[0] = 2;
        step[1] = 2;
    }
    if ((mass[1][3] == symbol) && (mass[2][2] == symbol) && (mass[3][1] == '.'))
    {
        step[0] = 3;
        step[1] = 1;
    }
    if ((mass[2][2] == symbol) && (mass[3][1] == symbol) && (mass[1][3] == '.'))
    {
        step[0] = 1;
        step[1] = 3;
    }
    if ((mass[1][3] == symbol) && (mass[3][1] == symbol) && (mass[2][2] == '.'))
    {
        step[0] = 2;
        step[1] = 2;
    }
    return step;
}

int game(char** mass, int size, int* step, int counter)
{
    char GameOver = '\0';
    
    GameOver = isOwer(mass, size);
    
    if (GameOver == '.')                                            //продолжаем, пока все клетки не заняты
    {
        int x = 0;                                                  //строка хода игрока
        int y = 0;                                                  //столбец хода игрока
        step[0] = 0;                                                //строка хода ПК
        step[1] = 0;                                                //столбец хода ПК

        cout << "Your move. Enter coordinates (x,y):" << endl;      //запрашиваем координаты и проверяем их корректность
        bool trigger = true;
        while (trigger)                                                 
        {
            cout << "x=";
            cin >> x;
            cout << "y=";
            cin >> y;
            if ((x > 0 && x <= 3) && (y > 0 && y <= 3) && (mass[x][y] == '.'))
            {
                trigger = false;
            }
            else
            {
                cout << "Incorrect coordinates! Try again:\n";
            }
        }
        mass[x][y] = 'X';                                           //делаем ход игрока
        display(mass, size);                                        //выводим новое состояние доски    
        
        ++counter;                                                  

        if (counter == 1)                                           //если это первый ход
        {
            if (mass[2][2] == 'X')                                  //то если середина не занята, то занимает ПК
            {
                step[0] = 1;
                step[1] = 1;
            }
            else
            {
                step[0] = 2;
                step[1] = 2;
            }
            mass[step[0]][step[1]] = '0';
        }
        else
        {
            move(mass, size, step, '0');                            //ПК проверяет, есть ли у него два подряд
            if (step[0] != 0)
            {
                mass[step[0]][step[1]] = '0';                       //соответственно ставит третий,
            }
            else
            {
                move(mass, size, step, 'X');                        //если нет, проверяет есть ли у игрока два подряд
                if (step[0] != 0)
                {
                    mass[step[0]][step[1]] = '0';                   //соответственно закрывает третий
                }
                else
                {
                    for (int i = 1; i < 4; i++)                     //если таких ситуаций нет, ПК идёт в первую свободную
                    {
                        for (int j = 1; j < 4; j++)
                        {
                            if (mass[i][j] == '.')
                            {
                                step[0] = i;
                                step[1] = j;
                                mass[step[0]][step[1]] = '0';
                                i = 4;
                                j = 4;
                            }
                        }
                    }
                }
            }
        }
        if (step[0] != 0)                                           
        {
            cout << "I move (x=" << step[0] << ", y=" << step[1] << "):" << endl;
            display(mass, size);                                    //выводим новое состояние доски после хода ПК
        }
        game(mass, size, step, counter);                            //рекурсия
    }
    else                                                            
    {
        if (GameOver == 'X')                                        //можно было бы и не писать - ПК не даст себя выйграть
        {
            cout << "You win ";
        }
        if (GameOver == '0')                                        //если у ПК получилось поставить подряд три 0
        {
            cout << "I win ";
        }
        if (GameOver == ' ')                                        //если ничья
        {
            cout << "Draw ";
        }
        return counter;
    }
}

int main()
{
    int size = 4;                           //размерность доски с обознячениями
    int counter = 0;                        //счётчик ходов

    char** board = new char* [size];        //создаём доску    
    for (int i = 0; i < size; ++i)
    {
        board[i] = new char[size];
    }
    for (int i = 0; i < size; ++i)          //инициализируем её точками и ставим обозначения
    {
        for (int j = 0; j < size; ++j)
        {
            board[i][j] = '.';
            if (i == 0)
            {
                board[i][j] = char (j + 48);
            }
            if (j == 0)
            {
                board[i][j] = char (i + 48);
            }
        }
    }
    board[0][0] = ' ';
    display(board, size);                   //выводим исходное положение

    int* step = new int [2];                //создаём массив для расчёта координат ходов ПК

    cout << "at " << game(board, size, step, counter) << " steps.";

    return 0;
}