## 《for循环与if条件》 课堂笔记

#### 上节课作业讲评

作业1：输出10～20的数字

> 思路：
>
> 1. 循环变量的数据类型为int，循环变量初值为10，循环条件为i<=20，循环变量递增值为1
> 2. 输出循环变量i

```C++
#include <iostream>
using namespace std;
int main(){
    for (int i = 10; i <= 20; i++)
        cout << i << endl;
    return 0;
}
```



作业2：输出a～z的英文字母

> 思路：
>
> 1. 循环变量的数据类型为char，循环变量初值为'a'，循环条件为i<='z'，循环变量递增值为1
> 2. 输出循环变量i和空格

```C++
#include <iostream>
using namespace std;
int main(){
    for (char i = 'a'; i <= 'z'; i++)
        cout << i << ' ';
    return 0;
}
```



作业3：输出1～20的奇数，换行，再输出2～20的偶数。数字之间以空格隔开

> 思路：
>
> 1. 先输出奇数：
>    1. 循环变量的数据类型为int，循环变量初值为1，循环条件为i<=20，循环变量递增值为2
>    2. 输出循环变量i和空格
> 2. 输出换行符
> 3. 再输出偶数：
>    1. 循环变量的数据类型为int，循环变量初值为2，循环条件为i<=20，循环变量递增值为2
>    2. 输出循环变量i和空格

```C++
#include <iostream>
using namespace std;
int main(){
    for (int i = 1; i <= 20; i+=2)
        cout << i << ' ';
    cout << endl;
    for (int i = 2; i <= 20; i+=2)
        cout << i << ' ';
    return 0;
}
```



作业4：倒序输出26个大写字母，换行，再输出26个正序小写字母

> 思路：
>
> 1. 先倒序输出26个大写字母
>    1. 循环变量的数据类型为char，循环变量初值为'Z'，循环条件为i>='A'，循环变量递增值为-1
>    2. 输出循环变量i和空格
> 2. 输出换行符
> 3. 再正序输出26个小写字母
>    1. 循环变量的数据类型为char，循环变量初值为'a'，循环条件为i<='z'，循环变量递增值为1
>    2. 输出循环变量i和空格

```C++
#include <iostream>
using namespace std;
int main(){
    for (char i = 'Z'; i >= 'A'; i--)
        cout << i << ' ';
    cout << endl;
    for (char i = 'a'; i <= 'z'; i++)
        cout << i << ' ';
    return 0;
}
```



#### 1 用输入控制循环次数

示例：输入一个数字n，输出1～n之间的所有数字

>  思路：
>
> 1. 循环变量初值为1，循环条件为i<=n，循环增量为1
> 2. n是从键盘输入的，需要提前定义变量n，然后cin输入
> 3. 输出循环变量i和空格

```C++
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    return 0;
}
```



练习：输入两个数字n1、n2（保证n1<n2），输出n1～n2之间的所有数字

> 思路：
>
> 1. 循环变量初值为n1，循环条件为i<=n2，循环增量为1
> 2. n1和n2是从键盘输入的，需要提前定义变量n1和n2，然后cin输入
> 3. 输出循环变量i和空格

```C++
#include <iostream>
using namespace std;
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = n1; i <= n2; i++)
        cout << i << ' ';
    return 0;
}
```



#### 2 有条件的for循环

【环节重点：学生能够了解带有条件的循环流程、解题思路（先找数据范围、分析输入输出、分析判断条件）

《小学生C++趣味编程 上册》P113 例题：

狐狸老师和格莱尔玩报数游戏。

狐狸老师数到2的倍数时，格莱尔就说“叮叮”；狐狸老师数到3的倍数时，格莱尔就说“当当”；狐狸老师数到2和3的公倍数时，格莱尔就说“叮叮当当”。

​	狐狸老师：1

​	狐狸老师：2

​	格莱尔：叮叮

​	狐狸老师：3

​	格莱尔：当当

​	狐狸老师：4

​	格莱尔：叮叮

​	狐狸老师：5

​	狐狸老师：6

​	格莱尔：叮叮当当

​	.....

试编一程序，模拟老师和格莱尔1~20的报数游戏。

> 思路：可以用循环语句枚举出1~20所有的数，每一个数都去判断，根据不同的判断结果输出不同的内容

程序流程图如下：

