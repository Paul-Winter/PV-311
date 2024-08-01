//ЭКЗАМЕНАЦИОННОЕ ЗАДАНИЕ.
//Создайте игру «Морской бой».
//Главные особенности реализации игры :
//■ Режимы игры :
//• Человек – компьютер;
//• Компьютер – компьютер.
//■ Расстановка кораблей :
//• Игрок расставляет вручную;
//• Компьютер расставляет за игрока.
//■ Компьютер может играть в двух режимах :
//• Случайный выстрел;
//• Интеллектуальная игра.Компьютер строит стратегию игры, а не стреляет случайно.
//■ Отображать текущее состояние игрового поля игрока и компьютера.
//■ Возможность остановки, приостановки, нового запуска игры.

#include <iostream>
using namespace std;

extern char blank = char(250);      //определяем вид элементов
extern char kill = char(88);
extern char missed = char(111);
extern char desk = char(254);

struct strike                       //структура для координат хода
{
    int x = 0;
    int y = 0;
};

void surround(char** pc, int size, int* place)  //функция окружает убитый корабль промахами
{
    //int counter = 0;

    if (place[2] == 1)
    {
        for (int i = place[0]; i <= place[0] + 2; i++)
        {
            for (int j = place[1]; j <= place[1] + place[3] + 1; j++)
            {
                if (pc[i - 1][j -1 ] != kill)
                {
                    if (pc[i - 1][j - 1] == blank || pc[i - 1][j - 1] == missed)
                    {
                        pc[i - 1][j - 1] = missed;
                    }
                }
            }
        }
    }
    else
    {
        //cout << "more 1 x=" << place[0] << " y=" << place[1] << " d=" << place[2] << " ds=" << place[3] << endl;
        for (int i = place[0]; i <= place[0] + place[3] + 1; i++)
        {
            for (int j = place[1]; j <= place[1] + 2; j++)
            {
                if (pc[i - 1][j - 1] != kill)
                {
                    if (pc[i - 1][j - 1] == blank || pc[i - 1][j - 1] == missed)
                    {
                        pc[i - 1][j - 1] = missed;
                    }
                }
            }
        }
    }

    //cout << "x=" << place[0] << " y=" << place[1] << " d=" << place[2] << " ds=" << place[3] << endl;
    //system("pause");
}

bool ifIKillPC(char** pc, int size, strike newStrike)   //проверяет убил ли ПК корабль
{
    int k = 1;
    int d_counter = 0;
    int lu_counter = 0;
    int rd_counter = 0;

    int* place = new int[4];

    if (pc[newStrike.x - 1][newStrike.y] != desk && pc[newStrike.x + 1][newStrike.y] != desk && pc[newStrike.x][newStrike.y - 1] != desk && pc[newStrike.x][newStrike.y + 1] != desk)
    {
        if (pc[newStrike.x - 1][newStrike.y] != kill && pc[newStrike.x + 1][newStrike.y] != kill && pc[newStrike.x][newStrike.y - 1] != kill && pc[newStrike.x][newStrike.y + 1] != kill)
        {
            place[0] = newStrike.x;
            place[1] = newStrike.y;
            place[2] = 1;
            place[3] = 1;
            //cout << "call 0" << endl;
            //system("pause");
            surround(pc, size, place);
            return true;
        }
    }

    //horizontal
    if (pc[newStrike.x][newStrike.y - 1] == desk || pc[newStrike.x][newStrike.y + 1] == desk || pc[newStrike.x][newStrike.y - 1] == kill || pc[newStrike.x][newStrike.y + 1] == kill)
    {
        while (pc[newStrike.x][newStrike.y - k] == desk || pc[newStrike.x][newStrike.y - k] == kill)
        {
            ++lu_counter;
            ++k;
        }
        k = 1;
        while (pc[newStrike.x][newStrike.y + k] == desk || pc[newStrike.x][newStrike.y + k] == kill)
        {
            ++rd_counter;
            ++k;
        }
        //cout << "lu_counter=" << lu_counter << " rd_counter=" << rd_counter << endl;
        place[0] = newStrike.x;
        place[1] = newStrike.y - lu_counter;
        place[2] = 1;
        place[3] = lu_counter + rd_counter + 1;
        //cout << "x=" << place[0] << " y=" << place[1] << " d=" << place[2] << " ds=" << place[3] << endl;

        for (int i = 0; i <= place[3]; i++)
        {
            k = i;
            if (pc[place[0]][place[1] + i] == kill)
            {
                //cout << "x=" << place[0] << " y=" << place[1] + i << " = " << k << endl;
                ++d_counter;
            }
        }
        //system("pause");
        if (k == d_counter)
        {
            //cout << "call H" << endl;
            //system("pause");
            surround(pc, size, place);
            return true;
        }
    }
    
    //vertical
    if (pc[newStrike.x - 1][newStrike.y] == desk || pc[newStrike.x + 1][newStrike.y] == desk || pc[newStrike.x - 1][newStrike.y] == kill || pc[newStrike.x + 1][newStrike.y] == kill)
    {
        while (pc[newStrike.x - k][newStrike.y] == desk || pc[newStrike.x - k][newStrike.y] == kill)
        {
            ++lu_counter;
            ++k;
        }
        k = 1;
        while (pc[newStrike.x + k][newStrike.y] == desk || pc[newStrike.x + k][newStrike.y] == kill)
        {
            ++rd_counter;
            ++k;
        }
        //cout << "lu_counter=" << lu_counter << " rd_counter=" << rd_counter << endl;
        place[0] = newStrike.x - lu_counter;
        place[1] = newStrike.y;
        place[2] = 2;
        place[3] = lu_counter + rd_counter + 1;
        //cout << "x=" << place[0] << " y=" << place[1] << " d=" << place[2] << " ds=" << place[3] << endl;
        
        for (int i = 0; i <= place[3]; i++)
        {
            k = i;
            if (pc[place[0] + i][place[1]] == kill)
            {
                //cout << "x=" << place[0] << " y=" << place[1] + i << " = " << k << endl;
                ++d_counter;
            }
        }
        //system("pause");
        if (k == d_counter)
        {
            //cout << "call V" << endl;
            //system("pause");
            surround(pc, size, place);
            return true;
        }
    }
       
    return false;
}

