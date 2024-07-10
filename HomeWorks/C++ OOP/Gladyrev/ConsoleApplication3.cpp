#include <iostream>
#include <string>
using namespace std;

class Drob {
private:
    int chisl;
    int znamen;
    int NOD(int x, int y)
    {
        if (y == 0) return x;
        return NOD(y, x % y);
    }
public:
    void input(int c, int z)
    {
        chisl = c;
        znamen = z;
    }
    void mult(int x)
    {
        chisl *= x;
        cout << "drob:  " << chisl << '/' << znamen << endl;
    }
    void div(int x)
    {
        znamen *= x;
        cout << "drob:  " << chisl << '/' << znamen << endl;

    }

    void sum(int x)
    {
        chisl += (x * znamen);
        cout << "drob:  " << chisl << '/' << znamen << endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        cout << "drob:  " << chisl << '/' << znamen << endl;

    }
    void show()
    {
        cout << "tekushaya drob:  " << chisl << '/' << znamen << endl;
    }
    int peredacha()
    {
        return NOD(chisl, znamen);
    }
    void reduct(int x)
    {
        chisl /= x;
        znamen /= x;
    }

};



int main() {
    int a, b, m;
    char c = 'y';
    cout << "vvedite cheslitel:" << endl;
    cin >> a;
    cout << "vvedite znamenatel:" << endl;
    cin >> b;
    Drob obj;
    obj.input(a, b);
    do {
        obj.reduct(obj.peredacha());
        obj.show();
        cout << "1:Pribavit k drobi chislo" << endl;
        cout << "2:Otniatb ot drobi chislo" << endl;
        cout << "3:Ymnojitb  drobna  chislo" << endl;
        cout << "4:Razdelitb  drob na chislo" << endl;
        cout << "Viberite deystvie" << '\n';
        cin >> m;
        switch (m)
        {
        case 1:
            cout << "Vvedite slagaemoe" << endl;
            cin >> a;
            obj.sum(a);
            break;
        case 2:
            cout << "Vvedite vichitaemoe" << endl;
            cin >> a;
            obj.sub(a);
            break;
        case 3:
            cout << "Vvedite mnojitel" << endl;
            cin >> a;
            obj.mult(a);
            break;
        case 4:
            cout << "Vvedite delitel" << endl;
            cin >> a;
            obj.div(a);
            break;
        default:
            cout << "Viberite pravilno" << endl;
        }
        cout << "prodoljit raboty?(y/n)" << endl;
        cin >> c;
    } while (c != 'n');
    return 0;
}









class Subscriber
{
    char* surname;
    char* name;
    char* secondName;
public:
    Subscriber() : Subscriber{ "Surname","Name","Second name" } {}
    Subscriber(const char* surnameP, const char* nameP, const char* secondNameP) :
        surname{ initSurname(surnameP) }, name{ initName(nameP) }, secondName{ initSecondName(secondNameP) } {}

    Subscriber(const Subscriber& object) :
        surname{ initSurname(object.surname) }, name{ initName(object.name) }, secondName{ initSecondName(object.secondName) } {}

    Subscriber& setSurname(const char* surnameP);
    Subscriber& setName(const char* nameP);
    Subscriber& setSecondName(const char* secondNameP);

    char* initSurname(const char* surnameP);
    char* initName(const char* nameP);
    char* initSecondName(const char* secondNameP);

    Subscriber& init(const char* surnameP, const char* nameP, const char* secondNameP);

    const char* getSurname()const { return surname; }
    const char* getName()const { return name; }
    const char* getSecondName()const { return secondName; }

    Subscriber& print();

    ~Subscriber() { delete[] surname; delete[] name; delete[] secondName; }
};

Subscriber& Subscriber::setSurname(const char* surnameP)
{
    auto len{ strlen(surnameP) + 1 };
    if (!surname) { surname = new char[len]; }
    else if (surname and strlen(surname) + 1 < len)
    {
        delete[] surname;
        surname = new char[len];
    }
    strcpy_s(surname, len, surnameP);
    return *this;
}

Subscriber& Subscriber::setName(const char* nameP)
{
    auto len{ strlen(nameP) + 1 };
    if (!name) { name = new char[len]; }
    else if (name and strlen(name) + 1 < len)
    {
        delete[] name;
        name = new char[len];
    }
    strcpy_s(name, len, nameP);
    return *this;
}

Subscriber& Subscriber::setSecondName(const char* secondNameP)
{
    auto len{ strlen(secondNameP) + 1 };
    if (!secondName) { secondName = new char[len]; }
    else if (secondName and strlen(secondName) + 1 < len)
    {
        delete[] secondName;
        secondName = new char[len];
    }
    strcpy_s(secondName, len, secondNameP);
    return *this;
}

