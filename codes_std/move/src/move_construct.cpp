/**
 * 
 * 
 */ 
#include <iostream>

class Student
{
public:
    Student() = default;
    // 拷贝构造函数，深拷贝
    Student(const Student &){
        printf("拷贝构造函数，深拷贝\n");
    }
    //移动构造函数，浅拷贝
    Student(Student &&){
        printf("移动构造函数，浅拷贝\n");
    }       

    std::string _name;
};

void test01()
{
    Student stu1;
    printf("1----------");
    Student stu2(stu1);            // 调用拷贝构造
    printf("2----------");
    Student stu3(Student());       // 优先调用移动构造函数，若没有定义移动构造，则调用拷贝构造（参数必须是const &）
    printf("3----------");
    Student stu4(std::move(stu1)); // 同上
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}