bool ifIKill(char** pc, char** pc2,  int size, strike newStrike)    //проверяет убил ли пользователь корабль ПК
{
    int k = 1;
    int d_counter = 0;
    int lu_counter = 0;
    int rd_counter = 0;

    int* place = new int[4];
        
    if (pc2[newStrike.x - 1][newStrike.y] != desk && pc2[newStrike.x + 1][newStrike.y] != desk)
    {
        if (pc2[newStrike.x][newStrike.y - 1] != desk && pc2[newStrike.x][newStrike.y + 1] != desk)
        {
            place[0] = newStrike.x;
            place[1] = newStrike.y;
            place[2] = 1;
            place[3] = 1;
            surround(pc, size, place);
            return true;
        }
        
        while (pc2[newStrike.x][newStrike.y - k] == desk)
        {
            ++lu_counter;
            ++k;
        }
        k = 1;
        while (pc2[newStrike.x][newStrike.y + k] == desk)
        {
            ++rd_counter;
            ++k;
        }
        place[0] = newStrike.x;
        place[1] = newStrike.y - lu_counter;
        place[2] = 1;
        place[3] = lu_counter + rd_counter + 1;
    
        for (int i = 0; i <= place[3]; i++)
        {
            k = i;
            if (pc[place[0]][place[1] + i] == kill)
            {
                 ++d_counter;
            }
        }
        if (k == d_counter)
        {
            surround(pc, size, place);
            return true;
        }
    }
    else
    {
        while (pc2[newStrike.x - k][newStrike.y] == desk)
        {
            ++lu_counter;
            ++k;
        }
        k = 1;
        while (pc2[newStrike.x + k][newStrike.y] == desk)
        {
            ++rd_counter;
            ++k;
        }
        place[0] = newStrike.x - lu_counter;
        place[1] = newStrike.y;
        place[2] = 2;
        place[3] = lu_counter + rd_counter + 1;

        for (int i = 0; i <= place[3]; i++)
        {
            k = i;
            if (pc[place[0] + i][place[1]] == kill)
            {
                ++d_counter;
            }
        }
        if (k == d_counter)
        {
            surround(pc, size, place);
            return true;
        }
    }

    return false;
}

bool amIHit(char** mass, int size, strike newStrike)    //проверяет есть ли попадание
{
    if (mass[newStrike.x][newStrike.y] == desk)
    {
        return true;
    }
    return false;
}

