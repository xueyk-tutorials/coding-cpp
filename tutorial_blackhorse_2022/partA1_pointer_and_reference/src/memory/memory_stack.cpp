#include <iostream>
#include <string>
using namespace std;

int a = 10;
int* fun_ok()
{
    a = 20;
    return &a;
}
int* fun_error()
{
    int a = 10;
    return &a;
}


int main(int argc, char *argv[])
{
    int *b1;
    b1 = fun_ok();
    cout << *b1 << endl;

    int *b2;
    b2 = fun_error();
    cout << *b2 << endl;

    return 0;
}

