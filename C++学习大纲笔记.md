### C++学习大纲笔记

参考网址：https://www.runoob.com/cplusplus/cpp-basic-syntax.html

#### 1. 程序基本概念

##### 程序框架/程序基本结构

这里有一段简单的代码，可以输出 `Hello World`

```c++
#include <iostream>
using namespace std;
 
int main()
{
  	// 输出 Hello World
   	cout << "Hello World";
   	return 0;
}
```

接下来我们讲解一下上面这段程序：

`#include <iostream>`

> C++ 语言定义了一些头文件，这些头文件包含了程序中必需的或有用的信息。上面这段程序中，包含了头文件 **<iostream>**。

`using namespace std;`

> 告诉编译器使用 std 命名空间。

`main() `

>  main() 是程序开始执行的地方

`// 输出 Hello World`

> 是一个单行注释。单行注释以 // 开头，在行末结束。
>
> // 后写上一些程序的说明。注释是给人看的，程序运行时会跳过注释的内容
>
> - 下一行 **int main()** 是主函数，程序从这里开始执行。
> - 下一行 **cout << "Hello World";** 会在屏幕上显示消息 "Hello World"。
> - 下一行 **return 0;** 终止 main( )函数，并向调用进程返回值 0。



##### 标识符

是用来标识变量、函数、类、模块，或任何其他用户自定义项目的名称。也就是我们目前经常用到的变量名，以后还会作为函数名、结构名等。

要求：

> 一个标识符以字母 A-Z 或 a-z 或下划线 _ 开始，后跟零个或多个字母、下划线和数字（0-9）。
>
> C++ 标识符内不允许出现标点字符，比如 @、& 和 %。
>
> C++ 是区分大小写的编程语言。

```c++
// 定义一个变量名
```





##### 关键字

下表列出了 C++ 中的关键字（也叫保留字）。

这些关键字有自己的意义不能作为常量名、变量名或其他标识符名称。

| —————      | —————    | —————            | —————    |
| ---------- | -------- | ---------------- | -------- |
| asm        | else     | new              | this     |
| auto       | enum     | operator         | throw    |
| bool       | explicit | private          | true     |
| break      | export   | protected        | try      |
| case       | extern   | public           | typedef  |
| catch      | false    | register         | typeid   |
| char       | float    | reinterpret_cast | typename |
| class      | for      | return           | union    |
| const      | friend   | short            | unsigned |
| const_cast | goto     | signed           | using    |
| continue   | if       | sizeof           | virtual  |
| default    | inline   | static           | void     |
| delete     | int      | static_cast      | volatile |
| do         | long     | struct           | wchar_t  |
| double     | mutable  | switch           | while    |



##### 常量

常量就像是常规的变量，只不过常量的值在定义后不能进行修改。



##### 变量

##### 字符串

##### 表达式

