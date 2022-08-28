/*
 * @Description: 
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-08-18 09:56:14
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-08-18 10:11:16
 */

#include <iostream>
using namespace std;

class AddNum
{
public:
    AddNum(int num) : _num(num)
    {

    }
    /**
     * 成员函数
     */ 
    int add(int x)
    {
        return x + _num;
    }
    /**
     * 仿函数：重载()运算符，使该类可以像调用函数一样被使用
     */ 
    int operator()(int x)
    {
        return x + _num;
    }
private:
    int _num;
};

/**
 * 使用类中的成员函数、()运算符
 */ 
void test01()
{
    AddNum addNum(5);
    int result1 = addNum.add(10);    
    cout << "使用成员函数：" << result1 << endl;

    int result2 = addNum(18);
    cout << "使用()运算符：" << result2 << endl;
}

/**
 * 使用lambda函数，没有函数名，只有函数体。本质上就是一个类，且重载了()运算符。
 */ 
void test02()
{
    int num1 = 1;
    auto f1 = [num1](int x){return num1 + x;};     //捕获列表[]中使用已定义的变量
    auto f2 = [num2=2](int x){return num2 + x;};     //捕获列表[]中使用未定义的变量并赋初值，该变量类型由编译器自动推断

    int result1 = f1(10);
    cout << "使用lambda函数1：" << result1 << endl;
    int result2 = f2(10);
    cout << "使用lambda函数2：" << result2 << endl;

}
int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}