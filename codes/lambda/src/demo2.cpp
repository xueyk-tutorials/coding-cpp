/*
 * @Description: 
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-08-18 09:56:14
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-08-18 10:38:17
 */

#include <iostream>
using namespace std;

/**
 * 使用类中的成员函数、()运算符
 */ 
void test01()
{
    int num1 = 1;
    using FuncPtr1 = void(*)(int);

    FuncPtr1 f1 = [](int x){ cout << "x=" << x << endl;};
    auto f2 = [](int x){ cout << "x=" << x << endl;};

    f1(10);
    cout << "typeid(f1):" << typeid(f1).name() << endl;
    cout << "typeid(f2):" << typeid(f2).name() << endl;
    
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}