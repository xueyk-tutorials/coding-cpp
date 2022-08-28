/**
 * 函数模板
 */
#include <iostream>
using namespace std;


template<typename T>
void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void test01()
{
    int ia = 1;
    int ib = 2;
    mySwap<int>(ia, ib);
    cout << "ia=" << ia << ",ib=" << ib << endl;

    //
    float fa = 1.0;
    float fb = 2.0;
    mySwap<float>(fa, fb);
    cout << "fa=" << fa << ",fb=" << fb << endl;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}