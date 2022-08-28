/**
 * 构造函数
 */
#include <iostream>
using namespace std;
class Person
{
public:
    // 无参构造
	Person(){
        cout << "无参构造" << endl;
    }
    // 有参构造
	Person(int a){
        cout << "有参构造" << endl;
        age = a;
    }
    // 拷贝构造
    Person(const Person &p){
        age = p.age;
        cout << "拷贝构造" << endl;
    }
    // 委托构造
    Person(int a, string n) : Person(a){
        cout << "委托构造" << endl;
    }
private:
    int age = 0;
    string name = "";
};

void test01()
{
    // 
    Person p;                // 无参构造函数不要带()，否则就是声明了一个函数
    // 1. 括号法
    cout << "---------------括号法" << endl;
    Person p1(10);           // 有参构造函数调用
    Person p2(p1);
    cout << "调用委托构造》》》" << endl;
    Person p3(10, "alex");   // 委托构造函数调用

    // 2. 显示法调用
    cout << "---------------显示法" << endl;
    Person p4 = Person(10);  // 其中Person(10)为匿名对象，创建后会立即销毁
    // Person(p4)            // 但不要利用拷贝构造函数初始化匿名对象，因为Person(p4)等价于Person p4
    Person p5 = Person(p4);  // 

    // 3. 隐式法
    cout << "---------------隐式法" << endl;
    Person p6 = 10;          // 相当于Person p5 = Person(10)，由编译器进行隐式转换
    Person p7 = p1;    
}

int main()
{   
    test01();
}

