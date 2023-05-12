#include <iostream>

using namespace std;


/**
 * 构造函数
 * - 默认构造函数
 * - 拷贝构造函数
 * - 拷贝赋值运算符
*/
/**
 * 默认构造函数
 * 
 * 如果类中没有构造函数，则编译器隐式生成无参构造函数、拷贝构造函数
 * 如果类中定义了其他构造函数，则编译器不再会生成默认的构造函数了，这时可以使用default进行显式让编译器创建
 * 默认构造函数不需要额外实现，否则报错
*/
class Entity{
public:
    Entity() = default;
    Entity(const Entity& e) = default;
    Entity(int x, int y);
    int x{0};
    int y{0};
};

// 不要额外实现默认构造函数
// Entity::Entity(){
//     cout << "default constructor" << endl;
// }
Entity::Entity(int x, int y){
    cout << "parameter constructor" << endl;
    x = x;
    y = y;
}

void test01(){
    Entity e1;
    Entity e2(1,2);
    Entity e3(e2);
}

/**
 * 虚析构函数
 * 
*/
void test02(){
    class Base{
    public:
        Base(){
            cout << "Base constructor" << endl;
        }
        virtual ~Base(){
            cout << "Base destructor" << endl;
        }
    };

    class Derived : public Base{
    public:
        Derived(){
            cout << "Derived constructor" << endl;
        }
        ~Derived(){
            cout << "Derived destructor" << endl;
        }
    };
    cout << ">>> " << endl;
    Derived *d = new Derived();
    delete d;

    cout << ">>> " << endl;
    Base *b1 = new Base();
    delete b1;

    cout << ">>> " << endl;
    Base *b = new Derived();
    /**
     * 如果父类析构函数不是虚析构，则delete指针时子类析构函数不会调用
    */
    delete b;

    cout << "---------------end---------------" << endl;

}

/**
 * new类数组
 * 
*/
void test03(){
    class Base{
    public:
        Base() = default;
        Base(int idx){
            cout << "Base constructor with parameter" << endl;
            idx = idx;
        }
        virtual ~Base(){
            cout << "Base destructor" << endl;
        }
        int idx{0};
    };

    class Derived : public Base{
    public:
        Derived() = default;
        // Derived(){
        //     cout << "Derived constructor" << endl;
        // }
        Derived(int x, int y){
            cout << "Derived constructor with parameter" << endl;
            x = x;
            y = y;
        }
        ~Derived(){
            cout << "Derived destructor" << endl;
        }
        int x{0};
        int y{0};
    };
    #define CNT 2
    cout << ">>> new array" << endl;
    Derived *d;
    d = new Derived[CNT];
    for(int i=0; i< CNT; ++i){
        d[i].idx = i;
    }
    for(int i=0; i< CNT; ++i){
        cout << "d[i].idx=" << i << endl;;
    }
    delete[] d;

    cout << "---------------end---------------" << endl;

}

/**
 * 显示调用父类的构造函数
 * 
*/
void test04(){
    class Base{
    public:
        Base(){
            cout << "Base constructor" << endl;
        }
        Base(int idx){
            cout << "Base constructor with parameter" << endl;
            cout << "idx=" << idx << endl;
            m_idx = idx;
        }
        virtual ~Base(){
            cout << "Base destructor" << endl;
        }
        int m_idx{-1};
    };

    class Derived : public Base{
    public:
        Derived(){
            cout << "Derived constructor" << endl;
        }
        // 通过委托构造，父类中修改成员变量同时修改子类成员变量
        Derived(int x, int y) : Base(x+y){
            cout << "Derived constructor with parameter" << endl;
            //
            // Derived::Base(0);  // 显式调用父类构造函数只修改父类成员变量，不会影响子类的成员变量
            //
            m_x = x;
            m_y = y;
        }
        ~Derived(){
            cout << "Derived destructor" << endl;
        }
        int m_x{0};
        int m_y{0};
    };
    Derived d(1,2);
    cout << d.m_idx << ", " << d.m_x << ", " << d.m_y << endl;

    cout << "---------------end---------------" << endl;

}
int main(int argc, char *argv[]){
    // test01();
    test02();
    test04();
    return 0;
}