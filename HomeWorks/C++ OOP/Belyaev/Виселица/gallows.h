#pragma once
#include "game.h"
#include "chrono"
#include <ctime>

class Gallows
{
public:
	
	string word;                                    //���������� �����
    string used_letters = "";                       //�������������� �����
    string guessed_letters = "";                    //��������� �����
    int lives = 7;              
    bool win = false;

    string* picture = new string[8]{
    {
        "                   HHHHHHHHHHHHHHH\n"
        "                   |             H\n"
        "                   |             H\n"
        "                   O             H\n"
        "                 / | \\           H\n"
        "                   |             H\n"
        "                  / \\            H\n"
        "                                 H\n"
        "                                 H\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "                   HHHHHHHHHHHHHHH\n"
        "                   |             H\n"
        "                   |             H\n"
        "                   O             H\n"
        "                 / | \\           H\n"
        "                   |             H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "                   HHHHHHHHHHHHHHH\n"
        "                   |             H\n"
        "                   |             H\n"
        "                   O             H\n"
        "                 /   \\           H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "                   HHHHHHHHHHHHHHH\n"
        "                   |             H\n"
        "                   |             H\n"
        "                   O             H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "                   HHHHHHHHHHHHHHH\n"
        "                   |             H\n"
        "                   |             H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "                   HHHHHHHHHHHHHHH\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "                                 H\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "            HHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"
        "            H                          H\n"
    },
    {
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
    }
    };

    char* letters = new char[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	Gallows() = delete;
    Gallows(const string word) : word{ word }
	{

	}
    
    char GetLetter()                            //��������, ��������� � ��������� ����� � ������� �������
    {
        char letter = '\0';
        bool right = false;
        while (!right)
        {
            cout << "Enter your letter>";
            cin >> letter;

            if (isalpha(letter))
            {
                letter = toupper(letter);
                this->letters[(static_cast<int>(letter)) - 65] = ' ';
                return letter;
            }
            else
            {
                cout << "Isn't letter! Try again..." << endl;
            }
        }
    }

    string usedLetters()                        //������� �������������� �����
    {
        used_letters = " ";
        char finded = '\0';

        for (int i = 0; i < 26; i++)
        {
            if (letters[i] == ' ')
            {
                finded = static_cast<char>(i + 65);
                used_letters += finded;
                used_letters += " ";
            }
        }
        return used_letters;
    }

    bool checkLetter(char letter)               //��������� ����� �� ��������� �, ���� �� �������, ������� ������� 
    {
        int cuurent_len = strlen(this->word.c_str());
        bool equal = false;

        for (int i = 0; i < cuurent_len; i++)
        {
            if (word[i] == letter)
            {
                equal = true;
                guessed_letters[i] = letter;
                if (guessed_letters == word)
                {
                    return true;
                }
            }
        }
        if (!equal)
        {
            --lives;
        }
        return false;
    }
    
    void display(int lives)                         //����� �������� ���������
    {
        system("cls");
        cout << "***************************************************" << endl;
        cout << "******************* THE GALLOWS *******************" << endl;
        cout << "***************************************************" << endl;
        cout << "                   unused letters:" << endl;
        for (int i = 0; i < 26; i++)
        {
            cout << letters[i] << " ";
        }
        cout << endl;
        cout << "                  guessed letters:" << endl;
        cout << "                        " << guessed_letters << endl;
        cout << endl;

        cout << picture[lives + 1] << endl;
        cout << "Your lives: " << lives + 1 << "\tUsed letters:" << usedLetters() << endl;
        cout << "***************************************************" << endl;
    }

	void Start()                                    
	{
        int counter = 0;                                //������� �������
        cout << this->word << endl;                     //���������� �����
        int cuurent_len = strlen(this->word.c_str());   //������������� ������ ��������� ����
        for (int i = 0; i < cuurent_len; i++)
        {
            guessed_letters += ' ';                     //������������� ������ ��������� ����
        }
        
        auto start = std::chrono::system_clock::now();  //����� ������

        while (win != true)                             //�������� ����, ���� �� ��������
        {
            this->display(lives - 1);
            win = this->checkLetter(this->GetLetter());
            ++counter;
            if (!lives)                                 //���� ������� ��������� - �������
            {
                break;
            }
        }
        this->display(lives - 1);

        string rez;
        if (win)
        {
            rez = "You win!";
        }
        else
        {
            rez = "You lost!";
        }

        auto end = std::chrono::system_clock::now();    //����� ���������
        std::chrono::duration<double> elapsed_seconds = end - start;
        
        cout << rez << " Attemps: " << counter << " ";  //����� �����������
        cout << "Elapsed Time: " << elapsed_seconds.count() << " sec" << endl;
        cout << "Hidden word is: " << word << ", used letters: " << used_letters << endl;
	}
};

