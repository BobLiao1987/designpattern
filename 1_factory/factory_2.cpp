#include <iostream>
using namespace std;

class SingleCore
{
public:
    virtual void Show()=0;
};

class SingleCoreA:public SingleCore
{
public:
    void Show(){cout<<"SingleCoreA"<<endl;}
};

class  SingleCoreB:public SingleCore
{
public:
    void Show(){cout<<"SingleCoreB"<<endl;}
    /* data */
};


class Factory
{
public:
    virtual SingleCore* CreateSingleCore()=0;
};
class FactoryA:public Factory
{
public:
    SingleCoreA* CreateSingleCore(){return new SingleCoreA();}
};
class FactoryB: public Factory
{
public:
    SingleCoreB* CreateSingleCore(){return new SingleCoreB();}
};

int main(int argc, char const *argv[])
{

    Factory * p_fac = new FactoryB();
    SingleCore* p_core= p_fac->CreateSingleCore();
    p_core->Show();

    delete p_core;
    delete p_fac;

    /* code */
    return 0;
}