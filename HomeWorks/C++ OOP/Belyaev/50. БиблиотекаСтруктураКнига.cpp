//ЗАДАНИЕ 1
//Разработайте программу «Библиотека».
//Создайте структуру «Книга»(название, автор, издательство,
//жанр).Создайте массив из 10 книг.Реализуйте для него
//следующие возможности :
//■■Редактировать книгу;
//■■Печать всех книг;
//■■Поиск книг по автору;
//■■Поиск книги по названию;
//■■Сортировка массива по названию книг;
//■■Сортировка массива по автору;
//■■Сортировка массива по издательству.

#include <iostream>
using namespace std;

struct library
{
    string name = "\0";
    string author = "\0";
    string publishing = "\0";
    string genre = "\0";

}; library* books;

library* fill(library* books, int num)
{
    srand(time(NULL));
    string s = "\0";
    cout << "FILLING LIBRARY..." << endl;

    for (int i = 0; i < num; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            s += char(97 + rand() % 26);
        }
        books[i].name = s;
        s = "\0";
        
        for (int k = 0; k < 5; k++)
        {
            s += char(97 + rand() % 26);
        }
        books[i].author = s;
        s = "\0";

        for (int k = 0; k < 5; k++)
        {
            s += char(97 + rand() % 26);
        }
        books[i].publishing = s;
        s = "\0";

        for (int k = 0; k < 5; k++)
        {
            s += char(97 + rand() % 26);
        }
        books[i].genre = s;
        s = "\0";
        
        //ручной ввод закоментировал, так как утомительно всё время вносить столько значений

        /*
        cout << i + 1 << " book: " << endl;
        cout << "Enter name: ";
        cin >> books[i].name;
        cout << "Enter author: ";
        cin >> books[i].author;
        cout << "Enter publishing: ";
        cin >> books[i].publishing;
        cout << "Enter genre: ";
        cin >> books[i].genre;
        */
    }
    return books;
}

int menu(library* books, int num)
{
    system("pause");
    system("cls");
    int cont = 0;
    while (cont == 0)
    {
        cout << "- LIBRARY -" << endl;
        cout << "1. Edit book." << endl;
        cout << "2. List books." << endl;
        cout << "3. Find books by author." << endl;
        cout << "4. Find books by name." << endl;
        cout << "5. Sorting by name." << endl;
        cout << "6. Sorting by autor." << endl;
        cout << "7. Sorting by publishing." << endl;
        cout << "8. Quit." << endl;
        cout << "Your choise(1-8): ";
        cin >> cont;
    }
    return cont;
}

void display(library* books, int num)
{
    cout << "\nLIST:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << " book info:" << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Name: " << books[i].name << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "Publishing: " << books[i].publishing << endl;
    }
}

void edit(library* books, int num, int number)
{
    cout << "Editing " << number << " book: " << endl;
    cout << "Old name: " << books[number - 1].name << ", enter new name: ";
    cin >> books[number - 1].name;
    cout << "Old author: " << books[number - 1].author << ", enter new author: ";
    cin >> books[number - 1].author;
    cout << "Old publishing: " << books[number - 1].publishing << ", enter new publishing: ";
    cin >> books[number - 1].publishing;
    cout << "Old genre: " << books[number - 1].genre << ", enter new genre: ";
    cin >> books[number - 1].genre;
}

void searchByAutor(library* books, int num, string author)
{
    int counter = 0;
    
    for (int i = 0; i < num; i++)
    {
        if (books[i].author == author)
        {
            ++counter;
            cout << "Finded book " << i + 1 << ": " << endl;
            cout << "Name: " << books[i].name << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Publishing: " << books[i].publishing << endl;
            cout << "Genre: " << books[i].genre << endl;
        }
    }
    if (counter == 0)
    {
        cout << "Don't find book this autor: " << author << endl;
    }
}

void searchByName(library* books, int num, string name)
{
    int counter = 0;

    for (int i = 0; i < num; i++)
    {
        if (books[i].name == name)
        {
            ++counter;
            cout << "Finded book " << i + 1 << ": " << endl;
            cout << "Name: " << books[i].name << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Publishing: " << books[i].publishing << endl;
            cout << "Genre: " << books[i].genre << endl;
        }
    }
    if (counter == 0)
    {
        cout << "Don't find book with name: " << name << endl;
    }
}

void sortByName(library* books, int num)
{
    int counter = 0;
    library buf;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (books[j].name > books[j + 1].name)
            {
                buf.author = books[j].author;
                buf.name = books[j].name;
                buf.publishing = books[j].publishing;
                buf.genre = books[j].genre;
                
                books[j].author = books[j + 1].author;
                books[j].name = books[j + 1].name;
                books[j].publishing = books[j + 1].publishing;
                books[j].genre = books[j + 1].genre;

                books[j + 1].author = buf.author;
                books[j + 1].name = buf.name;
                books[j + 1].publishing = buf.publishing;
                books[j + 1].genre = buf.genre;
            }
        }
    }
}

void sortByAuthor(library* books, int num)
{
    int counter = 0;
    library buf;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (books[j].author > books[j + 1].author)
            {
                buf.author = books[j].author;
                buf.name = books[j].name;
                buf.publishing = books[j].publishing;
                buf.genre = books[j].genre;

                books[j].author = books[j + 1].author;
                books[j].name = books[j + 1].name;
                books[j].publishing = books[j + 1].publishing;
                books[j].genre = books[j + 1].genre;

                books[j + 1].author = buf.author;
                books[j + 1].name = buf.name;
                books[j + 1].publishing = buf.publishing;
                books[j + 1].genre = buf.genre;
            }
        }
    }
}

void sortByPublishing(library* books, int num)
{
    int counter = 0;
    library buf;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (books[j].publishing > books[j + 1].publishing)
            {
                buf.author = books[j].author;
                buf.name = books[j].name;
                buf.publishing = books[j].publishing;
                buf.genre = books[j].genre;

                books[j].author = books[j + 1].author;
                books[j].name = books[j + 1].name;
                books[j].publishing = books[j + 1].publishing;
                books[j].genre = books[j + 1].genre;

                books[j + 1].author = buf.author;
                books[j + 1].name = buf.name;
                books[j + 1].publishing = buf.publishing;
                books[j + 1].genre = buf.genre;
            }
        }
    }
}

int main()
{
    int num = 10;
    int choise = 0;
    string str = "\0";
    books = new library[num];
    books = fill(books, num);
    
    while (choise != 8)
    {
        int k = 0;
        choise = menu(books, num);

        switch (choise)
        {
        case 1:
            cout << "Enter number of book(1-10): ";
            cin >> k;
            edit(books, num, k);
            break;
        case 2:
            display(books, num);
            break;
        case 3:
            cout << "Enter author to search: ";
            cin >> str;
            searchByAutor(books, num, str);
            break;
        case 4:
            cout << "Enter name to search: ";
            cin >> str;
            searchByName(books, num, str);
            break;
        case 5:
            sortByName(books, num);
            display(books, num);
            break;
        case 6:
            sortByAuthor(books, num);
            display(books, num);
            break;
        case 7:
            sortByPublishing(books, num);
            display(books, num);
            break;
        default:
            choise = 8;
        }
    }
    
    return 0;
}
