//ЗАДАНИЕ 2
//Реализовать структуру «Автомобиль» (длина,
//клиренс(высота посадки), объем двигателя, мощность
//двигателя, диаметр колес, цвет, тип коробки передач).
//Создайте функции для задания значений, отображения
//значений, поиска значений.

#include <iostream>
using namespace std;

struct automobile
{
    int lenght;
    int clearance;
    int volume;
    int power;
    int diameter;
    char color[10];
    char transmission[10];
}; automobile *cars;

automobile* fill(automobile *cars, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << i+1 << " car: " << endl;
        cout << "Enter lenght: ";
        cin >> cars[i].lenght;
        cout << "Enter clearance: ";
        cin >> cars[i].clearance;
        cout << "Enter volume of engine: ";
        cin >> cars[i].volume;
        cout << "Enter power of engine: ";
        cin >> cars[i].power;
        cout << "Enter diameter of disks: ";
        cin >> cars[i].diameter;
        cout << "Enter color: ";
        cin >> cars[i].color;
        cout << "Enter transmission: ";
        cin >> cars[i].transmission;
    }
    return cars;
}

void display(automobile *cars, int num)
{
    cout << "\nLIST:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << " car info:" << endl;
        cout << "Lenght: " << cars[i].lenght << endl;
        cout << "Clearance: " << cars[i].clearance << endl;
        cout << "Volume of engine: " << cars[i].volume << endl;
        cout << "Power of engine: " << cars[i].power << endl;
        cout << "Diameter of disks: " << cars[i].diameter << endl;
        cout << "Color: " << cars[i].color << endl;
        cout << "Transmission: " << cars[i].transmission << endl;
    }
}

int search(automobile *cars, int num)
{
    int index = -1;
    int value = 0;
    char c_value[10];
    int p = 0;
    
    cout << "\nSEARCHING:" << endl;
    cout << "1 - length" << endl;
    cout << "2 - clearance" << endl;
    cout << "3 - volume of engine" << endl;
    cout << "4 - power of engine" << endl;
    cout << "5 - diameter of disks" << endl;
    cout << "6 - color" << endl;
    cout << "7 - transmission" << endl;
    cout << "Choose parametr to search (1-7): ";
    cin >> p;
    cout << "Enter value of this parametr: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (p > 5)
    {
        cin.getline(c_value, 10);
    }
    else
    {
        cin >> value;
    }
    
    switch (p)
    {
    case 1:
    {
        for (int i = 0; i < num; i++)
        {
            if (cars[i].lenght == value)
            {
                index = i;
                break;
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < num; i++)
        {
            if (cars[i].clearance == value)
            {
                index = i;
                break;
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < num; i++)
        {
            if (cars[i].volume == value)
            {
                index = i;
                break;
            }
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < num; i++)
        {
            if (cars[i].power == value)
            {
                index = i;
                break;
            }
        }
        break;
    }
    case 5:
    {
        for (int i = 0; i < num; i++)
        {
            if (cars[i].diameter == value)
            {
                index = i;
                break;
            }
        }
        break;
    }
    case 6:
    {
        for (int i = 0; i < num; i++)
        {
            int k = 0;
            int m = 0;
            while (cars[i].color[k] != '\0')
            {
                if (cars[i].color[k] == c_value[m])
                {
                    ++m;
                }
                ++k;
            }
            if (k == m)
            {
                index = i;
                break;
            }
        }
        break;
    }
    default:
    {
        for (int i = 0; i < num; i++)
        {
            int k = 0;
            int m = 0;
            while (cars[i].transmission[k] != '\0')
            {
                if (cars[i].transmission[k] == c_value[m])
                {
                    ++m;
                }
                ++k;
            }
            if (k == m)
            {
                index = i;
                break;
            }
        }
    }
    }
    return index;
}

int main()
{
    int f = 0;
    int N = 0;
    cout << "Enter number of records: ";
    cin >> N;
    
    cars = new automobile[N];
    cars = fill(cars, N);
    
    display(cars, N);

    f = search(cars, N);
    if (f != -1)
    {
        cout << "Finded car number " << f + 1 << endl;
    }
    else
    {
        cout << "No finded!";
    }

    return 0;
}