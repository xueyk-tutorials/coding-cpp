/**
 * 
 */
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
    /**
     *
     */
    int a = 10;
    int *p;
    p = &a;
    cout << "a的地址:" << &a << endl;
    cout << "p=" << p << endl;
    
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;

    int b = 20;
    cout << "b的地址：" << &b << endl;  // 提前运行一遍，把地址记下来
    
    int *p2 = (int *)0x7ffe8dca4a2c;    //c++不允许对指针直接赋值一个内存地址，即使使用记录的地址赋值
    cout << "*p2=" << *p2 << endl;

    /**
     *
     */
    cout << "指针指向的值所占空间：" << sizeof(*p) << endl;
    cout << "指针所占空间:" << sizeof(p) << endl;
    cout << "int指针所占空间:" << sizeof(int *) << endl;
    cout << "double指针所占空间:" << sizeof(double *) << endl;

    /**
     *
     */
    // int *p2 = (int*)0xf350;    // 错误，指向非法空间，这个空间没有事先申请
    // cout << *p2 << end;
    return 0;
}

