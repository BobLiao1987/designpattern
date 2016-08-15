//how to compile me :g++ -o singleton *.cpp -std=c++11

#include "Singleton.h"
int main(int argc, char const *argv[])
{
    Singleton *st = Singleton::GetInstance("SingletonA");// or "SingletonB"
    st->Show();
    cout<<st<<endl;
    Singleton *st_more = Singleton::GetInstance("SingletonA");
    st_more->Show();
    cout<<st_more<<endl;// the address is the same as the previous

    return 0;
}