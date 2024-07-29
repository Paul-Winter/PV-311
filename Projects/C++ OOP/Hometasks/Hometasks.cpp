//#include<iostream>
//#include <string>
//#include <fstream>
//#include<Windows.h>
//#include<mmsystem.h>
//#include <vector>
//#pragma comment (lib, "winmm.lib")
//using namespace std;
//enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна
//void SetColor(Color text, Color background)
//{
//    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
//}
//class bank {
//private:
//    float viza = 0.000;
//    float viza2 = 0.000;
//    int d = 0, n = 0, m = 0;
//    char op, op1, opj, objj;
//    string regi, regi1, regi2, regi3, regi4, regi5;
//    string regi10, regi11, regi12, regi13, regi14, regi15;
//    ifstream file_1;
//    ofstream file, file1;
//    vector<vector<int>>CARD;
//public:
//    string pass() {
//        return regi5;
//    }
//    void miny1() {
//        cout << "Добро пожаловать банк Байкал!" << endl;
//        cout << "что вы хотите приобрести? 0:дебетовый, 9: кредитной" << endl;
//        cin >> op;
//        switch (op)
//        {
//        case '0':
//            cout << "Ввидите ФИО:" << endl;
//            cin >> regi;
//            getline(cin, regi);
//            cout << "Ввидите номер тел:" << endl; cin >> regi1;
//            cout << "Дата рождения:" << endl; cin >> regi2;
//            cout << "Серий и номер паспорта:" << endl; cin >> regi3;
//            cout << "какой платежной системы вы хотите? viza,master card,мир,maestro,masterPass" << endl;
//            cin >> regi4;
//            getline(cin, regi4);
//            cout << "придумайте пин-код:" << endl; pass(); cin >> regi5;
//            getline(cin, regi5);
//            break;
//        case '9':
//            cout << "Ввидите ФИО:" << endl;
//            cin >> regi10;
//            getline(cin, regi10);
//            cout << "Ввидите номер тел:" << endl; cin >> regi11;
//            cout << "Дата рождения:" << endl; cin >> regi12;
//            cout << "Серий и номер паспорта:" << endl; cin >> regi13;
//            cout << "какой платежной системы вы хотите? viza,master card,мир,maestro,masterPass" << endl;
//            cin >> regi14;
//            getline(cin, regi4);
//            cout << "придумайте пин-код:" << endl; pass(); cin >> regi15;
//            getline(cin, regi15);
//            break;
//        default:
//            while (true) {
//                cout << "!!!!ТЕБЯ ЗА СКАМИЛИ!!!!" << endl;
//                PlaySound(TEXT("D:\\Rick-Astley-Never-Gonna-Give-You-Up-_Official-Music-Video_.wav"), SND_SYNC, NULL);
//            }
//        }
//    }
//    void card() {
//        int ttg = 0; string h;
//        cout << "войти:7" << endl;
//        cout << "поменять пин-код:9" << endl;
//        cout << "Выход:8" << endl;
//        cin >> op1;
//        switch (op1)
//        {
//        case '7':
//            pass();
//            cout << "Ввидите пин-код:" << endl;
//            cin >> regi5;
//            getline(cin, regi5);
//            break;
//        default:
//            while (true) {
//                cout << "!!!!ТЕБЯ ЗА СКАМИЛИ!!!!" << endl;
//                PlaySound(TEXT("D:\\Rick-Astley-Never-Gonna-Give-You-Up-_Official-Music-Video_.wav"), SND_SYNC, NULL);
//            }
//        case '8':
//            cout << "Всего доброго до свидания!" << endl;
//            exit(0);
//            system("pause");
//            break;
//        case'9':
//            cin >> regi5;
//            cout << "придумайте пин-код:" << endl;
//            if (h == regi5)
//            {
//                ttg = 1;
//            }
//            break;
//        }
//    }
//    void k(int D = 0, int N = 0, int M = 0) {
//        this->d = D;
//        this->n = D;
//        this->m = M;
//        file1.open("ss.txt");
//        file1.close();
//    }
//    void miny(int D = 0, int N = 0, int M = 0) {
//        cout << "~~~КАТЕГОРИЯ~~~" << endl << "1:пополнить\n" << "2:топ расходы\n" << "3:посмотреть счёт на карте\n" << "4:Выход\n";
//        cin >> op;
//        switch (op)
//        {
//        case '1':
//            cout << "сколько хотите?" << endl;
//            cin >> viza;
//            viza -= 10.43;
//            viza--;
//            file << "с коммиссии:" << viza << ".Руб";
//            file.open("ggggg.txt");
//            break;
//        case '2':
//            k();
//            //cin >> op;
//            //if (op == viza) {
//            break;
//        case '3':
//            file << "Баланс:" << viza << ".Руб" << endl;
//            file.open("gggggg.txt");
//            break;
//        case '4':
//            cout << "Всего доброго до свидания!" << endl;
//            exit(0);
//            system("pause");
//        default:
//            while (true) {
//                cout << "!!!!ТЕБЯ ЗА СКАМИЛИ!!!!" << endl;
//                PlaySound(TEXT("D:\\Rick-Astley-Never-Gonna-Give-You-Up-_Official-Music-Video_.wav"), SND_SYNC, NULL);
//            }
//        }
//    }
//    void k1(int N = 0, int M = 0, int c = 1) {
//        this->n = N;
//        this->m = M;
//        for (int i = 0; i < c; i++)
//        {
//            file << "" << endl;
//            cin >> n;
//            file << "" << endl;
//        }
//    }
//};
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    SetColor(Cyan, LightRed);
//    ifstream file_1;
//    ofstream file;
//    string f;
//    string f1;
//    bank obj;
//    int d = 0, n = 0, m = 0;
//    int a = 0;
//    obj.miny1();
//    for (int i = 0; i < 2; i++)
//    {
//        obj.card();
//    }
//    while (true)
//    {
//        obj.miny();
//        obj.k(d, n, m);
//        //obj.k1();
//    }
//    file.open("yhhyy.txt");
//    file_1.open("ll.txt");
//}
//
//
//
//
//
//
//
//
//
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
using namespace std;


