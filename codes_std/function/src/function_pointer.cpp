/*
 * @Description: 函数指针
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-09-26 11:02:46
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-09-26 16:03:53
 */
#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <memory>

using namespace std;

////////////////////////////////////////////////////////////////////
/// 测试依赖
////////////////////////////////////////////////////////////////////
int Add(int a, int b)
{
    cout << "普通函数，加法运算" << endl;
    return a+b;
}
int Sub(int a, int b)
{
    cout << "普通函数，减法运算" << endl;
    return a-b;
}
/**
 * @description: 函数指针作为参数
 * @return {*}
 * @author: xueyuankui
 */
void Calculator(int(*cal)(int,int), int a, int b)
{
    int res = cal(a, b);
    cout << "res=" << res << endl;
}

class CCalculator
{
public:
    static int add_s(int a, int b)
    {
        cout << "类静态成员函数，加法运算" << endl;
        return a+b;
    }
    static int sub_s(int a, int b)
    {
        cout << "类静态成员函数，减法运算" << endl;
        return a-b;
    }
    
    int add(int a, int b)
    {
        cout << "类成员函数，加法运算" << endl;
        return a+b;
    }
    int sub(int a, int b)
    {
        cout << "类成员函数，减法运算" << endl;
        return a-b;
    }

    // 模板函数
    // 类成员函数指针作为参数，根据对象类型以及成员函数参数自动解析_C与_T
    template<class _C, class _T>
    void caclculator_t(int (_C:: *fn)(_T, _T), _T a, _T b)
    {
        cout << "CCalculator::caclculator_t" << endl;
        // int的typeid.name为i
        // char的typeid.name为c
        // float的typeid.name为f
        cout << "typeid(_C).name():" << typeid(_C).name() << endl;
        cout << "typeid(_T).name():" << typeid(_T).name() << endl;

        auto bfn = std::bind(fn, this, std::placeholders::_1, std::placeholders::_2);
        // // 调用
        bfn(a, b);
    }
};

/**
 * @description: 类普通成员函数指针作为参数
 * @return {*}
 * @author: xueyuankui
 */
void calculator(int (CCalculator:: *fun)(int,int), CCalculator &cal, int a, int b)
{
    // 
    cout << "成员函数指针的使用：1）直接调用" << endl;
    (cal.*fun)(a, b);
    // 
    cout << "成员函数指针的使用：2）std::bind" << endl;
    auto cal_fun = std::bind(fun, cal, std::placeholders::_1, std::placeholders::_2);
    cal_fun(a, b);
}

////////////////////////////////////////////////////////////////////
/// 测试函数
////////////////////////////////////////////////////////////////////
/**
 * @description: 函数指针定义，语法格式为：返回值类型(*指针变量名)(参数1,参数2,....)
 * @return {*}
 * @author: xueyuankui
 */
void test01()
{
    cout << "*********************** 普通函数指针定义与使用 ***********************" << endl;
    // 定义函数指针cal
    // int(*)(int, int) cal= &Add;                // 错误！！！虽然希望声明一个 int(*)(int, int)类型的变量，但不能使用这种方式
    int(*cal)(int, int) = &Add;                   // 正确！！！显示指定函数地址
    // int(*cal)(int, int) = Add;                 // 使用隐式转换
    // 调用
    cal(10, 11);
    // 重新赋值，使函数指针指向Sub函数
    cal = Sub;
    cal(10, 11);

    cout << "*********************** typedef定义普通函数指针别名 ***********************" << endl;
    // 使用typedef定义别名fp_cal，表示一个函数指针类型 int(*)(int,int)！后面可以使用这个别名定义函数指针
    typedef int(*fp_cal)(int,int);

    // 对于普通成员函数，可以使用&运算符进行赋值
    fp_cal cc_a = &Add;                           // 等价于 int(*cc_a)(int, int) = &Add
    cc_a(20, 21);                          
    // 如果没有使用&运算符，则进行隐式转换
    fp_cal cc_s = Sub;
    cc_s(30, 31);
}
/**
 * @description: 
 * 使用typedef定义函数指针，通过std::shared_ptr创建指向函数的智能指针
 * @return {*}
 * @author: xueyuankui
 */
