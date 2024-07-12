#include <iostream>//ввод
#include <fstream>// ввод из файла
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Hangman//состояние
{
private://только внутри класса
    vector<string>words;//слова из файла, которые мы загадываем
    string word;//слово,которое мы загадали, его нужно отгадать
    string guessedWord;//отгадываемые буквы в слове
    vector<char> guessedLetters;//массив из отгаданных букв
    int attempts;//количество попыток

public://то, что существует для всей программы
    Hangman()//наш конструктор
    {
        attempts = 6;
        ifstream file("word.txt");//открытие на чтение файла
        if (file.is_open())//проверка открылся ли наш файл
        {
            string temp;//временная строка
            while (file >> temp)//пока мы читаем  файл по сточкам
            {
                words.push_back(temp);//заполняем наш массив. Работаем только с английскими словами
            }
            file.close();
        }
        else
        {
            cerr << " Невозможно открыть файл" << endl;//cerr - system error,вывести как ошибку
            exit(1);//выход из прогаммы полностью
        }
        Word();

    }

    string Word()
    {
        word = words[rand() % words.size()];
        guessedWord = string(word.length(), '*');

        return word;
    }

    void startGame()
    {
        while (attempts > 0 && guessedWord != word)
        {
            displayHangman();
            displayWord();
            char guess;//букву, которую мы угадываем
            cin >> guess;
            checkLetter(guess);//проверить букву
            cout << "Введите букву: ";
        }

        if (attempts == 0)
        {
            displayHangman();
            cout << " Ты проиграл! Твое слово было: " << word << endl;
        }
        else
        {
            displayWord();
            cout << " Поздравляю! Ты угадал слово." << endl;
        }

        cout << " Игра закончена. Осталось попыток: " <<  attempts << endl;

    }

    void checkLetter(char letter)
    {
        if (guessedLetters.end() == find(guessedLetters.begin(), guessedLetters.end(), letter))//find для вектора
        {
            guessedLetters.push_back(letter);
           if (word.find(letter) != string::npos)//find для строки
           {
              for (int i = 0; i < word.length(); ++i)
              {
                if (word[i] == letter)
                {
                    guessedWord[i] = letter;
                }
              }
           }
           else
           {
            attempts--;
           }
        }
        else
        {
          cout << " Ты уже пробовал эту букву." << endl;
        }
    }

    void displayHangman()
    {
        int remainingAttempts = attempts;
        cout << " Осталось попыток: " << remainingAttempts << endl;
        cout << "---------------" << endl;
        if (remainingAttempts < 6)
        {
            cout << "            |" << endl;
        }
        if (remainingAttempts < 5)
        {
            cout << "            O" << endl;
        }
        if (remainingAttempts < 4)
        {
            if (remainingAttempts < 3)
            {
                cout << "           /";
            }
            if (remainingAttempts < 2)
            {
                cout << "|";
            }
            if (remainingAttempts < 1)
            {
                cout << "\\";
            }
            cout << endl;
        }
        if (remainingAttempts < 3)
        {
            cout << "            |" << endl;
        }
        if (remainingAttempts < 2)
        {
            cout <<"           / ";
        }
        if (remainingAttempts < 1)
        {
            cout << "\\" << endl;
        }
        cout << "---------------" << endl;
        cout << endl;
    }

    void displayWord()//вывод слова
    {
        cout << "Слово: ";
        for (int i = 0; i < guessedWord.length(); ++i)
        {
            cout << guessedWord[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Hangman hangman;
    hangman.startGame();

    return 0;
}
