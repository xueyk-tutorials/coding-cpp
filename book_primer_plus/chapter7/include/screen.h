#include <iostream>
#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;       // 在类作用域中，必须先定义的类型，然后才能使用该类型
    Screen() = default;                       // 默认构造函数，一般如果有多个构造函数，增加default来指定一个默认的，当类有默认构造函数时，编译器便不会再帮我们生成默认构造函数了
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}
    char get() const {return contents[cursor];} // 隐式内联函数（由于该函数定义在类内部，故是内联函数）
    inline char get(pos ht, pos wd) const;      // 显式内联函数，这里声明，在类外还需要进行定义
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &move(pos r, pos c);

    Screen &display(std::ostream &os){               // display重载，当对象不为const时调用这个
        os << "none const version" << std::endl;
        do_display(os);
        os << std::endl;
        return *this;
    }
    const Screen &display(std::ostream &os) const {  // display重载，当对象为const时调用这个
        os << "const version" << std::endl;
        do_display(os);
        os << std::endl;
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &os) const {os << contents;}
};