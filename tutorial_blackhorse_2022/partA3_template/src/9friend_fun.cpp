/**
 * 全局函数作为类模板友元
 * 1. 类内实现全局函数
 * 2. 类外实现全局函数
 */

#include <iostream>
#include <string>
using namespace std;

// 2. 类外实现
// 提前让编译器知道Person类的实现
template<class NameType, class AgeType>
class Person;

// 2. 类外实现
// 这个是模板函数，需要放到声明之前
template<class NameType, class AgeType>
void printPerson2(Person<NameType, AgeType> p)
{
    cout << "友元全局函数，类外实现" << endl;
    cout << "name=" << p.name << endl;
    cout << "age=" << p.age << endl;
}

template<class NameType, class AgeType>
class Person
{
// 1.类内实现
friend void printPerson(Person<NameType, AgeType> p)
{
    cout << "友元全局函数，类内实现" << endl;
    cout << "name=" << p.name << endl;
    cout << "age=" << p.age << endl;
}
// 2. 类外实现
// 加空模板参数列表，这样函数声明和定义才能匹配
// 如果全局函数类外实现，需要让编译器提前知道这个函数的存在，故需要将函数定义放到前面
friend void printPerson2<>(Person<NameType, AgeType> p);

public:
	Person(NameType name, AgeType age){
        this->age = age;
        this->name = name;
    }
private:
    AgeType age = 0;
    NameType name = "";

};

void test01()
{
    Person<string, int> c("charllie", 20);
    printPerson(c);
}

void test02()
{
    Person<string, int> b("bill", 20);
    printPerson2(b);
}

int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}