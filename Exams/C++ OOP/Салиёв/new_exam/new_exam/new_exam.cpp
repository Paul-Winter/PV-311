#include <filesystem>
#include <iostream>
#include <fstream>
#include <memory>
#include <list>
#include <string>
#include <stdio.h>


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




    //auto myIterator = disciplines.begin();
    //++myIterator;
    //--myIterator;
    //myIterator->fifthTask;
    //myIterator->fourthTask;
    //myIterator...




    User() = default;

    User(const string& name, const string& password) : name{ name }, password{ password }
    {

    }
public:
    virtual const void setName(const string& name) = 0;
    virtual const bool findName(const string& name) const = 0;
    virtual const bool correctPassword(const string& pass) const = 0;
    virtual const void displayMenu() = 0;
    virtual const string getName() = 0;
    virtual const bool setpassword(string name) = 0;
    virtual const void Math() = 0;
    virtual const void History() = 0;
    virtual const void Biology() = 0;
};

class Admin : public User
{
private:
    virtual const void Math() final{};
    virtual const void History() final {};
    virtual const void Biology() final {};
    
    virtual const bool setpassword(string name)
    {
        
        return true;
    };
    const void createUser()
    {

    }
    virtual const string getName()
    {
        return this->name;
    }
    virtual const void setName(const string& name) final
    {
        this->name = name;
    };
public:
    const void createAndDeleteUsers(int choice)
    {
        if (choice == 1)
        {
            cout << "Pls, enter name new user (student): ";
            string name;
            cin >> name;
            
            while((exists(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name))))
            {
                cout << "Error! User with that name already exists! Enter a different name." << endl;
                cin >> name;
            }
            create_directory("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name);
            cout << name << ", pls, create a password: ";
            int pass, pass1;
            cin >> pass;
            cout << "Pls, repeat password: ";
            cin >> pass1;
            
            while (pass != pass1)
            {
                cout << "Passwords don't match!, Enter the second password again!";
                cin >> pass1;
                
            }
            fstream in(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("password") + string(".txt")), ios::out);
            in << pass1;
            in.close();
            cout << "User is created!" << endl;
            displayMenu();
                     
        }
        else if (choice == 2)
        {
            cout << "Enter the name of the user (student) you want to delete: ";
            string name;
            cin >> name;
           /* while(exists(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name)))
            {
                cout << "User not found! Pls, try again!";
                cin >> name;
                if (atoi(name.c_str()) == 0)
                {
                    displayMenu();
                }
            }*/
           
            remove(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("password") + string(".txt")));
            remove(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("math") + string(".txt")));
            remove(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("history") + string(".txt")));
            remove(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("biology") + string(".txt")));
            remove((string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name)));
           
            cout << "User is deleted!" << endl;
            displayMenu();
            
        }
    }
    virtual const void displayMenu() final
    {
        cout << "Welcome, admin!" << endl;
        cout << "Pls, select one of the menu items" << endl;
        cout << "Create new user - 1" << endl;
        cout << "Delete user - 2" << endl;
        cout << "Go back to the main menu - 0" << endl;
        int choice;
        cin >> choice;
        createAndDeleteUsers(choice);

    }

    virtual const bool findName(const string& name) const final
    {
        if (exists(string(name + string(".txt")))) 
        {
            return true;
        }
        else
        {
            cout << "Incorrect name-admin!";
        }
        
        
    }

    virtual const bool correctPassword(const string& pass) const final
    {
        if (this->name.empty() || findName(this->name) != true)
        {
            return false;
        }

        fstream in(string(name + string(".txt")), ios::in);
        string s;
        in >> s;
        cout << s;
        if (s == pass)
        {
            cout << "Password is correct!" << endl;
            in.close();
            return true;
        } return false;

       
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
        if (exists(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(".txt"))))
        {      
            ifstream in(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(".txt")), ios::in);
            if (!in.is_open())
            {
                cout << "not open!";
                return false;
            }
            else
            {
                cout << "open!";
            }

            string strPass;
            //strPass.resize(30);
            //in.getline(reinterpret_cast<char*>(&strPass), 30);
            /* cout << strPass;
             in.getline(strPass.data(), 30);
             strPass.clear();*/
             //in >> strPass >> m.TaskName >> m.firstTask >> m.secondTask >> m.thirdTask >> m.fourthTask >> m.fifthTask;
            in >> strPass;

            cout << strPass << endl;
            char c;

            while (!in.eof())
            {
                getline(in, m.TaskName, '-');
                in >> c;
                in >> c;
                in >> c;
                in >> c;
                in >> c;               
                
                /*in.getline(&c, 1);
                in.get(&c, 1);
                in.get(&c, 1);
                in.get(&c, 1);
                in.get(&c, 1);
                in.get(&c, 1);*/
                //disciplines.emplace_back(std::move(m));
            }

            for (auto myItr = disciplines.begin(); myItr != disciplines.end(); ++myItr)
            {
                cout << myItr->TaskName << endl;
                cout << myItr->firstTask << endl;
                cout << myItr->secondTask << endl;
                cout << myItr->thirdTask << endl;
                cout << myItr->fourthTask << endl;
                cout << myItr->fifthTask << endl;
                cout << endl;
            }

            in.close();
            return true;
        }
        
    }
    Marks recordMarks()
    {

    }
