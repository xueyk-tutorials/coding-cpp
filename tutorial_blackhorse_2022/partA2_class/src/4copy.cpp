/**
 * 构造函数
 */
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    // 无参构造
	Person(){
    }
    // 有参构造
	Person(int a, string  addr){
        age = a;
        address = new string(addr);
    }
    // 拷贝构造
    Person(const Person &p){
        age = p.age;
        address = new string(*(p.address));    //重新手动申请堆区内存
    }

    int age = 0;
    string *address;
};

void test01()
{
    // 
    Person p1(10, "china");
    Person p2(p1);

    cout << "p1:" << (int *)p1.address << " " << *(p1.address) << endl;
    cout << "p2:" << (int *)p2.address << " " << *(p2.address) << endl;
}

int main()
{   
    test01();
}

