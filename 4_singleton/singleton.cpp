#include "Singleton.h"
#include "SingletonA.h"
#include "SingletonB.h"

#include<string.h>

Singleton* Singleton::singleton = nullptr;
Singleton* Singleton::GetInstance(const char* name)
{
    if(singleton==nullptr)
    {
        if(strcmp(name,"SingletonA") ==0)
            singleton =new SingletonA();
        else if (strcmp(name,"SingletonB")==0)
            singleton = new SingletonB();
        else
            singleton = new Singleton();
    }
    return singleton;
} 