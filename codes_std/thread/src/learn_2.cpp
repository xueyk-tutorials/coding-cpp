/**
 * @brief 在类中创建线程
 *      1. 声明std::thread类型的成员函数
 *      2. 成员函数初始化的几种方法
 */ 
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

using namespace std;

class MyClass
{
public:
    // _thread1作为成员变量，可以在初始化列表中完成初始化
    MyClass(int cnt) : _cnt(cnt), _thread1(std::bind(&MyClass::run1, this))
    {
        _thread1.join();
        // _thread2是通过动态指针创建的
        _thread2 = std::make_shared<std::thread>(std::bind(&MyClass::run2, this, 3));
        _thread2->join();
    }
    ~MyClass()
    {
    }
    void run1()
    {
        for(int i=0; i<_cnt; ++i)
        {
            cout << "run1: cnt=" << _cnt << ", i=" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        _cnt = 0;
    }
    void run2(int cnt)
    {
        for(int i=0; i<cnt; ++i)
        {
            cout << "run2: cnt=" << cnt << ", i=" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    int _cnt = 0;
private:
    std::thread _thread1;
    std::shared_ptr<std::thread> _thread2{};
};

void test01()
{
    MyClass my_class(5);
}


int main(int argc, char *argv[])
{
    test01();
    return 0;
}