void displaySingl(char** mass, int size)                //вывод одинарной доски
{
    system("cls");
    cout << "*********************** SEA BATTLE ********************** " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

char** setDeck(char** mass, int size, int* place)       //установка корабля
{
    for (int i = 1; i <= place[3]; i++)
    {
        if (place[2] == 1)
        {
            mass[place[0] + 1][place[1] + i] = desk;
        }
        else
        {
            mass[place[0] + i][place[1] + 1] = desk;
        }
    }
    return mass;
}

strike ifStriken(char** mass, int size)     //вернёт координаты следующего удара, если ПК ранил 
{
    int counter = 0;
    int rndm = 0;
    int k = 1;
    bool vertical = false;
    bool horizontal = false;
    strike nextStrike;
    strike* buf = new strike[8];
    for (int i = 0; i < 8; i++)
    {
        buf[i].x = 0;
        buf[i].y = 0;
    }

    for (int i = 2; i < size - 1; i++)
    {
        for (int j = 2; j < size - 1; j++)
        {
            if (mass[i][j] == kill)
            {
                if (mass[i - 1][j] == blank || mass[i - 1][j] == desk)
                {
                    nextStrike.x = i;
                    nextStrike.y = j;
                }
                if (mass[i + 1][j] == blank || mass[i + 1][j] == desk)
                {
                    nextStrike.x = i;
                    nextStrike.y = j;
                }
                if (mass[i][j - 1] == blank || mass[i][j - 1] == desk)
                {
                    nextStrike.x = i;
                    nextStrike.y = j;
                }
                if (mass[i][j + 1] == blank || mass[i][j + 1] == desk)
                {
                    nextStrike.x = i;
                    nextStrike.y = j;
                }
            }
        }
    }
    
    //cout << "str=" << nextStrike.x - 1 << ":" << nextStrike.y - 1 << endl;

    if (mass[nextStrike.x - 1][nextStrike.y] == kill || mass[nextStrike.x + 1][nextStrike.y] == kill)
    {
        vertical = true;
        while (mass[nextStrike.x - k][nextStrike.y] == kill)
        {
            ++k;
        }
        //cout << "do=" << mass[nextStrike.x - k][nextStrike.y] << endl;
        if (mass[nextStrike.x - k][nextStrike.y] == blank || mass[nextStrike.x - k][nextStrike.y] == desk)
        {
            buf[counter].x = nextStrike.x - k;
            buf[counter].y = nextStrike.y;
            //cout << "add5=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        k = 1;
        while (mass[nextStrike.x + k][nextStrike.y] == kill)
        {
            ++k;
        }
        //cout << "posle=" << mass[nextStrike.x + k][nextStrike.y] << endl;
        if (mass[nextStrike.x + k][nextStrike.y] == blank || mass[nextStrike.x + k][nextStrike.y] == desk)
        {
            buf[counter].x = nextStrike.x + k;
            buf[counter].y = nextStrike.y;
            //cout << "add6=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        
        /*
        if (mass[nextStrike.x - 1][nextStrike.y] == kill && mass[nextStrike.x - 2][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x - 2;
            buf[counter].y = nextStrike.y;
            cout << "add5=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        if (mass[nextStrike.x + 1][nextStrike.y] == blank || mass[nextStrike.x + 1][nextStrike.y] == desk)
        {
            buf[counter].x = nextStrike.x + 1;
            buf[counter].y = nextStrike.y;
            cout << "add6=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        */
    }
    if (mass[nextStrike.x][nextStrike.y - 1] == kill || mass[nextStrike.x][nextStrike.y + 1] == kill)
    {
        horizontal = true;

        while (mass[nextStrike.x][nextStrike.y - k] == kill)
        {
            ++k;
        }
        //cout << "do=" << mass[nextStrike.x][nextStrike.y - k] << endl;
        if (mass[nextStrike.x][nextStrike.y - k] == blank || mass[nextStrike.x][nextStrike.y - k] == desk)
        {
            buf[counter].x = nextStrike.x;
            buf[counter].y = nextStrike.y - k;
            //cout << "add7=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        k = 1;
        while (mass[nextStrike.x][nextStrike.y + k] == kill)
        {
            ++k;
        }
        //cout << "posle=" << mass[nextStrike.x][nextStrike.y + k] << endl;
        if (mass[nextStrike.x][nextStrike.y + k] == blank || mass[nextStrike.x][nextStrike.y + k] == desk)
        {
            buf[counter].x = nextStrike.x;
            buf[counter].y = nextStrike.y + k;
            //cout << "add8=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        /*
        if (mass[nextStrike.x][nextStrike.y - 1] == kill && mass[nextStrike.x][nextStrike.y - 2] == blank)
        {
            buf[counter].x = nextStrike.x;
            buf[counter].y = nextStrike.y - 2;
            cout << "add7=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        if (mass[nextStrike.x][nextStrike.y + 1] == blank || mass[nextStrike.x][nextStrike.y + 1] == desk)
        {
            buf[counter].x = nextStrike.x;
            buf[counter].y = nextStrike.y + 1;
            cout << "add8=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        */
    }

    if (!horizontal && !vertical)
    {
        if (mass[nextStrike.x - 1][nextStrike.y] == blank || mass[nextStrike.x - 1][nextStrike.y] == desk)
        {
            buf[counter].x = nextStrike.x - 1;
            buf[counter].y = nextStrike.y;
            //cout << "add1=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        if (mass[nextStrike.x + 1][nextStrike.y] == blank || mass[nextStrike.x + 1][nextStrike.y] == desk)
        {
            buf[counter].x = nextStrike.x + 1;
            buf[counter].y = nextStrike.y;
            //cout << "add2=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
    
        if (mass[nextStrike.x][nextStrike.y - 1] == blank || mass[nextStrike.x][nextStrike.y - 1] == desk)
        {
            buf[counter].x = nextStrike.x;
            buf[counter].y = nextStrike.y - 1;
            //cout << "add3=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
        if (mass[nextStrike.x][nextStrike.y + 1] == blank || mass[nextStrike.x][nextStrike.y + 1] == desk)
        {
            buf[counter].x = nextStrike.x;
            buf[counter].y = nextStrike.y + 1;
            //cout << "add4=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
            ++counter;
        }
    }
    
    /*
    //chek vertikal
    if (mass[nextStrike.x + 1][nextStrike.y] == kill && mass[nextStrike.x + 2][nextStrike.y] == kill)
    {
        vertical = true;
        if (mass[nextStrike.x + 3][nextStrike.y] == desk || mass[nextStrike.x + 3][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x + 3;
            buf[counter].y = nextStrike.y;
            ++counter;
        }
        if (mass[nextStrike.x - 1][nextStrike.y] == desk || mass[nextStrike.x - 1][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x - 1;
            buf[counter].y = nextStrike.y;
            ++counter;
        }
    }

    if(mass[nextStrike.x + 1][nextStrike.y] == kill)
    {
        vertical = true;
        if (mass[nextStrike.x + 2][nextStrike.y] == desk || mass[nextStrike.x + 2][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x + 2;
            buf[counter].y = nextStrike.y;
            ++counter;
        }
        if (mass[nextStrike.x - 1][nextStrike.y] == desk || mass[nextStrike.x - 1][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x - 1;
            buf[counter].y = nextStrike.y;
            ++counter;
        }
    }

    if (!vertical)
    {
        if (mass[nextStrike.x + 1][nextStrike.y] == desk || mass[nextStrike.x + 1][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x + 1;
            buf[counter].y = nextStrike.y;
            ++counter;
        }

        if (mass[nextStrike.x - 1][nextStrike.y] == desk || mass[nextStrike.x - 1][nextStrike.y] == blank)
        {
            buf[counter].x = nextStrike.x - 1;
            buf[counter].y = nextStrike.y;
            ++counter;
        }
    }
    
    //chek horizontal
    if (!vertical)
    {
        if (mass[nextStrike.x][nextStrike.y + 1] == kill && mass[nextStrike.x][nextStrike.y + 2] == kill)
        {
            horizontal = true;
            if (mass[nextStrike.x][nextStrike.y + 3] == desk || mass[nextStrike.x][nextStrike.y + 3] == blank)
            {
                buf[counter].x = nextStrike.x;
                buf[counter].y = nextStrike.y + 3;
                cout << "add1=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
                ++counter;
            }
            if (mass[nextStrike.x][nextStrike.y - 1] == desk || mass[nextStrike.x][nextStrike.y - 1] == blank)
            {
                buf[counter].x = nextStrike.x;
                buf[counter].y = nextStrike.y - 1;
                cout << "add2=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
                ++counter;
            }
        }

        if (mass[nextStrike.x][nextStrike.y + 1] == kill)
        {
            horizontal = true;
            if (mass[nextStrike.x][nextStrike.y + 2] == desk || mass[nextStrike.x][nextStrike.y + 2] == blank)
            {
                buf[counter].x = nextStrike.x;
                buf[counter].y = nextStrike.y + 2;
                cout << "add3=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
                ++counter;
            }
            if (mass[nextStrike.x][nextStrike.y - 1] == desk || mass[nextStrike.x][nextStrike.y - 1] == blank)
            {
                buf[counter].x = nextStrike.x;
                buf[counter].y = nextStrike.y - 1;
                cout << "add4=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
                ++counter;
            }
        }

        if (!horizontal)
        {
            if (mass[nextStrike.x][nextStrike.y + 1] == desk || mass[nextStrike.x][nextStrike.y + 1] == blank)
            {
                buf[counter].x = nextStrike.x;
                buf[counter].y = nextStrike.y + 1;
                cout << "add5=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
                ++counter;
            }

            if (mass[nextStrike.x][nextStrike.y - 1] == desk || mass[nextStrike.x][nextStrike.y - 1] == blank)
            {
                buf[counter].x = nextStrike.x;
                buf[counter].y = nextStrike.y - 1;
                cout << "add6=" << buf[counter].x - 1 << ":" << buf[counter].y - 1 << endl;
                ++counter;
            }
        }
    }
    
    cout << "v=" << vertical << " h=" << horizontal << endl;
    for (int i = 0; i < counter; i++)
    {
        cout << buf[i].x - 1 << ":" << buf[i].y - 1 << endl;
    }
    system("pause");*/

    srand(time(NULL));
    rndm = 1 + rand() % counter;
    //cout << rndm << endl;

    nextStrike.x = buf[rndm - 1].x;
    nextStrike.y = buf[rndm - 1].y;

    delete[] buf;

    return nextStrike;
}

bool isStriken(char** mass, int size)   //проверяет есть ли на доске раненные корабли
{
    bool empty = false;

    for (int i = 2; i < size - 1; i++)
    {
        for (int j = 2; j < size - 1; j++)
        {
            if (mass[i][j] == kill)
            {
                //cout << "x=" << i - 1 << " y=" << j - 1 << endl;
                
                if (mass[i - 1][j] == blank || mass[i - 1][j] == desk)
                {
                    empty = true;
                }
                if (mass[i + 1][j] == blank || mass[i + 1][j] == desk)
                {
                    empty = true;
                }
                if (mass[i][j - 1] == blank || mass[i][j - 1] == desk)
                {
                    empty = true;
                }
                if (mass[i][j + 1] == blank || mass[i][j + 1] == desk)
                {
                    empty = true;
                }
            }
        }
    }

    //cout << "striken = " << empty << endl;
    //system("pause");

    return empty;
}

void display(char** mass1, char** mass2, int size)      //вывод досок на экран
{
    int interval = 7;
    int newsize = size * 2 + interval;
    system("cls");
    cout << "*********************** SEA BATTLE ********************** " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < newsize; j++)
        {
            if (j < size)
            {
                cout << mass1[i][j] << " ";
            }
            if (j > size && j < interval + size)
            {
                cout << " ";
            }
            if (j >= interval + size)
            {
                cout << mass2[i][j - (interval + size)] << " ";
            }
        }
        cout << endl;
    }
}

int gameOver(char** user, char** pc, int size)      //проверяет не окончилась ли игра
{
    int count_user = 0;
    int count_pc = 0;

    for (int i = 2; i < size - 1; i++)
    {
        for (int j = 2; j < size - 1; j++)
        {
            if (user[i][j] == kill)
            {
                ++count_user;
                if (count_user == 20)
                {
                    return 2;
                }
            }
            if (pc[i][j] == kill)
            {
                ++count_pc;
                if (count_pc == 20)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

strike autoMove(char** mass, char** mass1, char** mass2, int size, bool isUserStrike)   //автоматический ход ПК
{
    strike nextStrike;
    int cont = 0;
    bool more = true;

    if (isStriken(mass1, size))
    {
        //cout << "was hit" << endl;
        nextStrike = ifStriken(mass1, size);
        //system("pause");
    }
    else
    {
        while (more)
        {
            srand(time(NULL));
            nextStrike.x = 2 + rand() % 10;
            nextStrike.y = 2 + rand() % 10;

            if (mass1[nextStrike.x][nextStrike.y] == blank)
            {
                system("cls");
                display(mass2, mass1, size);

                cont = gameOver(mass2, mass1, size);

                if (cont == 0)
                {
                    cout << "Your move:" << endl;
                    cout << "Row?: " << nextStrike.x - 1 << endl;
                    cout << "Column?: " << nextStrike.y - 1 << endl;
                    system("pause");
                }
                more = false;
            }
        }
    }

    return nextStrike;
}

strike currentMove(char** mass, char** mass1, char** mass2, int size, bool isUserStrike)    //вернёт координаты текущего хода
{
    strike nextStrike;
    int cont = true;

    if (isUserStrike)
    {
        system("cls");
        display(mass2, mass1, size);

        cont = gameOver(mass2, mass1, size);

        if (cont == 0)
        {
            cout << "Your move:" << endl;
            cout << "Row?: ";
            cin >> nextStrike.x;
            ++nextStrike.x;
            cout << "Column?: ";
            cin >> nextStrike.y;
            ++nextStrike.y;
        }
        else
        {
            nextStrike.x = 0;
            nextStrike.y = 0;
        }

    }
    else
    {
        if (isStriken(mass2, size))
        {
            //cout << "was hit" << endl;
            nextStrike = ifStriken(mass2, size);
            //system("pause");
        }
        else
        {
            srand(time(NULL));
            nextStrike.x = 2 + rand() % 10;
            nextStrike.y = 2 + rand() % 10;
        }
    }
    
    return nextStrike;
}

bool canIStrike(char** mass, int size, strike newStrike)    //проверяет можно ли туда бить
{
    if ((newStrike.x > 1 && newStrike.x < 12) && (newStrike.y > 1 && newStrike.y < 12))
    {
        if (mass[newStrike.x][newStrike.y] == desk || mass[newStrike.x][newStrike.y] == blank)
        {
            return true;
        }
    }
    return false;
}

bool isPlaceFreeHorizontal(char** mass, int size, int* place)   //проверяет свободно ли место для размещения корабля по горизонтали
{
    int counter = 0;

    for (int i = place[0]; i <= place[0] + 2; i++)
    {
        for (int j = place[1]; j <= place[1] + place[3] + 1; j++)
        {
            if (mass[i][j] == desk)
            {
                ++counter;
            }
        }
    }
    if (counter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPlaceFreeVertical(char** mass, int size, int* place) //проверяет свободно ли место для размещения корабля по вертикали
{
    int counter = 0;

    for (int i = place[0]; i <= place[0] + place[3] + 1; i++)
    {
        for (int j = place[1] ; j <= place[1] + 2; j++)
        {
            if (mass[i][j] == desk)
            {
                ++counter;
            }
        }
    }
    if (counter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool canIPlaced(char** mass, int size, int* place)  //проверяет можно ли сюда поставить корабль
{
    switch (place[3])
    {
    case 1:
        if (place[2] == 1)
        {
            if (place[0] > 0 && place[0] < 11 && place[1] > 0 && place[1] < 11)
            {
                if (isPlaceFreeHorizontal(mass, size, place))
                {
                    return true;
                }
            }
        }
        else if (place[2] == 2)
        {
            if (place[0] > 0 && place[0] < 11 && place[1] > 0 && place[1] < 11)
            {
                if (isPlaceFreeVertical(mass, size, place))
                {
                    return true;
                }
            }
        }
        break;
    case 2:
        if (place[2] == 1)
        {
            if (place[0] > 0 && place[0] < 11 && place[1] > 0 && place[1] < 10)
            {
                if (isPlaceFreeHorizontal(mass, size, place))
                {
                    return true;
                }
            }
        }
        else if (place[2] == 2)
        {
            if (place[0] > 0 && place[0] < 10 && place[1] > 0 && place[1] < 11)
            {
                if (isPlaceFreeVertical(mass, size, place))
                {
                    return true;
                }
            }
        }
        break;
    case 3:
        if (place[2] == 1)
        {
            if (place[0] > 0 && place[0] < 11 && place[1] > 0 && place[1] < 9)
            {
                if (isPlaceFreeHorizontal(mass, size, place))
                {
                    return true;
                }
            }
        }
        else if (place[2] == 2)
        {
            if (place[0] > 0 && place[0] < 9 && place[1] > 0 && place[1] < 11)
            {
                if (isPlaceFreeVertical(mass, size, place))
                {
                    return true;
                }
            }
        }
        break;
    default:
        if (place[2] == 1)
        {
            if (place[0] > 0 && place[0] < 11 && place[1] > 0 && place[1] < 8)
            {
                if (isPlaceFreeHorizontal(mass, size, place))
                {
                    return true;
                }
            }
        }
        else if (place[2] == 2)
        {
            if (place[0] > 0 && place[0] < 8 && place[1] > 0 && place[1] < 11)
            {
                if (isPlaceFreeVertical(mass, size, place))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

char** autoPlacement(char** mass, int size)     //автоматическое размещение кораблей на доске
{
    int* place = new int[4];

    bool allPlaced = false;
    bool deck4Placed = false;
    bool deck3Placed = false;
    bool deck2Placed = false;
    bool deck1Placed = false;
    int counter = 0;

    srand(time(NULL));
  
    while (!allPlaced)
    {
        while (!deck4Placed)
        {
            place[0] = 1 + rand() % 10;
            place[1] = 1 + rand() % 10;
            place[2] = 1 + rand() % 2;
            place[3] = 4;

            if (canIPlaced(mass, size, place))
            {
                if (place[2] == 1)
                {
                    if (isPlaceFreeHorizontal(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        deck4Placed = true;
                    }
                }
                else
                {
                    if (isPlaceFreeVertical(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        deck4Placed = true;
                    }
                }
            }
        }
        
        while (!deck3Placed)
        {
            place[0] = 1 + rand() % 10;
            place[1] = 1 + rand() % 10;
            place[2] = 1 + rand() % 2;
            place[3] = 3;

            if (canIPlaced(mass, size, place))
            {
                if (place[2] == 1)
                {
                    if (isPlaceFreeHorizontal(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        ++counter;
                        if (counter == 2)
                        {
                            deck3Placed = true;
                        }
                    }
                }
                else
                {
                    if (isPlaceFreeVertical(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        ++counter;
                        if (counter == 2)
                        {
                            deck3Placed = true;
                        }
                    }
                }
            }
        }
        counter = 0;

        while (!deck2Placed)
        {
            place[0] = 1 + rand() % 10;
            place[1] = 1 + rand() % 10;
            place[2] = 1 + rand() % 2;
            place[3] = 2;

            if (canIPlaced(mass, size, place))
            {
                if (place[2] == 1)
                {
                    if (isPlaceFreeHorizontal(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        ++counter;
                        if (counter == 3)
                        {
                            deck2Placed = true;
                        }
                    }
                }
                else
                {
                    if (isPlaceFreeVertical(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        ++counter;
                        if (counter == 3)
                        {
                            deck2Placed = true;
                        }
                    }
                }
            }
        }
        counter = 0;

        while (!deck1Placed)
        {
            place[0] = 1 + rand() % 10;
            place[1] = 1 + rand() % 10;
            place[2] = 1 + rand() % 2;
            place[3] = 1;

            if (canIPlaced(mass, size, place))
            {
                if (place[2] == 1)
                {
                    if (isPlaceFreeHorizontal(mass, size, place))
                    {
                        mass = setDeck(mass, size, place);
                        ++counter;
                        if (counter == 4)
                        {
                            deck1Placed = true;
                        }
                    }
                }
            }
        }
        counter = 0;

        if ((deck1Placed)&&(deck2Placed)&&(deck3Placed)&&(deck4Placed))
        {
            allPlaced = true;
        }
    }
    
    return mass;
}

char** userPlacement(char** mass, int size)     //ручное размещение кораблей на доске
{
    int* place = new int[4];
    
    bool deck4 = false;
    while (!deck4)
    {
        cout << "Enter coordinates a 4-deck ship:\n";
        cout << "Row?: ";
        cin >> place[0];
        cout << "Column?: ";
        cin >> place[1];
        cout << "Enter direction (1 - horizontal, 2 - vertical): ";
        cin >> place[2];
        place[3] = 4;
        if (canIPlaced(mass, size, place))
        {
            deck4 = true;
            setDeck(mass, size, place);
            system("cls");
            displaySingl(mass, size);
        }
        else
        {
            cout << "Incorrect values! Try again..." << endl;
        }
    }

    int counter = 1;
    bool deck3 = false;
    while (!deck3)
    {
        cout << "Enter coordinates a 3-deck ship(" << counter << "):\n";
        cout << "Row?: ";
        cin >> place[0];
        cout << "Column?: ";
        cin >> place[1];
        cout << "Enter direction (1 - horizontal, 2 - vertical): ";
        cin >> place[2];
        place[3] = 3;
        if (canIPlaced(mass, size, place))
        {
            if (counter == 2)
            {
                deck3 = true;
            }
            ++counter;
            setDeck(mass, size, place);
            system("cls");
            displaySingl(mass, size);
        }
        else
        {
            cout << "Incorrect values! Try again..." << endl;
        }
    }

    counter = 1;
    bool deck2 = false;
    while (!deck2)
    {
        cout << "Enter coordinates a 2-deck ship(" << counter << "):\n";
        cout << "Row?: ";
        cin >> place[0];
        cout << "Column?: ";
        cin >> place[1];
        cout << "Enter direction (1 - horizontal, 2 - vertical): ";
        cin >> place[2];
        place[3] = 2;
        if (canIPlaced(mass, size, place))
        {
            if (counter == 3)
            {
                deck2 = true;
            }
            ++counter;
            setDeck(mass, size, place);
            system("cls");
            displaySingl(mass, size);
        }
        else
        {
            cout << "Incorrect values! Try again..." << endl;
        }
    }

    counter = 1;
    bool deck1 = false;
    while (!deck1)
    {
        cout << "Enter coordinates a 1-deck ship(" << counter << "):\n";
        cout << "Row?: ";
        cin >> place[0];
        cout << "Column?: ";
        cin >> place[1];
        place[2] = 1;
        place[3] = 1;
        if (canIPlaced(mass, size, place))
        {
            if (counter == 4)
            {
                deck1 = true;
            }
            ++counter;
            setDeck(mass, size, place);
            system("cls");
            displaySingl(mass, size);
        }
        else
        {
            cout << "Incorrect values! Try again..." << endl;
        }
    }

    return mass;
}

char** createBoard(char** mass, int size, string title)     //создание игровой доски
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == 0 || i == 12)          //заголовок строки
            {
                mass[i][j] = ' ';
            }
            if (i == 1)
            {
                mass[i][j] = char(j + 47);
                if (j == 1)
                {
                    mass[i][j] = ' ';
                }
                if (j == 11)
                {
                    mass[i][j] = '1';
                }
                if (j == 12)
                {
                    mass[i][j] = '0';
                }
            }

            if (j == 0)                     //заголовок столбца
            {
                mass[i][j] = ' ';
            }
            if (j == 1 && i > 1)
            {
                mass[i][j] = char(i + 47);
                if (i == 0)
                {
                    mass[i][j] = ' ';
                }
                if (i == 11)
                {
                    mass[i][j - 1] = '1';
                    mass[i][j] = '0';
                }
                if (i == 12)
                {
                    mass[i][j] = ' ';
                }
            }

            if (i > 1 && j > 1 && i < 12)   //заполнение поля
            {
                if (j == 12)
                {
                    mass[i][j] = ' ';
                }
                else
                {
                    mass[i][j] = blank;
                }
            }
        }
    }

    for (int j = 0; j < size; ++j)
    {
        mass[0][j] = title[j];
    }

    return mass;
}

char** placement(char** mass, int size)     //выбор размещения
{
    int choise = 0;
    int counter = 0;
    char l = '\0';

    cout << "PLAYSMENT:" << endl;
    cout << "1. Yourself." << endl;
    cout << "2. Automatically." << endl;

    while (choise == 0 || choise > 2)
    {
        if (counter < 5)
        {
            cout << "Your choise (1-2): ";
            cin >> choise;
        }
        else
        {
            system("cls");
            choise = 2;
        }
        ++counter;
    }

    if (choise == 1)
    {
        mass = userPlacement(mass, size);
    }
    else
    {
        mass = autoPlacement(mass, size);
        displaySingl(mass, size);
        cout << "Liked? (y/n):";
        cin >> l;
        if (l == 'n')
        {
            system("cls");
            mass = createBoard(mass, size, "    -USER-   ");
            displaySingl(mass, size);
            placement(mass,size);
        }
    }
    
    return mass;
}

int game(char** user, char** pc, char** pc2, int size, int counter, int mode, bool isUserStrike)    //основная функция
{
    int cont = 0;
    strike newStrike;
    strike oldStrike;

    while (cont == 0)
    {
        cont = gameOver(user, pc, size);
        if (cont != 0)
        {
            break;
        }

        if (isUserStrike)
        {
            if (mode == 2)
            {
                newStrike = autoMove(pc2, pc, user, size, isUserStrike);
            }
            else
            {
                newStrike = currentMove(pc2, pc, user, size, isUserStrike);
            }
     
            if (canIStrike(pc2, size, newStrike))
            {
                if (amIHit(pc2, size, newStrike))
                {
                    pc[newStrike.x][newStrike.y] = kill;

                    ifIKill(pc, pc2, size, newStrike);
                    isUserStrike = true;
                    cont = gameOver(user, pc, size);
                    if (cont != 0)
                    {
                        break;
                    }
                }
                else
                {
                    pc[newStrike.x][newStrike.y] = missed;
                    isUserStrike = false;
                }
                ++counter;
            }
            else
            {
                if (cont == 2)
                {
                    break;
                }
                cout << "You can't hit there!" << endl;
                system("pause");
            }
        }
        else
        {
            newStrike = currentMove(pc2, pc, user, size, isUserStrike);

            if (canIStrike(user, size, newStrike))
            {
                system("cls");
                display(user, pc, size);

                cout << "My move:" << endl;
                cout << "Row: " << newStrike.x - 1 << endl;
                cout << "Column: " << newStrike.y - 1 << endl;
                system("pause");
                
                if (amIHit(user, size, newStrike))
                {
                    user[newStrike.x][newStrike.y] = kill;
                    ifIKillPC(user, size, newStrike);
                    //cout << "kill" << endl;
                    //system("pause");

                }
                else
                {
                    user[newStrike.x][newStrike.y] = missed;
                    isUserStrike = true;
                }
                ++counter;
            }
            else
            {
                isUserStrike = false;
            }
        }

        //game(user, pc, pc2, size, counter, mode, isUserStrike);        
    }
   
    if (cont == 1)
    {
        pc[newStrike.x][newStrike.y] = kill;
        system("cls");
        display(user, pc, size);
        cout << "You win at " << counter << " steps!" << endl;
        return counter;
    }
    else
    {
        user[newStrike.x][newStrike.y] = kill;
        system("cls");
        display(user, pc, size);
        cout << "I win at " << counter << " steps!" << endl;
        return counter;
    }
}

int mainMenu()      //меню игры
{
    int choise = 0;
    int counter = 0;
    cout << "*********************** SEA BATTLE ********************** " << endl;
    cout << "1. Start game USER with PC." << endl;
    cout << "2. Start game PC with PC." << endl;
    cout << "3. Quit." << endl;

    while (choise == 0 || choise > 3)
    {
        if (counter < 5)
        {
            cout << "Your choise (1-3): ";
            cin >> choise;
        }
        else
        {
            system("cls");
            cout << "Quit..." << endl;
            choise = 3;
        }
        ++counter;
    }
    return choise;
}

int main()
{
    bool newGame = true;
    
    while (newGame)
    {
        int size = 13;                              //размер доски
        int counter = 0;                            //счётчик ходов
        int mode = 0;                               //режим игры
        bool isUserStrike = true;                   //очерёдность хода

        mode = mainMenu();
        switch (mode)
        {
        case 1:
        {
            char** user = new char* [size];
            char** pc = new char* [size];
            char** pc2 = new char* [size];
            for (int i = 0; i < size; ++i)
            {
                user[i] = new char[size];
                pc[i] = new char[size];
                pc2[i] = new char[size];
            }
            createBoard(user, size, "    -USER-   ");
            createBoard(pc, size, "     -PC-     ");
            createBoard(pc2, size, "     -PC2-   ");

            displaySingl(user, size);
            user = placement(user, size);
            pc2 = autoPlacement(pc2, size);
            //
            //displaySingl(pc2, size);    //
            //system("pause");            //
            //
            game(user, pc, pc2, size, counter, mode, isUserStrike);
            mode = 0;
            break;
        }
        case 2:
        {
            char** user = new char* [size];
            char** pc = new char* [size];
            char** pc2 = new char* [size];
            for (int i = 0; i < size; ++i)
            {
                user[i] = new char[size];
                pc[i] = new char[size];
                pc2[i] = new char[size];
            }
            createBoard(user, size, "    -USER-   ");
            createBoard(pc, size, "     -PC-     ");
            createBoard(pc2, size, "     -PC2-   ");

            //displaySingl(user, size);
            user = autoPlacement(user, size);
            pc2 = autoPlacement(pc2, size);
            //
            //displaySingl(pc2, size);    //
            //system("pause");            //
            //
            game(user, pc, pc2, size, counter, mode, isUserStrike);
            mode = 0;
            break;
        }
        default:
            return 0;
        }
    }
    
    return 0;
}