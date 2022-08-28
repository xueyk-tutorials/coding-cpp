#include <iostream>
#include <string>
using namespace std;


void test01()
{
    string email("xueyuankui.good@163.com");
    cout << email.substr(0, email.find("@")) << endl;

    cout << email.substr(email.find("@")) << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}