
## 原理
编译阶段
会生成*.gcno文件,它包含重建基本块图和相应块的源码的行号信息

运行阶段
生成*.gcda文件

## 示例1
### 编写代码
这里创建程序代码test01.c

### 命令行
在终端进入代码所在路径，进行编译
```shell
编译：gcc -c test01.c -ftest-coverage -fprofile-arcs
链接：gcc test01.o -o test01 -lgcov

gcc -fprofile-arcs -ftest-coverage -o test test.c
```

### 运行程序
运行程序，生成`.gcda`文件。
```shell
./test01
```

### 生成报告
#### 生成info数据
```shell
$ lcov -c -d . -o test01.info --rc lcov_branch_coverage=1
```
#### 生成html可视化报告
```shell
$ genhtml --branch-coverage -o html_report --rc lcov_branch_coverage=1 test01.info
```


## 示例2
### CMake

```cmake
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
```
或者
```cmake
set(CMAKE_CXX_FLAGS_RELEASE "-O0 -fopenmp")
add_compile_options(-fprofile-arcs)
add_compile_options(-ftest-coverage)
add_compile_options(--coverage)
link_libraries(gcov)
```

## 示例3

```python
# generate test coverage
AddOption('--test-coverage', action='store_true', dest='test_coverage', help='enable test coverage analyze (with gcov)', default=False)

env = Environment(CCFLAGS=['-g', '-O0', '-Wall'])

if GetOption('test_coverage'):
	# https://gcc.gnu.org/onlinedocs/gcc-10.1.0/gcc/Instrumentation-Options.html
	env.Append(CXXFLAGS = ['-fprofile-arcs', '-ftest-coverage'],
		LIBS = ['gcov'])

env.Program('test.cpp')
```

## 生成报告
### 生成info数据
```shell
$ lcov -c -d . -o test.info --rc lcov_branch_coverage=1
```

### 生成html可视化报告
```shell
$ genhtml --branch-coverage -o html_report --rc lcov_branch_coverage=1 test.info
```


### info文件格式
生成info文件，打开看info文件信息：

一个源文件对应一条记录，记录详细格式如下：

TN: <Test name> 表示测试用例名称，即通过geninfo中的–test-name选项来命名的测试用例名称，默认为空；

SF: <File name> 表示带全路径的源代码文件名；

FN: <函数启始行号>, <函数名>; <函数有效行总数>; <函数有效行总数中被执行个数>

FNDA: <函数被执行的次数>, <函数名>; <函数有效行总数>; <函数有效行总数中被执行个数>

FNF: <函数总数>

FNH: <函数总数中被执行到的个数>

BRDA: <分支所在行号>, <对应的代码块编号>, <分支编号>, <执行的次数>

BRF: <分支总数>

BRH: <分支总数中被执行到的个数>

DA: <代码行号>, <当前行被执行到的次数>

LF: < counts> 代码有效行总数

LH: <counts> 代码有效行总数中被执行到的个数

end_of_record 一条“记录”结束符