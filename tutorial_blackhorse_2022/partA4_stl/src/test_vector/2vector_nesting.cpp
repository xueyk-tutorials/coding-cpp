#include <iostream>
#include <vector>
using namespace std;


void test01()
{
    vector<vector<int>> v;
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {11,22,33};
    vector<int> v3 = {21,22,23};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(auto m : v)
    {
        cout << "----" << endl;
        for(vector<int>::iterator it=m.begin(); it!=m.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}