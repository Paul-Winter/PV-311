//ЗАДАНИЕ 5
//Дана матрица целых чисел размером 10*12. Напечатайте индексы всех ее седловых точек (saddle points).
//(Седловой точкой называется элемент, который является наименьшим в своей строке и
//наибольшим в своем столбце или, наоборот, наибольшим в своей строке и наименьшим в своем столбце).

#include <iostream>
using namespace std;

void display_xy(int** mass, int size_x, int size_y)
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    bool find = false;
    int buf = 0;
    int size_x = 10;
    int size_y = 12;
    int min = 0;
    int max = 0;
    int min_i = 0;
    int min_j = 0;
    int max_i = 0;
    int max_j = 0;

    int** dmass = new int* [size_x];
    for (int i = 0; i < size_x; ++i)
    {
        dmass[i] = new int[size_y];
    }
    
    //т.к. рандомо массив заполняется числами не дающими седловых точек
    //(из более 30 запусков был лишь 1 случай),
    //то инициализируем его с принудительно установленными.
    dmass[0][0] = 88; dmass[0][1] = 36; dmass[0][2] = 40; dmass[0][3] = 48; dmass[0][4] = 89; dmass[0][5] = 24; dmass[0][6] = 89; dmass[0][7] = 58; dmass[0][8] = 14; dmass[0][9] = 34; dmass[0][10] = 51; dmass[0][11] = 88;
    dmass[1][0] = 64; dmass[1][1] = 55; dmass[1][2] = 65; dmass[1][3] = 90; dmass[1][4] = 57; dmass[1][5] = 72; dmass[1][6] = 85; dmass[1][7] = 93; dmass[1][8] = 62; dmass[1][9] = 83; dmass[1][10] = 94; dmass[1][11] = 93;
    dmass[2][0] = 26; dmass[2][1] = 11; dmass[2][2] = 53; dmass[2][3] = 34; dmass[2][4] = 61; dmass[2][5] = 44; dmass[2][6] = 77; dmass[2][7] = 75; dmass[2][8] = 66; dmass[2][9] = 76; dmass[2][10] = 82; dmass[2][11] = 54;
    dmass[3][0] = 54; dmass[3][1] = 54; dmass[3][2] = 43; dmass[3][3] = 25; dmass[3][4] = 70; dmass[3][5] = 26; dmass[3][6] = 79; dmass[3][7] = 21; dmass[3][8] = 29; dmass[3][9] = 21; dmass[3][10] = 66; dmass[3][11] = 66;
    dmass[4][0] = 53; dmass[4][1] = 37; dmass[4][2] = 21; dmass[4][3] = 73; dmass[4][4] = 92; dmass[4][5] = 41; dmass[4][6] = 22; dmass[4][7] = 78; dmass[4][8] = 64; dmass[4][9] = 33; dmass[4][10] = 36; dmass[4][11] = 28;
    dmass[5][0] = 37; dmass[5][1] = 29; dmass[5][2] = 36; dmass[5][3] = 31; dmass[5][4] = 56; dmass[5][5] = 39; dmass[5][6] = 12; dmass[5][7] = 34; dmass[5][8] = 46; dmass[5][9] = 18; dmass[5][10] = 27; dmass[5][11] = 48;
    dmass[6][0] = 51; dmass[6][1] = 18; dmass[6][2] = 71; dmass[6][3] = 43; dmass[6][4] = 79; dmass[6][5] = 76; dmass[6][6] = 75; dmass[6][7] = 50; dmass[6][8] = 77; dmass[6][9] = 84; dmass[6][10] = 49; dmass[6][11] = 73;
    dmass[7][0] = 22; dmass[7][1] = 44; dmass[7][2] = 80; dmass[7][3] = 25; dmass[7][4] = 77; dmass[7][5] = 21; dmass[7][6] = 56; dmass[7][7] = 93; dmass[7][8] = 44; dmass[7][9] = 96; dmass[7][10] = 28; dmass[7][11] = 46;
    dmass[8][0] = 15; dmass[8][1] = 10; dmass[8][2] = 98; dmass[8][3] = 74; dmass[8][4] = 98; dmass[8][5] = 95; dmass[8][6] = 41; dmass[8][7] = 39; dmass[8][8] = 94; dmass[8][9] = 80; dmass[8][10] = 10; dmass[8][11] = 58;
    dmass[9][0] = 32; dmass[9][1] = 22; dmass[9][2] = 23; dmass[9][3] = 87; dmass[9][4] = 69; dmass[9][5] = 11; dmass[9][6] = 85; dmass[9][7] = 64; dmass[9][8] = 45; dmass[9][9] = 21; dmass[9][10] = 41; dmass[9][11] = 80;

    for (int i = 0; i < size_x; i++)        //ищем максимальный и минимальный элементы массива
    {
        for (int j = 0; j < size_y; j++)
        {
            if (dmass[i][j] > max)
            {
                max = dmass[i][j];              
            }
            if (dmass[i][j] < max && i == 0)
            {
                min = dmass[i][j];              
            }
            else
            {
                if (dmass[i][j] < min)
                {
                    min = dmass[i][j];
                }
            }
        }
    }
 
    /*
    srand(time(0));
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            buf = rand() % 90 + 10;             //заполняем массив двузначными числами для наглядности
            dmass[i][j] = buf;
            if (dmass[i][j] > max)
            {
                max = dmass[i][j];              //ищем максимальный элемент
            }
            if (dmass[i][j] < max && i == 0)
            {
                min = dmass[i][j];              //ищем минимальный элемент
            }
            else
            {
                if (dmass[i][j] < min)
                {
                    min = dmass[i][j];
                }
            }
        }
    }
    */

    display_xy(dmass, size_x, size_y);

    buf = min;
    min = max;
    max = min;

    for (int i = 0; i < size_x; ++i)        //перебираем стоки находя в них минимальные элементы
    {
        min = max;
        for (int k = 0; k < size_y; ++k)
        {
            if (dmass[i][k] <= min)
            {
                min = dmass[i][k];          //минимальный элемент в строке
                min_j = k;                  //индекс по вертикали минимального элемента в строке
            }
        }

        max = min;
        for (int k = 0; k < size_x; ++k)
        {
            if (dmass[k][min_j] >= max)     //перебираем все значения по найденному столбцу с минимальным элементом
            {
                max = dmass[k][min_j];      //находим максимальные элемент
                max_j = k;                  //индекс максимального элемента по горизонтали
            }
        }

        if (min == max && min_j == max_j)   //если наименьший в своей строке и наибольший в своём столбце - выводим
        {
            find = true;
            cout << "Finded saddle points = " << min << " in " << max_j + 1 << " row and " << min_j + 1 << " col." << endl;
        }
    }
    
    for (int j = 0; j < size_y; ++j)        //теперь перебираем по столбцам в поисках минимального элемента
    {
        min = max;
        for (int k = 0; k < size_x; ++k)
        {
            if (dmass[k][j] <= min)
            {
                min = dmass[k][j];          //минимальный элемент в столбце
                min_i = k;                  //индекс по вертикали минимального элемента в столбце
            }
        }

        max = min;
        for (int k = 0; k < size_x; ++k)    //теперь перебираем все значения по найденной строке с минимальным элементом
        {
            if (dmass[min_i][k] >= max)
            {
                max = dmass[min_i][k];      //максимальный элемент в столбце
                max_i = k;                  //индекс максимального элемента по вертикали
            }
        }

        if (min == max && j == max_i)       //если наибольший в своей строке и наименьший в своём столбце - выводим
        {
            find = true;
            cout << "Finded saddle points = " << min << " in " << max_i + 1 << " row and " << min_i + 1 << " col." << endl;
        }
    }

    if (!find)                              //если седловых точек нет - сообщаем
    {
        cout << "Do not find saddle points!" << endl;
    }

    return 0;
}