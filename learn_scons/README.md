# scons

## 命令
- 编译: scons [-j8]

## API

### SConscript函数
功能：添加SConscript并执行
参数：
- src_dir


### env.Program函数
功能：编译并生成可执行程序，编译所有.c并生成.o，链接。
可以一次编译一个或多个源文件，但必须保证有main()函数！否则无法生成可执行程序。
