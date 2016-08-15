#pragma once
#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton* GetInstance(const char* name);
    virtual void Show(){}

protected:
    Singleton(){}
private:
    static Singleton* singleton;
};