class CGallows
{
    ifstream m_input;
    const string m_word;
    map<char, vector<size_t>> m_posMap;
    string m_searchWord;

    static const vector<string> m_images;

    enum steps : size_t
    {
        BEGIN,
        ONE, TWO, THREE, FOR, FIVE, SIX, SEVEN,
        END
    } m_step = BEGIN;

    enum result : size_t
    {
        LOSE, WIN
    } m_res = LOSE;

    void FillMap()
    {
        size_t pos{};
        for (char ch : m_word)
            m_posMap[ch].emplace_back(pos++);
    }

    char getChar()
    {
        cout << "Enter one character: ";
        char ch{}; cin >> ch;

        return m_posMap.find(ch) != m_posMap.cend() ? ch : '\0';
    }

    friend steps& operator++(steps&);
public:
    CGallows(const string& filename = "word.txt") :
        m_input(filename),
        m_word(
            istream_iterator<char>(m_input),
            istream_iterator<char>()
        ),
        m_searchWord(m_word.size(), '*')
    {
        FillMap();
    };

    void Play()
    {
        while (m_step != END)
        {
            system("cls");
            cout << "Your word is: " << m_searchWord << '\n' << endl;
            cout << m_images[m_step] << endl;

            if (char ch{ getChar() })
            {
                const vector<size_t>& vec{ m_posMap[ch] };
                for (size_t i{}, end{ vec.size() }; i < end; ++i)
                    m_searchWord[vec[i]] = ch;

                m_posMap.erase(ch);

                if (m_searchWord.find('*') == string::npos)
                    m_step = END, m_res = WIN;
            }
            else
                ++m_step;
        }

        system("cls");
        cout << "\nThe word is: " << m_word << endl;
        cout << "You are " << (m_res == WIN ? "winner.\n" : "loser.\n") << endl;
    }
};

CGallows::steps& operator++(CGallows::steps&);

int main()
{
    CGallows game;
    game.Play();

    system("pause");
}

CGallows::steps& operator++(CGallows::steps& st)
{
    size_t tmp = st;
    return st = static_cast<CGallows::steps>(++tmp);
}

const vector<string> CGallows::m_images
{
    {   },
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
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      /   \\           $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "       / \\            $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    }
};