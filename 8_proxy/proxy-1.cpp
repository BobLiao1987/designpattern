#include <iostream>
#include <string>
using namespace std;

class Image
{
public:
    Image(string name):m_imageName(name){}
    virtual ~Image(){}
    virtual void Show(){}
protected:
    string m_imageName;
};

class BigImage:public Image
{
public:
    BigImage(string name):Image(name){}
    ~BigImage(){}
    void Show(){cout<< "Show big image: "<< m_imageName<<endl;}
};

class BigImageProxy:public Image
{
private:
    BigImage *m_bigImage;
public:
    BigImageProxy(string name):Image(name),m_bigImage(nullptr){}
    ~BigImageProxy()
    {
        if(m_bigImage!=nullptr)
            delete m_bigImage;
    }
    void Show()
    {
        if(m_bigImage==nullptr)
            m_bigImage = new BigImage(m_imageName);
        m_bigImage->Show();
    }
};

int main(int argc, char const *argv[])
{
    Image *image= new BigImageProxy("proxy.jpg");
    image->Show();
    delete image;
    
    return 0;
}