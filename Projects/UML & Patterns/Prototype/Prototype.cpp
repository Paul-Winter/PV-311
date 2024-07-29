#include <iostream>
using namespace std;

class Device
{
    string name;

public:
    Device() : Device("Unknown device") {};
    Device(string deviceName)
    {
        SetName(deviceName);
    }

    string GetName() const { return name; };

    void SetName(string deviceName)
    {
        name = deviceName;
    }

    virtual Device* Clone() const = 0;

    void Show() const { cout << "Name is " << GetName(); };
};

class Phone : public Device
{
    string manufacturer;
    string model;
    string color;
    int year;

public:
    Phone() : Phone("No info", "Unknown model", "No color", 0)
    {
        SetName("Phone");
    };
    Phone(string pmanufacturer, string pmodel, string pcolor, int pyear) {};
    
    int GetYear() const { return year; };
    string GetManufacturer() const { return manufacturer; };
    string GetModel() const { return model; };
    string GetColor() const { return color; };

    void SetYear(int pyear) { year = pyear; };
    void SetManufacturer(string pmanufacturer) { manufacturer = pmanufacturer; };
    void SetModel(string pmodel) { model = pmodel; };
    void SetColor(string pcolor) { color = pcolor; };

    Device* Clone() const;
    void Show() const;
};

class Notepad : public Device
{
    string manufacturer;
    string model;
    string color;
    int size;
    int weight;
public:
    Notepad() : Notepad("No info", "Unknown model", "No color", 0,0)
    {
        SetName("Notepad");
    };
    Notepad(string pmanufacturer, string pmodel, string pcolor, int pweight,int psize) {};
    void SetWeight(int pweight) { weight = pweight; };
    void SetSize(int psize) {size = psize; };
    void SetManufacturer(string pmanufacturer) { manufacturer = pmanufacturer; };
    void SetModel(string pmodel) { model = pmodel; };
    void SetColor(string pcolor) { color = pcolor; };
    int GetWeight() const { return weight; };
    int GetSize() const { return size; };
    string GetManufacturer() const { return manufacturer; };
    string GetModel() const { return model; };
    string GetColor() const { return color; };
    Device* Clone() const;
    void Show() const;

};
    // реализация

Notepad::Notepad(string pmanufacturer, string pmodel, string pcolor, int psize,int pweight)
{
    SetName("Samsung");
    SetManufacturer(pmanufacturer);
    SetModel(pmodel);
    SetColor(pcolor);  
    SetSize(psize);
    SetWeight(pweight);
};
void Notepad::Show() const {
    cout << "Manufacturer " << GetManufacturer() << endl;
    cout << "Model " << GetModel() << endl;
    cout << "Color " << GetColor() << endl;
    cout << "Size" << GetSize() << endl;
    cout << "Weight" << GetWeight() << endl;
}
Device* Notepad::Clone() const
{
    Notepad* note = new Notepad;
    *note = *this;  
    return note;
}
Device* Phone::Clone() const
{
    Phone* iphone = new Phone();
    *iphone = *this;
    return iphone;
};

void Phone::Show() const
{
    //Phone::Show();
    cout << "Manufacturer " << GetManufacturer();
    cout << "Model " << GetModel();
    cout << "Color " << GetColor();
    cout << "Year " << GetYear();
}

Phone::Phone(string pmanufacturer, string pmodel, string pcolor, int pyear)
{
    SetName("Phone");
    SetManufacturer(pmanufacturer);
    SetModel(pmodel);
    SetColor(pcolor);
    SetYear(pyear);
};

int main()
{
    string manufacturer;
    cout << "Input manufacturer\n";
    cin >> manufacturer;
    int year;
    cout << "Input year\n";
    cin >> year;
    string model;
    cout << "Input model\n";
    cin >> model;
    string color;
    cout << "Input color\n";
    cin >> color;
    int size;
    cout << "Input size\n";
    cin >> size;
    int weight;
    cout << "Input weight\n";
    cin >> weight;
    Notepad s(manufacturer, model, color, size, weight); 
    Phone q(manufacturer, model, color, year);
    s.Show();
    cout << endl;
    q.Show();
    cout << endl;
    Notepad* scopy = (Notepad*)s.Clone();
    scopy->Show();
    Phone* qcopy = (Phone*)q.Clone();
    qcopy->Show();
}
