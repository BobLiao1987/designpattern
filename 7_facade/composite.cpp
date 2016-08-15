#include <iostream>
#include <string>
#include <list>
using namespace std;

class Company
{
public:
    Company(string name){m_name = name;}
    virtual ~Company(){}
    virtual void Add(Company* pCom){};
    virtual void Show(int depth){}
protected:
    string m_name;
};

class ConcreteCompany: public Company
{
public:
    ConcreteCompany(string name ):Company(name){}
    virtual ~ConcreteCompany(){}
    void Add(Company *pCom){m_listCompany.push_back(pCom);}
    void Show(int depth)
    {
        for (int i=0;i<depth;i++)
            cout<<"-";
        cout<<m_name<<endl;
        for(auto iter = m_listCompany.begin(); iter!= m_listCompany.end();iter++)
            (*iter)->Show(depth+2);
    }
private:
    list<Company*> m_listCompany;
};

class FinanceDepartment: public Company
{
public:
    FinanceDepartment(string name):Company(name){}
    virtual ~FinanceDepartment(){}
    virtual void Show(int depth)
    {
        for (int i=0;i<depth;i++)
           cout<<"-";
       cout<<m_name<<endl;
    }
};

class HRDepartment: public Company
{
public:
    HRDepartment(string name):Company(name){}
    virtual ~HRDepartment(){}
    virtual void Show(int depth)
    {
        for (int i=0;i<depth;i++)
           cout<<"-";
       cout<<m_name<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Company *root = new ConcreteCompany("HeadQuater Company");
    Company* leaf1 = new FinanceDepartment("finance department");
    Company* leaf2 = new HRDepartment("hr department");
    root->Add(leaf1);
    root->Add(leaf2);

    Company *mid1 = new ConcreteCompany("branch office A");
    Company *leaf3 = new FinanceDepartment("finance department");
    Company *leaf4 = new HRDepartment("hr department");
    mid1->Add(leaf3);
    mid1->Add(leaf4);
    root->Add(mid1);

    Company *mid2 = new ConcreteCompany("branch office B");
    Company *leaf5 = new FinanceDepartment("finance department");
    Company *leaf6 = new HRDepartment("hr department");
    mid2->Add(leaf5);
    mid2->Add(leaf6);
    root->Add(mid2);
    root->Show(0);


    delete leaf1; delete leaf2;  
    delete leaf3; delete leaf4;  
    delete leaf5; delete leaf6;   
    delete mid1; delete mid2;  
    delete root;

    return 0;
}