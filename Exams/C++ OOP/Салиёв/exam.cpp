#include <filesystem>
#include <iostream>
#include <fstream>
#include <memory>
#include <list>

using namespace std;
using namespace std::filesystem;




class User
{
protected:
    string name;
    string password;

    struct Marks
    {
        string TaskName;
        bool firstTask;
        bool secondTask;
        bool thirdTask;
        bool fourthTask;
        bool fifthTask;
        Marks() = default;
        Marks(Marks&& name) : TaskName{ std::move(name.TaskName) }, firstTask{ name.firstTask },
            secondTask{ name.secondTask }, thirdTask{ name.thirdTask }, fourthTask{ name.fourthTask },
            fifthTask{ name.fifthTask }
        {

        }

    } m;

    list<Marks> disciplines;

    User() = default;

    User(const string& name, const string& password) : name{ name }, password{ password }
    {

    }
public:
    virtual const void setName(const string& name) = 0;
    virtual const bool findName(const string& name) const = 0;
    virtual const bool correctPassword(const string& pass) const = 0;
};

class Admin : public User
{
private:
    virtual const void setName(const string& name) final
    {

    };
public:
    virtual void displayMenu() final
    {

    }

    virtual const bool findName(const string& name) const final
    {


    }

    virtual const bool correctPassword(const string& pass) const final
    {
        return true; //Исправить
    }

    Admin() : User("admin", "admin")
    {

    }
};

class Student : public User
{
private:
    bool readMarks()
    {
        if (exists(string("C:\\Users\\Dinorex\\Desktop\\usersProfiles\\") + this->name + string(".txt")))
        {
            fstream in(string("C:\\Users\\Dinorex\\Desktop\\usersProfiles\\") + this->name + string(".txt"), ios_base::in);
            if (!in.is_open())
            {
                in.close();
                return false;
            }

            string strPass;
            strPass.resize(30);
            in.getline(strPass.data(), 30);
            strPass.clear();

            while (!in.eof())
            {
                in.getline(m.TaskName.data(), 30, '-');
                in.get(reinterpret_cast<char*>(&m.firstTask), 1);
                in.get(reinterpret_cast<char*>(&m.secondTask), 1);
                in.get(reinterpret_cast<char*>(&m.thirdTask), 1);
                in.get(reinterpret_cast<char*>(&m.fourthTask), 1);
                in.get(reinterpret_cast<char*>(&m.fifthTask), 1);
                disciplines.emplace_back(std::move(m));
            }

            in.close();
            return true;
        }
    }

public:

    Student() = default;

    virtual void displayMenu() final
    {
        if (readMarks())
        {

        }
    }

    const void setName(const string& name) final
    {
        this->name = name;
    }

    virtual const bool findName(const string& name) const final
    {
        //if (exists(string("C:\\Users\\Никита\\Desktop\\userProfiles\\") + name + string(".txt")))
        //{
        //    return true;
        //}
        //else return false;
        return (exists(string("C:\\Users\\Никита\\Desktop\\userProfiles\\") + name + string(".txt")));
    }

    virtual const bool correctPassword(const string& pass) const final
    {
        if !(name.empty() || findName(this->name))
        {
            return false;
        }

        if (exists(string("C:\\Users\\Dinorex\\Desktop\\usersProfiles\\") + name + string(".txt")))
        {
            fstream in(string("C:\\Users\\Dinorex\\Desktop\\usersProfiles\\") + name + string(".txt"), ios_base::in);
            string s;
            in.getline(s.data(), 30);
            if (pass == s)
            {
                //cout << "Password is correct!" << endl;
                return true;
            }
            else return false;
        }
        else return false;
    };

};


class Test
{

private:
    short int choiceUser;
    unique_ptr<User> usrPtr;

public:

    unique_ptr<User> choiceUserPrivilege(const short int& choiceUser)
    {
        if (choiceUser == 0)
        {
            return  make_unique<Admin>();
        }
        else if (choiceUser == 1)
        {
            return make_unique<Student>();
        }
    }


    void displayMenu()
    {
        cout << "Hello! Pls, choice student - 0 or admin - 1! " << endl;
        cin >> choiceUser;
        usrPtr = choiceUserPrivilege(choiceUser);
        string UserName;
        cout << "Pls, enter your name: " << endl;
        cin >> UserName;

        while (!usrPtr->findName(UserName))
        {
            cout << "User not found!" << endl;
            cout << "Pls, enter your name: " << endl;
            cin >> UserName;
        }
        usrPtr->setName(UserName);
        string UserPassword;
        cout << "Pls, enter your password: " << endl;
        cin >> UserPassword;
        while (!usrPtr->correctPassword(UserPassword))
        {
            cout << "Password is not true, pls repeat again: ";
            cin >> UserPassword;
        }
        usrPtr->displayMenu();
    }
};

class Registration
{

};

class RecordUser
{

};

class ReadUser
{

};

class Mathemathic
{
private:
    string q1 = "2+2???";
    string q2 = "2 x 2 ???";
    string q3 = "4 / 2 ???";
    string q4 = "1 - 1 ???";
    string q5 = "2+2x2 ???";
    short int choice;
    enum trueAnswers
    {
        qs1 = 4,
        qs2 = 4,
        qs3 = 2,
        qs4 = 0,
        qs5 = 1
    };

public:
    bool question1()
    {
        cout << q1 << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "0" << endl;
        cout << "4" << endl;
        cout << "Choose answer: " << endl;
        cin >> choice;
        return choice == trueAnswers::qs1 ? true : false;

    }

    bool question2()
    {
        cout << q2 << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "0" << endl;
        cout << "4" << endl;
        cout << "Choose answer: " << endl;
        cin >> choice;
        return choice == trueAnswers::qs2 ? true : false;
    }

    bool question3()
    {
        cout << q3 << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "0" << endl;
        cout << "4" << endl;
        cout << "Choose answer: " << endl;
        cin >> choice;
        return choice == trueAnswers::qs3 ? true : false;
    }

    bool question4()
    {
        cout << q4 << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "0" << endl;
        cout << "4" << endl;
        cout << "Choose answer: " << endl;
        cin >> choice;
        return choice == trueAnswers::qs4 ? true : false;
    }

    bool question5()
    {
        cout << q5 << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "0" << endl;
        cout << "4" << endl;
        cout << "Choose answer: " << endl;
        cin >> choice;
        return choice == trueAnswers::qs5 ? true : false;
    }
};

int main()
{
    Mathemathic a;

}
