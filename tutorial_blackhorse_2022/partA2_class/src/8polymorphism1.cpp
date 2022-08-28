/**
 * 多态
 */
#include <iostream>
#include <string>
using namespace std;

class Vechile1
{
public:
    void move()
    {
        cout << "Vechile1 move" << endl;
    }
};
class Vechile2
{
public:
    virtual void move()
    {
        cout << "Vechile2 move" << endl;
    }
};

void test01()
{
    // 
    Vechile1 v1;                  // 由于没有非静态成员变量，故大小为1
    Vechile2 v2;                  // 由于有虚函数，故编译器添加一个vfptr指针成员变量，大小为4或8
    cout << sizeof(v1) << endl;
    cout << sizeof(v2) << endl;
}

int main()
{   
    test01();
}

