/**
 * 类模板中成员函数的创建时机
 */
#include <iostream>
#include <string>
using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1" << endl;
    }
};
class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2" << endl;
    }
};

template<class T>
class MyClass
{
public:
    T obj;
    // 类模板中的成员函数在被调用时才会创建！
    void func1()
    {
        obj.showPerson1();
    }
    
    void func2()
    {
        obj.showPerson2();
    }
};

void test01()
{
    MyClass<Person1> p1;
    p1.func1();
    MyClass<Person2> p2;
    p2.func2();
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}