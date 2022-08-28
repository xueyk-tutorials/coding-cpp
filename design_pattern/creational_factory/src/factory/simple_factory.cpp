/**
 * 简单工厂模式
 * 我们可以把类的实例化（产品类）放到另外一个开发好的类中（工厂类），使用工厂类用于创建产品！
 * 这样使用者就可以不用管产品类具体怎么创建的（开发者来完成），只需要拿来用即可。
 * 
 * 工厂类中需要拥有一个包含大量条件语句的构建方法， 可根据方法的参数来选择对何种产品进行初始化并将其返回。
 * 
 * 应用场景：
 * 1. 产品类的初始化比较繁琐
 * 2. 
 * 缺点：
 * 1. 不符合开闭原则
 * 
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
 * 如果需要增加水果类，工厂类就需要修改，不符合开闭原则
 */ 
class Factory
{
public:
    Fruit* createFruit(string name)
    {
        if("apple" == name)
        {
            return new FruitApple;
        }
        else if("banana" == name)
        {
            return new FruitBanana;
        }
    }
};

void test01()
{
    Factory *factory = new Factory;
    Fruit *apple = factory->createFruit("apple");
    apple->Show();
    delete apple;

    Fruit *banana = factory->createFruit("banana");
    banana->Show();
    delete banana;

}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}