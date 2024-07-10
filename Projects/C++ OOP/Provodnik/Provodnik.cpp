#include <iostream>
#include <direct.h>
#include <string.h>
#include <stdio.h>
#include <io.h>

using namespace std;

class Human
{
public:
    string name;
    int age;
};

void RenameFile()
{
    char oldName[100];
    char newName[100];

    cout << "\nEnter old name: " << endl;
    cin >> oldName;

    cout << "\nEnter new name: " << endl;
    cin >> newName;

    if (!rename(oldName, newName))
        cout << "Error rename!\n" << endl;
    else
        cout << "OK!\n";
}

void SearchFile()
{
    char path[200];
    cout << "\nEnter file path:" << endl;
    cin >> path;

    char mask[10];
    cout << "\nEnter file mask:" << endl;
    cin >> mask;

    strcat(path, mask);

    _finddata_t* fileinfo = new _finddata_t;
    
    long done = _findfirst(path, fileinfo);

    int mayWork = done;

    int count = 0;

    while (mayWork != -1)
    {
        count++;
        cout << fileinfo->name << "\n\n";
        mayWork = _findnext(done, fileinfo);
    }

    cout << "\nInformation: " << count;
    cout << "\nPath: " << path;

    _findclose(done);
    delete fileinfo;
}

void RemoveFile()
{
    char name[100];

    cout << "\nEnter file name:" << endl;
    cin >> name;

    if (!remove(name))
        cout << "Error remove!\n" << endl;
    else
        cout << "OK!\n";
}

void RenameDir()
{
    char oldName[100];
    char newName[100];

    cout << "\nEnter old name: " << endl;
    cin >> oldName;

    cout << "\nEnter new name: " << endl;
    cin >> newName;

    if (!rename(oldName, newName))
        cout << "Error rename!\n" << endl;
    else
        cout << "OK!\n";
}

void RemoveDir()
{
    char name[100];

    cout << "\nEnter directory name:" << endl;
    cin >> name;

    if (_rmdir(name) == -1)
        cout << "Error remove!\n" << endl;
    else
        cout << "OK!\n";
}

void CreateDir()
{
    char name[100];

    cout << "\nEnter directory name:" << endl;
    cin >> name;

    if (_mkdir(name) == -1)
        cout << "Error create!\n" << endl;
    else
        cout << "Ok!\n";
}

int main()
{
    Human student;
    Human worker;

    cout << "student name " << endl;
    cin >> student.name;
    cout << "student age " << endl;
    cin >> student.age;

    FILE* f = fopen("Test.txt", "w+");
    if (!f) exit(0);
    fwrite(&student, sizeof(Human), 1, f);
    fclose(f);

    f = fopen("Test.txt", "r");
    if (!f) exit(0);
    fread(&worker, sizeof(Human), 1, f);
    fclose(f);

    cout << worker.name << " " << worker.age << endl;

    cout << "\n\n__________________________________________\n\n" << endl;

    char command;
    do {
        cout << "Enter number to run:\n" << endl;
        cout << "1 - RenameFile" << endl;
        cout << "2 - RemoveFile" << endl;
        cout << "3 - SearchFile" << endl;
        cout << "4 - RenameDir" << endl;
        cout << "5 - RemoveDir" << endl;
        cout << "6 - CreateDir" << endl;
        cin >> command;

        switch (command)
        {
            case '1': RenameFile(); break;
            case '2': RemoveFile(); break;
            case '3': SearchFile(); break;
            case '4': RenameDir(); break;
            case '5': RemoveDir(); break;
            case '6': CreateDir(); break;
        }
    } while (command != '0');
}
