/**
 * 抽象工厂模式
 * 每个工厂需要生产套件产品，每套产品包含多个不同类别产品，且套与套之间风格类型不一样。
 * 参考：https://refactoringguru.cn/design-patterns/abstract-factory
 * 
 * 如果不仅希望工厂生产苹果、香蕉，还希望工厂能够根据客户不同需求生产不同类型的产品，例如有的客户喜欢吃水果派，有的喜欢果汁。
 *               |   apple     |   banana    |
 *   factorypi   | apple pi    | banana pi   |
 *   ____________|_____________|_____________|
 *               |             |             |
 *   factoryjuice| apple juice | banana juice|
 *   ____________|_____________|_____________|
 * 
 */ 
#include <iostream>
#include <string>
using namespace std;

class Apple
{
public:
    virtual ~Apple(){};
    virtual string Show() = 0;
};

class ApplePi : public Apple
{
public:
    string Show() override
    {
        return "这个是苹果派";
    }
};
class AppleJuice : public Apple
{
public:
    string Show() override
    {
        return "这个是苹果汁";
    }
};

class Banana
{
public:
    virtual ~Banana(){};
    virtual string Show() = 0;
    virtual string Fun(Apple &apple) = 0;
};

class BananaPi : public Banana
{
public:
    string Show() override
    {
        return "这个是香蕉派";
    }
    string Fun(Apple &apple) override
    {
        string result = apple.Show();
        return this->Show() + result;
    }
};
class BananaJuice : public Banana
{
public:
    string Show() override
    {
        return "这个是香蕉汁";
    }
    string Fun(Apple &apple) override
    {

        string result = apple.Show();
        return this->Show() + result;
    }
};


class Factory
{
public:
    virtual ~Factory(){};
    virtual Apple* createApple() = 0;
    virtual Banana* createBanana() = 0;
};

class FactoryPi : public Factory
{
public:
    Apple* createApple() override
    {
        return new ApplePi();
    }
    Banana* createBanana() override
    {
        return new BananaPi();
    }
};
class FactoryJuice : public Factory
{
public:
    Apple* createApple() override
    {
        return new AppleJuice();
    }
    Banana* createBanana() override
    {
        return new BananaJuice();
    }
};

void ClientCode(Factory &factory)
{
    Apple *apple = factory.createApple();
    Banana *banana = factory.createBanana();

    cout << apple->Show() << endl;
    cout << banana->Fun(*apple) << endl;

    delete apple;
    delete banana;
}
void test01()
{
    Factory *factory1 = new FactoryPi();

    Factory *factory2 = new FactoryJuice();

    ClientCode(*factory1);
    ClientCode(*factory2);

    delete factory1;
    delete factory2;
}

int main(int argc, char *argv[])
{
    test01();
}