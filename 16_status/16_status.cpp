#include <iostream>
using namespace std;

class War;
class State
{
public:
    virtual void Prophase(War *war){}
    virtual void Metaphase(War *war){}
    virtual void Anaphase(War *war){}
    virtual void End(War *war){}
    virtual void CurrentState(War *war){}
};

class War
{
private:
    State *m_state;
    int m_days;
public:
    War(State* state):m_state(state),m_days(0){}
    ~War(){delete m_state;}
    void SetDays(int x){m_days=x;}
    int GetDays(){return m_days;}
    void SetState(State *state){delete m_state; m_state=state;}
    void GetState(){m_state->CurrentState(this);}
};


class EndState: public State
{
public:
    void End(War *war)
    {
        cout<<"war end!"<<endl;
    }
    void CurrentState(War *war)
    {
        End(war);
    }
};
class AnaphaseState: public State
{
public:
    void Anaphase(War *war)
    {
        if(war->GetDays() < 30)
            cout<<"the "<< war->GetDays()<<"days"<<" AnaphaseState"<<endl;
        else
        {
            war->SetState(new EndState());
            war->GetState();
        }
    }
    void CurrentState(War *war)
    {
        Anaphase(war);
    }
};


class MetaphaseState: public State
{
public:
    void Metaphase(War *war)
    {
        if(war->GetDays() < 20)
            cout<<"the "<< war->GetDays()<<"days"<<" MetaphaseState"<<endl;
        else
        {
            war->SetState(new AnaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war)
    {
        Metaphase(war);
    }
};


class ProphaseState: public State
{
public:
    void Prophase(War *war)
    {
        if(war->GetDays() < 10)
            cout<<"the "<< war->GetDays()<<"days"<<" ProphaseState"<<endl;
        else
        {
            war->SetState(new MetaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war)
    {
        Prophase(war);
    }
};

int main(int argc, char const *argv[])
{
    War *war = new War(new ProphaseState());
    for(int i=0;i<40;i++)
    {
        war->SetDays(i);
        war->GetState();
    }
    delete war;

    return 0;
}