# chapter4-CompositeType-notes

## 第四章 《复合类型》笔记



## 数组

#### 一维数组的定义

定义一维数组的通用格式：

```c++
typeName arrayName[arraySize];
```

实例：

```C++
int A[10];
```

> 数组是一种复合类型，它创建时所有值在编译时都必须是已知的。即：arraySize不能是**变量**。
>
> 使用`int A[10];`进行创建的方法属于栈空间，栈空间有计算机底层的支持，压栈和出栈都有专门的指令，效率较高。



若想要动态进行一维数组的创建，可以用函数`new`申请堆空间：

```C++
int n;
cin >> n;
int *A = new int[n];
```

> C语言允许直接将数组指针`A`作为数组名使用，C++继承了这一特性。
>
> 使用堆空间通过函数动态获取空间，涉及可用空间[链表](https://so.csdn.net/so/search?q=链表&spm=1001.2101.3001.7020)的扫描和调整以及相邻可用空间的合并等操作，效率相对较低。



`sizeof`运算符返回类型或数据对象的长度（单位为字节）。



#### 二维数组的定义

定义二维数组的通用格式：

```c++
typeName arrayName[arraySize1][arraySize2];
```

实例，申请栈空间：

```C++
int A[10][10];
```

若想要动态进行一维数组的创建，可以用函数`new`申请堆空间：

```C++
int n;
cin >> n;
int **A = new int*[n]; // 创建一维指针数组A，记录二维数组A中每一列的起始地址
for (int i = 0; i < n; i++){
    A[i] = new int[n]; // 创建n个指针Ai指向的一维数组
}
```



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



#### 指针的概念

现在，有一种新的策略，它在开发C++类时非常重要。

这种策略以指针为基础，**指针是一个变量，其存储的是值的地址，而不是值本身。**

> 如何找到常规变量的地址：对变量应用取地址符(`&`)，就可以获得它的位置。如果`home`是一个变量，那么`&home`是它的地址。
>
> 地址可以cout输出，cout使用十六进制表示法，这也是常用于内存的表示法



#### 指针与值的关系

使用常规的变量时，值是指定的量，而地址为派生量。

这种新的策略中，地址是指定的量，而值是派生量。

一种特殊类型的变量——**指针**用于存储值的地址。因此，指针名表示的是地址。

`*`运算符被称为间接值（indirect value）或解除引用运算符（dereferencing），将其用于指针，可以得到该地址处存储的值。

> C++根据上下文来确定*指的是乘法还是解除引用。

假设`manly`是一个指针，则`manly`表示的是一个地址，而`*manly`表示存储在这个地址中的值。`*manly`与常规int变量等效。

```C++
// 值的定义
int a;

// 指针的定义
int * p_a = &a;

// 赋值
a = 6;		// 给变量a赋值
*p_a = 6;	// 修改指针p_a指向的值

// 读取值
cout << a;
cout << *p_a;	// *运算符可获得指针指向的值

// 读取指针
cout << p_a;
cout << &a;		// &运算符可获得值的地址
```

> 传统上，C程序员使用`int *ptr;` 强调*ptr是一个int类型的值。
>
> 而很多C++程序员使用`int* ptr;` 强调int*是一种类型：指向int的指针。
>
> 在哪里添加空格对于编译器来说没有任何区别。



#### 指针的危险

在C++中创建指针时，计算机将分配用来存储地址的内存，但不会分配用来存储指针所指向的数据的内存。

为数据提供空间是一个独立的步骤。

示例：

```C++
long* fellow;		// create a pointer-to-long
*fellow = 23333;	// place a value in never-never land
```

fellow是一个指针，但没有初始化，所以它可能指向任何位置。如果指向系统代码的位置，有可能导致难以跟踪的bug。

>  也称为空对象。

**一定要在对指针应用解除引用运算符`*`之前，将指针初始化为一个确定的、恰当的地址。**



#### `new ` 和 `delete`管理动态内存

指针经常用于在运行时分配未命名的内存以存储值。这种情况下，只能通过指针来访问内存。

在C语言中，可以用库函数`malloc()`来分配内存。

在C++中也可以用，但更常用`new`运算符。



##### `new`分配内存

在运行阶段为一个int值分配未命名的内存，并使用指针来访问这个值。

程序员要告诉new，需要为哪种数据类型分配内存；new将找到一个长度正确的内存块，并返回该内存块的地址。

示例：

```C++
int* pn = new int;
```

`new int`告诉程序，需要适合存储int类型的内存。new运算符根据类型来确定需要多少字节的内存。然后它找到这样的内存，并返回其地址。接下来，将地址赋给pn，pn是被声明为指向int的指针。

> 现在，pn是地址，而*pn是存储在那里的值。

原本的方法示例：

```C++
int data;
int* pd = &data; 
```



`new`分配的内存块通常与常规变量声明分配的内存块不同。变量data和pd的值都存储在被称为栈<kbd>stack</kbd>的内存区域中，而new从被称为堆<kbd>heap</kbd>或自由存储区<kbd>free store</kbd>的内存区域分配内存。



##### `delete`释放内存

使用`delete`时，后面要写上指向内存块的指针。

示例：

```C++
int* pd = new int;
*pd = 1000;
// ...
delete pd;
```

这将释放pd指向的内存，但不会删除指针pd本身。例如，可以将pd重新指向另一个新分配的内存块。

一定要配对地使用new和delete，否则将发生**内存泄漏**<kbd>memory leak</kbd>，也就是说，被分配的内存将再也无法使用。

> 也不能释放已经释放的内存块，这样做的标准是不确定的，什么情况都有可能发生。
>
> 也不能用delete来释放用声明变量所获得的内存。



##### `new`创建动态数组

在编译时给数组分配内存被称为静态联编<kbd>static binding</kbd>。

使用new时，可以在程序运行过程中选择是否创建或自定义创建数组的长度，这被称为动态联编<kbd>dynamic binding</kbd>。意味着数组是在运行时创建的。这种数组被称为动态数组<kbd>dynamic array</kbd>。

创建动态数组示例：

```C++
int* pt = new int[10];	// get a block of 10 ints
```

删除动态数组示例：

```C++
delete [] pt;	// free a dynamic array
```



##### 动态数组的使用

C/C++中，数组和指针是等价的，可以把指针当作数组名使用。

示例：

```C++
double* pd = array;
```

和所有的数组一样，存在下列的等式：

```C++
pd == array == &array[0]
```



##### 数组和指针的不同

- 可以修改指针的值，而数组名是常量
- 对数组使用sizeof将得到数组的长度，而对指针使用sizeof将得到指针的长度，即使指针指向的是一个数组。

> 对数组取地址时，地址名也不会被解释为其地址。数组名被解释为其第一个元素的地址，而对数组名应用取地址符时，得到的是整个数组的地址。



##### 指针算术

C++允许将整数与指针相加。加1的结果等于原来的地址值加上指向的对象占用的总字节数。

示例：

```C++
double* pd = new double;
pd = pd - 1;	// 减少8个字节

int* pi = new int;
pi = pi - 1;	// 减少4个字节
```



##### 指针和字符串

```C++
char* s = "bird";
```

`"bird"`实际上表示的是字符串的地址，因此这条语句把地址赋值给了s指针。

可以通过`strcpy()`和`new`，获得字符串的两个独立副本。



`=`复制字符串示例：

```C++
string animal = "fox";
string ps;
ps = animal;
```

> 这样ps与animal的地址相同，也就是说，复制的是地址，不是值。



`new`复制字符串示例：

```C++
ps = new char[strlen(animal) + 1]; // get new storage
```



`strcpy()`复制字符串示例：

```C++
strcpy(ps, aniaml);	// copy string to new storage
```

> `strcpy()`有两个参数，第一个参数是目标字符串的地址，第二个参数是要复制的字符串的地址



##### `new`创建动态结构

```C++
struct inflatable{
    string name;
    int year;
};

inflatable* pi = new inflatable;
```

> 这将足以存储inflatable结构的一块可用内存的地址赋给pi。



访问结构成员的方法：

- 创建动态结构时，不能将成员运算符句点用于结构名，因为这种结构没有名称，只知道地址。C++专门为这种情况提供了一个运算符：箭头成员运算符`->`，可用于指向结构的指针，就像点运算符可以用于结构名一样。例如，如果pi指向一个inflatable结构，则`pd->name`是被指向的结构的name成员。

<img src="/Users/wyrm/Downloads/IMG_0230.jpg" alt="IMG_0230" style="zoom: 33%;" />

- 另一种方法是，如果pi是指向inflatable的指针，那么*pi就是被指向的值——结构本身。

  由于*pi是一个结构，因此`(*pi).year`是该结构的year成员。



#### 自动存储、静态存储和动态存储

1. 自动存储

在函数内部定义的常规变量使用自动存储空间，被称为自动变量 （automatic variable），只在包含它的代码中有效，这意味着它们在所属的函数被调用时自动产生，在该函数结束时消亡。

自动变量通常存储在栈中。

2. 静态存储

静态存储是整个程序执行期间都存在的存储方式。使变量成为静态 的方式有两种：一种是在函数外面定义它；另一种是在声明变量时使用 关键字 `static`。

3. 动态存储

`new` 和 `delete` 运算符提供了一种比自动变量和静态变量更灵活的方法。它们管理了一个内存池，这在C++中被称为自由存储空间（free store）或堆（heap）。该内存池同用于静态变量和自动变量的内存是分开的。



#### 类型组合：指针数组（指向指针的指针）

```C++
#include <iostream>
using namespace std;

struct pd{
    int year;
    string name;
};

int main(){
    pd s1 = {1,"Andy"}, s2 = {2,"Bob"}, s3 = {3, "Candy"};
    pd *p[3] = {&s1, &s2, &s3};
    cout << s1.name << endl;
    cout << p[1]->name << endl;
    cout << (*p[2]).name << endl;
    pd **pp = p;
    cout << (*p[0]).year << endl;
    return 0;
}
```



#### `vector` 和 `array`类简介

`vector`和`array`是数组的替代品。模板类 `vector` 类似于 `string` 类，也是一种动态数组，创建时要包含头文件 vector 。可以在运行阶段设置 `vector` 对象的长度，也可在末尾附加新数据，还可以在中间插入新数据，`vector` 的长度不要求必须设定，因为它会依据插入的数据量自动增长，容量增长的速度是 2 的 `n` 次方。

基本上，它是使用 `new` 创建动态数组的替代品。实际上，`vector` 类确实使用 `new` 和`delete` 来管理内存，但这种工作是自动完成的。

##### vector

在c++中，vector是一个十分有用的容器。

作用：它能够像容器一样存放各种类型的对象，简单地说，vector是一个能够存放任意类型的动态数组，能够增加和压缩数据。

vector在C++标准模板库中的部分内容，它是一个多功能的，能够操作多种数据结构和算法的[模板类](http://baike.baidu.com/view/1923683.htm)和函数库。

**`vector` 的声明方式：**

```Cpp
#include<vector>
vector<typeName> v_name(number);
```

这样 v_name 就是一个 vector 对象，但 number 不是必须的。

**实例1：**

```C++
vector<int>test;	//建立一个vector，int为数组元素的数据类型，test为动态数组名
```

简单的使用方法如下：

```C++
vector<int> test;	//建立一个vector
test.push_back(1);
test.push_back(2);	//把1和2压入vector，这样test[0]就是1,test[1]就是2
```

**实例2：**

```C++
vector<vector<int> > test2; //定义一个二维数组
test2[0].size();  	//指第一行的列数
```

**常用基本操作**

1. 头文件  `#include<vector>`
2. 创建vector对象:  `vector<int> vec;`
3. 尾部插入数字：`vec.push_back(a);`
4. 使用下标访问元素:  `cout << vec[0] << endl;` 记住下标是从0开始的。
5. 使用迭代器访问元素

```C++
vector<int> vec;
vector<int>::iterator it;	// 生成迭代器it
for(it = vec.begin(); it != vec.end(); it++)
	cout << *it << endl;
```

> ```C++
> int i;
> vector<int> vec;
> for (i = 0; i< 10; i++) 
>     cout << vec[i] << endl;
> ```
>
> 这种方法也可以读取

6. 插入元素：`vec.insert(vec.begin()+i,a);` 在第i+1个元素前面插入a
7. 删除元素：

```C++
vec.erase(vec.begin()+2);	// 删除第3个元素
vec.erase(vec.begin()+i,vec.end()+j);	// 删除区间[i,j-1];区间从0开始
```

8. 向量大小:  `vec.size();`
9. 清空:  `vec.clear();`

特别提示：这里有`begin()`与`end()`函数、`front()`与`back()`的差别

**重要说明**

vector的元素不仅仅可以是int,double,string,还可以是结构体，但是要注意：结构体要定义为全局的，否则会出错。

```C++
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef struct rect
{
    int id;
    int length;
    int width;

　　//对于向量元素是结构体的，可在结构体内部定义比较函数，下面按照id,length,width升序排序。
　　bool operator< (const rect &a)  const	// 重载操作符<，对两个rect可以使用<操作符进行比较
    {
        if (id != a.id)
            return id < a.id;
        else
        {
            if (length != a.length)
                return length < a.length;
            else
                return width < a.width;
        }
    }
} Rect;

int main()
{
    vector<Rect> vec;
    Rect rect;
    rect.id = 1;
    rect.length = 2;
    rect.width = 3;
    vec.push_back(rect);
    vector<Rect>::iterator it = vec.begin();
    cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;    
return 0;
}
```

**算法**

1. 使用reverse将元素翻转：

   - 需要头文件`#include<algorithm>`

   - `reverse(vec.begin(),vec.end());`将元素翻转，即逆序排列
   - (在vector中，如果一个函数中需要两个迭代器，一般后一个都不包含)

2. 使用sort排序：

   - 需要头文件`#include<algorithm>`

   - `sort(vec.begin(),vec.end());`默认是按升序排列,即从小到大

     可以通过重写排序比较函数按照降序比较，如下：

     定义排序比较函数：

     ```C++
     bool Comp(const int &a,const int &b)
     {
         return a>b;
     }
     ```

     调用:

     ```C++
     sort(vec.begin(),vec.end(),Comp);	// 降序排序
     ```

3. 输出Vector中的元素   

```C++
vector<float> vecClass; 
int nSize = vecClass.size();   

 //打印vecClass,方法一：使用数组下标 
for (int i = 0; i < nSize; i++)  
   cout << vecClass[i] << " ";
cout << endl;

//打印vecClass,方法二：使用at函数     
for (int i = 0; i < nSize; i++)  
   cout << vecClass.at(i) << " "; 
cout << endl;  

//打印vecClass,方法三：使用迭代器（输出某一指定的数值时不方便）
for (vector<float>::iterator it = vecClass.begin(); it != vecClass.end(); it++)  
    cout << *it << " ";  
cout << endl;
```

> 需要注意的是：以方法一进行输出时，数组的下标必须保证是整数。 



二维数组的使用：

```C++
#include <vector> 
#include <iostream> 
using namespace std;
int main()
{
	int out[3][2] = { 	1, 2, 
			 			3, 4,
						5, 6 };
	vector <int*> v1;
 
	v1.push_back(out[0]);
	v1.push_back(out[1]);
	v1.push_back(out[2]);
 
	cout << v1[0][0] << endl; 	// 1
	cout << v1[0][1] << endl; 	// 2
	cout << v1[1][0] << endl; 	// 3
	cout << v1[1][1] << endl; 	// 4
	cout << v1[2][0] << endl; 	// 5
	cout << v1[2][1] << endl; 	// 6
 
	return 0;
}
```



其他用法

```C++
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> sv;  // create vector, can create without num
    int n;
    sv.assign(10, 1);   // assign: can init vector
    for (int i = 0; i < sv.size(); ++i) {
        cout << sv.at(i) << ' '; // at: can read
    }
    cout << endl;
    sv.at(sv.size() - 1) = 9;   // at: can wirte
    sv.at(0) = 0;
    cout << sv.back() << endl;  // back: can r/w the last one
    cout << *sv.begin() << endl; // begin: a pointer
    for (int i = 0; i < 5; ++i) {
        cin >> n;
        sv.push_back(n);    // push_back: add the last one of vector
    }
    for (int i = 0; i < sv.size(); ++i) {
        cout << sv.at(i) << ' '; // at: can read
    }
    cout << endl;
    sv.pop_back();  // pop_back: pop the last one of vector
    for (int i = 0; i < sv.size(); ++i) {
        cout << sv.at(i) << ' '; // at: can read
    }
    return 0;
}
```

