#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

bool isCorrectGuess(const string& secretWord, const vector<bool>& guessedLetters) {
    for (size_t i = 0; i < secretWord.size(); ++i) 
    {
        if (!guessedLetters[i]) 
        { 
            return false; 
        }
    }
    return true; 
}


void drawHangman(int incorrectGuesses) 
{
    if (incorrectGuesses == 0)
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 1) 
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 2) 
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |        |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 3) 
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 4) 
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|\\" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 5) 
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|\\" << endl;
        cout << " |       / " << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|\\" << endl;
        cout << " |       / \\" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
}

int main() {
    vector<string> words; 
    string word;
    ifstream inputFile("words.txt"); 
    while (getline(inputFile, word)) {
        if (!word.empty() && word[word.size() - 1] == '\r') 
        { 
            word = word.substr(0, word.size() - 1);
        }
        words.push_back(word);
    }

    inputFile.close();
    srand(static_cast<unsigned int>(time(nullptr))); 
    string secretWord = words[rand() % words.size()];
    vector<bool> guessedLetters(secretWord.size(), false);
    int attemptsLeft = 6; 
    cout << "Hangman Game" << endl;

    while (attemptsLeft > 0) { 
        
        cout << "Secret Word: ";
        for (size_t i = 0; i < secretWord.size(); ++i) {
            if (guessedLetters[i]) {
                cout << secretWord[i] << " "; 
            }
            else {
                cout << "_ "; 
            }
        }
        cout << endl;
        char inputChar;
        cout << "Guess a letter: "; 
        cin >> inputChar;
        bool letterFound = false;
        for (size_t i = 0; i < secretWord.size(); ++i) { 
            if (secretWord[i] == inputChar) {
                guessedLetters[i] = true;
                letterFound = true;
            }
        }

        if (!letterFound) 
        {
            --attemptsLeft; 
            cout << "Incorrect guess. Attempts left: " << attemptsLeft << endl;
        }
        drawHangman(6 - attemptsLeft);
        if (isCorrectGuess(secretWord, guessedLetters)) 
        { 
            cout << "Congratulations! You have won the game. The word was:" << secretWord << endl;
            break;
        }
    }

    if (attemptsLeft <= 0) 
    { 
        cout << "Game Over! The word was: " << secretWord << endl; 
    }

    return 0;
}