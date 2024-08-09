#include "game.h"
#include "gallows.h"


void game()
{
	const char* path = "C:\\Intel\\words.txt";
	Load Text(path);
	
    string* words = new string[10];
    words = Encript(path);

    string hidden_word = select_word(words);
    Gallows newGame(hidden_word);

    newGame.Start();
}

string* Encript(const char* path)           //סקטעûגאול פאיכ ט נאסרטפנמגûגאול סכמגא
{
    string* list_of_words = new string[10];
    string current_str = "";
    string encript_str = "";
    int counter = 0;

    ifstream file;
    file.open(path);

    if (file.is_open())
    {
        while (!file.eof())
        {
            while (getline(file, current_str))
            {
                for (int i = 0; i < strlen(current_str.c_str()); i++)
                {
                    encript_str += static_cast<char>(static_cast<int>(current_str.at(i)) - 1);
                }
                list_of_words[counter] = encript_str;
                encript_str = "";
                ++counter;
            }
        }
    }
    else
    {
        cout << "Can't open file to read!" << endl;
    }
    file.close();

    return list_of_words;
}

string select_word(const string* words)              //גûבטנאול חאדאהûגאולמו סכמגמ
{
    srand(time(NULL));
    int n = rand() % 10;
    return words[n];
}