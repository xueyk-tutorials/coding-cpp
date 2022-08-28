#include <iostream>
#include <string>
using namespace std;


// 全局变量
int g_a = 10;
int g_b = 20;

const int c_g_a = 10;
const int c_g_b = 20;

int main(int argc, char *argv[])
{
    int l_a = 10;
    int l_b = 20;
    static int s_a = 10;
    static int s_b = 20;

    string l_stra = "hello world a";
    string l_strb = "hello world b";

    const char *l_chara = l_stra.c_str();
    char *l_charb = "hello world b";


    cout  << "全局变量g_a的地址：" << &g_a << endl;
    cout  << "全局变量g_b的地址：" << &g_b << endl;
    cout  << "静态变量s_a的地址：" << &s_a << endl;
    cout  << "静态变量s_b的地址：" << &s_b << endl;

    cout  << "常量c_g_a的地址：" << &c_g_a << endl;
    cout  << "常量c_g_b的地址：" << &c_g_b << endl;

    cout  << "字符串常量的地址：" << &"hello world a" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << &l_chara << endl;
    cout << &l_charb << endl;

    cout  << "局部变量l_a的地址：" << &l_a << endl;
    cout  << "局部变量l_b的地址：" << &l_b << endl;

    cout  << "局部字符串变量l_stra的地址：" << &l_stra << endl;
    cout  << "局部字符串变量l_strb的地址：" << &l_strb << endl;


    return 0;
}

