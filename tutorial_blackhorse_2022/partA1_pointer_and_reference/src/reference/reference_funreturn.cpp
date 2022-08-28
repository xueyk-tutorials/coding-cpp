/**
 * 引用做函数返回值
 * 1. 不要返回局部变量的引用
 * 2. 函数的调用可以做左值
 */
#include <iostream>
#include <string>
using namespace std;


int& test01()
{
    int a = 10;
    return a;
}

int& test02()
{
    static int a = 10;       // 静态变量，全局区
    return a;
}

int main(int argc, char *argv[])
{
    /**
     * 
     */
    // int &ref = test01();
    // cout << "ref=" << ref << endl;        // 会造成Segmentation fault错误
    /**
     *
     */
    int &ref2 = test02();
    cout << "ref2=" << ref2 << endl;

    test02() = 1000;                        // 作为左值
    cout << "ref2=" << ref2 << endl;
    return 0;
}

