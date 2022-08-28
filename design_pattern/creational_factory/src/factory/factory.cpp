/**
 * 工厂模式
 * 我们可以把类的实例化（产品类）放到另外一个开发好的类中（工厂类），使用工厂类用于创建产品！
 * 这样使用者就可以不用管产品类具体怎么创建的（开发者来完成），只需要拿来用即可。
 * 解决简单工厂模式缺点
 * 应用场景：
 * 1. 产品类的初始化比较繁琐
 * 2. 
 * 缺点：
 * 1. 
 * 参考：https://refactoringguru.cn/design-patterns/factory-method/cpp/example
 */ 
#include <iostream>
using namespace std;

class Fruit
{
public:
    virtual ~Fruit(){}
    virtual string Show() = 0;
};

class FruitApple : public Fruit
{
public:
    string Show() override
    {
        cout << "这个是苹果" << endl;
    }
};
class FruitBanana : public Fruit
{
public:
    string Show() override
    {
        cout << "这个是香蕉" << endl;
    }
};

/**
 * 
 *
 */ 
class Factory
{
public:
    virtual ~Factory(){};

    virtual Fruit* createFruit() = 0;         // 虚函数必须添加`()=0`，否则编译出现错误：undefined reference to `vtable for Factory'

    string SomeOperation()
    {
        Fruit* fruit = this->createFruit();
        string result = "生产水果：生产的水果信息" + fruit->Show();
        delete fruit;

        return result;
    }
};

class AppleFactory : public Factory
{
public:
    Fruit* createFruit() override
    {
        return new FruitApple();
    }
};

class BananaFactory : public Factory
{
public:
    Fruit* createFruit() override
    {
        return new FruitBanana();
    }
};

/**
 * 开发者可以后续扩展任何其他产品类和对应工厂类，这个函数都可以正常工作。因为工厂类保证了接口统一性，
 * 且提供了隔离手段，将用户代码与实际的类进行了隔离！
 * 
 */ 

void ClientCode(Factory& factory)
{
    cout << "用户程序：虽然我不清楚这个工厂到底是生产什么的，但仍然可以正常工作" << endl;
    cout << factory.SomeOperation() << endl;

}
void test01()
{
    Factory* factory1 = new AppleFactory();
    ClientCode(*factory1);

    Factory* factory2 = new BananaFactory();
    ClientCode(*factory2);

    delete factory1;
    delete factory2;
}


int main(int argc, char *argv[])
{
    test01();
    return 0;
}