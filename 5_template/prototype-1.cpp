#include <iostream>
#include <string.h>
using namespace std;

class Resume
{
protected:
    char *name;
public:
    Resume(){}
    virtual ~Resume(){}
    virtual Resume* Clone(){return nullptr;}
    virtual void Set(char* n){}
    virtual void Show(){}
};

class ResumeA :public Resume
{
public:
    ResumeA(const char *str)
    {
        if(str==nullptr)
        {
            name = new char[1];
            name[0] ='\0';
        }
        else
        {
            name = new char[strlen(str)+1];
            strcpy(name,str);
        }
    }
    ResumeA(const ResumeA& r)
    {
        name = new char[strlen(r.name)+1];
        strcpy(name, r.name);
    }
    ~ResumeA()
    {
        delete [] name;
    }
    ResumeA* Clone()
    {
        return new ResumeA(*this);
    }
    void Show()
    {
         cout<<"ResumeA name: "<<name<<endl;
    }
};


class ResumeB :public Resume
{
public:
    ResumeB(const char *str)
    {
        if(str==nullptr)
        {
            name = new char[1];
            name[0] ='\0';
        }
        else
        {
            name = new char[strlen(str)+1];
            strcpy(name,str);
        }
    }
    ResumeB(const ResumeB& r)
    {
        name = new char[strlen(r.name)+1];
        strcpy(name, r.name);
    }
    ~ResumeB()
    {
        delete [] name;
    }
    ResumeB* Clone()
    {
        return new ResumeB(*this);
    }
    void Show()
    {
         cout<<"ResumeB name: "<<name<<endl;
    }
};



int main(int argc, char const *argv[])
{
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->Clone();
    Resume *r4 = r2->Clone();
    r1->Show();r2->Show();
    delete r1; delete r2; r1 =r2 =nullptr;
    r3->Show(); r4->Show();
    delete r3; delete r4; r3 =r4 =nullptr;

    return 0;
}