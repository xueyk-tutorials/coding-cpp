#include <iostream>
#include <string>
#include <memory>
#include <functional>


using namespace std;

class Foo
{
public:
    Foo()
    {
        cout << "Foo()" << endl;
    }
    Foo(std::string name)
    {
        cout << "Foo(string name)" << endl;
    }
    ~Foo()
    {
        cout << "~Foo()" << endl;
    }
    void print()
    {
        cout << "Foo::print()" << endl;
    }
};

class Destroyer
{
public:
    void operator()(Foo *foo)                         // 类重载()方法
    {
        cout << "delete foo with Destoryer()" << endl;
        delete foo;
    }
};

void delete_foo(Foo *foo)                             // 函数，用来处理uniqure_ptr
{
    cout << "delete foo with delete_foo()" << endl;
    delete foo;
}

/**
 * @description: unique_ptr构造
 * @return {*}
 * @author: xueyuankui
 */
void test01()
{
    std::unique_ptr<Foo> p1(new Foo());                     // 通过new初始化unique_ptr
    p1->print();

    std::unique_ptr<Foo> p2 = std::make_unique<Foo>();      // C++14及以上版本才支持make_unique
    p2->print();

    //
    std::unique_ptr<Foo> p3;
    p3 = std::move(p2);
    p3->print();

    std::unique_ptr<Foo> p4 = std::make_unique<Foo>(std::string("alex"));
}

/**
 * @description: unique_ptr析构时的处理
 * 
 * 创建unique_ptr对象时，可以传入一个函数，用于处理对象析构时的处理操作
 * 智能指针析构处理方式有：
 * 1. 通过注册一个lambda表达式，用于处理unique_ptr的回收
 * 2. 通过std::bind绑定处理函数
 * 3. 通过伪函数，类()重载运算符进行指针的回收处理
 * 
 * @return {*}
 * @author: xueyuankui
 */
void test02()
{
    using foo_ptr = std::unique_ptr<Foo, std::function<void (Foo *)>>;
    // 方式一：lambda表达式
    foo_ptr p1 = foo_ptr(new Foo(), [](Foo *foo){cout << "delete foo with lamda function" << endl; delete foo;});
    
    // 方式二：std::bind()
    foo_ptr p2 = foo_ptr(new Foo(), std::bind(delete_foo, std::placeholders::_1));

    // 方式三：伪函数
    std::unique_ptr<Foo, Destroyer> p3(new Foo);
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