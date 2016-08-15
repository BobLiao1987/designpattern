#include <iostream>
using namespace std;

class ReplaceAlgorithm
{
public:
    virtual void Replace()=0;
};
class LRU_ReplaceAlgorithm:public ReplaceAlgorithm
{
public:
    void Replace(){cout<<"LRU replace algorithms"<<endl;}
};
class FIFO_ReplaceAlgorithm:public ReplaceAlgorithm
{
public:
    void Replace(){cout<<"FIFO replace algorithms" <<endl;}
};
class Random_ReplaceAlgorithm:public ReplaceAlgorithm
{
public:
    void Replace(){cout<<"Random replace algorithms"<<endl;}
};

template<class RA>
class Cache
{
private:
    RA m_ra;
public:
    Cache(){}
    ~Cache(){}
    void Replace(){m_ra.Replace();}
};

int main(int argc, char const *argv[])
{
    Cache<LRU_ReplaceAlgorithm> cache;
    cache.Replace();
    return 0;
}