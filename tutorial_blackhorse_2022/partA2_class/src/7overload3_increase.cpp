/**
 * 运算符重载：输出<<运算符
 */
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int a){
        age = a;
    }
	Person &operator++(){
        ++age;
        return *this;
    }
    Person operator++(int){
        Person tmp = *this;
        age++;
        return tmp;
    }
    int age = 0;
};

void test01()
{
    Person p1(32);
    ++(++p1);
    cout << p1.age << endl;
    Person p2 = p1++;
    cout << p1.age << endl;
    cout << p2.age << endl;
}

int main()
{   
    test01();
}

