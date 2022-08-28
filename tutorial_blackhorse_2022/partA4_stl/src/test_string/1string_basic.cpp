#include <iostream>
#include <string>
using namespace std;


void test01()
{
    string str1;
    string str2("hello world");
    string str3(str2);
    string str4(5, 'h');

    cout << "str1=" << str1 << endl;
    cout << "str2=" << str2 << endl;
    cout << "str3=" << str3 << endl;
    cout << "str4=" << str4 << endl;

}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}