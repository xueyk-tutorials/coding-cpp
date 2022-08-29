/**
 * @brief 创建线程
 *        1. 传入普通函数，包括无参函数、有参函数
 *        2. 传入类对象方法
 */ 
#include <iostream>
#include <thread>

using namespace std;

void fun(string param)
{   
    int cnt = 5;
    for(int i=0; i<cnt; ++i)
    {
        cout << param << ": cnt=" << cnt << ". i=" << i << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


void test01()
{
    cout << "成员函数join()的使用" << endl;
    thread A(fun, "func1");
    thread B(fun, "func2");

    // 主线程阻塞，等待子线程执行完毕。
    A.join();
    thread C(fun, "func3");
    B.join();
    C.join();
}

void test02()
{
    cout << "成员函数detach()的使用" << endl;
    thread A(fun, "func1");
    thread B(fun, "func2");

    // 主线程阻塞，等待子线程执行完毕。
    A.detach();
    B.detach();
    thread C(fun, "func3");
    C.detach();
}

void test03()
{
    cout << "成员函数detach()不能与join()同时使用" << endl;
    thread A(fun, "func1");
    cout << "detach" << endl;
    A.detach();
    cout << "joinable=" << A.joinable() << endl;
    if(A.joinable())
    {
        cout << "can join" << endl;
        A.join();
    }
    else
    {
        cout << "cannot join" << endl;
    }
}
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "需要提供参数，用来选择要运行的测试函数，参数就是要运行的函数名，例如 ./learn_3 test01" << endl;
        return 0;
    }
    cout << ">>>begin test" << endl;
    std::string param = argv[1];
    if(param == "test01")
    {
        test01();
    }
    else if(param == "test02")
    {
        test02();
    }
    else if(param == "test03")
    {
        test03();
    }
    cout << ">>>end test" << endl;
    cout << ">>>sleep" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    cout << ">>>exit" << endl;
    return 0;
}
