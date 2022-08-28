#include <iostream>
#include <string>
using namespace std;


void test01()
{
    string str1("hello world");
    cout << string::npos << endl;

    cout << "查找" << endl;
    cout << str1.find("wor") << endl;
    cout << str1.find(string("ll")) << endl;

    cout << str1.find("l") << endl;

    //
    cout << str1.rfind("l") << endl;
    cout << str1.rfind("l", 1) << endl;
    cout << str1.rfind("l", 2) << endl;
    cout << str1.rfind("l", 5) << endl;

    cout << "替换" << endl;
    cout << str1.replace(6, 2, "123") << endl;
    // cout << str1.replace(6, 4, "123") << endl;
    // cout << str1.replace(str1.find("wo"), 4, "123") << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}