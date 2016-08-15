#include <iostream>
#include <string>
#include <list>

using namespace std;

class Observer
{
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void Update(){}
};
class Blog
{
public:
    Blog(){}
    virtual ~Blog(){}
    void Attach(Observer* observer){m_observer.push_back(observer);}
    void Remove(Observer* observer){m_observer.remove(observer);}
    void Notify()
    {
        for(auto iter = m_observer.begin(); iter!= m_observer.end();iter++)
            (*iter)->Update();
    }
    virtual void SetStatus(string s){m_status = s;}
    virtual string GetStatus(){return m_status;}
private:
    list<Observer*> m_observer;
protected:
    string m_status;
};

class BlogCSDN: public Blog
{
private:
    string m_name;
public:
    BlogCSDN(string name):m_name(name){}
    ~BlogCSDN(){}
    void SetStatus(string s){m_status="CSDN notify"+m_name+s;}
};
class ObserverBlog:public Observer
{
private:
    string m_name;
    Blog *m_blog;
public:
    ObserverBlog(string name, Blog* blog):m_name(name), m_blog(blog){}
    ~ObserverBlog(){}
    void Update()
    {
        string status = m_blog->GetStatus();
        cout<< m_name <<"-------"<<status<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Blog *blog = new BlogCSDN("bobliao");
    Observer *observer = new ObserverBlog("liao",blog);
    blog->Attach(observer);
    blog->SetStatus("update a article about navigation");
    blog->Notify();
    
    delete blog; delete observer;
    return 0;
}