//ЗАДАНИЕ 3
//Написать игру «Быки и коровы». Программа
//«загадывает» четырёхзначное число и играющий должен
//угадать его.После ввода пользователем числа программа
//сообщает, сколько цифр числа угадано(быки) и сколько
//цифр угадано и стоит на нужном месте(коровы).После
//отгадывания числа на экран необходимо вывести количество 
//сделанных пользователем попыток.В программе
//необходимо использовать рекурсию.

#include <iostream>
using namespace std;

bool bac(int** mass)
{
    int buls = 0;
    int cows = 0;
    int buf = 0;
    bool trigger = false;

    if (mass[0][0] == mass[1][0])           //если числа совпали, возвращаем ЛОЖЬ.
    {
        return false;
    }
    else
    {
        for (int j = 1; j < 5; j++)         //считаем быков
        {
            buf = mass[1][j];
            for (int n = j + 1; n < 5; ++n) 
            {
                if (buf == mass[1][n])
                {
                    trigger = true;         //устанавливаем триггер, если во введённом числе повторяются цифры
                }
            }
            
            for (int k = 1; k < 5; k++)     
            {
                if (buf == mass[0][k] && !trigger)
                {
                    ++buls;
                }
            }
            trigger = false;
        }
        
        for (int k = 1; k < 5; k++)         //считаем коров
        {
            if (mass[0][k] == mass[1][k])
            {
                ++cows;
            }
        }
        
        if (mass[1][0] > 0)
        {
            cout << "Number " << mass[1][0] << " has " << buls << " buls and " << cows << " cows. Try again..." << endl;
        }
        return true;
    }
}

int** fill(int n1, int n2)
{
    int** mass = new int* [4];
    for (int i = 0; i < 2; ++i)
    {
        mass[i] = new int[2];
    }
    
    //создаём двумерный массив из двух строк и пяти столбцов,
    //где 0-я строка содержит в 0-ом элементе загаданное ПК число, а потом его разложение по цифрам,
    //соответственно, в 0-ом элементе 1-й строки - введённое игоком число, и затем его разложение по цифрам 

    mass[0][0] = n1;
    mass[0][1] = (n1 - (n1 % 1000)) / 1000;
    mass[0][2] = (n1 % 1000) / 100;
    mass[0][3] = ((n1 % 1000) % 100) / 10;
    mass[0][4] = n1 - (mass[0][1] * 1000 + mass[0][2] * 100 + mass[0][3] * 10);
    mass[1][0] = n2;
    mass[1][1] = (n2 - (n2 % 1000)) / 1000;
    mass[1][2] = (n2 % 1000) / 100;
    mass[1][3] = ((n2 % 1000) % 100) / 10;
    mass[1][4] = n2 - (mass[1][1] * 1000 + mass[1][2] * 100 + mass[1][3] * 10);
    
    return mass;
}

int game(int number, int entered, int counter)
{
    bool cont = true;
    if (entered == 0)
    {
        cout << "Number is " << number << endl;
        cout << "Game over!" << endl;
        return counter;
    }
    else
    {
        ++counter;
        
        bool trigger = true;
        while (trigger)                         //ввод числа и проверка на корректность
        {
            cout << "Enter " << counter << " number (XXXX): ";
            cin >> entered;
           
            if (entered == 0)
            {
                break;
            }
            if (entered > 999 && entered < 10000)
            {
                trigger = false;
            }
            else
            {
                cout << "Wrong number! Try format (XXXX)." << endl;
            }
        }
        
        cont = bac(fill(number, entered));
        if (cont)
        {
            game(number, entered, counter);     //рекурсия
        }
        else
        {
                cout << "You win at " << counter << " attemps!";
        }
    }
}

int main()
{
    cout << "****************" << endl;
    cout << "*bulls and cows*" << endl;
    cout << "****************" << endl;
    cout << "To quit enter 0 or any symbol.\n" << endl;

    int number = 0;
    int entered = 1;
    int counter = 0;
    srand(time(0));
    number = rand() % 9000 + 1000;
    //cout << number << endl;
    
    game(number, entered, counter);     //вызов рекурсивной фунции

    return 0;
}
