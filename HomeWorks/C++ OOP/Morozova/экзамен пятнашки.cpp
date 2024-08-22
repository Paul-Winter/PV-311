// экзамен пятнашки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <string>
#include <set>


using namespace std;

 int Size_board = 3;
const int Empty_tile = 0;

struct Point//координаты клеток
{
    int x;
    int y;
};

class Pazzle
{
private:
    vector<vector<int>> board;

    string convertBoardToString() 
    {
        string state;
        for ( auto& row : board)
        {
            for (int cell : row)
            {
                state += to_string(cell) + ",";
            }
        }
        return state;
    }
public:
    int t = time(0);
    int count = 0;

    Pazzle()
    {
        initBoard();
    }

    void initBoard()
    {
        board.resize(Size_board, vector<int>(Size_board));

        int num = 0;
        for (int i = 0; i < Size_board; i++)
        {
            for (int j = 0; j < Size_board; j++)
            {
                board[i][j] = num++;
            }
        }
        board[0][0] = Empty_tile;
    }


    Point findEmptyTile()
    {
        Point empty;
        for (int i = 0; i < Size_board; i++)
        {
            for (int j = 0; j < Size_board; j++)
            {
                if (board[i][j] == Empty_tile)
                {
                    empty.x = j;
                    empty.y = i;
                    return empty;
                }
            }
        }
        return empty;
    }


    void printBoard()
    {
        cout << "Move: "<< count << "Time: "<<time(0) - t << endl;

        for (int i = 0; i < Size_board; i++)
        {
            for (int j = 0; j < Size_board; j++)
            {
                if (board[i][j] == Empty_tile)
                {
                    cout << setw(3) << " ";
                }
                else
                {
                    cout << setw(3) << board[i][j];
                }
            }
            cout << endl;
        }
    }

    void shuffleBoard()
    {
        srand(time(0));
        for (int i = 0; i < 1000; i++)
        {
            int randomMove = rand() % 4;
            moveTile(randomMove);
        }
    }

    bool moveTile(int move)
    {
        Point empty = findEmptyTile();
        Point target = empty;
        if (move == 0 && empty.y > 0)
        {
            target.y -= 1; //Up
        }
        else if (move == 1 && empty.y < Size_board - 1)
        {
            target.y += 1; //Down
        }
        else if (move == 2 && empty.x > 0)
        {
            target.x -= 1; //Left
        }
        else if (move == 3 && empty.x < Size_board-1)
        {
            target.x += 1; //Right
        }
        else
        {
            return false; //Invalid move
        }
        count++;
        swap(board[empty.y][empty.x], board[target.y][target.x]);
        return true;

    }

    bool checkBoard()
    {
        bool f = true;
        int num = 0;
        for (int i = 0; i < Size_board; i++)
        {
            for (int j = 0; j < Size_board; j++)
            {
                if (board[i][j] != num)
                {
                    f = false;
                    return f;
                }
                num++;
            }
        }
        return f;
    }

    bool solve(set<string>&visitedStates)
    {
        string currentState = convertBoardToString();

        if (visitedStates.count(currentState) > 0)
        {
            return false;
        }

        visitedStates.insert(currentState);

        if (checkBoard() == Size_board * Size_board)
        {
            return true;
        }

        vector<vector<int>> moveEstimate;

        for (int move = 0; move < 4; move++)
        {
            if (moveTile(move))
            {
                vector<int>score = { move, checkBoard() };//записывем наш ход и сколько чисел на своих местах
                moveEstimate.push_back(score);
                if (move % 2 == 0)
                {
                    moveTile(move + 1);
                }
                else
                {
                    moveTile(move - 1);
                }
            }
            else
            {
                vector<int> score = { move, -1 };
                moveEstimate.push_back(score);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3 - i; j++)
            {
                if (moveEstimate[j][1] > moveEstimate[j + 1][1])
                {
                    swap(moveEstimate[j], moveEstimate[j + 1]);
                }
            }
        }

        vector<vector<int>> reserveBoard = board;
        int reserveCount = count;

        for (int i = 3; i >= 0; i--)
        {
            moveTile(moveEstimate[i][0]);
            count++;
            printBoard();
            bool f = solve(visitedStates);
            if (f)
            {
                return true;
            }
            board = reserveBoard;
            count = reserveCount;
        }
    }
};

int main()
{
   // puzzle.printBoard();
    int answer;
    cout << "Enter 3 for  3x3 mode, 4 for 4x4 mode: ";
    cin >> answer;
    Size_board = answer;
    Pazzle puzzle;
    cout << "Enter 1 for automatic shuffle and 2 for manual shuffle: ";
    cin >> answer;
    int move;

    if (answer == 1)
    {
      puzzle.shuffleBoard();

    }
    else
    {
      puzzle.printBoard();
      
        while (true)
        {
            cout << "Enter move: 0 - up, 1 - down, 2 - left, 3 - right or -1  ";
            cin >> move;
            if (move == -1)
            {
                break;
            }
            puzzle.moveTile(move);
            puzzle.printBoard();
        }
    }

    cout << "Your boart is shuffled. You can start solving it now." << endl;
    set<string> visitedStates;
    
    puzzle.count = 0;
    puzzle.printBoard();

    cout << "Enter 1 for automatic solve and 2 for manual solve: ";
    cin >> answer;

    puzzle.t = time(0);

    if (answer == 1)
    {
        if (puzzle.solve(visitedStates))
        {
            cout << "Solved";
        }
    }
    else
    {
        puzzle.printBoard();

         while (!puzzle.checkBoard())
            {
                cout << "Enter move: 0 - up, 1 - down, 2 - left, 3 - right  ";
                cin >> move;
                puzzle.moveTile(move);
                puzzle.count++;
                puzzle.printBoard();
        
            }
         cout << "You won";
    }

    return 0;
}
