# 类——初级

## 成员

类的成员包括：

- 成员变量，也称属性
- 成员函数，也称方法

### 类对象的大小

类对象中只包含非静态成员变量，所有类实例化出来的对象共享成员函数和静态成员变量。

```c++
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    int age = 0;                 // 普通成员变量
    static string name;          // 静态成员变量
};
string Person::name = "alex";    // 静态成员，类内声明，类外定义
void test01()
{
    Person p1;
    cout << sizeof(p1) << endl;  // 类对象的大小为4，也就是只包括属性`age`！
}
int main()
{   
    test01();
}
```

如果一个类为空，则其大小为1！

### 类的默认函数成员

一个空类，编译器会默认给定四个函数成员

- 默认构造函数（无参，函数体为空）
- 默认析构函数（无参，函数体为空）
- 拷贝构造函数，对属性进行值拷贝
- 赋值运算符`operator=`重载函数，对属性进行值拷贝

## 构造

### 构造函数分类

- 无参构造

  无参构造也可以叫做默认构造函数。

- 有参构造

  构造函数有参数

- 拷贝构造

  通过传入一个自身类对象进行构造

- 委托构造

  委托其他构造函数进行构造，先运行指定的其他构造函数，然后再运行自身

```c++
#include <iostream>
using namespace std;
class Person
{
public:
    // 无参构造
	Person(){
        cout << "无参构造" << endl;
    }
    // 有参构造
	Person(int a){
        cout << "有参构造" << endl;
        age = a;
    }
    // 拷贝构造
    Person(const Person &p){
        age = p.age;
    }
    // 委托构造
    Person(int a, string n) : Person(a){
        cout << "委托构造" << endl;
    }
private:
    int age = 0;
    string name = "";
};
```

### 调用

```c++
int main()
{   
    // 
    Person p;                // 无参构造函数不要带()，否则就是声明了一个函数
    // 1. 括号法
    cout << "---------------括号法" << endl;
    Person p1(10);           // 有参构造函数调用
    Person p2(p1);
    cout << "调用委托构造》》》" << endl;
    Person p3(10, "alex");   // 委托构造函数调用

    // 2. 显示法调用
    cout << "---------------显示法" << endl;
    Person p4 = Person(10);  // 其中Person(10)为匿名对象，创建后会立即销毁
    // Person(p4)            // 但不要利用拷贝构造函数初始化匿名对象，因为Person(p4)等价于Person p4
    Person p5 = Person(p4);  // 

    // 3. 隐式法
    cout << "---------------隐式法" << endl;
    Person p6 = 10;          // 相当于Person p5 = Person(10)，由编译器进行隐式转换
    Person p7 = p1;  
}
```

### 构造初始化列表

常量无法在函数体内初始化，只能通过初始化列表实现

```c++
class Person
{
public:
	Person(string n) : name(n){  // 在构造函数初始化列表中初始化const成员变量
    }
    const string name;           // 常量无法在构造函数体内初始化，只能在初始化列表中进行初始化
};
```

成员变量的初始化是按照声明顺序进行的。

```c++
class Person
{
public:
    // 初始化顺序是根据成员变量声明顺序，先age，再height
	Person(int a, int h) : height(h), age(a){
    }
    int age;
    int height;
};

```

> 问题：
>
> 引用是否可以在成员列表中初始化？Linux系统下好像不支持。

### 拷贝构造

拷贝构造函数调用的三种情况：

- 使用已经创建好的对象初始化一个新对象
- 值传递的方式给函数参数传值
- 函数返回值为一个全局对象

```c++
void transfer_person(Person p)
{
}
Person p;
Person return_person()
{
 cout << (int *)&p << endl;
 return p;
}
int main()
{
    Person p1(20);
    cout << ">>>1.使用已经创建好的对象初始化一个新对象" << endl;
    Person p2(p1);
    //
    cout << ">>>2.值传递的方式给函数参数传值" << endl;
    transfer_person(p2);
    cout << ">>>3.函数返回值为一个全局对象" << endl;
    Person p3 = return_person();
}
```

> 问题：
>
> 如果是通过函数返回值返回一个**局部对象**并赋值给新创建的对象，那么不会对新对象进行拷贝构造，而是将新对象直接指向这个局部对象内存空间。就像是函数返回，但局部对象内存没有释放，转而给这个新对象使用了。
>
> ```c++
> Person return_person()
> {
>  Person p(10);
>  cout << (int *)&p << endl;
>  return p;
> }
> int main()
> {
>  Person p3 = return_person();
>  cout << (int *)&p3 << endl;
> }
> // p和p3两个地址打印出来一样！
> ```

### 深拷贝与浅拷贝