```flow
st=>start: 开始
op00=>operation: 循环变量赋初值1
cond=>condition: 循环条件i<=20
op0=>operation: 输出“狐狸老师:”和i
con1=>condition: i%2==0并且i%3==0
op1=>operation: 输出"格莱尔：叮叮当当"
con3=>condition: i%3==0
op3=>operation: 输出"格莱尔：当当"
con2=>condition: i%2==0
op2=>operation: 输出"格莱尔：叮叮"
op4=>operation: 循环变量递增：i++
e=>end: 结束
st(right)->op00->cond
cond(yes)(right)->op0->con1
con1(yes)->op1(right)->cond
con1(no)->con2
con2(yes)->op2(right)->cond
con2(no)->con3
con3(yes)->op3(right)->cond
con3(no)->cond
cond(no)->e
```

编写程序：

```C++
#include <iostream>
using namespace std;
int main(){
    for (int i = 1; i <= 20; ++i) {
        cout << "狐狸老师：" << i << endl;
        if (i % 3 == 0 && i % 2 == 0) cout << "格莱尔：叮叮当当" << endl;
        else if (i % 2 == 0) cout << "格莱尔：叮叮" << endl;
        else if (i % 3 == 0) cout << "格莱尔：当当" << endl;
    }
    return 0;
}
```



想一想：为什么要先判断`i % 3 == 0 && i % 2 == 0`？

> 原因：如果先判断`i % 2 == 0`，能同时被2、3整除的数会被先判断为只能被2整除，输出叮叮。先判断`i % 3 == 0`同理。



练习：书本选择题



#### 3 计数器的概念

在上节课中我们学到，在for循环中，**语句`i = i + 1`，每运行一次，i的值就增加1。这样变量i可以起到统计次数的作用，有计数的功能。**

> 通常我们把拥有计数功能的变量称为**计数器**。如变量`i`就是一个计数器。

我们也将i称作循环变量。

在程序中，有时除了记录循环的运行次数外，还需要额外进行计数：如最常用的统计某个数字出现的次数。这种情况下，需要增加一个功能是计数的变量，用来统计我们想要统计的次数。



#### 4 加上计数器的if嵌套for循环

【环节重点：学生能够回顾计数器的概念，能够分析流程并画出流程图，学习在循环中使用计数器】

例题：请你算一算，在1～20之间，2的倍数有几个？

> 思路：
>
> 1. 循环变量初值为1，循环条件为i<=20，循环增量为1
> 2. 创建一个计数变量t，t的初值为0
> 3. 每一个数都判断是不是2的倍数，若是，计数器t加1
> 4. 输出计数器t

```flow
st=>start: 开始
op0=>operation: 循环变量赋初值1
cond=>condition: 循环条件i<=20
op1=>operation: 创建计数器t，赋初值0
con1=>condition: i%2==0
op2=>operation: 计数器t加1
op4=>operation: 循环变量递增：i++
e=>end: 结束
st(right)->op0->cond
cond(yes)(right)->con1
con1(yes)->op2(left)->cond
con1(no)->cond
cond(no)->e
```



```C++
#include <iostream>
using namespace std;
int main(){
    int t = 0;
    for (int i = 1; i <= 20; ++i) {
        if (i % 2 == 0) t++;
    }
    cout << t;
    return 0;
}
```



练习：请你依次输出在1～20之间2的倍数的数量、3的倍数的数量和2与3的公倍数的数量

> 思路：
>
> 1. 循环变量初值为1，循环条件为i<=20，循环增量为1
> 2. 创建三个计数变量t1、t2、t3，初值都为0
> 3. 每一个数都判断是不是2的倍数，若是，计数器t1加1
> 4. 每一个数都判断是不是3的倍数，若是，计数器t2加1
> 5. 每一个数都判断是不是2与3的倍数，若是，计数器t3加1
> 6. 输出计数器t1，空格，t2，空格，t3

```C++
#include <iostream>
using namespace std;
int main(){
    int t1 = 0, t2 = 0, t3 = 0;
    for (int i = 1; i <= 20; ++i) {
        if (i % 2 == 0 && i % 3 == 0) t3++;
        else if (i % 2 == 0) t1++;
        else if (i % 3 == 0) t2++;
    }
    cout << t1 << ' ' << t2 << ' ' << t3;
    return 0;
}
```



练习：输入m和n，统计m到n之间（包括m、n）的偶数有多少个

> 思路：
>
> 1. 创建整型变量m、n
> 2. 输入m、n的值
> 3. 循环变量初值为m，循环条件为i<=n，循环增量为1
> 4. 创建一个计数变量t，初值为0
> 5. 每一个数都判断是不是偶数，若是，计数器t加1
> 6. 输出计数器t

```C++
#include <iostream>
using namespace std;
int main(){
    int t = 0, m, n;
    cin >> m >> n;
    for (int i = m; i <= n; ++i) {
        if (i % 2 == 0) t++;
    }
    cout << t;
    return 0;
}
```



课后练习：

http://noi.openjudge.cn/ch0105/11/

http://noi.openjudge.cn/ch0105/12/


