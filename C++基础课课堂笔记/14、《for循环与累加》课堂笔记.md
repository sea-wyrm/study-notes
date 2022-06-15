## 《for循环与累加》课堂笔记

#### 1 累加器【复习】

**示例问题：**

试编一程序，算一算《雪花》第一句中数字1、2、3、4的和是多少？

<img src="../../../Library/Application%20Support/typora-user-images/image-20220615155806722.png" alt="image-20220615155806722" style="zoom:40%;" />

```C++
#include <iostream>
using namespace std;
int main(){
    int sum = 0;
    sum = sum + 1; 	// 第1次运算后sum的结果：
    sum = sum + 2; 	// 第2次运算后sum的结果：
    sum = sum + 3;	// 第3次运算后sum的结果：
    sum = sum + 4;	// 第4次运算后sum的结果：
    cout << "1+2+3+4= " << sum <<endl;	// 输出结果
    return 0;
}
```

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220615163455081.png" alt="image-20220615163455081" style="zoom:40%;" />

赋值语句`sum = sum + i;`，就是把原来sum的值加上i的值，然后再赋值给sum。每运行一次，就加一个新的i值，这样变量sum就可以起到累加求和的作用。

> 通常我们把拥有累加求和功能的变量称为**累加器**。如变量`sum`就是一个累加器。
>
> 由于分配给变量的内存上可能已经存在值，所以需要给累加器做初始化为零的操作，以防影响累加结果。（计数器也一样）



#### 2 累加求和

**示例问题：**布纳特老师出的难题

德国“数学王子”高斯三岁时便能够纠正父亲的借款账目。十岁时，有一次布纳特老师出了一道算术题：求1到100所有整数的和，老师刚叙述完题目，高斯就算出了正确答案。

试编一程序，先求1+2+3+4+5的和。

```flow
st=>start: 开始
op1=>operation: 累加器sum = 0
cond=>condition: i <= 5
op2=>operation: i = 1
op3=>operation: sum = sum + i
op4=>operation: i++
op5=>operation: 输出sum的值
e=>end: 结束
st(right)->op1(right)->op2->cond(right)
cond(yes)->op3->op4(left)->cond
cond(no)->op5->e
```

用变量sum作为累加器，设初始值为0，运用循环让sum依次加上1、2、3、4、5，最终求出它们的和。

```C++
#include <iostream>
using namespace std;
int main(){
    int sum = 0;
    for (int i = 1; i <= 5; ++i) {
        sum = sum + i;
    }
    cout << sum;
    return 0;
}
```

> 其中`sum = sum + i;`也可以写作`sum += i;`
>
> `+=`、`-=`、`*=`、`/=`、`%=`是复合运算符，是对`sum = sum + i`这类累加运算（以及其他类似运算）的缩写。



**练习**：如何求1+2+3+4+5...+99+100的和？

```C++
#include <iostream>
using namespace std;
int main(){
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum = sum + i;
    }
    cout << (double) sum / 100;
    return 0;
}
```



**总结：**我们来总结一下编程解决这种累加问题的基本方法

1. 累加器sum初始化为0
2. 写上循环的起点、终点和加数的变化规律
3. 重复做累加运算
4. 输出累加器sum的值



小提问：如果想要求1～100的平均数怎么求呢？

> 修改一下第四步：输出累加器sum/个数100的值



#### 3 累加和的应用

【01:求平均年龄】http://noi.openjudge.cn/ch0105/01/

```flow
st=>start: 开始
op0=>operation: 定义累加器sum、次数n、输入的年龄age，其中sum=0
cond=>condition: i <= 5
op1=>operation: 输入个数n
op2=>operation: i = 1
op3=>operation: sum = sum + age
op4=>operation: i++
op5=>operation: 格式化输出平均年龄（总年龄sum/人数n）
op6=>operation: 输入年龄age
e=>end: 结束
st(right)->op0->op1->op2->cond(right)
cond(yes)->op6->op3->op4(left)->cond
cond(no)->op5->e
```

```C++
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int sum = 0, n, age;
    for (int i = 1; i <= n; ++i) {
        cin >> age;
        sum = sum + age;
    }
    cout << fixed << setprecision(2) << (double)sum / n;
    return 0;
}
```



**总结：**我们来总结一下编程解决这种有输入的值总和/平均数问题的基本方法

1. 定义值的个数n、定义用来存储输入的值的变量a、定义累加器sum
2. 累加器sum初始化为0
3. 写上循环的次数
4. 将一个待累加的值输入到a中：cin>>a
5. 将这个值a累加到sum中：sum+=a
6. 根据题目要求输出累加器sum的值或输出平均数sum/n



**练习：**

【02:财务管理】http://noi.openjudge.cn/ch0105/02/

【03:均值】http://noi.openjudge.cn/ch0105/03/

【04:求整数的和与均值】http://noi.openjudge.cn/ch0105/04/



#### 4 拓展练习

【08:多边形内角和】http://noi.openjudge.cn/ch0105/08/（可拓展累减）

【07:奥运奖牌计数】http://noi.openjudge.cn/ch0105/07/（多项累加）

【09:奇数求和】http://noi.openjudge.cn/ch0105/09/（有条件的累加）





**后面的内容待定：**

累加和、阶乘、



累减（多边形内角和）

http://noi.openjudge.cn/ch0105/08/

求极值

[ 整数序列的元素最大跨度值](http://noi.openjudge.cn/ch0105/06/)

多项求和

[ 奥运奖牌计数](http://noi.openjudge.cn/ch0105/07/)

单项求和

[ 多边形内角和](http://noi.openjudge.cn/ch0105/08/)

带条件的求和

[ 奇数求和](http://noi.openjudge.cn/ch0105/09/)

[ 满足条件的数累加](http://noi.openjudge.cn/ch0105/10/)