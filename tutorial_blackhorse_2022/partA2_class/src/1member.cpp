/**
 * 构造函数
 */
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    int age = 0;
    static string name;
};
string Person::name = "alex";    // 静态成员，类内声明，类外定义

void test01()
{
    // 
    Person p1;
    cout << sizeof(p1) << endl;
}

int main()
{   
    test01();
}

