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
    int &b = a;

    cout << "before" << endl;
    cout << b << endl;
    cout << a << endl;

    cout << "after" << endl;
    b = 20;
    cout << b << endl;
    cout << a << endl;
}

int main(int argc, char *argv[])
{
    test01();
    
    return 0;
}

