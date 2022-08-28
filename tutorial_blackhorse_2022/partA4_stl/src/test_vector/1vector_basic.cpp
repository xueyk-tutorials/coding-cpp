#include <iostream>
#include <vector>
using namespace std;


void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 遍历方式一：
    // cout << "遍历方式一" << endl;
    // it存放的就是一个成员指针
    // for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
    // {
    //     cout << *it << endl;
    // }
    
    // 遍历方式二：
    cout << "遍历方式二" << endl;
    for(auto it : v)
    {
        cout << it << endl;
    }
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}