/**
 * 重载
 */
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(int a, string n){
        age = a;
        name = n;
    }
    int age = 0;
    string name = "";
};

template<class T>
bool myEqual(T a, T b)
{
    if (a == b){
        return true;
    }
    else{
        return false;
    }
}
template<> bool myEqual(Person a, Person b)
{
    if (a.age == b.age && a.name == b.name){
        return true;
    }
    else{
        return false;
    }
}

void test01()
{
    Person a(10, "alex");
    Person b(20, "alex");
    cout << myEqual(a, b) << endl;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}