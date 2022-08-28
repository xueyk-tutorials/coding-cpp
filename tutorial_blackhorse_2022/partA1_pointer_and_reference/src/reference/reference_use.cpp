/**
 * 1. new的基本语法
 * 2. 创建一个变量
 * 3. 创建一个数组
 */
#include <iostream>
#include <string>
using namespace std;


void test01()
{
    int a = 100;
    int b = 200;
    
    // int &c;       // 错误，必须初始化！
    int &c = a;

    c = b;           // 赋值操作，而不是更改引用

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;

}

int main(int argc, char *argv[])
{
    test01();
    
    return 0;
}

