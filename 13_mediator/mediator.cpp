#include <iostream>
#include <string>
using namespace std;

class Mediator;

class Person
{
protected:
    Mediator *m_mediator;
public:
    virtual void SetMediator(Mediator *mediator){}
    virtual void SendMessage(string message){}
    virtual void GetMessage(string message){}
};
class Mediator
{
public:
    virtual void Send(string message, Person* person){}
    virtual void SetA(Person* A){}
    virtual void SetB(Person* B){}
};

class Renter: public Person
{
public:
    void SetMediator(Mediator* mediator)
    {
        m_mediator = mediator;
    }
    void SendMessage(string message)
    {
        m_mediator->Send(message, this);
    }
    void GetMessage(string message)
    {
        cout<< "render receive info"<<message<<endl;
    }
};
class Landlord :public Person
{
public:
    void SetMediator(Mediator* mediator)
    {
        m_mediator = mediator;
    }
    void SendMessage(string message)
    {
        m_mediator->Send(message, this);
    }
    void GetMessage(string message)
    {
        cout<< "Landlord receive info"<<message<<endl;
    }
};
class HouseMediator: public Mediator
{
private:
    Person *m_A;//render
    Person *m_B;//landlord
public:
    HouseMediator():m_A(nullptr), m_B(nullptr){}
    void SetA(Person *A){m_A = A;}
    void SetB(Person *B){m_B =B;}
    void Send(string message, Person *person)
    {
        if(person==m_A)
            m_B->GetMessage(message);
        else 
            m_A->GetMessage(message);

    }
};




int main(int argc, char const *argv[])
{
    Mediator *mediator= new HouseMediator();
    Person *person1 = new Renter();
    Person *person2 = new Landlord();
    mediator->SetA(person1);
    mediator->SetB(person2);
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);

    person1->SendMessage("I want rend a house in nanjing lu");
    person2->SendMessage("My house is 1000rmb per month");

    delete person1; delete person2; delete mediator;
    return 0;
}