public:

    //Student() = default;
    const void counting(int dispres)
    {
        if (dispres == 1)
        {
            fstream in(("aM.txt"), ios::in);
            fstream on(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("math") + string(".txt")), ios::in);
            bool counting[5];
            int tA[5], uA[5];
            string tempT, tempU;
            for (int i = 0; i < 5; ++i)
            {
                getline(in, tempT);
                getline(on, tempU);
                tA[i] = atoi(tempT.c_str());
                uA[i] = atoi(tempU.c_str());
                if (tA[i] == uA[i])
                {
                    counting[i] = true;
                }
                else counting[i] = false;
            }
            cout << "Your mark is: " << endl;
            int temp=0;
            for (int i = 0; i < 5; ++i)
            {
                if (counting[i] == true)
                {
                    temp++;
                }
            }
            cout << temp << endl;
            displayMenu();
        }
        else if (dispres == 2)
        {
            fstream in(("hM.txt"), ios::in);
            fstream on(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("history") + string(".txt")), ios::in);
            bool counting[5];
            int tA[5], uA[5];
            string tempT, tempU;
            for (int i = 0; i < 5; ++i)
            {
                getline(in, tempT);
                getline(on, tempU);
                tA[i] = atoi(tempT.c_str());
                uA[i] = atoi(tempU.c_str());
                if (tA[i] == uA[i])
                {
                    counting[i] = true;
                }
                else counting[i] = false;
            }
        }
        else if (dispres == 0)
        {
            displayMenu(); 
        }
    }

    const void results()
    {
        cout << "Choice discip for view results: " << endl;
        cout << "Math - 1" << endl;
        cout << "History - 2" << endl;
        cout << "Biology - 3" << endl;
        int dispres;
        cin >> dispres;
        counting(dispres);          
    }
    virtual const void Math()
    {
        fstream in(("qM.txt"), ios::in);     
        fstream on(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("math") + string(".txt")), ios::out);      
        //fstream on(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(".txt")), ios::out);
        string temp;
        int q = 0;
        int Anwers[5];
        
        while (getline(in, temp) && q !=5)
        {
            cout << temp;
            cin >> Anwers[q];        
            on << Anwers[q];
            on << endl;
            q++;
        };
        on.close();
        in.close();
        cout << "Test is done! Ty!" << endl;
        displayMenu();
    }
   
    virtual const void History()
    {

    }
    virtual const void Biology()
    {

    }
    const void choiceDiscip()
    {
        cout << "Pls, choice discip you want to testing! " << endl;
        cout << "Math - 1" << endl;
        cout << "History - 2" << endl;
        cout << "Biology - 3" << endl;
        cout << "If you want come back to menu press 0" << endl;   
        int choiceDis;
        cin >> choiceDis;
        if (choiceDis == 1)
        {
            Math();
        }
        else if (choiceDis == 2)
        {
            History();
        }
        else if (choiceDis == 3)
        {
            Biology();
        }
        else if (choiceDis == 0)
        {
            displayMenu();
        }
        
    }
    virtual const void displayMenu() final
    {

        cout << "Hello, to start testing, press 0. To view your results, press 1" << endl;
        int userChoice;
        cin >> userChoice;
        if (userChoice == 0)
        {
            choiceDiscip();
        }
        else if (userChoice == 1)
        {
            results();
        }
        else
        {
            cout << "Incorrect number, try again!" << endl;
            displayMenu();
        }



    }

    const void setName(const string& name) final
    {
        this->name = name;
    }

    const string getName()
    {
        return this->name;
    }

    virtual const bool findName(const string& name) const final
    {

        if (exists(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name)))
        {
            
            return true;     // работает норм
        }
        else
        {
            
            return false;
        }
            
       
    }
    virtual const bool setpassword(string UserPassword)
    {
        std::ofstream out;          // поток для записи
        out.open(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\") + this->name + string(".txt"));      // открываем файл для записи
        if (out.is_open())
        {
            out << UserPassword << std::endl;
        }                                                              //сюда не смотреть 
        out.close();
        std::cout << "File has been written" << std::endl;
        return 0;
    }

    virtual const bool correctPassword(const string& pass) const final
    {
        if (this->name.empty() || findName(this->name) != true)
        {
            return false;
        } 
             
            fstream in(string("C:\\Users\\User\\Desktop\\PV-311\\Exams\\C++ OOP\\Салиёв\\new_exam\\new_exam\\" + name + string(("\\")) + string("password") + string(".txt")), ios::in);        
            string s;
            in >> s;        
            cout << s;
            if (s == pass)
            {
                cout << "Password is correct!" << endl;
                in.close();
                return true;
            } return false;
           
    }
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


    void displayGMenu()
    {
        cout << "Hello! Pls, choice student - 1 or admin - 0! " << endl;
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
        cout << endl;
        //usrPtr->setpassword(UserPassword);      
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

//class Mathemathic 
//{
//private:
//    string q1 = "2+2???";
//    string q2 = "2 x 2 ???";
//    string q3 = "4 / 2 ???";
//    string q4 = "1 - 1 ???";
//    string q5 = "2+2x2 ???";
//    short int choice;
//    enum trueAnswers
//    {
//        qs1 = 4,
//        qs2 = 4,
//        qs3 = 2,
//        qs4 = 0,
//        qs5 = 1
//    };
//
//public:
//    bool question1()
//    {
//        cout << q1 << endl;
//        cout << "2" << endl;
//        cout << "3" << endl;
//        cout << "0" << endl;
//        cout << "4" << endl;
//        cout << "Choose answer: " << endl;
//        cin >> choice;
//        return choice == trueAnswers::qs1 ? true : false;
//
//    }
//
//    bool question2()
//    {
//        cout << q2 << endl;
//        cout << "2" << endl;
//        cout << "3" << endl;
//        cout << "0" << endl;
//        cout << "4" << endl;
//        cout << "Choose answer: " << endl;
//        cin >> choice;
//        return choice == trueAnswers::qs2 ? true : false;
//    }
//
//    bool question3()
//    {
//        cout << q3 << endl;
//        cout << "2" << endl;
//        cout << "3" << endl;
//        cout << "0" << endl;
//        cout << "4" << endl;
//        cout << "Choose answer: " << endl;
//        cin >> choice;
//        return choice == trueAnswers::qs3 ? true : false;
//    }
//
//    bool question4()
//    {
//        cout << q4 << endl;
//        cout << "2" << endl;
//        cout << "3" << endl;
//        cout << "0" << endl;
//        cout << "4" << endl;
//        cout << "Choose answer: " << endl;
//        cin >> choice;
//        return choice == trueAnswers::qs4 ? true : false;
//    }
//
//    bool question5()
//    {
//        cout << q5 << endl;
//        cout << "2" << endl;
//        cout << "3" << endl;
//        cout << "0" << endl;
//        cout << "4" << endl;
//        cout << "Choose answer: " << endl;
//        cin >> choice;
//        return choice == trueAnswers::qs5 ? true : false;
//    }
//};

int main()
{
    
    Test a;
    a.displayGMenu();

}