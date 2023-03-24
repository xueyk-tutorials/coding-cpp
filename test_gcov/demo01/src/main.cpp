#include <iostream>
#include <functional>

using namespace std;

void fun(){
    cout << "fun()" << endl;
}

void test01(){
    cout << "test01" << endl;

    std::function<void()> f = fun;
    f();
}

int main(int argc, char *argv[]){
    cout << "test gcov" << endl;
    test01();
    return 0;
}