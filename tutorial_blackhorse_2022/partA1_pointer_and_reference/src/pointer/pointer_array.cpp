/**
 * 
 */
#include <iostream>
#include <string>
using namespace std;

void test01()
{
    int a[5] = {1,2,3,4,5};
    int *p1 = a;
    int *p2 = &a[1];

    cout << "数组的长度：" << sizeof(a) << endl;
    cout << "指针1的长度："<< sizeof(p1) << endl;
    cout << "指针2的长度："<< sizeof(p2) << endl;

    cout << "数组的地址：" << a << endl;
    cout << "指针指向的地址：" << p1 << endl;

    cout << "a+1：" << a+1 << endl;
    cout << "p1+1：" << p1+1 << endl;

}
void test02()
{
    char c = 'a';
    int a = 10;
    cout << "---------------------------------" << endl;
    char *p = &c;
    cout << "指向字符的指针地址：p=" << (int*)p << endl;
    cout << "指向字符的指针累加：p+2=" << (int*)(p+2) << endl; 

    cout << "---------------------------------" << endl;
    int *p1 = &a;
    cout << "指向整形的指针地址：p1=" << p1 << endl;
    cout << "指向整形的指针累加：p1+2=" << p1+2 << endl;                  // p1+2，偏移2个P1指向的类型，p1+2*sizeof(int)
    cout << "&p1[2]=" << &p1[2] << endl;
    cout << "*(p1+2)=" << *(p1+2) << endl;
    cout << "p1[2]=" << p1[2] << endl;
}

void test03()
{
    int arr[5] = {1,2,3,4,5};
    cout << "以指针方式访问数组内的元素：*(arr+4)=" << *(arr+4) << endl;
    cout << "以下标方式访问数组内的元素：arr[4]=" << arr[4] << endl;
    cout << "---------------------------------" << endl;
    int *p2 = arr;
    cout << "使用指针指向整形数组首元素的首地址：p2=" << p2 << endl;
    cout << "对首元素首地址累加4：p2+4=" << p2+4 << endl;                  // p2+4，偏移数组内4个元素
    cout << "以指针方式访问被指针指向的数组内的元素：*(p2+4)=" << *(p2+4) << endl;
    cout << "以下标方式访问被指针指向的数组内的元素：p2[4]=" << p2[4] << endl;

    cout << "---------------------------------" << endl;
    int *p3 = (int *)(&arr);
    cout << "数组首元素的首地址：arr=" << arr << endl;
    cout << "数组的地址：&arr=" << &arr << endl;
    cout << "使用指针指向数组地址：p3=" << p3 << endl;
    cout << "数组地址累加：(int*)(&arr+1)" << (int*)(&arr+1) << endl;   // &arr+1 = arr + sizeof(arr)*1

}
int main(int argc, char *argv[])
{
    /**
     *
     */
    // test01();
    // test02();
    test03();
    return 0;
}

