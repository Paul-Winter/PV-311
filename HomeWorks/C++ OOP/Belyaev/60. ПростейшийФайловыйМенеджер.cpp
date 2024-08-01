//ЗАДАНИЕ 1.
//Добавьте к программе «Простейший файловый менеджер» такие возможности :
//1. Создание нового файла в текущем каталоге.
//2. Удаление файла из текущего каталога.
//3. Переименование файла в текущем каталоге.
//4. Перемещение файла из текущего каталога в указанный пользователем каталог.
//5. Вывод содержимого указанного пользователем файла из текущего каталога на экран.

#include <iostream>
#include <filesystem>
using namespace std;

void show(std::filesystem::path cur_path)
{
    string filename;

    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
    for (const auto& dirEntry : recursive_directory_iterator(cur_path))
    {
        filename = dirEntry.path().string();
        cout << filename << endl;
    }
    cout << endl;
}

void showCurrentFolder(std::filesystem::path cur_path)
{
    for (const auto& entry : std::filesystem::directory_iterator(cur_path))
    {
        std::cout << entry.path() << std::endl;
    }
}

void createDir(std::filesystem::path cur_path, string foldername)
{
    std::filesystem::path current_path(cur_path);
    string create_path = std::filesystem::current_path().string() + '\\' + foldername;
    
    cout << "Creating new directory: " << create_path.c_str() << endl;
    std::filesystem::create_directory(create_path);
    
    cout << "Done." << endl;
    system("pause");
    system("cls");
}

void deleteDir(std::filesystem::path cur_path, string foldername)
{
    std::filesystem::path current_path(cur_path);
    string delpath = std::filesystem::current_path().string() + '\\' + foldername;
    
    cout << "Deleting directory: " << delpath.c_str() << endl;
    std::filesystem::remove_all(delpath);
    cout << "Done." << endl;

    system("pause");
    system("cls");
}

void createFile(std::filesystem::path cur_path, string filename)
{
    FILE* out;
    string path = cur_path.string().c_str() + filename;

    cout << "Creating file " << path.c_str() << ":" << endl;
    if (fopen_s(&out, path.c_str(), "w") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        cout << "Done." << endl;
    }
    fclose(out);

    system("pause");
    system("cls");
}

void deleteFile(std::filesystem::path cur_path, string filename)
{
    std::filesystem::path current_path(cur_path);

    for (const auto& dirEntry : std::filesystem::directory_iterator(current_path))
    {
        if (!dirEntry.is_directory())
        {
            if (dirEntry.path().filename() == filename)
            {
                cout << "Deleting file " << dirEntry.path().string().c_str() << ":" << endl;
                std::filesystem::remove(dirEntry.path().filename());
            }
        }
    }
    cout << "Done." << endl;
    system("pause");
    system("cls");
}

void renameFile(std::filesystem::path cur_path, string filename, string newname)
{
    std::filesystem::path current_path(cur_path);
    std::filesystem::path old_path(cur_path.string().c_str() + filename);
    std::filesystem::path new_path(cur_path.string().c_str() + newname);

    for (const auto& dirEntry : std::filesystem::directory_iterator(current_path))
    {
        if (!dirEntry.is_directory())
        {
            if (dirEntry.path().filename() == filename)
            {
                cout << "Renaming file " << old_path.string().c_str() << " to " << new_path.string().c_str() << endl;
                std::filesystem::rename(old_path, new_path);
            }
        }
    }
    cout << "Done." << endl;
    system("pause");
    system("cls");
}

void removeFile(std::filesystem::path cur_path, string filename, string newpath)
{
    std::filesystem::path current_path(cur_path);
    std::filesystem::path old_path(cur_path.string().c_str() + filename);
    std::filesystem::path new_path(newpath + filename);

    for (const auto& dirEntry : std::filesystem::directory_iterator(current_path))
    {
        if (!dirEntry.is_directory())
        {
            if (dirEntry.path().filename() == filename)
            {
                cout << "Removing file " << old_path.string().c_str() << " to " << new_path.string().c_str() << endl;
                std::filesystem::rename(old_path, new_path);
            }
        }
    }
    cout << "Done." << endl;
    system("pause");
    system("cls");
}

void displayFile(std::filesystem::path cur_path, string filename)
{
    FILE* in;
    string path = cur_path.string().c_str() + filename;

    cout << "Reading file " << path.c_str() << ":" << endl;
    if (fopen_s(&in, path.c_str(), "r") != NULL)
    {
        cout << "Can't open file to read!" << endl;
    }
    else
    {
        while (!feof(in))
        {
            cout << (char)fgetc(in);
        }
        cout << endl;
    }
    fclose(in);

    system("pause");
    system("cls");
}

int main()
{
    string cur_path = "C:\\Intel\\";
    std::filesystem::current_path(cur_path);
    string foldername;
    string var_path;
    string filename;
    string newname;

    show(cur_path);

    int choise = 0;

    while (true)
    {
        cout << "Current path=" << std::filesystem::current_path().string() << endl;
        showCurrentFolder(std::filesystem::current_path());

        cout << "Choose action:" << endl;
        cout << "1 - create folder" << endl;
        cout << "2 - delete folder" << endl;
        cout << "3 - change directory" << endl;
        cout << "4 - create file" << endl;
        cout << "5 - delete file" << endl;
        cout << "6 - rename file" << endl;
        cout << "7 - replace file" << endl;
        cout << "8 - read txt-file" << endl;
        cout << ">";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "Enter folder name to create: " << endl;
            cin >> foldername;
            createDir(std::filesystem::current_path().string() + '\\', foldername);
            break;
        case 2:
            cout << "Enter folder name to delete: " << endl;
            cin >> foldername;
            deleteDir(std::filesystem::current_path().string() + '\\', foldername);
            break;
        case 3:
            cout << "Enter directory name to change (../ to return): " << endl;
            cin >> var_path;
            std::filesystem::current_path(filesystem::current_path().string() + '\\' + var_path);
            cout << "New current path: " << std::filesystem::current_path().string().c_str() << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Enter file name (without extention) to create: " << endl;
            cin >> filename;
            createFile(std::filesystem::current_path().string() + '\\', filename + ".txt");
            break;
        case 5:
            cout << "Enter full file name (with extention) to delete: " << endl;
            cin >> filename;
            deleteFile(std::filesystem::current_path().string() + '\\', filename);
            break;
        case 6:
            cout << "Enter full file name (with extention) would you like to rename: " << endl;
            cin >> filename;
            cout << "Enter new name (with extention) to this file: " << endl;
            cin >> newname;
            renameFile(std::filesystem::current_path().string() + '\\', filename, newname);
            break;
        case 7:
            cout << "Enter full file name (with extention) would you like to remove: " << endl;
            cin >> filename;
            cout << "Enter destination for whis file (for example C:\\Windows\\): " << endl;
            cin >> newname;
            removeFile(std::filesystem::current_path().string() + '\\', filename, newname);
            break;
        case 8:
            cout << "Enter file name (without extention) to read: " << endl;
            cin >> filename;
            displayFile(std::filesystem::current_path().string() + '\\', filename + ".txt");
            break;
        default:
            break;
        }
    }

    return 0;
}