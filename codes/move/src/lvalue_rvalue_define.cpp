/**
 * 左值和右值定义
 */ 
#include <iostream>

int add(int a, int b)
{   
    int c = a + b;
    return c;
}

int test01()
{
    int n = 10, m = 20;
    int sum1 = 0;
    int sum2 = sum1;

    sum1 = n + m;
    sum2 = 100 + 200;
    sum2 = add(n, m);
}
int main(int argc, char *argv[])
{

    return 0;
}