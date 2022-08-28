#include <iostream>
#include <vector>
using namespace std;

// 判断vector发生了多少次动态内存扩展
void test01()
{
    vector<int> v;
    // v.reserve(100000);              // 如果没有进行预留空间，则会多次分配内存空间

    int num = 0;
    int *p = NULL;

    for(int i=0; i<100000; ++i)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            num++;
            p = &v[0];
        }
    }
    cout << num << endl;
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}