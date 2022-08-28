/**
 * 引用做函数参数
 */
#include <iostream>
#include <string>
using namespace std;


void swap01(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int main(int argc, char *argv[])
{
    int a = 10, b = 20;
    swap01(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    
    return 0;
}

