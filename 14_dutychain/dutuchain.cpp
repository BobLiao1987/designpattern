#include <iostream>
#include <string>
using namespace std;

//abstract manager
class Manager
{
protected:
    Manager* m_manager;
    string m_name;
public:
    Manager(Manager* manager, string name):m_manager(manager), m_name(name){}
    virtual void DealWithRequest(string name, int num){}
};

class CommonManager :public Manager
{
public:
    CommonManager(Manager* manager, string name):Manager(manager,name){}
    void DealWithRequest(string name, int num)
    {
        if(num<500)
        {
            cout<< "manger:"<<m_name<<" approve:"<<name<<" Add "<<num<<endl;
        }
        else
        {
            cout<< "manger:"<<m_name<<" no right handle"<<endl;
            m_manager->DealWithRequest(name, num);
        }
    }

};
class Majordomo: public Manager
{
public:
    Majordomo (Manager* manager, string name): Manager(manager, name){}
    void DealWithRequest(string name, int num)
    {
        if(num<1000)
        {
            cout<< "Majordomo:"<<m_name<<"approve:"<<name<<" Add "<<num<<endl;
        }
        else
        {
            cout<< "Majordomo"<<m_name<<" no right handle"<<endl;
            m_manager->DealWithRequest(name, num);
        }
   
    }

};
class GenralManager :public Manager
{
public:
    GenralManager(Manager* manager, string name):Manager(manager, name){}
    void DealWithRequest(string name,int num)
    {
            cout<< "GenralManager:"<<m_name<<"approve:"<<name<<" Add "<<num<<endl;
    }
};



int main(int argc, char const *argv[])
{
    Manager *genral = new GenralManager(nullptr, "A");
    Manager *majordomo = new Majordomo(genral, "B");
    Manager *common = new CommonManager(majordomo,"C");

    common->DealWithRequest("D", 300);
    common->DealWithRequest("E", 600);
    common->DealWithRequest("F", 1000);

    return 0;
}