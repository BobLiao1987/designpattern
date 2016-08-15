#include <iostream>
using namespace std;

//simple factory mode
enum CTYPE {COREA,COREB  };
class SingleCore
{
public:
    SingleCore(){}
    ~SingleCore(){}

    virtual void Show()=0;
    /* data */
};

//Single COREA
class SingleCoreA :public SingleCore
{
public:
    SingleCoreA(){}
    ~SingleCoreA(){}
    void Show(){
        cout<<"SingleCoreA"<<endl;
    }
};
//Single COREB
class SingleCoreB:public SingleCore
{
public:
    SingleCoreB(){}
    ~SingleCoreB(){}
    void Show(){
        cout<<"singleCoreB"<<endl;
    }
    /* data */
};

//factory 
class  Factory
{
public:
     Factory(){}
    ~ Factory(){}

    SingleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if(ctype==COREA)
            return new SingleCoreA();
        else if(ctype==COREB)
            return new SingleCoreB();
        else
            return nullptr;
    }
    /* data */
};

int main(int argc, char const *argv[])
{
    Factory fac;
    SingleCore * core = fac.CreateSingleCore(COREA);
    core->Show();

    core = fac.CreateSingleCore(COREB);
    core->Show();
    
    return 0;
}