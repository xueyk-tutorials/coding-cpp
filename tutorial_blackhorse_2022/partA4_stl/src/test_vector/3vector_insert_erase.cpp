#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for(auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);    
    printVector(v);

    vector<int>::iterator it = v.begin();

    cout << "-----------------insert" << endl;
    v.insert(it, 10);
    v.insert(it+2, 3, 22);
    printVector(v);
    v.insert(v.end(), 100);
    printVector(v);
    cout << "-----------------erase" << endl;
    v.erase(v.begin());
    // v.erase(it);       //错误！不要使用旧的迭代器，因为容器已经发生了变化
    printVector(v);
    v.erase(v.begin(), v.end()-1);
    printVector(v);
    v.clear();
    cout << v.empty() << endl;

}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}