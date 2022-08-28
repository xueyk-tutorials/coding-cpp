/**
 * 1. 常量引用，主要用来修饰形参，防止误操作
 */
#include <iostream>
#include <string>
using namespace std;


void test01(const int &a)
{
    // val = 200;            // 无法编译成功，故保证了参数只读，避免误操作
    cout << "a=" << a << endl;
}

int main(int argc, char *argv[])
{
    /**
     */
    // int &ref = 10;       // 错误，引用必须引用一块合法的内存空间
    // const int &ref = 10; // 正确，加上const后，编译器重新修改代码为 int tmp=10; const int &ref=tmp;
    // cout << "ref=" << ref << endl;
    // ref = 100;           // 错误，无法编译成功，因为const修饰的常量不可以更改
    
    /**
     */
    int a = 100;
    test01(a);
    
    return 0;
}

