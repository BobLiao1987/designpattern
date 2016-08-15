#include <iostream>
#include <vector>
using namespace std;

class Memento
{
public:
    int m_vitality;
    int m_attack;
    int m_defense;
public:
    Memento(int vitality, int attack, int defense):
        m_vitality(vitality),m_attack(attack),m_defense(defense){}
    Memento& operator = (const Memento& memento)
    {
        m_vitality = memento.m_vitality;
        m_attack = memento.m_attack;
        m_defense = memento.m_defense;
        return *this;
    }
};

class GameRole
{
private:
    int m_vitality;
    int m_attack;
    int m_defense;
public:
    GameRole():m_vitality(100),m_attack(100),m_defense(100){}
    Memento Save()
    {
        Memento memento(m_vitality,m_attack,m_defense);
        return memento;
    }
    void Load(Memento memento)
    {
        m_vitality = memento.m_vitality;
        m_attack = memento.m_attack;
        m_defense = memento.m_defense;
    }
    void Show()
    {
        cout<<"vitality:"<<m_vitality<<",attack:"<<m_attack<<",defense:"<<m_defense<<endl;
    }
    void Attack()
    {
        m_vitality-=10;
        m_attack -=10 ;
        m_defense-=10;
    }
};

class Caretake
{
public:
    Caretake(){}
    void Save(Memento memento){m_vecMemento.push_back(memento);}
    Memento Load(int state){return m_vecMemento[state];}
private:
    std::vector<Memento> m_vecMemento;
};

int main(int argc, char const *argv[])
{
    Caretake caretake ;
    GameRole role;
    role.Show();
    caretake.Save(role.Save());

    role.Attack();
    role.Show();
    role.Load(caretake.Load(0));
    role.Show();
    
    return 0;
}