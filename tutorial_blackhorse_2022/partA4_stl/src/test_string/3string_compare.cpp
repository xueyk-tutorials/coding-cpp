#include <iostream>
#include <string>
using namespace std;


void test01()
{
    string str1("hello world");
    string str2("hello alex");

    cout << str1.compare(string("hello world")) << endl;
    cout << str1.compare(str2) << endl;
    cout << str2.compare(str1) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}