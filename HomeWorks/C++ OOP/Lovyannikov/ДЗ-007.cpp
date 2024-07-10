
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Student {

public:

    Student() {

    }
    Student(int age, const vector<string>& name) : age_{ age }, personal_info_{ name } {
        
    }
    void DisplayInfo() {
        cout << "Personal information: "s;
        for (const string& x : personal_info_)
        {
            cout << x << " "s;
        }
        cout << "\nAge: "s << age_ << endl;
    }
    
    int GetAge() {
        return age_;
    }
    vector<string> GetInfo() {
        return personal_info_;
    }

    
private:

protected:
    int age_;
    vector<string> personal_info_;
    

};

class GraduatedStudent : protected Student {
public:

    GraduatedStudent() {

    }
    GraduatedStudent(Student student, string dissertation) : Student(student) , dissertation_{ dissertation } {
        age_ = student.GetAge() + 5;
        personal_info_ = student.GetInfo();
    }

    void DisplayInfo() {
        cout << "Personal information: "s;
        for (const string& x : personal_info_)
        {
            cout << x << " "s;
        }
        cout << "\nTheme of dessertation: "s << dissertation_ << endl;
        cout << "Age: "s << age_ << endl;
    }

private:
    int age_;
    vector<string> personal_info_;
    string dissertation_;
protected:

    
};

int main()
{
    Student a(19, { {"Petrov"s},{"Ivan"s},{"Petrovich"s} });
    a.DisplayInfo();
    cout << endl;
    GraduatedStudent b{a, "Philosophi"s };
    b.DisplayInfo();
    
}

