/*
 * @Description: 演示如何创建管理线程对象的智能指针，以及注册回调函数用于线程对象析构时的处理操作
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-09-21 13:03:34
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-09-27 16:46:02
 */

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;


void run()
{
    for(int i=0; i<10; ++i)
    {
        cout << "running cnt" << i << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

class Foo
{
public:
    Foo()
    {
        cout << "Foo()" << endl;
        using thread_ptr = std::unique_ptr<std::thread, std::function<void (std::thread *)>>;
        // 初始化uniqure_ptr：第一个参数是创建一个新的线程，第二个参数是定义回调函数用于线程析构时的处理
        thread_ptr exec_thread = thread_ptr(
            new std::thread([this](){
                cout << "exec thread" << endl;
                this->loop();
            }),
            [this](std::thread *t)
            {
                cout << "thread join" << endl;
                t->join();
                cout << "thread finished" << endl;
                delete t;
            }
        );

        for(int i=0; i<5; ++i)
        {
            cout << "After unique_ptr, at end of constructor: cnt" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    ~Foo()
    {
        cout << "~Foo()" << endl;
    }
    void loop()
    {
        for(int i=0; i<10; ++i)
        {
            cout << "Foo::loop: cnt" << i << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    void print()
    {
        cout << "Foo::print()" << endl;
    }
};


/**
 * @description: 测试示例1，不使用类
 * @return {*}
 * @author: xueyuankui
 */
void test01()
{
    using thread_ptr = std::unique_ptr<std::thread, std::function<void (std::thread *)>>;
    // 初始化uniqure_ptr：第一个参数是创建一个新的线程，第二个参数是定义回调函数用于线程析构时的处理
    thread_ptr exec_thread = thread_ptr(
        new std::thread([](){
            cout << "exec thread" << endl;
            run();
        }),
        [](std::thread *t)
        {
            cout << "thread join" << endl;
            t->join();
            cout << "thread finished" << endl;
            delete t;
        }
    );

    for(int i=0; i<5; ++i)
    {
        cout << "main looping cnt" << i << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
/**
 * @description: 测试示例2，使用类
 * @return {*}
 * @author: xueyuankui
 */
void test02()
{
    Foo foo;
    foo.print();
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "Help:" << std::endl;
        std::cout << "./unique_ptr <test01>" << std::endl;
    }
    else
    {
        std::string fun(argv[1]);
        if(fun == "test01")
        {
            test01();
        }
        else if(fun == "test02")
        {
            test02();
        }
    }
    return 0;
}