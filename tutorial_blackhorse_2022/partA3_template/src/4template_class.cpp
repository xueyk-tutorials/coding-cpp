/**
 * 类模板
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


void test01()
{
    Person<string, int> a("alex", 20);
    a.showPerson();

    Person<string> b("bill", 29);
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}