- 浅拷贝

  简单的值拷贝，系统提供的默认拷贝构造函数就是浅拷贝。

  但如果类中有指针成员变量，且在类中使用new在堆区开辟了空间，那么浅拷贝时无法拷贝堆区的内存！仅仅拷贝了指针中存放的地址而已。

- 深拷贝

  能够拷贝堆区内存。

```c++
public:
{
    // 拷贝构造，深拷贝
    Person(const Person &p){
        age = p.age;
        address = new string(*(p.address));    //重新手动申请堆区内存
    }
    int age = 0;
    string *address;
};
```

## 析构

析构函数只有一个，且没有参数。

## this

this是指向对象的指针。

非静态成员函数返回自身，通过`return *this`可以返回对象本身，这样就可以实现成员函数的级联调用。

```c++
class Person
{
public:
	Person(int a){
        age = a;
    }
    Person &addAge(Person b){
        this->age += b.age;
        return *this;
    }
    int age = 0;
};
int main()
{
    Person p1(10);
    Person p2(20);
    p2.addAge(p1).addAge(p1);             //实现函数级联调用
    cout << "p2.age=" << p2.age << endl;
}
```



## 作用域

当函数定义在类的外部，必须指定类名，且指定类名之后，函数定义的剩余部分就都在类作用域内了。

```c++
class Screen
{
public:
    typedef std::string::size_type pos;
    char get(pos ht, pos wd) const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

/**
 * 1. 使用Screen::来指明get是类Screen的成员函数
 * 2. 由于已经指明了作用域，故pos、width都默认从类Screen中查找
 */
char Screen::get(pos r, pos c) const
{
    return contents[r*width+c];
}
```

但注意，返回类型出现在函数名之前，故是处于类作用域之外的，所以如果要使用类中声明的类型，需要添加类作用域。

```c++
Screen::pos Screen::Width() const
{
    return width;
}
```



## 运算符重载

运算符重载说白了就是重新定义一个函数，实现特定类型数据的运算。需要用到关键字`operator`，从函数角度理解，设计运算符重载函数要从如下三点考虑：

- 在operator后加上运算符构成新的**函数名**；

- 根据运算需要添加参数，由于运算符一般涉及到一个对象（如++，--）或两个对象的运算操作（如+，*），故参数也要相应添加；

- 确定函数返回值类型，一般主要有`void`，`T`，引用`T &`；

  当只返回数据类型`T`时，表示返回了对象拷贝；当返回数据类型引用时`T &`，实质上返回了某个对象的引用，特别是在类运算符级联操作时需要用到。

> 注意：
>
> 1. `T`表示用户定义的类
>
> 2. 内置数据类型表达式运算符不可以重载！

运算符重载包括：**类成员函数运算符重载**、**全局函数运算符重载**。

- 类成员函数运算符重载

  这种重载是自定义数据类型对象本身与传入参数之间的运算操作，调用的格式为`对象.运算符(参数)`，也就是运算符在第一个参数之前！

  ```c++
  // 返回类型 operator运算符(参数1)
  class T{
  	T &operator+(T t1); 
  };
  ```

- 全局函数运算符重载

  这种重载一般是两个自定义数据类型对象参数之间的运算操作，调用格式为`参数1 运算符 参数2`，也就是运算符在第一个参数之后！

  ```c++
  // 返回类型 operator运算符(参数1，参数2)
  T &operator+(T t1, T t2);
  ```

### 加法运算符+重载

加法运算符重载涉及到两个对象之间的操作，故如果使用类函数运算符重载需要传入一个参数，而使用全局函数运算符重载需要传入两个参数！

```c++
#include <iostream>
using namespace std;
class Person
{
public:
    Person(){
    }
	Person(int a){
        age = a;
    }
    // 类成员函数运算符重载（代码不能与全局函数重载同时存在，二者其一进行注释）
    Person operator+(Person p){
        Person tmp;
        tmp.age = this->age + p.age;
        return tmp;
    }
    int age = 0;
};
//全局函数运算符重载（代码不能与类成员函数重载同时存在，二者其一进行注释）
// Person operator+(Person p1, Person p2)
// {
//     Person tmp;
//     tmp.age = p1.age + p2.age;
//     return tmp;
// }
void test01()
{
    // 1. 类成员函数运算符重载
    Person p1(10);
    Person p2(20);
    Person p3 = p1.operator+(p2); // 等价于
    // Person p3 = p1 + p2;     
    cout << p3.age << endl;

    // 2. 全局函数运算符重载（取消对应注释）
    // Person p4 = operator+(p1, p2);
    // Person p4 = p1 + p2;
    // cout << p4.age << endl;
}
int main()
{
    test01();
}
```

### 输出运算符<<重载

