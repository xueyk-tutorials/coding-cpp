/*
 * @Description: 
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-08-18 14:39:10
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-08-18 15:08:41
 */
#include <iostream>
#include <functional>
using namespace std;

class AddCall
{
public:
    AddCall(){}
    void create_add_callback(const std::function<int(int, int)> &func_add)
    {
        this->_func_add = func_add;
    }
    void add_callback(int a, int b)
    {
        this->_func_add(a, b);
    }
private:
    std::function<int(int, int)> _func_add;
};

class AddImpl
{
public:
    AddImpl()
    {
        add_call.create_add_callback(std::bind(&AddImpl::add, this, std::placeholders::_1, std::placeholders::_2));
    }
    void loop()
    {
        add_call.add_callback(2, 3);
    }
private:
    AddCall add_call;

    /**
     * add的具体实现
     */ 
    int add(int a, int b)
    {
        int result = a + b;
        cout << "a=" << a << ", b=" << b << endl;
        cout << "a + b =" << result << endl;
        return result;
    }
};

template<class T>
class AddCall_T
{
public:
    AddCall_T(){}
    void create_add_callback(const std::function<T(T, T)> &func_add)
    {
        this->_func_add = func_add;
    }
    void add_callback(T a, T b)
    {
        this->_func_add(a, b);
    }
private:
    std::function<T(T, T)> _func_add;
};

class AddImpl_T
{
public:
    AddImpl_T()
    {
        add_call.create_add_callback(std::bind(&AddImpl_T::add, this, std::placeholders::_1, std::placeholders::_2));
    }
    void loop()
    {
        add_call.add_callback(2, 3);
    }
private:
    AddCall_T<int> add_call;

    /**
     * add的具体实现
     */ 
    int add(int a, int b)
    {
        int result = a + b;
        cout << "a=" << a << ", b=" << b << endl;
        cout << "a + b =" << result << endl;
        return result;
    }
};

void test01()
{
    cout << "/************************类回调函数************************/" << endl;
    AddImpl add_impl;
    add_impl.loop();
}
void test02()
{
    cout << "/************************模板类回调函数************************/" << endl;
    AddImpl_T add_impl;
    add_impl.loop();
}
int main(int argc, char *argv)
{
    // test01();
    test02();
    return 0;
}