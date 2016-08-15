#include <iostream>
using namespace std;

//Single Core
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

//Multi Core
class MultiCore
{
public:
    virtual void Show()=0;
};
class MultiCoreA:public MultiCore
{
public:
    void Show(){cout<<"MultiCoreA"<<endl;}
};
class MultiCoreB:public MultiCore
{
public:
    void Show(){cout<<"MultiCoreB"<<endl;}
};

class Factory
{
public:
    virtual SingleCore* CreatesingleCore()=0;
    virtual MultiCore* CreateMultiCore()=0;
};
class FactoryA:public Factory
{
public:
    SingleCore* CreatesingleCore(){ return new SingleCoreA(); }
    MultiCore* CreateMultiCore(){ return new MultiCoreA(); }
};
class FactoryB:public Factory
{
public:
    SingleCore* CreatesingleCore(){return new SingleCoreB();}
    MultiCore* CreateMultiCore(){return new MultiCoreB();}
};

int main(int argc, char const *argv[])
{
    Factory * pa_fa = new FactoryA();
    SingleCore *p_sa =  pa_fa->CreatesingleCore();
    MultiCore *p_ma = pa_fa->CreateMultiCore();
    p_sa->Show();
    p_ma->Show();

    delete p_sa;
    delete p_ma;
    delete pa_fa;
    return 0;
}