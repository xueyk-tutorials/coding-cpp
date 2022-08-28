/**
 * 类模板对象作为参数
 */
#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age){
        this->age = age;
        this->name = name;
    }
    void showPerson()
    {
        cout << "name=" << name << endl;
        cout << "age=" << age << endl;
    }
    AgeType age = 0;
    NameType name = "";

};

//1、直接显式对象的数据类型
void printFunc1(Person<string, int> p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> a("alex", 20);
    printFunc1(a);
}
//2、 使用模板函数，将对象中的参数变为模板进行传递
template<class NameType, class AgeType>
void printFunc2(Person<NameType, AgeType> p)
{
    p.showPerson();
    cout << "NameType=" << typeid(NameType).name() << endl;
    cout << "AgeType=" << typeid(AgeType).name() << endl;
}
void test02()
{
    Person<string, int> b("bill", 20);
    printFunc2<string, int>(b);
}
//3、使用模板函数，将这个对象类型模板化进行传递
template<class T>
void printFunc3(T &p)
{
    p.showPerson();
}
void test03()
{
    Person<string, int> c("charllie", 20);
    printFunc3(c);
}
int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();
    return 0;
}