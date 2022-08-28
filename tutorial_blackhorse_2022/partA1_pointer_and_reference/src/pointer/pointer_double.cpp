/**
 * 二级指针
 */

#include <iostream>
#include <string>
using namespace std;

int a = 10;
int b = 100;
int *q;

// void test01(int *p)
// {
//     cout << "test01" << endl;
//     cout << "&p=" << &p << endl;
//     cout << "p=" << p << endl;

//     p = &b;
//     cout << "&p=" << &p << endl;
//     cout << "p=" << p << endl;

// }

void test01(int *p)
{
    p = &b;
}
void test02(int **p)
{
    *p = &b;
}
int main(int argc, char *argv[])
{
    // cout << "--------------------1" << endl;
    // cout << "&a=" << &a << endl;
    // cout << "&b=" << &b << endl;
    // cout << "&q=" << &q << endl;
    // cout << "q=" << q << endl;
    // cout << "--------------------2" << endl;
    // q = &a;
    // cout << "*q=" << *q << endl;
    // cout << "q=" << q << endl;

    // cout << "--------------------3" << endl;
    // test01(q);
    // cout << "--------------------4" << endl;
    // cout << "*q=" << *q << endl;
    // cout << "q=" << q << endl;

    q = &a;
    cout << *q << endl;
    test02(&q);
    cout << *q << endl;
    return 0;
}


