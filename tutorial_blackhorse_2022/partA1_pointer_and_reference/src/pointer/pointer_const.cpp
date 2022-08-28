/**
 * 
 */
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
    int a = 10;
    int b = 20;
    /**
     * const修饰常量，常量指针
     * 指针指向的值无法更改，指针的指向可以更改
     */
    // const int *p1 = &a;
    // p1 = &b;         // 正确
    // *p1 = 100;       // 错误

    /**
     * const修饰指针，指针常量
     * 无法更改指针的指向，但指针指向的值可以更改
     */
    // int *const p2 = &a;
    // p2 = &b;         // 错误
    // *p2 = 100;       // 正确

    /**
     * const修饰二者
     * 无法更改指针的指向，也无法更改指针指向的值
     */
    const int *const p3 = &a;

    return 0;
}

