# thread

## 参考文档

- API

  https://www.apiref.com/cpp-zh/cpp/thread/thread.html



## thread基础

### 简介

线程创建后立即执行。

当线程启动后，一定要在和线程相关联的std::thread对象销毁前，对线程运用join()或者detach()方法。

## thread成员函数
### 构造函数
| 构造函数                                                     |      |            |
| ------------------------------------------------------------ | ---- | ---------- |
| thread() noexcept;                                           | (1)  | (C++11 起) |
| thread( thread&& other ) noexcept;                           | (2)  | (C++11 起) |
| template< class Function, class... Args > explicit thread( Function&& f, Args&&... args ); | (3)  | (C++11 起) |
| thread(const thread&) = delete;                              | (4)  | (C++11 起) |

### join()与detach()

#### 二者的区别

- join

  可以理解为线程等待。有如下特性：

  1）子线程join后，会阻塞主线程，也就是主线程等待子线程执行完毕后才可以继续执行。

  2）如果有多个子线程，子线程A的join()函数不会影响其他**已创建过的**（也就是在A.join()前创建了B）子线程B的运行。

- detach
  可以理解为线程分离。有如下特性：
  
  1）子线程detach后，在后台运行（守护线程），不会阻塞主线程，主线程可以立即继续执行。
  
  2）主线程若在子线程执行完毕前退出，则子线程仍然继续运行。

> 注意：
>
> 1. join的线程不能调用detach()，detach的线程不能调用join()。
>
> 2. 创建线程对象后，需要对该对象要么使用join()，要么使用detach()，如果对象两个函数都没调用，那么该线程对象被析构时，会调用std::terminate()从而立即结束该线程！！！

代码示例

- join示例

```c++
int main(){
    thread A(fun);    // A创建完毕后立即执行
    thread B(fun);    // B创建完毕后立即执行
    A.join();         // 阻塞主线程，等待A执行完成，但不会阻塞B
    B.join();         // 阻塞主线程，等待B执行完成，但不会阻塞A
    // 主线程阻塞，等待已经join的子线程A和B运行完毕
    thread C(fun);    // 在主线程中创建C，故A和B运行完毕后才能开始执行C
    C.join(); 
    // 主线程阻塞，等待已经join的子线程C运行完毕
    // 主线程执行结束
    return 0;
}
```

- detach示例

```c++
int main(){
    thread A(fun);    // A创建完毕后立即执行
    thread B(fun);    // B创建完毕后立即执行
    A.detach();       
    B.detach();
    // 主线程非阻塞，同步运行子线程A和B运行
    thread C(fun);    // 不需要等A和B运行完毕就可以主线程创建并开始执行C
    C.detach(); 
    sleep(5);         // 主线程sleep的同时，子线程A,B,C若没退出可同步运行
    return 0;         // 主线程执行结束
}
```

#### 应用场合

- join

  如果线程作为某个类的成员变量，则线程join()一般放在该类的析构函数中。

- detach

  一般detach()会在线程创建后立即实行！

## 原子类型atomic<>

原子操作指“不可分割的操作”，用来给一个变量“加锁”，用于创建多个线程中都需要访问的变量！