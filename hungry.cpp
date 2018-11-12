#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton* GetInstance()      //接口，获得m_instance的地址
    {
        return &m_instance;
    }
private:
    Singleton() {};
    Singleton(const Singleton& );
    Singleton& operator=(const Singleton&);
    static Singleton m_instance;          //声明成静态变量
};

Singleton Singleton::m_instance;         //定义一个对象

int main()
{
    Singleton* p = Singleton::GetInstance();
    cout << p << endl;
    return 0;
}
