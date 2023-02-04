/**
 * 
 */ 
#include <iostream>
#include <string>
using namespace std;

// #define PRINT(str) do{printf("-------------------"#str"-----------------\n");}while(0)
#define PRINT(str) do{printf("-------------------%s-----------------\n",str);}while(0)

/**
 * @brief 定义
 * 
 */
void test01()
{
    // PRINT(test01);
    PRINT("test01");
    int i = 10;
    // int &&rr1 = i;          // 不合法，不能使用变量赋值（变量是左值）
    int &&rr1 = std::move(i);
    printf("rr1=%d\n", rr1);

    int &&rr2 = i * 10;
    printf("rr2=%d\n", rr2);
}

/**
 * 引用就是取别名，故右值引用本质也是指针常量
*/
void test02()
{
    PRINT("test02");
    int i = 10;
    printf("i addr=0x%x\n", &i);

    int &&rr1 = std::move(i);
    int &&rr2 = 10;
    printf("rr1 addr=0x%x\n", &rr1);
    printf("rr2 addr=0x%x\n", &rr2);
}

// int &&fun01(){
//     int ref = 10;
//     return ref;
// }

int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}