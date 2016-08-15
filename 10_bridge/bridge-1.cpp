#include <iostream>
using namespace std;

class OS
{
public:
    virtual void InstallOS_Imp(){}
};
class WindowOS: public OS
{
public:
    void InstallOS_Imp(){cout<<"install woindows os"<<endl;}
};

class LinuxOS: public OS
{
public:
    void InstallOS_Imp(){cout<<"install linux os"<<endl;}
};
class UnixOS: public OS
{
public:
    void InstallOS_Imp(){cout<<"install Unix os"<<endl;}
};

class computer
{
public:
    virtual void InstallOS(OS *os){}
};
class DellComputer:public computer
{
public:
    virtual void InstallOS(OS *os){os->InstallOS_Imp();}
};

class AppleComputer:public computer
{
public:
    virtual void InstallOS(OS *os){os->InstallOS_Imp();}
};

class HPComputer:public computer
{
public:
    virtual void InstallOS(OS *os){os->InstallOS_Imp();}
};

int main(int argc, char const *argv[])
{
    OS *os1 = new WindowOS();
    OS *os2 = new LinuxOS();

    computer *computer1 = new AppleComputer();
    computer1->InstallOS(os1);
    computer1->InstallOS(os2);

    return 0;
}