//ЗАДАНИЕ 1
//Написать программу, которая выводит на экран линию
//заданным символом, вертикальную или горизонтальную, причем линия может выводиться быстро,
//нормально и медленно. Общение с пользователем организовать через меню.
//ЗАДАНИЕ 2
//Написать игру «Кубики». Пользователь и компьютер по
//очереди бросают 2 кубика. Победитель — тот, у кого по результатам трех бросков 
//сумма больше. Предусмотреть красивый интерфейс игры.

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    
    //ЗАДАНИЕ 1
    char symbol;
    int speed = 0;
    int vector = 0;
    int pause = 0;

    cout << "Enter symbol: ";
    cin >> symbol;

    cout << "Choose vector: 1 - right, 2 - down" << endl;
    cin >> vector;
    if (vector != 1 && vector != 2)
    {
        cout << "Wrong choise!" << endl;
        vector = 1;
    }

    cout << "Enter speed: 1 - slow, 2 - midle, 3 - quickly" << endl;
    cin >> speed;
    
    switch (speed)
    {
        case 1:
        {
            pause = 1000;
            break;
        }
        case 2:
        {
            pause = 100;
            break;
        }
        case 3:
        {
            pause = 0;
            break;
        }
        default:
        cout << "Wrong choise!" << endl;
        pause = 0;
    }
    
    for (int i = 0; i < 20; i++)
    {
        if (vector != 1)
        {
            cout << symbol << endl;
        }
        else
        {
            cout << symbol;
        }
        Sleep(pause);
    }
    cout << endl;
    

    //ЗАДАНИЕ 2
    srand(time(0));
    char game = '\0';
    int br1 = 0;
    int br2 = 0;
    
    cout << "*********************************************" << endl;
    Sleep(200);
    cout << "*                                           *" << endl;
    Sleep(200);
    cout << "*  *   *  *   *  ****  *   *  *   *  *   *  *" << endl;
    Sleep(200);
    cout << "*  *  *   *   *  *     *   *  *  *   *   *  *" << endl;
    Sleep(200);
    cout << "*  * *     *  *  ***   *  **  * *    *  **  *" << endl;
    Sleep(200);
    cout << "*  *  *      *   *  *  * * *  *  *   * * *  *" << endl;
    Sleep(200);
    cout << "*  *   *   **    ***   *   *  *   *  *   *  *" << endl;
    Sleep(200);
    cout << "*                                           *" << endl;
    Sleep(200);
    cout << "*********************************************" << endl;
    
    while (game != 'n')
    {
        int ObSum1 = 0;
        int ObSum2 = 0;

        cout << "START GAME? (y/n)";
        cin >> game;
        cout << endl;
        if (game == 'n')
        {
            break;
        }

        for (int j = 0; j < 3; j++)
        {
            br1 = rand() % 6 + 1;
            for (int i = 0; i < 5; i++)
            {
                cout << ">";
                Sleep(500);
            }
            cout << "Your cast: " << br1 << endl;
            ObSum1 += br1;

            br2 = rand() % 6 + 1;
            for (int i = 0; i < 5; i++)
            {
                cout << ">";
                Sleep(500);
            }
            cout << "My cast: " << br2 << endl;
            ObSum2 += br2;
        }

        if (ObSum1 > ObSum2)
        {
            cout << "You win!" << endl;
        }
        else if (ObSum1 < ObSum2)
        {
            cout << "I win!" << endl;
        }
        else
        {
            cout << "No winers!" << endl;
        }
    }
    
    return 0;
}