#include <iostream>
using namespace std;

class Phone
{
public:
    Phone(){}
    virtual ~Phone(){}
    virtual void ShowDecorate(){}
};

class iPhone: public Phone
{
private:
    string m_name;
public:
    iPhone(string name):m_name(name){}
    ~iPhone(){}
    void ShowDecorate(){cout<<m_name<<"'s decorate"<<endl;}

};

class NokiaPhone:public Phone
{
private:
    string m_name;
public:
    NokiaPhone(string name):m_name(name){}
    ~NokiaPhone(){}
    void ShowDecorate(){cout<<m_name<<"'s decorate"<<endl;}

};

class DecoratorPhone:public Phone
{
private:
    Phone *m_phone;
public:
    DecoratorPhone(Phone* phone): m_phone(phone){}
    virtual void ShowDecorate(){m_phone->ShowDecorate();}
};
class DecoratorPhoneA: public DecoratorPhone
{
public:
    DecoratorPhoneA(Phone *phone):DecoratorPhone(phone){}
    void ShowDecorate()
    {
        DecoratorPhone::ShowDecorate(); 
        AddDecorate();
    }
private:
    void AddDecorate()
    {
        cout<<"add extra guajian decorate"<<endl;
    }
};


class DecoratorPhoneB: public DecoratorPhone
{
public:
    DecoratorPhoneB(Phone *phone):DecoratorPhone(phone){}
    void ShowDecorate()
    {
        DecoratorPhone::ShowDecorate(); 
        AddDecorate();
    }
private:
    void AddDecorate()
    {
        cout<<"add extra tiemo decorate"<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Phone *phone = new iPhone("5s");
    Phone *dpa = new DecoratorPhoneA(phone);
    Phone *dpb = new DecoratorPhoneB(phone);
    dpa->ShowDecorate();
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete phone;

    return 0;
}