char* Subscriber::initSurname(const char* surnameP)
{
    surname = { new char[strlen(surnameP) + 1] };
    strcpy_s(surname, strlen(surnameP) + 1, surnameP);
    return surname;
}
char* Subscriber::initName(const char* NameP)
{
    name = { new char[strlen(NameP) + 1] };
    strcpy_s(name, strlen(NameP) + 1, NameP);
    return name;
}
char* Subscriber::initSecondName(const char* secondNameP)
{
    secondName = { new char[strlen(secondNameP) + 1] };
    strcpy_s(secondName, strlen(secondNameP) + 1, secondNameP);
    return secondName;
}

Subscriber& Subscriber::init(const char* surnameP, const char* nameP, const char* secondNameP)
{
    setSurname(surnameP);
    setName(nameP);
    setSecondName(secondNameP);
    return *this;
}

Subscriber& Subscriber::print()
{
    std::cout << "\033[1;32m" << "Surname: " << "\033[0m" << surname
        << "\033[1;32m" << "\nName: " << "\033[0m" << name << "\nSecond name: " << secondName << '\n';
    return *this;
}

class PhoneBook
{
    Subscriber contact;
    int homePhone;
    int workPhone;
    int mobilePhone;
    char* addContactDetails;

public:
    PhoneBook() : PhoneBook{ "test", "test","test", 0,0,0,"test" } {}
    PhoneBook(const char* surnameP, const char* nameP, const char* secondNameP, int homePhoneP, int workPhoneP, int mobilePhoneP, const char* addContactDetailsP) :
        contact{ surnameP,nameP,secondNameP }, homePhone{ homePhoneP }, workPhone{ workPhoneP }, mobilePhone{ mobilePhoneP }, addContactDetails{ initContactDetailsP(addContactDetailsP) } {}
    PhoneBook(const PhoneBook& contacts) :
        contact{ contacts.contact }, homePhone{ contacts.homePhone }, workPhone{ contacts.workPhone }, mobilePhone{ contacts.mobilePhone }, addContactDetails{ initContactDetailsP(contacts.addContactDetails) } {}

    PhoneBook& setContacts(const char* surnameP, const char* nameP, const char* secondNameP)
    {
        contact.setSurname(surnameP); contact.setName(nameP); contact.setSecondName(secondNameP); return *this;
    }

    PhoneBook& setHomePhone(int homePhoneP) { homePhone = homePhoneP; return *this; }
    PhoneBook& setWorkPhone(int workPhoneP) { workPhone = workPhoneP; return *this; }
    PhoneBook& setMobilePhone(int mobilePhoneP) { mobilePhone = mobilePhoneP; return *this; }

    PhoneBook& setContactDetails(const char* addContactDetailsP);

    const char* getContactSurname()const { return contact.getSurname(); }
    const char* getContactName()const { return contact.getName(); }
    const char* getContactSecondName()const { return contact.getSecondName(); }

    int getHomePhone()const { return homePhone; }
    int getWorkPhone()const { return workPhone; }
    int getMobilePhone()const { return mobilePhone; }

    const char* getaddContactDetails()const { return addContactDetails; }

    char* initContactDetailsP(const char* addContactDetailsP);

    PhoneBook& init(const char* surnameP, const char* nameP, const char* secondNameP, int homePhoneP, int workPhoneP, int mobilePhoneP, const char* addContactDetailsP);

    PhoneBook& print();

    ~PhoneBook() { delete[] addContactDetails; }
};

PhoneBook& PhoneBook::setContactDetails(const char* addContactDetailsP)
{
    auto len{ strlen(addContactDetailsP) + 1 };
    if (!addContactDetails) { addContactDetails = new char[len]; }
    else if (addContactDetails and strlen(addContactDetails) + 1 < len)
    {
        delete[] addContactDetails;
        addContactDetails = new char[len];
    }
    strcpy_s(addContactDetails, len, addContactDetailsP);
    return *this;
}

char* PhoneBook::initContactDetailsP(const char* addContactDetailsP)
{
    addContactDetails = { new char[strlen(addContactDetailsP) + 1] };
    strcpy_s(addContactDetails, strlen(addContactDetailsP) + 1, addContactDetailsP);
    return addContactDetails;
}

