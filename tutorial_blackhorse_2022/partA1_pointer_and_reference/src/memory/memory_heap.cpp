#include <iostream>
#include <string>
using namespace std;


int* fun()
{
    // 指针a是存放到栈区上的，然而指针指向的地址是在堆区
    int *a = new int(10);
    return a;
}

int main(int argc, char *argv[])
{
    int *b = fun();
    cout << *b << endl;
    cout << *b << endl;
    
    return 0;
}