void test02()
{
    cout << "*********************** typedef与std::shared_ptr ***********************" << endl;
    // 智能指针, 函数指针类型为int(*)(int,int)
    std::shared_ptr<int(*)(int,int)> ptr_sub = std::make_shared<int(*)(int,int)>(Sub);
    (*ptr_sub)(1,2);

    // 使用typedef定义别名fp_cal，表示一个函数指针类型！后面可以使用这个别名定义函数指针
    typedef int(*fp_cal)(int,int);

    std::shared_ptr<fp_cal> ptr_add = std::make_shared<fp_cal>(Add);
    (*ptr_add)(10, 11);
}

/**
 * @description: 普通函数指针作为参数
 * @return {*}
 * @author: xueyuankui
 */
void test03()
{
    cout << "*********************** 普通函数指针作为参数 ***********************" << endl;
    cout << "传入Add函数" << endl;
    Calculator(Add, 10, 11);
    cout << "传入Sub函数" << endl;
    Calculator(Sub, 10, 11);
}
/**
 * @description: 类静态成员函数指针，由于静态函数只有一份，故使用方式跟普通函数类似
 * @return {*}
 * @author: xueyuankui
 */
void test04()
{
    cout << "*********************** 类静态成员函数指针作为参数 ***********************" << endl;
    Calculator(CCalculator::add_s, 30, 31);
    Calculator(CCalculator::sub_s, 30, 31);
}
/**
 * @description: 类普通成员函数指针，由于普通成员函数与类实例化的对象绑定，故使用起来比较繁琐！
 * @return {*}
 * @author: xueyuankui
 */
void test05()
{
    cout << "*********************** 类普通成员函数指针使用 ***********************" << endl;
    // 声明类CCalculator的成员函数指针
    int(CCalculator::* ccal)(int, int) = &CCalculator::add;
    // 实例化一个对象
    CCalculator cal1;
    //
    (cal1.*ccal)(1, 2);                        // 普通成员函数指针调用时必须加括号！！！
    ccal = &CCalculator::sub;
    (cal1.*ccal)(1, 2);                        // 普通成员函数指针调用时必须加括号！！！
    
    cout << "*********************** 类普通成员函数指针使用, 通过typedef定义别名 ***********************" << endl;
    // 通过typedef定义一个别名tp_ccal，其对应的类型使类成员函数指针，tp_ccal的类型为 int(CCalculator::* )(int, int)，指向类CCalculator的成员函数
    typedef int(CCalculator::* tp_ccal)(int, int);
    // 定义成员函数指针p_add，其指向的是类CCalculator的add成员函数
    tp_ccal p_add = &CCalculator::add;

    // 实例化一个对象
    CCalculator cal2;
    // 调用函数指针
    (cal2.*p_add)(10, 11);

    cout << "*********************** 类普通成员函数指针作为普通函数的参数 ***********************" << endl;
    calculator(&CCalculator::add, cal2, 10, 11);
    calculator(&CCalculator::sub, cal2, 10, 11);
}

void test06()
{
    cout << "*********************** 类普通成员函数指针作为该类另一个成员函数的参数 ***********************" << endl;
    typedef int(CCalculator:: *fp_cal)(int, int);
    fp_cal p_add = &CCalculator::add;

    CCalculator cal;
    
    cal.caclculator_t(&CCalculator::add, 10, 11);
}


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Help ./function_pointer <test01|test02|....>" << endl;
    }
    else
    {
        std::string fun_name(argv[1]);
        std::map<std::string, int> map_functions {{"test01", 0}, {"test02", 1}, {"test03", 2}, {"test04", 3}, {"test05", 4}, {"test06", 5}};
        std::map<std::string, int>::iterator iter = map_functions.find(fun_name);

        // 创建函数指针vector，存放各函数的指针
        std::vector<void(*)()> vector_functions{&test01, &test02, &test03, &test04, &test05, &test06};
        // 获取函数指针并调用函数
        vector_functions[iter->second]();
    }

    return 0;
}