PhoneBook& PhoneBook::init(const char* surnameP, const char* nameP, const char* secondNameP, int homePhoneP, int workPhoneP, int mobilePhoneP, const char* addContactDetailsP)
{
    setContacts(surnameP, nameP, secondNameP);
    homePhone = homePhoneP;
    workPhone = workPhoneP;
    mobilePhone = mobilePhoneP;
    setContactDetails(addContactDetailsP);
    return *this;
}

PhoneBook& PhoneBook::print()
{
    contact.print();
    std::cout << "Home phone: " << homePhone << "\nWork phone: " << workPhone << "\nMobile phone: " << mobilePhone
        << "\nAdditional contact details: " << addContactDetails << '\n';
    return *this;
}

void listPhoneBook(PhoneBook* begin, PhoneBook* end)
{
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        contacts->print(); std::cout << '\n';
    }
}

void contactSearch(PhoneBook* begin, PhoneBook* end, char* found, bool(*searchCriterion)(const PhoneBook& const contacts, char* found))
{
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        if (searchCriterion(*contacts, found)) { contacts->print(); std::cout << '\n'; }
    }
}

bool searchBySurname(const PhoneBook& const contacts, char* found)
{
    return strstr(contacts.getContactSurname(), found);
}

bool searchByName(const PhoneBook& const contacts, char* found)
{
    return strstr(contacts.getContactName(), found);
}

void savePhoneBook(PhoneBook* begin, PhoneBook* end)
{
    std::ofstream outf;
    outf.open("PhoneBook.txt");
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        outf << contacts->getContactSurname() << '\n';
        outf << contacts->getContactName() << '\n';
        outf << contacts->getContactSecondName() << '\n';
        outf << contacts->getHomePhone() << '\n';
        outf << contacts->getWorkPhone() << '\n';
        outf << contacts->getMobilePhone() << '\n';
        outf << contacts->getaddContactDetails() << '\n';
    }
    outf.close();
}

void loadPhoneBook(PhoneBook* begin, PhoneBook* end)
{
    std::ifstream inf;
    char surnameP[15];
    char nameP[15];
    char secondNameP[15];
    int homePhoneP{ 0 };
    int workPhoneP{ 0 };
    int mobilePhoneP{ 0 };
    char contactDetailsP[15];

    inf.open("PhoneBook.txt");
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        inf.getline(surnameP, 15);
        inf.getline(nameP, 15);
        inf.getline(secondNameP, 15);
        inf >> homePhoneP;
        inf >> workPhoneP;
        inf >> mobilePhoneP;
        inf.ignore(100, '\n');
        inf.getline(contactDetailsP, 15);
        contacts->init(surnameP, nameP, secondNameP, homePhoneP, workPhoneP, mobilePhoneP, contactDetailsP);
    }
    inf.close();
}

void pastInArr(PhoneBook*& Arr, size_t& arrSize, size_t idxPastElem)
{
    PhoneBook* newArr{ new PhoneBook[arrSize + 1] };
    for (size_t i{ 0 }; i < arrSize; ++i)
    {
        newArr[i + (i >= idxPastElem)].PhoneBook::PhoneBook(Arr[i]);
    }
    delete[] Arr;
    Arr = newArr;
    arrSize++;
}

void cutFromArr(PhoneBook*& Arr, size_t& arrSize, size_t idxCutElem)
{
    PhoneBook* newArr{ new PhoneBook[arrSize--] };
    for (size_t i{ 0 }; i < arrSize; ++i)
    {
        newArr[i].PhoneBook::PhoneBook(Arr[i + (i >= idxCutElem)]);
    }
    delete[]Arr;
    Arr = newArr;
}

void phoneBookSort(PhoneBook* contacts, size_t PhoneBookSize, bool(*criteria)(const PhoneBook& contactsA, const PhoneBook& contactsB))
{
    PhoneBook tmp;
    for (size_t head{ 0 }; head < PhoneBookSize; ++head)
    {
        for (size_t tail{ PhoneBookSize - 1 }; tail > head; --tail)
        {
            if (criteria(contacts[tail], contacts[head]))
            {
                tmp.PhoneBook::PhoneBook(contacts[tail]);
                contacts[tail].PhoneBook::PhoneBook(contacts[head]);
                contacts[head].PhoneBook::PhoneBook(tmp);
            }
        }
    }
}

bool sortBySurname(const PhoneBook& contactsA, const PhoneBook& contactsB)
{
    return strcmp(contactsA.getContactSurname(), contactsB.getContactSurname()) < 0;
}

bool sortByName(const PhoneBook& contactsA, const PhoneBook& contactsB)
{
    return strcmp(contactsA.getContactName(), contactsB.getContactName()) < 0;
}

