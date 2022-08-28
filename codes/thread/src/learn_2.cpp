/**
 * @brief 创建线程并传入类方法
 * 
 */ 
#include <iostream>
#include <thread>

using namespace std;


class MyClass
{
public:
    MyClass(int cnt) : _cnt(cnt)
    {

    }
    void run1()
    {
        for(int i=0; i<_cnt; ++i)
        {
            cout << "cnt=" << _cnt++ << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        _cnt = 0;
    }
    void run2(int cnt)
    {
        for(int i=0; i<cnt; ++i)
        {
            cout << "cnt=" << cnt++ << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    int _cnt = 0;
};

void test01()
{
    cout << "创建无参函数线程" << endl;
    thread th1(fun_1);


    // 主线程阻塞，等待子线程执行完毕。
    th1.join();
    th2.join();
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
