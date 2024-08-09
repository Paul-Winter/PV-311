//ЗАДАНИЕ 4
//Модифицировать игру «GUESS MY NUMBER» следующим образом:
//■ пользователь не выбирает уровень, т. к. переход ко второму
//уровню возможен только после завершения первого без
//проигрыша (если игрок желает продолжать);
//■ первый уровень длится три раунда (на каждом раунде
//загадывается новое число), а второй — два раунда. Новые
//жизни начисляются игроку перед новым раундом.
//■ если пользователь проиграл раунд, то компьютеру начисляются очки 
//за раунд в размере начальные жизни пользователя, умноженные на 5
//для первого уровня и на 10 для второго;
//■ количество очков сохраняется и накапливается в раундах и уровнях;
//■ промежуточные итоги выводятся после каждого раунда и уровня.

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    srand(time(0));
    
    //ЗАДАНИЕ 4
    int level = 1;          //уровень игры
    int number = 0;         //загаданное число
    int num = 0;            //число, введённое игроком 
    int lives = 1;          //количество жизней
    char help = '\0';       //символ для выбора (y/n)
    int ScorePl = 0;        //очки игрока за раунд
    int ObScorePl = 0;      //общие очки игрока за игру
    int ScorePk = 0;        //очки ПК
    bool game = true;       //признак продолжения раунда
    bool win = false;       //признак победы

    for (int round = 1; round < 6; round++)     //цикл для 3 раундов 1-го уровня и 2-ух второго 
    {
        game = true;                            //устанавливаем признак продолжения игры

        if (round > 3)                          //если прошли 3 раунда, увеличиваем уровень игры
        {
            ++level;
        }

        if (level == 1)                         //начисляем исходные жизни и загадываем число для 1 и 2 уровней
        {
            cout << "1 LEVEL (1-10)" << endl;
            lives = 10 / 2;                      
            number = 1 + rand() % 10;
            //cout << number << endl;             
        }
        else
        {
            cout << "2 LEVEL (10-100)" << endl;
            lives = 90 / 4;
            number = 10 + rand() % 91;;
            //cout << number << endl;
        }
        cout << "Round: " << round << ". Your score: " << ObScorePl << endl;        //выводим промежуточные итоги
        
        while (game)                                                                //играем, пока установлен признак продолжения раунда
        {

            cout << "Lives: " << lives << ". Enter number: ";                       //вывод оставшихся жизней и ввод числа
            cin >> num;

            if (num != number)                                                      //если число не угадано
            {
                if (lives > 1)                                                      //если ещё есть жизни
                {

                    if (lives == 2)                                                 //если штрф за подсказку добьёт, то не предлагаем
                    {
                        --lives;                                                    //уменьшаем жизни за неотгаданное
                        cout << "Don't guess! Stay last chanse!" << endl;           //предупреждаем, что остался последний ход
                    }
                    else
                    {
                        --lives;                                                    //уменьшаем жизни за неотгаданное
                        cout << "Don't guess! Wonna help? (y/n)";                   //предлагаем помощь
                        cin >> help;
                        if (help == 'y')                                            //если согласился
                        {
                            --lives;                                                //уменьшаем жизни за подсказку
                            help = '\0';
                            if (number > num)
                            {
                                cout << "The number is greater." << endl;           //вывод подсказки
                            }
                            else
                            {
                                cout << "The number is less." << endl;
                            }
                            if (lives == 0)                                         //если подсказка забрала последнюю жизнь
                            {
                                cout << "You lost! Number is " << number << endl;   //выводим ответ
                                game = false;                                       //выключаем признак продолжения раунды
                                round = 6;                                          //завершаем игру
                                if (level == 1)                                     //рассчитываем очки ПК
                                {
                                    ScorePk = 10 / 2 * 5;
                                }
                                else
                                {
                                    ScorePk = 90 / 4 * 10;
                                }
                            }
                        }
                    }
                }
                else                                                            //если жизни кончились
                {
                    cout << "You lost! Number is " << number << endl;           //выводим неугаданное число
                    game = false;                                               //завершаем раунд
                    round = 6;                                                  //завершаем игру
                    if (level == 1)                                             //рассчитываем очки ПК
                    {
                        ScorePk = 10 / 2 * 5;
                    }
                    else
                    {
                        ScorePk = 90 / 4 * 10;
                    }
                }
            }
            else                                                                //если число угадано
            {
                if (level == 1)                                                 //расчёт очков для 1 и 2 уровня
                {
                    ScorePl = lives * 5;
                }
                else
                {
                    ScorePl = lives * 10;
                }
                cout << "You win! Your score: " << ScorePl << endl;             //вывод результата раунда
                if (round == 5)                                                 //если все раунды пройдены
                {
                    win = true;                                                 //включаем признак победы
                    game = false;                                               //завершаем последний раунд
                }
                else                                                            //если ещё не все раунды пройдены
                {
                    if (round < 4)
                    {
                        cout << "Continue? (y/n)";                              //предлагаем продолжать
                        cin >> help;
                        if (help == 'n')                                        //в случае отказа
                        {
                            round = 6;                                          //завершаем игру

                        }
                    }
                    game = false;                                               
                }
            }

            if (lives == 0)                                                     //если жизни кончились - завершаем игру
            {
                game = false;
                round = 6;
            }
            
            ObScorePl += ScorePl;                                               //накапливаем общий результат игрока

        }
    }
    
    if (win)                                                                    //вывод финальных результатов
    {
        cout << "FULL WIN!" << endl;
        cout << "YOUR SCORE: " << ObScorePl << endl;
    }
    else
    {
        cout << "GAME OVER" << endl;
        cout << "YOUR SCORE: " << ObScorePl << endl;
        cout << "COMP SCORE: " << ScorePk << endl;
    }
      
    return 0;
}