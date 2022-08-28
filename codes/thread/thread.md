# thread

参考文档：

## thread基础

API：

https://www.apiref.com/cpp-zh/cpp/thread/thread.html

### 简介

线程创建后立即执行。

当线程启动后，一定要在和线程相关联的std::thread对象销毁前，对线程运用join()或者detach()方法。

### 构造函数

| thread() noexcept;                                           | (1)  | (C++11 起) |
| ------------------------------------------------------------ | ---- | ---------- |
| thread( thread&& other ) noexcept;                           | (2)  | (C++11 起) |
| template< class Function, class... Args > explicit thread( Function&& f, Args&&... args ); | (3)  | (C++11 起) |
| thread(const thread&) = delete;                              | (4)  | (C++11 起) |



### join()与detach()

- join

  可以理解为等待。子线程join后，会阻塞主线程，也就是主线程等待子线程执行完毕后才可以执行其他的。

- detach：





## 原子类型atomic<>

原子操作指“不可分割的操作”，用来给一个变量“加锁”，用于创建多个线程中都需要访问的变量！