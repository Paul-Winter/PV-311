//
//  main.cpp
//  Viseliccca_2
//
//  Created by Jaroslav on 29.06.2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Words
{
private:

    string text = "";

    /*void record_text()
    {
    ofstream out;
    out.open(R"(/Users/jaroslav/Desktop/C++ /Viseliccca_2/Viseliccca_2/Viseliccca_2/words.txt)");

    if (out.is_open())
        {


            {
            out << "qwerty shlyapa " << " " <<endl;
            }
        }
    out.close();
    }*/

    string read_text()
    {
        string line;
        //string text="";

        ifstream in(R"(/Users/User/Desktop/ÏÂ-311/Exams/Ðÿæñêèõ/words.txt)");
        if (in.is_open())
        {
            while (getline(in, line))
            {
                text = line;
            }
        }
        else cout << "fuck up!";
        in.close();

        return text;
    }
public:
    string get_open_text()
    {
        text = read_text();
        return text;
    }

    string search_rand_word(const string& link)
    {
        string search_word = link;
        string word = "";
        string word_beg = "";
        string word_end = "";
        size_t random_index = (rand() % search_word.size());
        //acout<<"size="<<search_word.size()<<endl;

        if (search_word[random_index] == ' ')
        {
            random_index = random_index - 1;
        }
        else
        {
            random_index = random_index;
        }
        //cout<<random_index<<"="<<search_word[random_index]<<endl;

        for (size_t i = random_index; i < search_word.size(); ++i)
        {
            word_end.push_back(search_word[i]);

            if (search_word[i] == ' ')
            {
                break;
            }
        }
        cout << endl;

        for (size_t i = random_index; i >= 0; --i)
        {
            word_beg.push_back(search_word[i]);

            if (search_word[i] == ' ')
            {
                break;
            }
        }
        cout << endl;

        size_t size = word_beg.size();
        string temp = "";
        for (size_t i = size; i > 0; --i)
        {
            temp.push_back(word_beg[i]);
        }
        word_beg = temp;
        word = word_beg + word_end;
        size_t size_word = word.size();

        word.erase(word[0], 2);
        word.pop_back();
        //word.erase(word[size-2],2);

        return word;
    }
};

class Hangman
{
private:
    int MAX_ATTEMPS = 6;
    string secret_word_;
    string current_word_;
    vector<char> guessed_letters_;

    bool LetterAlreadyGuessed(char letter) {
        return find(guessed_letters_.begin(), guessed_letters_.end(), letter) != guessed_letters_.end();
    }

    bool UpdateCurrentWord(char letter) {
        bool correct_letter = false;
        for (int i = 0; i < secret_word_.size(); ++i) {
            if (secret_word_[i] == letter) {
                correct_letter = true;
                current_word_[i] = letter;
            }
        }
        guessed_letters_.push_back(letter);
        return correct_letter;
    }

    void DisplayGameInfo() {
        cout << "Word: "s << current_word_ << endl;
        cout << "You have "s << MAX_ATTEMPS << " attemps left."s << endl;
        cout << "Guessed letters: "s;
        for (char& ch : guessed_letters_) {
            cout << ch << " "s;
        }
        cout << endl;
    }

    void DisplayGame() {
        if (MAX_ATTEMPS == 5) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 4) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |     |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 3) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 2) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 1) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |    /" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (MAX_ATTEMPS == 0) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |    / \\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
    }

public:

    Hangman() {
        Words method;
        string text = method.get_open_text();

        srand((int)time(NULL));
        secret_word_ = method.search_rand_word(text);
        current_word_ = string(secret_word_.length(), '_');

    }

    void Play() {
        while (MAX_ATTEMPS > 0) {
            DisplayGameInfo();
            char guess_letter;
            cout << "Guess the letter: "s;
            cin >> guess_letter;
            if (LetterAlreadyGuessed(guess_letter)) {
                cout << "You guessed this letter."s << endl;
            }
            else {
                bool correct_guess = UpdateCurrentWord(guess_letter);
                if (current_word_ == secret_word_) {
                    DisplayGameInfo();
                    cout << "Congratulations! Secret word was: "s << secret_word_ << endl;
                    //MAX_ATTEMPS = 6;
                    return;
                }
                if (correct_guess) {
                    cout << "We have this letter!"s << endl;
                    system("cls");
                }
                else {
                    system("cls");
                    cout << "Word doesn't content this letter."s << endl;
                    --MAX_ATTEMPS;
                    DisplayGame();
                }
            }
        }
        cout << "You ran out of attemps..."s << endl;
        cout << "Secret word was: "s << secret_word_ << endl;
    }
};



int main()
{
    srand((int)time(0));
    bool isPlay = true;
    //Words method;

    while (isPlay)
    {
        cout << "Please, enter '1' to continue and '0' to exit" << endl;
        cin >> isPlay;
        if (!isPlay) break;
        //cout<<"massive of words: "<<method.get_open_text();
        Hangman game;
        game.Play();

        //system("cls");
    }
}

