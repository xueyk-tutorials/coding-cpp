/**
 * 1. new的基本语法
 * 2. 创建一个变量
 * 3. 创建一个数组
 */
#include <iostream>
#include <string>
using namespace std;


int* fun()
{
    // 指针a是存放到栈区上的，然而指针指向的地址是在堆区
    int *p = new int(10);
    return p;
}

void test01()
{
    int *b = fun();
    cout << *b << endl;
    cout << *b << endl;
    cout << *b << endl;

    delete b;
    cout << *b << endl;
}

void test02()
{
    int *arr = new int[10];   // 创建一个10个int成员的数组
    for(int i=0; i<10; ++i)
    {
        arr[i] = i + 100;
    }
    for(int i=0; i<10; ++i)
    {
        cout << arr[i] << endl;
    }
    // 释放数组
    delete[] arr;
}

int main(int argc, char *argv[])
{
    // test01();
    test02();
    
    return 0;
}

