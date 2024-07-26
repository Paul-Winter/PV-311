#pragma once
class Emploer
{
public:
    Emploer();
    ~Emploer();
    virtual void Print() = 0;
};
//-----------------------------------------------
#pragma once
#include "Emploer.h"
class President :
    public Emploer
{
public:
    President();
    ~President();
    virtual void Print();
};
//-------------------------------------------------
#include "stdafx.h"
#include "President.h"


President::President()
{
}


President::~President()
{
}

void President::Print()
{
    cout << "President";
}

#include "stdafx.h"
#include "Emploer.h"
#include "President.h"

int _tmain(int argc, _TCHAR* argv[])
{
    President ekz1;
    ekz1.Print();
    system("pause");
    return 0;
}