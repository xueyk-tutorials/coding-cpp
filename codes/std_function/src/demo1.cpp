/*
 * @Description: 
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-08-18 09:56:14
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-08-18 14:37:19
 */

#include <iostream>
#include <functional>
using namespace std;

/**
 * @brief 包装普通函数
 */ 
int add(int a, int b)
{
    int result = a + b;
    cout << "a=" << a << ", b=" << b << endl;
    cout << "a + b =" << result << endl;
    return result;
}
void test01()
{
    cout << "/************************包装普通函数************************/" << endl;
    int a = 10, b = 20;

    std::function<int(int, int)> func_bind1 = std::bind(add, a, b);
    std::function<int(int, int)> func_bind2 = std::bind(add, a, b=5);      // 给变量b重新赋值
    std::function<int(int, int)> func_bind3 = std::bind(add, std::placeholders::_1, std::placeholders::_2);
    // 绑定时指定参数，即使在调用时传入新的参数也不起作用
    func_bind1(1, 2); 
    cout << ">>>>>>>>>>>> func_bind2" << endl;
    func_bind2(a, b);
    // 使用占位符，这样就可以在传入调用时指定的参数
    cout << ">>>>>>>>>>>> func_bind3" << endl;
    func_bind3(1, 2);

    /**
     * 
     */ 
    cout << "-------------------" << endl;
    cout << ">>>>>>>>>>>> func_1" << endl;
    std::function<int(int, int)> func_1 = add;
    func_1(a, b);
    func_1(1, 2);
}
/**
 * @brief 包装模板函数
 */ 
template<class T>
T add_t_fun(T a, T b)
{
    T result = a + b;
    cout << "a=" << a << ", b=" << b << endl;
    cout << "a + b =" << result << endl;
    return result;
}
void test02()
{
    cout << "/************************包装模板函数************************/" << endl;
    int a = 10, b = 20;

    std::function<int(int, int)> func_bind1 = std::bind(add_t_fun<int>, std::placeholders::_1, std::placeholders::_2);
    func_bind1(a, b);
    
    std::function<int(int, int)> func_1 = add_t_fun<int>;
    func_1(a, b);
}

/**
 * @brief 包装labmda表达式
 */
auto add_lambda = [](int a, int b){
    int result = a + b;
    cout << "a=" << a << ", b=" << b << endl;
    cout << "a + b =" << result << endl;
    return result;
};
void test03()
{
    cout << "/************************包装lambda表达式************************/" << endl;
    int a = 10, b = 20;
    
    std::function<int(int, int)> func_bind1 = std::bind(add_lambda, std::placeholders::_1, std::placeholders::_2);
    func_bind1(a, b);

    std::function<int(int, int)> func_1 = add_lambda;
    func_1(a, b);
}

/**
 * @brief 包装类静态成员函数， 非模板与模板
 */
class AddNumS
{
public:
    static int add(int a, int b)
    {
        int result = a + b;
        cout << "a=" << a << ", b=" << b << endl;
        cout << "a + b =" << result << endl;
        return result;
    }
};
template<class T>
class AddNumST
{
public:
    static int add(T a, T b)
    {
        T result = a + b;
        cout << "a=" << a << ", b=" << b << endl;
        cout << "a + b =" << result << endl;
        return result;
    }
};
void test05()
{
    cout << "/************************包装类静态成员函数************************/" << endl;
    int a = 10, b = 20;
    std::function<int(int,int)> func_bind1 = std::bind(&AddNumS::add, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int,int)> func_1 = &AddNumS::add;
    cout << "非模板" << endl;
    func_bind1(a, b);
    func_1(a,b);

    cout << "模板" << endl;
    std::function<int(int,int)> func_bind_t1 = std::bind(&AddNumST<int>::add, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int,int)> func_t1 = &AddNumST<int>::add;
    func_bind_t1(a, b);
    func_t1(a, b);
}

/**
 * @brief 包装类对象成员函数， 非模板与模板
 *      只能用bind绑定！！！
 */
class AddNum
{
public:
    int add(int a, int b)
    {
        int result = a + b;
        cout << "a=" << a << ", b=" << b << endl;
        cout << "a + b =" << result << endl;
        return result;
    }
};
template<class T>
class AddNumT
{
public:
    int add(T a, T b)
    {
        T result = a + b;
        cout << "a=" << a << ", b=" << b << endl;
        cout << "a + b =" << result << endl;
        return result;
    }
};
void test04()
{
    cout << "/************************包装类对象成员函数************************/" << endl;
    int a = 10, b = 20;
    AddNum add_num;
    AddNumT<int> add_num_t;

    std::function<int(int,int)> func_bind1 = std::bind(&AddNum::add, &add_num, std::placeholders::_1, std::placeholders::_2);
    cout << "非模板" << endl;
    func_bind1(a, b);

    cout << "模板" << endl;
    std::function<int(int,int)> func_t_1 = std::bind(&AddNumT<int>::add, &add_num_t, std::placeholders::_1, std::placeholders::_2);
    func_t_1(a, b);
}

int main(int argc, char *argv[])
{
    // test01();
    // test02();
    // test03();
    // test04();
    test05();

    return 0;
}