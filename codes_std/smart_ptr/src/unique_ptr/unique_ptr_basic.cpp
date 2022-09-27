#include <cstdio>
#include <iostream>
#include <string>
#include <memory>

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

/**
 * @description: unique_ptr构造
 * 
 * std::unique_ptr<T> ptr(new T())
 * std::unique_ptr<T> ptr = std::make_unique<T>()
 * 
 * @return {*}
 * @author: xueyuankui
 */
void test01()
{
    cout << "************************* unique_ptr构造:使用内置类型 *************************" << endl;
    std::unique_ptr<int> up_age(new int(10));                            // 通过new初始化
    std::unique_ptr<int> up_age2 = std::make_unique<int>(10);            // c++14后支持make_unique
    cout << "*up_age=" << *up_age << endl;

    // 由于unique_ptr所有权是唯一的，故无法两个unique_ptr管理同一个对象！只能move
    cout << "before move up_age: " << up_age.get() << endl;
    std::unique_ptr<int> up_age3(std::move(up_age));
    cout << "after move up_age:" << up_age.get() << ", up_age3:" << up_age3.get() << endl;

    // unique_ptr可以与普通指针共同指向同一个地址！
    int *p_age2 = up_age2.get();
    cout << "地址up_age2:" << up_age2.get() << ", p_age2:" << p_age2 << endl;
    cout << "*up_age2=" << *up_age2 << endl;                    // *up_age=10, p_age=10
    cout << "*p_age2= " << *p_age2 << endl;
    *p_age2 = 100;                                              // 更改普通指针也就更改了unique_ptr指向的对象
    cout << "*up_age2=" << *up_age2 << endl;                    // *up_age=100, p_age=100
    cout << "*p_age2= " << *p_age2 << endl;
    *up_age2 = 200;                                             // 更改unique_ptr也就更改了普通指针指向的对象
    cout << "*up_age2=" << *up_age2 << endl;                    // *up_age=200, p_age=200
    cout << "*p_age2= " << *p_age2 << endl;

    cout << "************************* unique_ptr构造:使用自定义类类型 *************************" << endl;
    std::unique_ptr<Foo> up_foo(new Foo);
    std::unique_ptr<Foo> up_foo2 = std::move(up_foo);

    // 函数结束后，对所有unique_ptr对象进行析构处理，按照由后到前的顺序进行。
    // unique_ptr对象的析构时会自动对其管理的对象进行析构，up_foo2析构时会对up_foo对象进行析构，调用~Foo函数
    cout << "test01 end" << endl;
}


/**
 * @description: unique_ptr成员函数
 * @return {*}
 * @author: xueyuankui
 */
void test02()
{

}
int main(int argc, char *argv[])
{
    test01();
    // if(argc < 2)
    // {
    //     std::cout << "Help:" << std::endl;
    //     std::cout << "./unique_ptr_basic <test01>" << std::endl;
    // }
    // else
    // {
    //     std::string fun(argv[1]);
    //     if(fun == "test01")
    //     {
    //         test01();
    //     }
    //     else if(fun == "test02")
    //     {
    //         test02();
    //     }
    // }
    return 0;
}