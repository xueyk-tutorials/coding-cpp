# 模板

**泛型编程**也是C++编程模式之一。泛型编程的基本技术是模板，模板的本质是解决了数据类型参数化！

模板包括函数模板和类模板。

## 函数模板

### 函数模板格式

```c++
template<typename T>
返回值类型 函数名(参数列表){
    
}
```

其中

1. 返回值类型和参数类型可以是T，或者是其他数据类型
2. typename可以替换成class
3. 模板函数可以发生函数重载



示例

```c++
#include <iostream>
using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void test01()
{
    int ia = 1;
    int ib = 2;
    // 调用的时候可理解为：函数名+<数据类型参数列表>+(函数参数列表)
    mySwap<int>(ia, ib);
    cout << "ia=" << ia << ",ib=" << ib << endl;
    //
    float fa = 1.0;
    float fb = 2.0;
    mySwap<float>(fa, fb);
    cout << "fa=" << fa << ",fb=" << fb << endl;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
```



### 调用规则

- 如果模板函数和普通函数都可以调用，优先调用普通函数；
- 可以通过空模板参数列表，强制调用模板函数；
- 如果模板函数可以产生更好的匹配，优先调用模板函数；



示例

```c++
#include <iostream>
using namespace std;

void mySwap(int &a, int &b)
{
    cout << "调用普通函数" << endl;
}
template<typename T>
void mySwap(T &a, T &b)
{
    cout << "调用模板函数" << endl;
}
template<typename T>
void mySwap(T &a, T &b, T &c)
{
    cout << "调用重载的模板函数" << endl;
}
void test01()
{
    int ia = 1;
    int ib = 2;
    int ic = 3;
    mySwap(ia, ib);        // 优先调用普通函数
    mySwap<>(ia, ib);      // 空模板参数，调用模板函数
    mySwap<int>(ia, ib);   // 显示指定调用模板函数
    mySwap(ia, ib, ic);    // 模板重载

    char ca = 'a';
    char cb = 'b';
    mySwap(ca, cb);       // 模板函数参数匹配度更高，故调用模板函数。虽然没有显式给定数据类型，但这里编译器使用自动类型推导，而如果使用普通函数则需要隐式转换。
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
```



## 模板重载

模板函数体内具体化实现时，可能并不能对所有数据类型（例如自定义的类）都适用，这时候就需要模板重载技术。

```c++
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(int a, string n){
        age = a;
        name = n;
    }
    int age = 0;
    string name = "";
};

template<class T>
bool myEqual(T a, T b)
{
    if (a == b){
        return true;
    }
    else{
        return false;
    }
}
template<> bool myEqual(Person a, Person b)
{
    if (a.age == b.age && a.name == b.name){
        return true;
    }
    else{
        return false;
    }
}

void test01()
{
    Person a(10, "alex");
    Person b(20, "alex");
    cout << myEqual(a, b) << endl;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
```



## 类模板

类中成员的数据类型可以不指定。

### 类模板格式

```c++
template<class T1, class T2>
类
```

示例

```c++
#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age){
        this->age = age;
        this->name = name;
    }
    void showPerson()
    {
        cout << "name=" << name << endl;
        cout << "age=" << age << endl;
    }
    AgeType age = 0;
    NameType name = "";

};

void test01()
{
    Person<string, int> a("alex", 20);
    a.showPerson();
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
```

### 类模板与函数模板区别

- 类模板没有数据类型自动推导的能力

- 类模板在模板参数列表中可以给定默认参数

示例

```c++
template<class NameType, class AgeType=int>
class Person
{
};

Person a("alex", 20);          // 错误
Person<string> b("bill", 29);  // 默认类型参数
```

## 成员函数创建

类模板中成员函数和普通类中成员函数创建时机是有区别的：

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用时才创建

```c++
#include <iostream>
#include <string>
using namespace std;

class Person1
{
public:
    void showPerson1(){
        cout << "Person1" << endl;
    }
};
class Person2
{
public:
    void showPerson2(){
        cout << "Person2" << endl;
    }
};

template<class T>
class MyClass
{
public:
    T obj;
    // 类模板中的成员函数在被调用时才会创建！
    void func1(){
        obj.showPerson1();
    }
    
    void func2(){
        obj.showPerson2();
    }
};

void test01()
{
    MyClass<Person1> p1;
    p1.func1();
    MyClass<Person2> p2;
    p2.func2();
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
```

## 类模板对象作为函数参数

三种传入方式：

- 指定传入的类型 

  直接显式对象的数据类型

- 参数模板化

  使用模板函数，将对象中的参数变为模板进行传递

- 整个类模板化

  使用模板函数，将这个对象类型模板化进行传递

示例

```c++
/**
 * 类模板对象作为参数
 */
#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age){
        this->age = age;
        this->name = name;
    }
    void showPerson()
    {
        cout << "name=" << name << endl;
        cout << "age=" << age << endl;
    }
    AgeType age = 0;
    NameType name = "";

};

//1、直接显式对象的数据类型
void printFunc1(Person<string, int> p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> a("alex", 20);
    printFunc1(a);
}
//2、 使用模板函数，将对象中的参数变为模板进行传递
template<class NameType, class AgeType>
void printFunc2(Person<NameType, AgeType> p)
{
    p.showPerson();
    cout << "NameType=" << typeid(NameType).name() << endl;
    cout << "AgeType=" << typeid(AgeType).name() << endl;
}
void test02()
{
    Person<string, int> b("bill", 20);
    printFunc2<string, int>(b);
}
//3、使用模板函数，将这个对象类型模板化进行传递
template<class T>
void printFunc3(T &p)
{
    p.showPerson();
}
void test03()
{
    Person<string, int> c("charllie", 20);
    // 注意，这里不是printFunc3<Person>(c);
    printFunc3(c);     
}
int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();
    return 0;
}
```

