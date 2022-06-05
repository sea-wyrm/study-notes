# chapter4-CompositeType-notes

### 第四章 《复合类型》笔记



## 数组

***

#### 数组的定义

定义数组的通用格式：

```c++
typeName arrayName[arraySize];
```

> 数组是一种复合类型，它创建时所有值在编译时都必须是已知的。即：arraySize不能是**变量**。



`sizeof`运算符返回类型或数据对象的长度（单位为字节）。



#### 数组的初始化

只有在定义数组时才能使用初始化，此后就不能使用了，也不能将一个数组赋值给另一个数组：

```C++
int a[4] = {1, 2, 3, 4}; 	// okay
int b;		// okay
int c = a;	// okay

a[4] = {1, 2, 3, 4};		// not allowed
b = a;		// not allowed
```

> 1. 初始化数组时，提供的值可以少于数组的元素数目，编译器将把其他元素设置为0。
>
>    > `int a[10] = {0};`是一种方便将所有元素初始化为0的写法。
>
> 2. 若初始化数组时`[]`为空，则编译器将计算提供的元素个数。（不推荐使用，因为值有可能被遗漏）



C++11中，初始化数组可省略 (=)，也可以在大括号中不包含任何东西（这将所有元素设置为0）。





## 字符串

***

### C-风格字符串

#### 字符串的初始化

C-风格字符串具有一种特殊的性质：以空字符<kbd>null character</kbd>结尾，空字符被写作`'\0'`，其ASCII码为0，用来标记字符串的结尾。

```c++
char dog[8] = {'T', 'o', 'n', 'y'}; 		// not a string
char cat[8] = {'M', 'i', 'l', 'k', '\0'}; 	// a string
```

> C++中处理字符串的函数，都逐个处理字符串中的字符，直到发现`'\0'`为止。



另一种更便携的初始化方法：使用一个用引号括起的字符串，这种字符串被称为字符串常量<kbd>string constant</kbd>或字符串字面值<kbd>string literal</kbd>，如下所示：

```c++
char dog[8] = "Tony";	// the '\0' is understood
char cat = "Milk";		// let the compiler count
```

> C++对字符串长度没有限制。因此，让编译器<kbd>compiler</kbd>来计算字符元素数量更为安全。



#### 字符常量与字符串常量的区别

**注意：字符串常量（使用双引号）不能与字符常量（使用单引号）互换。**

**原因：**	

1. 字符常量（如 `'S'`）是字符编码的简写表示。在ASCII系统上，`'S'`只是`83`的另一种写法。
2. 字符串常量（如`"S"`）不是字符常量，它表示两个字符（字符`S`和`\0`）组成的字符串。且`"S"`实际上表示的是字符串所在的内存地址。



#### 拼接字符串

有时候，字符串很长，无法放到一行中。C++可以将两个用引号括起的字符串合并为一个。事实上，任何由空白（空格、制表符、换行符）分隔的字符串常量都将自动拼合成一个。

因此，以下输出语句都是等效的：

```c++
cout << "Today is a good day.\n";
cout << "Today ""is a good day.\n";
cout << "Today "
    	"is a good day.\n";
```

> 拼接时不会在连接的字符串之间添加空格，第一个字符串中的`'\0'`将被第二个字符串的第一个字符取代。



#### 字符串长度

`sizeof(arrayName)`：求整个数组的长度

`strlen(arrayName)`：求在数组中的字符串长度，且只计算可见字符，而不把空字符计算在内。

> 样例程序： [chapter4-strings.cpp](chapter4-strings.cpp) 



#### 字符串输入

1. 面向单词的输入：`cin`

   > 使用空白（空格、制表符、换行符）来确定字符串的结束位置。

2. 面向行的输入：`getline()`

   > `getline()`函数读取整行，利用换行符来确定输入结尾，**但不保存换行符**。
   >
   > 要调用这种方法，可以使用`cin.getline()`，该函数有两个参数：
   >
   > > 第一个参数是用来存储输入行的数组名称
   > >
   > > 第二个参数是要读取的字符数，若参数为20，则最多读取19个字符，最后一个存储自动在结尾添加的空字符
   >
   > ````c++
   > cin.getline(name1, 20); // 将把一行读入到name1数组中
   > cin.getline(name2, 20);	// 将把下一行读入到name2数组中
   > ````

3. 面向行的输入：`get()`

   > `get()`函数与`getline()`函数类似，参数相同，都读取到行尾，**但不再读取并丢弃换行符，而是将其留在输入队列中。**
   >
   > ```c++
   > cin.get(name1, 20);	// 将把一行读入到name1数组中
   > cin.get();			// 获取换行符，开启新行
   > cin.get(name2, 20);	// 将把下一行读入到name2数组中
   > ```



