# chrono

[标准库头文件  - C++中文 - API参考文档 (apiref.com)](https://www.apiref.com/cpp-zh/cpp/header/chrono.html)

chrono包含三种类

- 时间间隔duration
- 时间点time_point
- 时钟clocks

## duration

duration表示一段时间间隔，用来记录时间长度，可以表示几秒钟、几分钟或者几个小时的时间间隔，duration的原型是：

```c++
template<class Rep, class Period = std::ratio<1>> class duration;
```

第一个模板参数Rep是一个数值类型，如int，float，int64_t等；

第二个模板参数是一个默认模板参数std::ratio，它的原型是：

```c++
template<std::intmax_t Num, std::intmax_t Denom = 1> class ratio;
```

它表示每个时钟周期的秒数，其中第一个模板参数Num代表分子，Denom代表分母，分母默认为1，ratio代表的是一个分子除以分母的分数值，比如：

- ratio<2>代表一个时钟周期是两秒

- ratio<60>代表了一分钟

- ratio<1, 1000>代表的则是1/1000秒即一毫秒

> ratio<num, den>表示一个系数，通常用于定义一个新的单位，而一个单位=num/den，分子为num，分母为den。

### 标准时间单位

标准库chrono定义了标准的时间单位，如：

```c++
typedef duration<int64_t, ratio<3600,1>>       hours;
typedef duration<int64_t, ratio<60,1>>         minutes;
typedef duration<int64_t, ratio<1,1>>          seconds;
typedef duration<int64_t, ratio<1,1000>>       milliseconds;
typedef duration<int64_t, ratio<1,1000000>>    microseconds;
typedef duration<int64_t, ratio<1,1000000000>> nanoseconds;
```

### 成员函数count

duration最关键的成员函数是**count()**，返回的是一个计数，这个计数要配合对应的时间单位才能表示具体时间长度。

例如`std::chrono::milliseconds d_ms(100)`，其中`d_ms`的计数为100，其单位是ms，故其代表的时间长度为100ms。

### 显示类型转换

不同时间单位的时间长度之间，可以使用`std::chrono::duration_cast<>`进行转换，例如：

```c++
auto duration_hour = std::chrono::hours(1);
auto duration_seconds = std::chrono::duration_cast<std::chrono::seconds>(duration_hour);
```

## time_point

time_point表示一个时间点，用来获取1970.1.1以来的秒数和当前的时间, 可以做一些时间的比较和算术运算，可以和ctime库结合起来显示时间.

时间点都有一个时间戳，即时间原点。chrono库中采用的是Unix的时间戳1970年1月1日 00:00。所以time_point也就是距离时间戳(epoch)的时间长度（duration）。

### 成员函数

- time_since_epoch

### 类型转换

std::chrono::time_point_cast

## clock

Clocks包含三种时钟： 

- system_clock：从系统获取的时钟；

- steady_clock：不能被修改的时钟；

- high_resolution_clock：高精度时钟，实际上是system_clock或者steady_clock的别名。

### 成员函数

- now()

可以通过now()来获取当前时间点：

- to_time_t

  将一个time_point转换为std::time_t

- from_time_t

  将std::time_t转换为time_point

