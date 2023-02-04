/**
 * 我们以构建一个政府为例，讲解单例模式的使用。
 * 在多线程使用中，通过lock解决安全问题
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class Government{
public:
    static Government* get_instance(){
        // 通过双重检查，提高效率。如果第一次检查判断为空，就不需要再进行lock操作。
        if(_instance==nullptr){
            std::lock_guard<std::mutex> lock(_mutex);
            if(_instance==nullptr){
                _instance = new Government;
            }            
        }
        return _instance;
    }

    void handle_war(){
        cout << "Government handle war" << endl;
    }
    void handle_economy(){
        cout << "Government handle economy" << endl;
    }
private:
    static Government *_instance;
    static std::mutex _mutex;
    /* 将默认无参构造函数声明为私有，防止外部对类进行实例化操作 */
    Government() = default;

    /* 禁用拷贝构造函数和赋值运算*/
    Government(const Government &ins) = delete;
    Government operator=(const Government &ins) = delete;
};
// 对静态成员变量进行初始化
Government *Government::_instance=nullptr;
std::mutex Government::_mutex;

void test01()
{
    std::thread thread1([=](){
        Government *gov = Government::get_instance();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        gov->handle_war();
    }
    );

    std::thread thread2([=](){
        Government *gov = Government::get_instance();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        gov->handle_economy();
    }
    );
    thread1.join();
    thread2.join();
}

int main(int argc, char *argv[]){
    test01();

    return 0;
}