int main()
{
    size_t PhoneBookSize{ 10 };
    PhoneBook* contacts{ new PhoneBook[PhoneBookSize] };
    auto contactsEnd{ contacts + PhoneBookSize };

    contacts[0].init("Kulyk", "Volodymir", "Oleksandrovich", 0, 0, 312231701, " ");
    contacts[1].init("Stepanuk", "Oleh", "Vasylyovich", 0, 0, 672356575, " ");
    contacts[2].init("Marchuk", "Ivan", "Stepanovich", 0, 0, 6756455, " ");
    contacts[3].init("Kozluk", "Andriy", "Mykolayovich", 0, 0, 502456988, "Friend");
    contacts[4].init("Philipchuk", "Yriy", "Leonidvich", 312221321, 312231705, 677777777, "Director");
    contacts[5].init("Karasev", "Dmytro", "Stepanovich", 0, 312225565, 679638521, " ");
    contacts[6].init("Shevchuk", "Oleksander", "Ivanovich", 0, 312225533, 670996523, " ");
    contacts[7].init("Solovey", "Andriy", "Oleksandrovich", 312228511, 312231799, 507412525, "Mechanic");
    contacts[8].init("Havryluk", "Valeriy", "Stepanovich", 312221300, 0, 637894532, " ");
    contacts[9].init("Marchuk", "Olena", "Mykolaivna", 312221515, 312231755, 671030303, "Famaly doctor");

    listPhoneBook(contacts, contactsEnd);

    char foundS[]{ "Marchuk" };
    std::cout << "\033[1;31m" << "\nSearch by Surname:\n" << "\033[0m";
    contactSearch(contacts, contactsEnd, foundS, searchBySurname);

    char foundN[]{ "Andriy" };
    std::cout << "\033[1;31m" << "\nSearch by name:\n" << "\033[0m";
    contactSearch(contacts, contactsEnd, foundN, searchByName);

    savePhoneBook(contacts, contactsEnd);

    std::cout << "\033[1;31m" << "\nLoad contacts from file :\n" << "\033[0m";
    PhoneBook* fileContacts{ new PhoneBook[PhoneBookSize] };
    auto fileContactsEnd{ fileContacts + PhoneBookSize };
    loadPhoneBook(fileContacts, fileContactsEnd);
    listPhoneBook(fileContacts, fileContactsEnd);

    std::cout << "\033[1;31m" << "\nAdd contact in contacts :\n" << "\033[0m";
    pastInArr(contacts, PhoneBookSize, 3);
    contacts[3].init("Savchuk", "Oleh", "Olehovich", 0, 0, 502582525, "worker");
    listPhoneBook(contacts, contacts + PhoneBookSize);

    std::cout << "\033[1;31m" << "\nDelete contact from contacts :\n" << "\033[0m";
    cutFromArr(contacts, PhoneBookSize, 3);
    listPhoneBook(contacts, contacts + PhoneBookSize);

    phoneBookSort(contacts, PhoneBookSize, sortBySurname);
    std::cout << "\033[1;31m" << "\nSorted by Surname:\n" << "\033[0m";
    listPhoneBook(contacts, contacts + PhoneBookSize);

    delete[] contacts;
    return 0;
}











using namespace std;

class string_
{
private:
    char* strings;
    int len;
public:
    string_()
    {
        len = 81;
        strings = new char[len];
        strcpy(strings, strings);
    }
    string_(int len)
    {
        strings = new char[len + 1];
        strcpy(strings, strings);
    }
    string_(const char* string)
    {
        strings = new char[strlen(strings) + 1];
        strcpy(strings, string);
    }
    string_(const string_& news)
    {
        strings = new char[strlen(strings) + 1];
        strcpy(strings, news.strings);
    }
    ~string_()
    {
        delete[] strings;
    }

    string_& operator + (const string_& right)
    {
        string_ result(strcat(strings, right.strings));
        return *this;
    }

    friend istream& operator >> (istream& stream, string_& orig);
    friend ostream& operator << (ostream& stream, const string_& orig);
};

istream& operator >> (istream& stream, string_& orig)
{
    stream >> orig.strings;
    return stream;
}

ostream& operator << (ostream& stream, const string_& orig)
{
    stream << orig.strings;
    return stream;
}

int main()
{
    string_ string1, string2(80);

    cout << "Enter string 1: ";
    cin >> string1;

    cout << "Enter string 2: ";
    cin >> string2;

    cout << string1 << " + " << string2;
    string1 + string2;
    cout << " = " << string1 << endl;

    return 0;
}