加法运算符重载涉及到两个值之间的操作，一个是输出流`ostream`对象，一个是要打印的对象本身，由于输出流对象必须要在运算符之前（cout << a），故只能使用全局函数运算符重载且需要传入两个参数！

```c++
#include <iostream>
using namespace std;

class Person
{
// 只有友元才能访问私有成员变量
friend ostream &operator<<(ostream &out, Person p);   
public:
    Person(){
    }
	Person(int a, string n){
        age = a;
        name = n;
    }
private:
    int age = 0;
    string name = "";
};
// 只有全局函数重载，才能实现cout在<<左边
ostream &operator<<(ostream &out, Person p) 
{
    out << "age=" << p.age << ",name=" << p.name << endl;
    // 只有返回流引用，才能实现运算符级联操作
    return out;                                     
}
void test01()
{
    Person p1(32, "alex");
    cout << p1 << endl;
}
int main()
{   
    test01();
}
```

### 递增运算符++重载

由于递增运算符只涉及到一个对象的操作，故如果使用类成员函数运算符重载来实现，就不需要额外传递参数。

递增运算符分为前置和后置。

```c++
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int a){
        age = a;
    }
    // 前置++
	Person &operator++(){
        ++age;
        return *this;
    }
    // 运算符重载必须以参数区分，故c++编译器规定后置++必须传入int参数
    Person operator++(int){
        Person tmp = *this;
        age++;
        return tmp;
    }
    int age = 0;
};
void test01()
{
    Person p1(32);
    ++(++p1);
    cout << p1.age << endl;
    Person p2 = p1++;
    cout << p1.age << endl;
    cout << p2.age << endl;
}
int main()
{   
    test01();
}
```





## 继承



### 菱形继承

使用虚继承的方式解决菱形继承中成员二义性的问题。

## 多态

### 多态基础

多态分为静态多态和动态多态：

- 静态多态

  函数重载是静态多态的一种。

- 动态多态

  运行时确定函数调用。基本思路是定义基类指针或引用指向子类对象，通过基类指针或引用来调用子类成员。

### virtual

实现多态是通过函数前面添加`virtual`关键字实现，这种函数叫做虚函数。

一旦声明虚函数，类就会自动创建一个虚函数指针**vfptr**，并指向一个虚函数列表**vftable**，这样就是为什么包含虚函数的空类大小为4个字节（因为这个类有个指针成员变量vfptr，指针的大小为4）。

> 在64位操作系统上，指针大小为8个字节

```c++
#include <iostream>
#include <string>
using namespace std;

class Vechile1
{
public:
    void move(){
        cout << "Vechile1 move" << endl;
    }
};
class Vechile2
{
public:
    virtual void move(){
        cout << "Vechile2 move" << endl;
    }
};
void test01()
{
    Vechile1 v1;        // 由于没有非静态成员变量，故大小为1
    Vechile2 v2;        // 由于有虚函数，故编译器添加一个vfptr指针成员变量，大小为4或8
    cout << sizeof(v1) << endl;
    cout << sizeof(v2) << endl;
}
int main()
{   
    test01();
}
```

由于**基类的虚函数一般在子类中被重写**，故虚函数的函数体并不被执行，是多余的，所以写成如下形式：

```c++
class Vechile
{
public:
    virtual void move() = 0;
};
```

这种就叫做**纯虚函数**。

### 抽像类

包含有纯虚函数的类称为抽象类，抽象类不能实例化对象，但是可以定义指针和引用。

```c++
#include <iostream>
#include <string>
using namespace std;

class Vechile
{
public:
    virtual void move() = 0;  // 纯虚函数
};
class Car : public Vechile
{
public:
    void move() override{
        cout << "Car move" << endl;
    }
};
class Drone : public Vechile
{
public:
    void move() override{
        cout << "Drone fly" << endl;
    }
};
// 抽象类指针或引用作为参数
void fun_move(Vechile &v)
{
    v.move();
}
void test01()
{
    Car car;
    Drone drone;
    fun_move(car);   // 传入子类Car对象
    fun_move(drone); // 传入子类Drone对象
    
    //Vechile v;       // 错误，抽象类不能实例化对象
}
int main()
{   
    test01();
}
```

当然抽象类可以不仅仅包括纯虚函数，也可以定义正常的成员函数：

```c++
class Vechile
{
public:
    virtual void move() = 0;   // 纯虚函数
    void set_speed(float s){   // 成员函数
        speed = s;
        cout << "set speed=" << speed << endl;
    }
    float speed;               // 成员变量
};
void test01()
{
    Car car;
    Drone drone;
    fun_move(car);
    car.set_speed(20);
    fun_move(drone);
    drone.set_speed(100);
}
```