### string 类字符串

string对象和字符数组之间的主要区别是，可以将字符声明为简单变量

程序读取输入时候，将自动调整string对象的长度

需要使用头文件`<cstring>`

#### string的赋值、拼接、附加

> 可以将一个string对象赋给另一个string对象
>
> ```c++
> string a = "1234";
> string b;
> b = a;
> ```

> 可以用运算符`+`将两个string对象合并起来，也可以用`+=`。



####  string的其他操作

```c++
strcpy(char1, char2);	// copy char2 to char1
strcat(char1, char2);	// append contents of char2 to char1, 将 char2 的内容附加到 char1末尾

str1.size();			// obtain length of str1
strlen(char2);			// obtain length of char2
```

> `size()`与`strlen()`功能大致相同，语法不同：
>
> > C函数使用参数来指出要用哪个字符串
> >
> > C++ string类对象使用对象名和句点运算符来指出要用哪个字符串



#### string的输入

```C++
getline(cin, str);
```

> 将cin作为参数，指出到哪里去查找输入。
>
> 没有指出字符串长度，因为string对象将根据字符串的长度自动调整自己的大小

## 

## 结构

结构定义：
$$
\overbrace{struct}^{\text{关键字}} \ \ \ \ \overbrace{inflatable}^{\text{标记成为新类型的名称}} \\
左大括号和
右大括号
\begin{Bmatrix}
\{ \\
& char & name[20]; & \\
& float & volume;  & \\
& double & price; & \\
\ \underbrace{\};}_{\text{结束结构声明}}
\end{Bmatrix}结构的成员
$$

样例：


```C++
struct name{
  	int n1;
    double n2;
    int n3[100];
};

name peo = {1, 2, {0}};
```

> C++ 不提倡使用外部变量，但提倡使用外部结构声明。



## 共用体

共用体是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种数据类型。

> 也就是说，结构可以同时存储int、float和double，但共用体只能存储int、float或double。

样例：

```C++
union one4all
{
    int int_val;
    long long_val;
    double double_val;
};
```

可以使用one4all变量来存储int、long或double，但需要在不同的时间进行：

```C++
one4all pail;
pail.int_val = 15;		// store an int
cout << pail.int_val;
pail.double_val = 1.38;
cout << pail.double_val;	// store a double, int value is lost
```

共用体的用途：当数据项使用两种或更多种格式（但不会同时使用）时，可以节省空间。



## 枚举

`enum`可以创建符号常量，可以代替const。

样例：

```C++
enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
```

这条语句完成两项工作：

- 让spectrum成为新类型的名称：spectrum被称为**枚举**<kbd>enumeration</kbd>，就像struct变量被称为结构一样。
- 将red、orange、yellow等作为符号常量，它们对应整数值0~7。这些常量叫做**枚举量**<kbd>enumerator</kbd>。

> 在默认情况下，将整数值赋给枚举量，第一个枚举量的值为0，第二个枚举量的值为1，以此类推。可以通过显式地指定整数值来覆盖默认值。

可以用枚举名来声明这种类型的变量：

```C++
spectrum band;	// band: a variable of sype spectrum
```

在不进行强制转换的情况下，只能将定义枚举时使用的枚举量赋给这种枚举的变量：

```C++
band = blue;	// valid, blue is an enumerator
band = 2000;	// invalid, 2000 is not an enumerator
```

枚举量是整型，可被提升为int类型，但int类型不能自动转换为枚举类型：

```C++
int color = blue;	// valid, spectrum type promoted to int
band = 3;		// invalid, int not converted to spectrum
color = 3 + red;	// valid, red converted to int
```



## 指针

计算机程序在存储数据时必须跟踪的3种基本属性：

- 信息存储在何处
- 存储的值为多少
- 存储的信息是什么类型

> 以往，我们用了一种策略来达到以上的目的：定义一个简单变量。声明语句指出了值的类型和符号名，还让程序为值分配内存，并在内部跟踪该内存单元。



现在，有一种新的策略，它在开发C++类时非常重要。

这种策略以指针为基础，**指针是一个变量，其存储的是值的地址，而不是值本身。**

> 如何找到常规变量的地址：对变量应用取地址符(`&`)，就可以获得它的位置。如果`home`是一个变量，那么`&home`是它的地址



## `new ` 和 `delete`管理动态内存

## 动态数组

## 自动存储、静态存储和动态存储

## `vector` 和 `array`类简介

