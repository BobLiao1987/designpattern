#include <iostream>
#include <string.h>
using namespace std;

class Resume
{
protected:
    virtual void SetPersonalInfo(){}
    virtual void SetEducation(){}
    virtual void SetWorkExp(){}
public:
    void FillResume()
    {
        SetPersonalInfo();
        SetEducation();
        SetWorkExp();
    }

};

class  ResumeA :public Resume
{
protected:
    void SetPersonalInfo(){cout<<"A's personalInfo"<<endl;}
    void SetEducation(){cout<<"A's Education"<<endl;}
    void SetWorkExp(){cout<<"A's Work experience"<<endl;}
};

class  ResumeB :public Resume
{
protected:
    void SetPersonalInfo(){cout<<"B's personalInfo"<<endl;}
    void SetEducation(){cout<<"B's Education"<<endl;}
    void SetWorkExp(){cout<<"B's Work experience"<<endl;}
};

int main(int argc, char const *argv[])
{
    Resume *r1;
    r1 = new ResumeA();
    r1->FillResume();
    delete r1;
   
    r1 = new ResumeB();
    r1->FillResume();
    delete r1;
    r1 =nullptr;

    return 0;
}

