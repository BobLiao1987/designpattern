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

//method 1, client need to provide pointer
class Cache
{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(ReplaceAlgorithm* ra){m_ra=ra;}
    ~Cache(){delete m_ra;}
    void Replace(){m_ra->Replace();}
};

int main(int argc, char const *argv[])
{
    Cache cache(new Random_ReplaceAlgorithm());
    cache.Replace();

    return 0;
}

