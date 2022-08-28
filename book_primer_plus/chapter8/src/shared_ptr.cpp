#include <iostream>
#include <memory>
using namespace std;

std::shared_ptr<int> g_p;

void show(std::shared_ptr<int> &p, string describe="")
{
    cout << "/****" << describe << "*****/" << endl;
    if(p == nullptr)
    {
        cout << "p is nullptr" << endl;
        return;
    }
    cout << "*p=" << *p << endl;
    cout << "p.use_count()=" << p.use_count() << endl;
    cout << "p指向的地址为: p.get()=" << (int *)(p.get()) << endl;
    cout << "p存放在地址: &p=       " << (int *)(&p) << endl;
}

void fun1_as_param(std::shared_ptr<int> p)
{
    show(p, "as param");
    *p = 999;
}
std::shared_ptr<int> fun1_as_return()
{
    std::shared_ptr<int> p = std::make_shared<int>(777);
    show(p, "as return");
    return p;
}
void fun1_as_return2()
{
    std::shared_ptr<int> p = std::make_shared<int>(200);
    show(p, "as return2");
    *p = 999;
    g_p = p;
}

int fun2_as_return()
{
    int a = 100;
    cout << "&a=" << (int *)(&a) << endl;
    return a;
}
/**
 * 创建动态指针
 */
void test01()
{
    //
    std::shared_ptr<int> p1;
    show(p1, "p1");
    // *p1 = 100;                    //错误，未初始化的动态指针为空，无法实用解引用操作，故不能赋值
    p1 = std::make_shared<int>(100);
    show(p1, "p1");
    //
    std::shared_ptr<int> p2(new int(200));
    show(p2, "p2");
    //
    std::shared_ptr<int> p3(p1);
    *p3 = 200;
    show(p3, "p3");

}

/**
 * 动态指针与函数，作为参数、作为返回值
 */
void test02()
{
    //
    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    fun1_as_param(p1);
    show(p1, "p1");

    //
    std::shared_ptr<int> p2 = fun1_as_return();
    show(p2, "p2");
    //
    fun1_as_return2();
    show(g_p, "g_p");
}

void test03()
{
    int b = fun2_as_return();
    cout << "&b=" << (int *)(&b) << endl;
}
int main(int argc, char *argv[])
{
    // test01();
    test02();
    // test03();
    return 0;
}