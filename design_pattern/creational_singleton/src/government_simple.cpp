/**
 * 我们以构建一个政府为例，讲解单例模式的使用。
 * 缺点：不能用于多线程
*/
#include <iostream>
using namespace std;

class Government{
public:
    static Government* get_instance(){
        if(_instance==nullptr){
            _instance = new Government;
            return _instance;
        }
    }

    void handle_war(){
        cout << "Government handle war" << endl;
    }
    void handle_economy(){
        cout << "Government handle economy" << endl;
    }
private:
    static Government *_instance;
    /* 将默认无参构造函数声明为私有，防止外部对类进行实例化操作 */
    Government() = default;

    /* 禁用拷贝构造函数和赋值运算*/
    Government(const Government &ins) = delete;
    Government operator=(const Government &ins) = delete;
};
// 对静态成员变量进行初始化
Government *Government::_instance=nullptr;

void test01()
{
    Government *gov = Government::get_instance();

    gov->handle_economy();
}

int main(int argc, char *argv[]){
    test01();

    return 0;
}