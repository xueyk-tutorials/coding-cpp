/**
 * 运算符重载：输出<<运算符
 */
#include <iostream>
using namespace std;

class Person
{
friend ostream &operator<<(ostream &out, Person p);   // 只有友元才能访问私有成员变量
public:
    Person(){
    }
	Person(int a, string n){
        age = a;
        name = n;
    }
private:
    int age = 0;
    string name = "";
};

ostream &operator<<(ostream &out, Person p)         // 只有全局函数重载，才能实现cout在<<左边
{
    out << "age=" << p.age << ",name=" << p.name << endl;
    return out;                                     // 只有返回流引用，才能实现运算符级联操作
}


void test01()
{
    Person p1(32, "alex");
    cout << p1 << endl;
}

int main()
{   
    test01();
}

