/**
 * 构造函数
 */
#include <iostream>
using namespace std;
class Person
{
public:
	Person(int a){
        age = a;
    }
    Person &addAge(Person b){
        this->age += b.age;
        return *this;
    }

    int age = 0;
};

void test01()
{
    // 
    Person p1(10);
    Person p2(20);
    p2.addAge(p1).addAge(p1);
    cout << "p2.age=" << p2.age << endl;
}

int main()
{   
    test01();
}

