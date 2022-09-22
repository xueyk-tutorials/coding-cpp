/**
 * 
 * 
 */ 
#include <iostream>

class Student
{
public:
    Student() = default;
    Student(const Student &);  // 拷贝构造函数
    Student(Student &&);       // 移动构造函数

    std::string _name;
};

void test01()
{
    Student stu1;
    Student stu2(stu1);            // 调用拷贝构造
    Student stu3(Student());       // 优先调用移动构造函数，若没有定义移动构造，则调用拷贝构造（参数必须是const &）
    Student stu4(std::move(stu1)); // 同上
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}