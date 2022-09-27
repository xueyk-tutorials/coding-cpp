# std

## 参考

https://en.cppreference.com/w/

## std::get





## 智能指针

### std::unique_ptr

https://blog.csdn.net/lemonxiaoxiao/article/details/108603916



### std::remove_pointer

功能：剥掉指针“外衣”，得到指针指向对象的类型

语法：

```c++
std::remove_pointer<T>::type
```

示例：

```c++
std::remove_pointer<int*>::type a;
```



