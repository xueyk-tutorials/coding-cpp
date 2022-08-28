/**
 * @brief 创建线程
 *        1. 传入普通函数，包括无参函数、有参函数
 *        2. 传入类对象方法
 */ 
#include <iostream>
#include <thread>

using namespace std;

void fun_1()
{
    cout << "子线程中显示子线程id为" << this_thread::get_id()<< endl;
    cout << "这个是fun_1()，无参函数" << endl;
}

void fun_2(int a)
{
    cout << "子线程中显示子线程id为" << this_thread::get_id()<< endl;
    cout << "这个是fun_2()，有参函数" << endl;
    cout << "参数 a=" << a << endl;
}

class MyClass
{
public:
    MyClass(int cnt=5) : _cnt_1(cnt), _cnt_2(cnt)
    {

    }
    void run1()
    {
        for(int i=0; i<_cnt_1; ++i)
        {
            cout << "无参成员函数: _cnt_1=" << _cnt_1 << ". i=" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        _cnt_1 = 0;
    }
    void run2(int cnt)
    {
        for(int i=0; i<cnt; ++i)
        {
            cout << "有参成员函数: cnt=" << cnt << ". i=" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    void operator()()
    {
        for(int i=0; i<_cnt_2; ++i)
        {
            cout << "伪函数: _cnt_2=" << _cnt_2 << ". i=" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }        
        _cnt_2 = 0;
    }
    //
    int _cnt_1 = 0;
    int _cnt_2 = 0;
};

void test01()
{
    cout << "创建无参函数线程" << endl;
    thread th1(fun_1);
    cout << "主线程中显示子线程id为" << th1.get_id() << endl;

    cout << "创建有参函数线程" << endl;
    thread th2(fun_2, 100);

    // 主线程阻塞，等待子线程执行完毕。
    th1.join();
    th2.join();
}

void test02()
{
    MyClass alex(3);
    MyClass bill;
    MyClass charllie(7);

    thread th1(&MyClass::run1, &alex);    // 无参成员函数
    th1.join();

    thread th2(&MyClass::run2, &bill, 3); // 有参成员函数
    th2.join();

    thread th3(std::ref(charllie));       // 运行operator()
    th3.join();
}

int main(int argc, char *argv[])
{
    // test01();
    test02();
    return 0;
}
