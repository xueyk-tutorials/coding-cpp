/*
 * @Description: 本示例给出创建类时什么时候需要使用enable_shared_from_this，以及为什么！
 * 
 * 控制块的概念：
 * 通过指针初始化智能指针时会创建一个新的控制块，std::shared_ptr<T>(new T())，该控制块记录着到底有多少智能指针指向该对象，当没有智能指针指向该对象时，该对象就被销毁。
 * 
 * 1）使用enable_shared_from_this的必要性：
 * 在类函数中，如果返回一个智能指针 return std::shared_ptr<T>(this)，会创建一个新的控制块！
 * 如果已经存在一个智能指针指向该对象并且存在一个控制块时，这个返回操作会造成有两个控制块分别管理两个不同智能指针，且该两个智能指针指向同一个对象！
 * 那么两个智能指针被回收时，都会触发销毁同一个对象！造成内存错误！
 * 
 * 2）什么时候需要使用
 * 当类中有成员函数返回指向对象智能指针时。
 * 
 * 3）解决方法
 * 使用shared_from_this()代替return std::shared_ptr<T>(this)
 * 
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-10-06 22:30:44
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-10-06 22:38:04
 */
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Foo
{
public:
    Foo()
    {
        cout << "Foo" << endl;
    }
    ~Foo()
    {
        cout << "~Foo" << endl;
    }
    string info;
    void print()
    {
        cout << "info=" << info << endl;
    }

    std::shared_ptr<Foo> get_ptr()
    {
        // 使用this指针初始化智能指针，会造成新的控制块被创建！！！
        std::shared_ptr<Foo> p_self = std::shared_ptr<Foo>(this);
        return p_self;
    }
};
/**
 * @description: 一个控制块管理两个智能指针，只有两个智能指针都被回收时才销毁对象
 * @return {*}
 * @author: xueyuankui
 */
void test01()
{
    cout << "---------------------- test01 ----------------------" << endl;
    // Foo foo;
    // foo.info = "foo";
    // std::shared_ptr<Foo> p1 = std::make_shared<Foo>();
    std::shared_ptr<Foo> p1(new Foo());                   // 通过new创建对象指针来初始化智能指针会创建一个控制块(这个控制块记录着到底有多少个智能指针指向该对象)
    cout << "p1.use_count()=" << p1.use_count() << endl;

    // 创建一个新的智能指针，两个智能指针都指向同一个对象，且两个智能指针使用同一个控制块
    cout << "create a new shared_ptr" << endl;
    std::shared_ptr<Foo> p2 = p1;
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为2
    cout << "p2.use_count()=" << p2.use_count() << endl;  // 计数为2，p1和p2关联到同一个控制块

    // 重置p1
    cout << "reset p1" << endl;
    p1.reset();
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为0，对p1进行回收处理
    cout << "p2.use_count()=" << p2.use_count() << endl;  // 计数为1，然而不会销毁foo，因为控制块显示p2还指向它
    
    // 重置p2
    cout << "reset p2" << endl;
    p2.reset();                                           // 指向foo的智能指针都进行了析构回收，控制块显示无智能指针指向foo，对foo进行销毁
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为0
    cout << "p2.use_count()=" << p2.use_count() << endl;  // 计数为0
    cout << "---------------------- test01 end ----------------------" << endl;
}

/**
 * @description: 两个控制块管理两个智能指针，两个智能指针回收时都会触发销毁对象，造成同一个对象被销毁两次，会引发错误“free(): double free detected in tcache 2”
 * @return {*}
 * @author: xueyuankui
 */
void test02()
{
    cout << "---------------------- test02 ----------------------" << endl;
    // Foo foo;
    // foo.info = "foo";
    // 创建智能指针，且会创建第一个控制块
    // std::shared_ptr<Foo> p1 = std::make_shared<Foo>(foo);
    std::shared_ptr<Foo> p1(new Foo());
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为1

    // get_ptr中返回一个新的智能指针，同时创建了第二个控制块！现在有两个控制块管理着同一个对象！
    std::shared_ptr<Foo> p2 = p1->get_ptr();
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为1，p1关联第一个控制块，故其计数为1
    cout << "p2.use_count()=" << p2.use_count() << endl;  // 计数为1，p2关联第二个控制块，故其计数也为1，两个控制块互相没有联系

    //
    p1->info = "p1 object";
    p1->print();
    p2->print();                // p2打印出的内容与p1一样，这是因为p1与p2指向同一个对象

    // 重置p1
    cout << "reset p1" << endl;
    p1.reset();                // p1回收后，第一个控制块显示没有指向foo的智能指针了，foo被销毁
    cout << "p1.use_count()=" << p1.use_count() << endl;
    cout << "p2.use_count()=" << p2.use_count() << endl;

    // 重置p2
    cout << "reset p2" << endl;
    p2.reset();                 // p2回收后，第二个控制块又显示没有指向foo的智能指针了，再次触发销毁foo的操作！造成重复销毁！！！内存出错！！！

    cout << "---------------------- test02 end ----------------------" << endl;

}

/**
 * @description: 使用enable_shared_from_this，不再会造成重复销毁对象的问题
 * 注意，继承时必须使用public
 * @return {*}
 * @author: xueyuankui
 */
class FooEnable : public std::enable_shared_from_this<FooEnable>
{
public:
    FooEnable()
    {
        cout << "FooEnable" << endl;
    }
    ~FooEnable()
    {
        cout << "~FooEnable" << endl;
    }
    string info;
    void print()
    {
        cout << "info=" << info << endl;
    }

    std::shared_ptr<FooEnable> get_ptr()
    {
        // 通过shared_from_this去查找哪个控制块在管理对象本身，不再创建新的控制块了
        // std::shared_ptr<FooEnable> p_self = shared_from_this();
        return shared_from_this();
    }
};

void test03()
{
    cout << "---------------------- test03 ----------------------" << endl;
    std::shared_ptr<FooEnable> p1(new FooEnable());
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为1

    std::shared_ptr<FooEnable> p2 = p1->get_ptr();
    cout << "p1.use_count()=" << p1.use_count() << endl;  // 计数为2
    cout << "p2.use_count()=" << p2.use_count() << endl;  // 计数为2，p1和p2关联同一个控制块


    cout << "reset p1" << endl;
    p1.reset();                                           // 回收p1，暂不销毁对象，因为控制块显示还有p2指向该对象
    cout << "reset p2" << endl;
    p2.reset();                                           // 销毁对象foo
    cout << "---------------------- test03 end ----------------------" << endl;
}

int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();
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