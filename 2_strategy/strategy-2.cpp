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

//method 2, client need to provide enum name
enum RA {LRU,FIFO,RANDOM};
class Cache
{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(enum RA ra)
    {
        if (ra==LRU)
        {
            m_ra = new LRU_ReplaceAlgorithm();
        }
        else if (ra==FIFO)
        {
            m_ra = new FIFO_ReplaceAlgorithm();

        }
        else if(ra==RANDOM)
        {
            m_ra = new Random_ReplaceAlgorithm();
        }
        else
        {
            m_ra=nullptr;
        }
    }
    ~Cache(){delete m_ra;}
    void Replace(){m_ra->Replace();}
};

int main(int argc, char const *argv[])
{
    Cache cache(FIFO);
    cache.Replace();

    return 0;
}


