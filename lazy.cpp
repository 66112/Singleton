#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
public:
    static Singleton* GetInstance()      //接口，获得m_pinstance的地址
    {
        if(nullptr == m_pinstance){      //提高效率，一旦不为空，就不用上锁了
            m_mtx.lock();       //锁
            if(nullptr == m_pinstance){   //防止多线程通过锁后，创建多个对象
                m_pinstance = new Singleton();
            }
            m_mtx.unlock();     //V操作
        }
        return m_pinstance;
    }
    //内嵌垃圾回收
    class CGrbo{
    public:
        ~CGrbo(){
            if(Singleton::m_pinstance){
                delete Singleton::m_pinstance;
                cout <<"i will go" << endl;
            }
        }
    };
    static CGrbo Garbo;    //只是声明，并不是定义

private:
    Singleton() {};
    Singleton(const Singleton& );
    Singleton& operator=(const Singleton&);
    static Singleton* m_pinstance;          //声明单例对象指针
    static mutex m_mtx;         //互斥锁
};

Singleton* Singleton::m_pinstance = nullptr;         //定义一个单例对象指针
mutex Singleton::m_mtx;                 //定义一个锁
Singleton::CGrbo Garbo;               //定义一个内部类对象,待进程结束后，调用析构函数释放单例对象,必须有


int main()
{
    Singleton* p=Singleton::GetInstance();
    cout << p << endl;
    return 0;
}
