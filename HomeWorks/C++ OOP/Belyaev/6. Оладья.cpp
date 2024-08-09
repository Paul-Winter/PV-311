//ЗАДАНИЕ 3
//Есть стопка оладий различного радиуса. Единственная
//операция, проводимая с ними — между любыми двумя суем
//лопатку и меняем порядок оладий над лопаткой на обратный.
//Необходимо за минимальное количество операций таких
//отсортировать снизу вверх по убыванию радиуса.

#include <iostream>
using namespace std;

int main()
{

    srand(time(0));

    int size = 10;
    int buf = 0;
    int max = 0;
    int ind = 0;
    int* mass = new int[size];

    cout << "Ishodnaya stopka:" << endl;
    for (int i = 0; i < size; ++i)
    {
        mass[i] = 1 + rand() % 10;
        cout << "\t" << mass[i] << endl;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        max = mass[i];
        ind = i;
        
        for (int j = i; j >= 0; j--)        //ищем максимальный эелемент
        {
            if (mass[j] > max)
            {
                max = mass[j];
                ind = j;
            }
        }
        
        for (int k = 0; k <= ind / 2; ++k)  //переворачиваем часть массива, чтобы максимальный оказался сверху
        {
            if (ind == 0)                   //если верхний элемент максимальный
            {
                break;
            }

            buf = mass[k];
            mass[k] = mass[ind - k];
            mass[ind - k] = buf;

        }
        
        for (int k = 0; k <= i / 2; ++k)    //переворачиваем опять, чтобы максимальный оказался внизу стопки
        {
            buf = mass[k];
            mass[k] = mass[i - k];
            mass[i - k] = buf;
        }
    }

    cout << "Otsortirovannaya stopka:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "\t" << mass[i] << endl;
    }

    return 0;
}