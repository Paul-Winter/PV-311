//ЗАДАНИЕ 1
// Описать структуру Student (фамилия, группа,
//успеваемость(массив из 5 int)).Создать массив студентов
//и написать программу, позволяющую:
//■ Динамически изменять размер массива;
//■ Выводить список отличников(> 75 % отличных оценок);
//■ Выводить список двоечников(> 50 % оценок 2 и 3).

#include <iostream>
using namespace std;
extern int num = 1;                 //счётчик элементов массива структур

struct student
{
    string name = "\0";
    string group = "\0";
    int* performance = new int[5];

}; student* students;

student* fill(student* students, int N)     //функция заполнения текущего (N) элемента массива структур
{
    cout << num << " student: " << endl;
    cout << "Enter name: ";
    cin >> students[N-1].name;
    cout << "Enter group: ";
    cin >> students[N-1].group;
    cout << "Academic performance: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter mark of " << i + 1 << " course (2-5): ";
        cin >> students[N-1].performance[i];
    }
    
    return students;
}

student* add(student* students)             //функция добывления нового элемента в массив структур
{
    student* buf = new student[num];        //создаём новый массив, размером на 1 больше текущего

    for (int i = 0; i < num - 1; i++)       //копируем в новый массив элементы из старого
    {
        buf[i] = students[i];
    }
    
    buf = fill(buf, num);                   //заполняем последний (пустой) элемент нового массива
    delete[] students;                      //старый массив удаляем
    ++num;                                  //увеличиваем счётчик элементов массива
    return buf;                             //возвращаем новый массив
}

student* del(student* students, int k)      //функция удаления выбранного (k) элемента из массива структур
{
    int counter = 0;
    student* buf = new student[num - 1];    //создаём новый массив, размером на 1 меньше текущего

    for (int i = 0; i < num - 1; i++)       //копируем в новый массив элементы из старого кроме ненужного
    {
        if (k !=  i)
        {
            buf[counter] = students[i];
            ++counter;
        }
    }

    delete[] students;                      //старый массив удаляем
    --num;                                  //уменьшаем счётчик элементов массива
    return buf;                             //возвращаем новый массив
}

void display(student* students, int e)      //функция вывода элементов массива структур в трёх режимах
{
    if (e == 1)                             //1 -вывод отличников (из 5 оценок - 4 пятёрки и 1 четвёрка, или все пятёрки)
    {
        cout << "\nList of excellents:" << endl;
    }
    else if (e == 2)                        //2 - вывод двоечников (из 5 оценок - 2 тройки и одна 2, или 1 тройка и 2 двойки, или двоек больше 2)
    {
        cout << "\nList of losers:" << endl;
    }
    else                                    //0 - вывод всего списка
    {
        cout << "\nList of students:" << endl;
    }
        
    for (int i = 0; i < num - 1; i++)
    {
        if (e == 1)
        {
            int counter5 = 0;
            int counter4 = 0;
            for (int j = 0; j < 5; j++)
            {
                if (students[i].performance[j] == 5)
                {
                    ++counter5;
                }
                else if (students[i].performance[j] == 4)
                {
                    ++counter4;
                }
            }
            if ((counter5 == 4 && counter4 == 1)||(counter5 == 5))
            {
                cout << i + 1 << " student:" << endl;
                cout << "Name: " << students[i].name << endl;
                cout << "Group: " << students[i].group << endl;
            }
        }
        else if (e == 2)
        {
            int counter3 = 0;
            int counter2 = 0;
            for (int j = 0; j < 5; j++)
            {
                if (students[i].performance[j] == 3)
                {
                    ++counter3;
                }
                else if (students[i].performance[j] == 2)
                {
                    ++counter2;
                }
            }
            if ((counter3 == 2 && counter2 == 1) || (counter3 == 1 && counter2 == 2) || (counter2 > 2))
            {
                cout << i + 1 << " student:" << endl;
                cout << "Name: " << students[i].name << endl;
                cout << "Group: " << students[i].group << endl;
            }
        }
        else
        {
            cout << i + 1 << " student:" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Group: " << students[i].group << endl;
            cout << "Performance: " << endl;
            for (int j = 0; j < 5; j++)
            {
                cout << "Course " << j + 1 << " mark: " << students[i].performance[j] << endl;
            }
        }
    }
    system("pause");
}

int menu()
{
    system("cls");
    int cont = 0;
    while (cont == 0)
    {
        cout << "- STUDENTS -" << endl;
        cout << "1. Add new student." << endl;
        cout << "2. Delete student." << endl;
        cout << "3. List all students." << endl;
        cout << "4. List of excellents." << endl;
        cout << "5. List of losers." << endl;
        cout << "6. Quit." << endl;
        cout << "Your choise(1-6): ";
        cin >> cont;
    }
    return cont;
}

int main()
{
    int k = 0;
    int choise = 0;
    students = new student[num];

    while (choise != 6)                     //пока не выбран выход - выводим меню
    {
        choise = menu();

        switch (choise)
        {
        case 1:
            if (num != 1)
            {
                students = add(students);
            }
            else
            {
                students = fill(students, num);
                ++num;
            }
            break;
        case 2:
            display(students, 0);
            cout << "Enter number of student to delete: ";
            cin >> k;
            students = del(students, k - 1);
            break;
        case 3:
            display(students, 0);
            break;
        case 4:
            display(students, 1);
            break;
        case 5:
            display(students, 2);
            break;
        default:
            choise = 5;
        }
    }

    return 0;
}