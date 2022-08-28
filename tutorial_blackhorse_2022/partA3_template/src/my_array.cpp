#include <iostream>
#include "myArray.hpp"
using namespace std;

void test01()
{
    myArray<int> my_array(10);
    my_array.pushBack(1);
    my_array.pushBack(2);
    cout << my_array.getSize() << endl;
    cout << my_array[0] << endl;
    cout << my_array << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}


