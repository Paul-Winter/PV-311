//ЗАДАНИЕ 2
//Создайте консольную версию игры «Виселица».
//Важно:
//■ Слово выбирается компьютером из списка слов.
//■ Список слов находится в файле в зашифрованном виде.
//■ По завершении игры на экран выводится статистика игры:
//• количество времени;
//• количество попыток;
//• искомое слово;
//• буквы игрока.

#include <iostream>
#include "load.h"
#include "game.h"
using namespace std;

int main()
{
    bool cont = true;
    char choise = ' ';

    while (cont)
    {
        system("cls");
        game();
        system("pause");
        cout << "Wanna play again?\n>";
        cin >> choise;
        
        if (choise == 'y' || choise == 'Y')
        {
            cont = true;
        }
        else
        {
            cont = false;
        }
    }
    
    return 0;
}