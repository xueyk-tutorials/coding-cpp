/**
 * 调用规则 
 */
#include <iostream>
using namespace std;

void mySwap(int &a, int &b)
{
    cout << "调用普通函数" << endl;
}

template<typename T>
void mySwap(T &a, T &b)
{
    cout << "调用模板函数" << endl;
}

template<typename T>
void mySwap(T &a, T &b, T &c)
{
    cout << "调用重载的模板函数" << endl;
}
void test01()
{
    int ia = 1;
    int ib = 2;
    int ic = 3;
    mySwap(ia, ib);        // 优先调用普通函数
    mySwap<>(ia, ib);      // 空模板参数，调用模板函数
    mySwap<int>(ia, ib);   // 显示指定调用模板函数
    mySwap(ia, ib, ic);    // 模板重载

    char ca = 'a';
    char cb = 'b';
    mySwap(ca, cb);       // 模板函数参数匹配度更高，故调用模板函数。虽然没有显式给定数据类型，但这里编译器使用自动类型推导，而如果使用普通函数则需要隐式转换。
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}