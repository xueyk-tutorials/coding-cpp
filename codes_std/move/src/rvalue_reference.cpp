/**
 * 
 */ 
#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Student
{
public:
    Student(){};
    Student(std::string name){
        _name = name;
    };
    ~Student(){};

    std::string _name;
    int _age;
};

/**
 * 传参测试
 */

void handleStudent_copy(Student stu)
{
    cout << "传入拷贝." << "stu地址为：" << (int *)(&stu) << endl;
}

void handleStudent_ref(Student &stu)
{
    cout << "传入引用." << "stu地址为：" << (int *)(&stu) << endl;
}
void handleStudent_ref(const Student &stu)
{
    cout << "传入常量引用." << "stu地址为：" << (int *)(&stu) << endl;
}
void handleStudent_ref(Student &&stu)
{
    cout << "传入右值引用." << "stu地址为：" << (int *)(&stu) << endl;
}

void test01()
{
    Student stu1;
    cout << "stu1地址为：" << (int *)(&stu1) << endl;
    
    handleStudent_copy(stu1);   //拷贝一份对象，然后在函数内使用
    handleStudent_ref(stu1);    //
}

void test02()
{
    Student stu1;
    const Student stu2;

    handleStudent_ref(stu1);       // 调用handleStudent_ref(Student &stu)
    handleStudent_ref(stu2);       // 调用handleStudent_ref(const Student &stu)
    handleStudent_ref(Student());  // 传入一个右值，优先调用右值引用的重载，如果没有右值引用重载，则调用常量引用的重载
}

/**
 * 返回值测试
 * 在c++11后，默认对函数内的局部变量进行移动，而非拷贝。
 */
Student createStudent()
{
    Student stu;
    cout << "移动变量." << "stu地址为：" << (int *)(&stu) << endl;
    return stu;
}

// 不合法，无法返回局部对象的引用！
Student& createStudent_ref()
{
    Student stu("alex");
    cout << "返回拷贝." << "stu地址为：" << (int *)(&stu) << endl;
    return stu;
}

int createInt()
{
    int m;
    cout << "返回拷贝." << "m地址为：" << (int *)(&m) << endl;
    return m;
}
std::string createString()
{
    std::string str = "alex haha";
    cout << "返回拷贝." << "str地址为：" << (int *)(&str) << endl;
    return str;
}

void test11()
{
    // Student stu1 = createStudent_ref();                  // 不合法
    
    Student stu1 = createStudent();                    // 如果返回的是类对象，则不会拷贝，只会移动函数内开辟的内存到stu1
    cout << "stu1地址为：" << (int *)(&stu1) << endl;
    cout << stu1._name << endl;

    std::string str = createString();
    cout << "str地址为：" << (int *)(&str) << endl;

    // 如果返回的是内置类型，则拷贝一份
    int m = createInt();
    cout << "m地址为：" << (int *)(&m) << endl;
}

void test21()
{
    int i = 10;
    // int &&rr1 = i;          // 不合法
    int &&rr2 = i * 10;

    // 引用赋值只能通过std::move()实现
    // int &&rr3 = rr2;
    int &&rr3 = std::move(rr2);
    cout << "rr3=" << rr3 << endl;
    rr3 = 300;
    cout << "rr3=" << rr3 << endl;

    // 由于rr2和rr3都是引用，指向同一个内存，故改变一个就会改变另外一个
    rr2 = 200;
    cout << "rr2=" << rr2 << endl;
    cout << "rr3=" << rr3 << endl;

}

int main(int argc, char *argv[])
{
    // test01();
    // test02();

    // test11();
    test21();
    return 0;
}