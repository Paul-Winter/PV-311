#include "stdafx.h"
#include <iostream> 
#include <string>
using namespace std;

struct String {
    size_t size;
    char* str;
public:
    friend ostream& operator<<(ostream& stream, String obj);
    friend istream& operator>>(istream& stream, String obj);
    String(char* str = "");
    ~String();
    String(const String& obj)
    {
        if (size != obj.size)
        {
            size = obj.size;
            delete[] str;
            str = new char[size + 1];
        }
        strcpy_s(str, strlen(str), obj.str);
    }
    void String::operator=(String& obj2)
    {
        delete str;
        str = new char[size = obj2.size];
        strcpy_s(str, strlen(str), obj2.str);
    };
    int main()
    {
        setlocale(0, "");
        String obj1, obj2;
        int deistv;
        cout << "The first string";
        cin >> obj1;
        cout << "\nYour string";
        cout << obj1;
        cout << "The second string";
        cin >> obj2;
        cout << "\nYour string";
        obj1 = obj2;
        cout << obj2;
        system("PAUSE");
        return 0;

    }
};














class Fraction {
private:
    double x_;//числитель
    double y_;//знаменатель      
    //поле с динамической переменной double, хранящей отношение (результат деления).
    double* z_ = new double;
    //Статическая переменная класса одна для всех созданных экземпляров!  
    static int count_; //1.подсчет количества и получения значения.

public:
    //constructor 
    Fraction() : x_(0), y_(1)// Конструктор по умолчанию инициализирует дробь 0/1
    {
        // some code
        count_++;// здесь считаем объекты введённые в консоли пользователем        
    }

    // Конструктор, принимающий числитель и знаменатель
    Fraction(double x, double y) :x_(x), y_(y) {//в (те значения, которые мы введём в main)
        //x_ = x;//это второй способ инициализации конструктора 
        //y_ = y;
        cout << "\n Вызвали конструктор для дроби ";
        *z_ = x_ / y_;
        count_++;// здесь считаем объекты проинициализированные в консоли       
    }

    static int GetCount()
    {
        return count_;
    }

    // Добавлен конструктор копирования
    Fraction(const Fraction& other) : Fraction(other.x_, other.y_)
    {

    }
    // Добавлена операторная функция operator=()
    Fraction& operator =(const Fraction& other)//нельзя сделать const
    {// 1. Выделить память, если она не была предварительно выделена
        if (z_ == nullptr)
            z_ = new double;
        // 2. Скопировать данные
        x_ = other.x_; y_ = other.y_; *z_ = *other.z_;

        return *this;// 3. Возвратить текущий объект
    }

    void setZ()const
    {
        *z_ = x_ / y_;
    }

    //Аксессор/инспектор (getter)
    double getZ()const
    {
        if (z_ != nullptr)
            return *z_;
        else
            return 0;
    }
    //Деструктор
    ~Fraction()
    { // Освободить предварительно выделенную память
        if (z_ != nullptr)
            //cout << "\n deleted z";
            delete  z_;
        count_--;
    }

    void input() { //нельзя сделать const
        cout << " Введите числитель x: \n";
        cin >> x_;
        cout << " Введите знаменатель y_: \n";
        cin >> y_;
        *z_ = x_ / y_;
        cout << *z_;
    }

    //метод печати в консоль
    void Print() const {
        cout << "\n Вы ввели дробь \n";

        cout << x_ << " / " << y_;
        cout << " выведем z в методе Print:\n";
        *z_ = x_ / y_;
        cout << *z_;
    }
    void Print2() {
        cout << x_ << " " << y_;
    }

    //метод деления дробей
    void division1() const {

        if (y_ == 0)
        {
            cout << "\n Ошибка, на ноль делить нельзя!";
        }
        else
            cout << "\n  Результат деления самой дроби: ";
        cout << x_ / y_ << "\n";
    }

    //оператор перегрузки + (должен сложить две дроби)
    Fraction operator+ (const Fraction& f) {
        Fraction res{ x_ + f.x_, y_ + f.y_ };
        Fraction res{ (x_ * f.y_ + f.x_ * y_) / (y_ * f.y_) };
        cout << "Метод сложения в перегруженном операторе \n";

        return res;
    }

    //метод сложения дробей 
    //в этом методе сложения заменим аргументы на ссылку
    void sum(const Fraction& f)  const {
        cout << "\n  Результат сложения дробей: ";
        cout << (x_ * f.y_ + f.x_ * y_) / (y_ * f.y_) << "\n";
    }

    //метод вычитания дробей 
    void subtraction(Fraction f) const {
        cout << "\n  Результат вычитания дробей: ";
        cout << (x_ * f.y_ - f.x_ * y_) / (y_ * f.y_) << "\n";
    }

    //метод умножения дробей 
    void multiplication(Fraction f) const {
        cout << "\n  Результат умножения дробей: ";
        cout << (x_ * f.x_) / (y_ * f.y_) << "\n";
    }

    //метод деления дробей 
    void divisoin2(Fraction f) const {
        cout << "\n  Результат деления дробей: ";
        //cout << (x_ * f.y_) / (y_ * f.x_) << "\n";
        cout << "\n Вывод динамической переменной z в методе деления дробей: ";
        *z_ = (x_ * f.y_) / (y_ * f.x_);
        cout << *z_;
    }
};

int Fraction::count_ = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);//для понимания русских символов
    SetConsoleOutputCP(1251);
    //Fraction f1, f2;  // для инициализации дробей с клавиатуры   

    //f1.input(); // Вводим первую дробь с клавиатуры   
    //f2.input(); // Вводим вторую дробь с клавиатуры   
    //cout << "\n Добавьте числитель и знаменатель для двух дробей с клавиатуры:\n";   

    Fraction f1{ 32, 4 }; // вызов конструктора (инициализация дроби f1)
    Fraction f2{ 10, 5 };

    f1.Print();
    f2.Print();
    Fraction f3 = f1 + f2; //в р3 пишем результат (оператор перегрузки +)
    f3.Print2();
    cout << "\n Первая дробь:";
    f1.division1();
    cout << "\n Вторая дробь:";
    f2.division1();

    f1.sum(f2);//вызываем метод sum от f1 и добавляем f2
    f1.subtraction(f2); //вызываем метод subtraction от f1 и добавляем f2
    f1.multiplication(f2);//вызываем метод multication от f1 и добавляем f2
    f1.divisoin2(f2); //вызываем метод division от f1 и добавляем f2

    cout << "\n Количество созданных объектов равно: ";
    cout << Fraction::GetCount() << endl;//Подсчёт объектов класса Fraction

    cout << "\n The End \n";
    cout << endl;
    system("pause");

    return 0;
}








struct f
{
    explicit f(int) { std::cout << "int"; }
    f(const f&) { std::cout << "copy"; }
};

int main()
{
    f obj = 5;
}