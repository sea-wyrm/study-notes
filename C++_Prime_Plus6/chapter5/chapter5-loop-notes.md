### 第五章 《循环和关系表达式》笔记

#### 等待一段时间：编写延时循环

函数 `clock()` 可以返回程序开始执行后所用的系统时间。但，首先，clock( )返回时间的单位不一定是秒；其次，该函数的返回类型在某些系统上可能是long，在另一些系统上可能是unsigned long或其他类型。

头文件 `ctime` 提供了这些问题的解决方案。首先，它定义了一个符号常量—`CLOCKS_PER_SEC`，该常量等于每秒钟包含的系统时间单位数。因此，将系统时间除以这个值，可以得到秒数。或者将秒数乘以 `CLOCK_PER_SEC`，可以得到以系统时间单位为单位的时间。其次，`ctime` 将 `clock_t` 作为 `clock()` 返回类型的别名，这意味着可以将变量声明为 `clock_t` 类型，编译器将把它转换为long、unsigned int 或适合系统的其他类型。

![image-20220616185707039](/Users/wyrm/Library/Application Support/typora-user-images/image-20220616185707039.png)



