/**
 * 运算符重载：加法运算符
 * 1. 类成员函数运算符重载
 * 2. 全局函数运算符重载
 */
#include <iostream>
using namespace std;
class Person
{
public:
    Person(){

    }
	Person(int a){
        age = a;
    }
    // 类成员函数运算符重载（代码不能与全局函数重载同时存在，二者其一进行注释）
    Person operator+(Person p)
    {
        Person tmp;
        tmp.age = this->age + p.age;
        return tmp;
    }

    int age = 0;
};

/*
 * 全局函数运算符重载（代码不能与类成员函数重载同时存在，二者其一进行注释）
 */
// Person operator+(Person p1, Person p2)
// {
//     Person tmp;
//     tmp.age = p1.age + p2.age;
//     return tmp;
// }

void test01()
{
    // 1. 类成员函数运算符重载
    Person p1(10);
    Person p2(20);
    Person p3 = p1.operator+(p2); // 等价于
    // Person p3 = p1 + p2;     
    cout << p3.age << endl;

    // 2. 全局函数运算符重载（取消对应注释）
    // Person p4 = operator+(p1, p2);
    // Person p4 = p1 + p2;
    // cout << p4.age << endl;
}

int main()
{   
    test01();
}

