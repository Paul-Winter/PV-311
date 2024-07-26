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
    // реализация
Phone::Phone(string pmanufacturer, string pmodel, string pcolor, int pyear)
{
    SetName("Phone");
    SetManufacturer(pmanufacturer);
    SetModel(pmodel);
    SetColor(pcolor);
    SetYear(pyear);
};

Device* Phone::Clone() const
{
    Phone* iphone = new Phone();
    *iphone = *this;
    return iphone;
};

void Phone::Show() const
{
    Phone::Show();
    cout << "Manufacturer " << GetManufacturer();
    cout << "Model " << GetModel();
    cout << "Color " << GetColor();
    cout << "Year " << GetYear();
}

int main()
{
    string manufacturer;
    cout << "Input manufacturer\n";
    getline(cin, manufacturer);
}
