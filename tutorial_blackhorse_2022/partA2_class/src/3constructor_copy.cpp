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
    int age = 0;
    string name = "";
};

// 
void transfer_person(Person p)
{
}

// 返回一个局部变量
Person return_person()
{
    Person p(10);
    cout << "局部变量p的地址为：" << (int *)&p << endl;
    return p;
}
Person return_person2()
{
    Person p;
    cout << p.age << endl;
    cout << "局部变量p的地址为：" << (int *)&p << endl;
    return p;
}
// 返回一个全局变量
Person p;
Person return_person3()
{
    cout << p.age << endl;
    cout << "全局变量p的地址为：" << (int *)&p << endl;
    return p;
}

void test01()
{
    Person p1(20);
    cout << ">>>1" << endl;
    Person p2(p1);
    //
    cout << ">>>2" << endl;
    transfer_person(p2);
    //
    cout << ">>>3" << endl;
    Person p3 = return_person();
    cout << (int *)&p3 << endl;
    cout << "--------------------" << endl;
    Person p4(return_person());
    cout << (int *)&p4 << endl;
}

void test02()
{
    cout << "--------------- test02 ---------------" << endl;
    Person p1;
    cout << ">>>1" << endl;
    Person p2(p1);
    //
    cout << ">>>2" << endl;
    transfer_person(p2);
    //
    cout << "--------------------" << endl;
    cout << ">>>3" << endl;
    Person p3 = return_person2();
    cout << "p3的地址为：" << (int *)&p3 << endl;
    cout << "--------------------" << endl;
    Person p4(return_person2());
    cout << "p4的地址为：" << (int *)&p4 << endl;
}

void test03()
{
    cout << "--------------- test03 ---------------" << endl;
    Person p1 = return_person3();
    cout << "p1的地址为：" << (int *)&p1 << endl;

    p = return_person3();
    cout << "p的地址为：" << (int *)&p << endl;

}
int main()
{   
    // test01();
    test02();
    test03();
}

