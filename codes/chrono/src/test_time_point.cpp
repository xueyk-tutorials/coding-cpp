#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono_literals;

/**
 * 实例化对象
 */
void test01()
{
    // 实例化
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp(std::chrono::seconds(2));
    cout << "From epoch: " << tp.time_since_epoch().count() << "s" << endl;

    // 拷贝构造
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp1(tp);
    cout << "From epoch: " << tp1.time_since_epoch().count() << "s" << endl;

    //
    std::chrono::time_point<std::chrono::milliseconds> tp2(std::chrono::milliseconds(2000));
    cout << "From epoch: " << tp2.time_since_epoch().count() << "ms" << endl;
}

/**
 * 时间单位转换
 */
void test02()
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>      tp_s(std::chrono::seconds(2));
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp_ms(std::chrono::milliseconds(2540));
    // 单位由s->ms，可以隐式转换，无精度损失
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp_ms1(tp_s);
    cout << "From epoch: " << tp_ms1.time_since_epoch().count() << "ms" << endl;

    // 单位由ms->s，必须显示转换，有精度损失
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp_s1 = std::chrono::time_point_cast<std::chrono::seconds>(tp_ms);
    cout << "From epoch: " << tp_s1.time_since_epoch().count() << "s" << endl;
}


/**
 * 计时，计算函数段运行时间
 */
void test03()
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::cout << "Hello World\n";
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Printing took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";
}

/**
 * system_clock::now()
 */
void test04()
{
    std::chrono::time_point<std::chrono::system_clock> tp = std::chrono::system_clock::now();
    auto d_ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    cout << "ms since epoch: " << d_ms.count() << endl;

    auto d_hours = std::chrono::duration_cast<std::chrono::hours>(tp.time_since_epoch());
    cout << "hours since epoch: " << d_hours.count() << endl;
}

/**
 * to_time_t, ctime
 */
void test05()
{
    std::chrono::time_point<std::chrono::system_clock> p0 = std::chrono::time_point<std::chrono::system_clock>{};
    auto p1 = std::chrono::system_clock::now();
    auto p2 = p1 - std::chrono::hours(24);
 
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(p0);
    std::cout << "epoch: " << std::ctime(&epoch_time);
    
    auto today_time = std::chrono::system_clock::to_time_t(p1);
    std::cout << "today: " << std::ctime(&today_time);
 
    std::cout << "hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                   p1.time_since_epoch()).count() 
              << '\n';
    std::cout << "yesterday, hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                   p2.time_since_epoch()).count() 
              << '\n';
}

int main(int argc, char *argv[])
{
    // test01();
    // test02();
    // test03();
    test04();

    return 0;
}