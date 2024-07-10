// 1.07 дз казино.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<queue>
#include <vector>
#include <ctime>//нужен для времени seed
#include <algorithm>//для перетасовки  элемента массива
#include<random>
using namespace std;

//функция для генерации случайного числа в заданном диапазоне, чтобы создавать случайное количество прокрутов колеса

int Random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{

    //queue<char> reel1, reel2, reel3;//барабаны
    queue<char> spin1, spin2, spin3;//прокруты барабанов, наши очереди
    srand(time(0));
    vector<char>symbols = { '@', '#', '$', '%', '*', '&' };

    random_device rd;// мы создаем случайное число
    mt19937 g(rd());//алгоритм для shuffle, алгоритм псевдослучайного числа
    
    vector<char> symbols1 = symbols;
    vector<char> symbols2 = symbols;
    vector<char> symbols3 = symbols;

    shuffle(symbols1.begin(), symbols1.end(), g);//чтобы символы были в разном порядке
    shuffle(symbols2.begin(), symbols2.end(), g);//массивы с барабанами
    shuffle(symbols3.begin(), symbols3.end(), g);

    int reward = 0;//количество заработанных денег
    bool f = false;//  специальная переменная, чтобы поделить выйгрыш  50/50

    while (true)
    {
        getchar();//берет только один символ, нужен для Enter, программа будет дальше работать, если мы нажмем Enter
        
        for (int i = 0; i < 6; i++)//даем информацию нашим прокрутам как изменились барабаны
         {
            spin1.push(symbols[i]);//
            spin2.push(symbols[i]);
            spin3.push(symbols[i]);
         }
        int money = -10;// чтобы сделать прокрут, в  казино нужно заплатить 10 долларов

        int count1 = Random(1, 6), count2 = Random(1, 6), count3 = Random(1, 6);//количество прокрутов каждого барабана
        //первый барабан
        for (int i = 0; i < count1; ++i)
        {
            char front = spin1.front();//возвращает элемент в переменную front
            spin1.pop();//удаляет элемент
            spin1.push(front);//добавляет элемент в конец очереди
        }
        //второй барабан
        for (int i = 0; i < count2; ++i)
        {
            char front = spin2.front();
            spin2.pop();
            spin2.push(front);
        }
        //третий барабан
        for (int i = 0; i < count3; ++i)
        {
            char front = spin3.front();
            spin3.pop();
            spin3.push(front);
        }
        f = false;

        while (!spin1.empty())//пока очередь не пуста
        {
            char a = spin1.front(), b = spin2.front(), c = spin3.front();
            if (a == b && b == c)
            {
                money += 1000;
                int chance = Random(1, 2);
                if (chance == 1)
                {
                    f = true;
                    cout << " Error in spin. Try again";
                    break;
                }
            }
            cout << a << " | " << b << " | " << c << endl;
            spin1.pop();
            spin2.pop();
            spin3.pop();
        }
        if (f)
        {
            continue;
        }
        reward += money;
        cout << "You win! " << money << " dollars. Congratulations! Your balance: " << reward;

    }
    return 0;

}

