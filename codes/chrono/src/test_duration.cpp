#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

/**
 * ratio<num, den>: 表示一个系数，通常用于定义一个新的单位，而一个单位=num/den，分子为num，分母为den。
 * duration表示一段时间，其单位可以是秒、小时等，或者可以自定义其他的单位，例如天。
 */
void test01()
{
    std::chrono::duration<int, ratio<60, 1>> one_minute(1);
    cout << "one_minute:" << endl;
    cout << "count=" << one_minute.count() << endl;

    std::chrono::duration<int, ratio<60*60, 1>> one_day(24);
    cout << "one_day:" << endl;
    cout << "count=" << one_day.count() << endl;
}
void test02()
{
    auto duration_hour = std::chrono::hours(1);

    // 时间单位转换，通过count与单位系数实现
    double seconds_in_hour = double(duration_hour.count()) * std::chrono::hours::period::num / std::chrono::hours::period::den; 
    cout << "hours转换为seconds：" << endl;
    cout << seconds_in_hour << endl;
    // 时间单位转换：通过类型转换实现
    auto duration_seconds = std::chrono::duration_cast<std::chrono::seconds>(duration_hour);
    cout << duration_seconds.count() << endl;
    
    auto duration_millisecond = std::chrono::milliseconds(1);
    cout << "millisecond转换为seconds：" << endl;
    cout << double(duration_millisecond.count()) * std::chrono::milliseconds::period::num / std::chrono::milliseconds::period::den << endl;
    auto duration_seconds2 = std::chrono::duration_cast<std::chrono::seconds>(duration_millisecond);
    cout << duration_seconds2.count() << endl;
}

/**
 * duration字面量
 * 定义于内联命名空间 std::literals::chrono_literals
 */
void test03()
{
    std::chrono::hours d_d = 24h;
    cout << "小时：" << d_d.count() << endl;

    std::chrono::milliseconds d_m = 100ms;
    cout << "毫秒：" << d_m.count() << endl;

    std::chrono::microseconds d_u = 100us;
    cout << "微秒：" << d_u.count() << endl;
}
int main(int argc, char *argv[])
{
    // test01();
    test02();
    // test03();
    return 0;
}