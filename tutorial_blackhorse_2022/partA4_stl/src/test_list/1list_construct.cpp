#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> l)
{
    for(list<int>::const_iterator it=l.begin(); it!=l.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    printList(l1);

    list<int> l2 = {10, 20, 30, 40, 50};
    printList(l2);

}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}