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
    cout << "创建线程：" << param << endl;
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
    thread A(fun, "func1");    // 线程A创建后立即运行
    thread B(fun, "func2");    // 线程A创建后立即运行
    
    A.join();                  // 主线程阻塞，等待子线程A执行完毕。
    thread C(fun, "func3");    // A线程执行完毕后，继续执行主线程，创建线程C
    B.join();                  // 阻塞主线程，等待B执行完毕
    C.join();                  // 阻塞主线程，等待B执行完毕
}

void test02()
{
    cout << "成员函数detach()的使用" << endl;
    thread A(fun, "func1");
    thread B(fun, "func2");

    // 不阻塞主线程，子线程A与B在后台运行
    A.detach();
    B.detach();
    // 创建子线程C
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
