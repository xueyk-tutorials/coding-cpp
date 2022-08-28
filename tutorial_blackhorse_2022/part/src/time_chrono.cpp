#include <unistd.h>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;


/**
 * duration
 */
void test_duration_01()
{
    // duration类实例化
    // chrono::duration<int> d = chrono::seconds(1);        // seconds
    // auto d = chrono::microseconds(1);                    // microseconds
    // chrono::microseconds d = chrono::microseconds(100);

    auto d = chrono::seconds(1) + chrono::microseconds(100);
    cout << d.count() << endl;

    auto d1 = chrono::seconds(12);
    cout << d1.count() << endl;
}


void test01()
{
    // chrono::system_clock::time_point t1 = chrono::system_clock::now();        // 1. 确定类型
    // auto t1 = chrono::system_clock::now();                                    // 2. 使用auto
    chrono::time_point<chrono::system_clock> t1 = chrono::system_clock::now();  // 3. 使用模板类
    cout << "t1=" << t1.time_since_epoch().count() << endl;

}

/**
 * 计时
 * 由于usleep的精度有限，可以精确到毫秒，无法精确计量微妙。
 */
void test02()
{
    chrono::time_point<chrono::system_clock> t1;
    t1 = chrono::system_clock::now();
    cout << "延迟间隔1s" << endl;
    cout << "t1=" << t1.time_since_epoch().count() << endl;
    sleep(1);
    t1 = chrono::system_clock::now();
    cout << "t1=" << t1.time_since_epoch().count() << endl;
    sleep(1);
    t1 = chrono::system_clock::now();
    cout << "t1=" << t1.time_since_epoch().count() << endl;
    
    cout << "延迟间隔1000us" << endl;
    cout << "t1=" << t1.time_since_epoch().count() << endl;
    usleep(1000);
    t1 = chrono::system_clock::now();
    cout << "t1=" << t1.time_since_epoch().count() << endl;
    usleep(1000);
    t1 = chrono::system_clock::now();
    cout << "t1=" << t1.time_since_epoch().count() << endl;

    // 延迟间隔1s
    // t1=1655840323614247700
    // t1=1655840324614866100
    // t1=1655840325615169400
    // 延迟间隔1000us
    // t1=1655840325615169400
    // t1=1655840325616368100
    // t1=1655840325617563100

}


/**
 * 不同时钟计时区别
 * system_clock：输出为1655841484446669
 * steady_clock: 输出为4803246111
 */
void test03()
{
    // system_clock
    typedef chrono::time_point<chrono::system_clock, chrono::microseconds> sys_microClock_type;
    sys_microClock_type tp_sys;

    tp_sys = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
    cout << tp_sys.time_since_epoch().count() << endl;

    // steady_clock，系统启动到当前的时间，精确到微妙
    typedef chrono::time_point<chrono::steady_clock, chrono::microseconds> std_microClock_type;
    std_microClock_type tp_std_micro;
    cout << "以微秒为单位输出系统启动时间，间隔1000微妙" << endl;
    for(int i=0;i<10;++i)
    {
        tp_std_micro = chrono::time_point_cast<chrono::microseconds>(chrono::steady_clock::now());
        cout << tp_std_micro.time_since_epoch().count() << endl;
        usleep(1000);
    }
    // steady_clock，系统启动到当前的时间，精确到毫秒
    typedef chrono::time_point<chrono::steady_clock, chrono::milliseconds> std_milliClock_type;
    std_milliClock_type tp_std_milli;

    cout << "以毫秒为单位输出系统启动时间，间隔1毫秒" << endl;
    for(int i=0;i<10;++i)
    {
        tp_std_milli = chrono::time_point_cast<chrono::milliseconds>(chrono::steady_clock::now());
        cout << tp_std_milli.time_since_epoch().count() << endl;
        usleep(1000);
    }
}

/**
 * 转换
 */
void test04()
{
    chrono::system_clock::time_point tp = chrono::system_clock::now();
    auto t1 = chrono::time_point_cast<chrono::nanoseconds>(tp);
    cout << t1.time_since_epoch().count() << endl;
    auto t2 = chrono::time_point_cast<chrono::milliseconds>(tp);
    cout << t2.time_since_epoch().count() << endl;
    auto t3 = chrono::time_point_cast<chrono::microseconds>(tp);
    cout << t3.time_since_epoch().count() << endl;
    auto t4 = chrono::time_point_cast<chrono::seconds>(tp);
    cout << t4.time_since_epoch().count() << endl;
    auto t5 = chrono::time_point_cast<chrono::minutes>(tp);
    cout << t5.time_since_epoch().count() << endl;
    auto t6 = chrono::time_point_cast<chrono::hours>(tp);
    cout << t6.time_since_epoch().count() << endl;
}

/**
 * 运算
 */
void test05()
{
    // 
    auto start = chrono::system_clock::now();
    sleep(2);
    chrono::duration<double> d2 = chrono::system_clock::now() - start;
    cout << d2.count() << endl;
}

/**
 * 与ctime的互相转换
 */
void test_convert_with_ctime()
{
    auto tp = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(tp);


    // 以us打印，结果为1655852362480254
    cout << chrono::time_point_cast<chrono::microseconds>(tp).time_since_epoch().count() << endl;
    // 以ms打印，结果为1655852362480
    cout << chrono::time_point_cast<chrono::milliseconds>(tp).time_since_epoch().count() << endl;
    // 以s打印，结果为1655852362
    cout << chrono::time_point_cast<chrono::seconds>(tp).time_since_epoch().count() << endl;

    // ctime():返回时间字符串
    char* dt = ctime(&tt);
	cout << dt << endl;

    // localtime(): 返回tm结构体指针
    tm *ltm = localtime(&tt);

    char mydate[30];
    sprintf(mydate, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d", 1900+ltm->tm_year, 1+ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    cout << mydate << endl;
}
int main(int argc, char *argv[])
{
    // test01();
    // test02();
    test03();
    // test04();

    // test_duration_01();
    test_convert_with_ctime();
    return 0;
}