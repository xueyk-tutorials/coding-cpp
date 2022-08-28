/**
 * 构造函数
 */
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    // 初始化顺序是根据成员变量声明顺序，先age，再height
	Person(int a, int h, string n) : height(h), age(a), name(n){

    }

    int age;
    int height;        // 引用无法在构造函数体内初始化，只能在初始化列表中进行初始化
    const string name;  // 常量无法在构造函数体内初始化，只能在初始化列表中进行初始化
};

void test01()
{
    // 
    int a = 10;
    int &b = a;
    Person p1(10, 178, "alex");
}

int main()
{   
    test01();
}

