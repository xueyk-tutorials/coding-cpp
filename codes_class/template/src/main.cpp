/*
 * @Description: 类成员函数模板，使用类作为模板参数
 * @Version: 1.0
 * @Author: xueyuankui
 * @Date: 2022-09-23 09:14:55
 * @LastEditors: xueyuankui
 * @LastEditTime: 2022-09-23 09:20:27
 */

#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

/**
 * @description: 基类，该类实例化是通过创建shared_ptr的方式
 * @author: xueyuankui
 */
class Plug : public enable_shared_from_this<Plug>
{
public:
    Plug(){};
    virtual ~Plug() = default;

    template<class _C>
    void make_handler(void (_C::* fn)(int msg_id))
    {
        // 查看_C的类型
        // cout << typename(_C) << endl;
        cout << ">>>Plug::make_handler" << endl;
        cout << typeid(_C).name() << endl;

        // 创建function
        std::function<void (int)> bfn = std::bind(fn,
                std::static_pointer_cast<_C>(shared_from_this()), std::placeholders::_1);
        // auto bfn = std::bind(fn,
        //         std::static_pointer_cast<_C>(shared_from_this()), std::placeholders::_1);
        
        // 调用
        bfn(123);
    }

    virtual void get_subscription() = 0;
};

/**
 * @description: 子类
 * @author: xueyuankui
 */
class PlugImu : public Plug
{
public:
    PlugImu(){
        cout << ">>>PlugImu()" << endl;
    }

    void handle_attitude(int msg_id)
    {
        cout << ">>>PlugImu::handle_attitude" << endl;
        cout << "msg_id=" << msg_id << endl;
    }
    void get_subscription() override
    {
        cout << ">>>PlugImu::get_subscription" << endl;

        make_handler(&PlugImu::handle_attitude);
        // make_handler<PlugImu>(&PlugImu::handle_attitude);
    }
};

void test01()
{
    std::shared_ptr<PlugImu> imu(new PlugImu());
    imu->get_subscription();

}
void test02()
{
    
}
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "Help:" << std::endl;
        std::cout << "./unique_ptr <test01>" << std::endl;
    }
    else
    {
        std::string fun(argv[1]);
        if(fun == "test01")
        {
            test01();
        }
        else if(fun == "test02")
        {
            test02();
        }
    }
    return 0;
}