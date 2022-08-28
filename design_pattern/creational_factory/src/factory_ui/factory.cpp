
/**
 * 
 * 
 */ 
#include <iostream>
#include <functional>
using namespace std;

/* ================================================== */
// 开发者代码：开发人员（角色）负责的部分
/* ================================================== */


class Button
{
public:
    virtual void onClick() = 0;
    std::function<void()> fun_onclick;
private:
};

class WindowsButton : public Button
{
public:
    void onClick() override
    {
        cout << "WindowsButton: onClick" << endl;
        fun_onclick();
    }
private:
};

class LinuxButton : public Button
{
public:
    void onClick() override
    {
        cout << "LinuxButton: onClick" << endl;
        fun_onclick();
    }
private:
};

/**
 * 生产者基类
 * 1. 生产者包括一个成员函数，用来生产button，生产者子类重写该方法用于实例化不同Button子类对象
 * 2. 生产者不仅仅用于生产button，还通常包括一些核心业务逻辑
 * 3. 生产者不是必须返航一个新的对象，可以是已存在的对象！
 */ 
class Dialog
{
public:
    virtual Button *createButton() = 0;
    void bind(std::function<void()> &fun)
    {
        
    }
    void onClick()
    {
        Button *button = createButton();
        button->onClick();
    }
private:
};

class DialogWindowsButton : public Dialog
{
public:
    Button *createButton()
    {
        Button *button = new WindowsButton();
        return button;
    }
private:
};

class DialogLinuxButton : public Dialog
{
public:
    Button *createButton()
    {
        Button *button = new LinuxButton();
        return button;
    }
private:
};


/**
 * TODO: 可以非常方便的进行扩展其他类型的button，且满足开闭原则（不改代码，只需要增加即可）。
 * 例如希望扩展MacOs button，只需要实现子类MacOSButton，以及DialogMacOSButton
 */ 
class MacOSButton : public Button
{

};
class DialogMacOSButton : public Dialog
{

};


/* ================================================== */
// 用户者代码：用户人员（角色）负责的部分
/* ================================================== */

void callback_onclick()
{
    cout << "callback_onclick" << endl;
}
void test01()
{
    DialogWindowsButton dialog_win_button;
    dialog_win_button.onClick();
}


int main(int argc, char *argv[])
{
    test01();
    return 0;
}