#include <iostream>
#include "screen.h"
using namespace std;

inline Screen &Screen::move(pos r, pos c) // 在定义函数时，使该函数变为内联函数(推荐在函数定义时添加inline)
{
    cursor = r*width + c;
    return *this;
}

char Screen::get(pos r, pos c) const      // 常函数内部不能改变类成员变量，除非使用mutable声明成员变量
{
    pos row = r * width;
    
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width + c] = ch;
    return *this;
}

void test01()
{
    Screen myscreen;
    myscreen.set('h');
    cout << myscreen.get() << endl;

    cout << "------------------------------------------" << endl;
    Screen myscreen2(3, 5, 'h');
    cout << myscreen2.move(1, 2).get() << endl;

    myscreen2.move(1, 2).set('o');
    cout << myscreen2.get() << endl;

    cout << "------------------------------------------" << endl;
    const Screen myscreen3 = myscreen2;
    myscreen2.display(cout);
    myscreen3.display(cout);

}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}