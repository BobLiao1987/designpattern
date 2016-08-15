#include<iostream>
using namespace std;

class  Scanner
{
public:
    void Scan(){cout<<"word analysis"<<endl;}
};
class Parser
{
public:
    void Parse(){cout<<"stem analysis"<<endl;}
};
class GenMidCode
{
public:
    void GenCode(){cout<<"generate middle code"<<endl;}
};
class GenMachineCode
{
public:
    void GenCode(){cout<<"generate machine code"<<endl;}
};

class Compiler
{
public:
    void Run()
    {
        Scanner scanner;
        Parser parser;
        GenMidCode genmidcode;
        GenMachineCode genmachcode;

        scanner.Scan();
        parser.Parse();
        genmidcode.GenCode();
        genmachcode.GenCode();
    }
};

int main(int argc, char const *argv[])
{
    Compiler compiler;
    compiler.Run();

    return 0;
}
