#### 1. 数据类型

##### 1.1 整型（存储整数）

- 长整型 `long long`：可存储的数字范围是<kbd>-9223372036854775808 ~ 9223372036854775807</kbd>（19位数）
- 整型 `int`：可存储的数字范围是<kbd>-2147483648 ~ 2147483647</kbd>(-21亿～21亿，10位数)



##### 1.2 浮点型（存储小数）

- 单精度浮点型`float`：整个数的有效数字6～7位（1.23456）
- 双精度浮点型`double`：整个数的有效数字15～16位（1.2345678910）



#### 2. 格式化输出语句`printf()`

> 专门用于输出有效小数位n位、输出有效字符宽度的情况

##### 2.1 `printf()`的语法

`printf()`是一个需要指定输出的数据类型的输出语句。只有输出字符、字符串时不需要额外说明数据类型

**输出字符串**

```C++
printf("hello, world!");
```

**输出换行符**

```C++
printf("\n");
```

**输出字符串并换行**

```C++
printf("hello, world!\n");
```

**输出字符以外的数据**

```C++
printf("格式控制符", 数据);
```

> <img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726223615194.png" alt="image-20220726223615194" style="zoom:35%;" />
>
> 输出纯数字及表达式
>
> ```C++
> printf("%d", 123);			// 输出整数123
> printf("%d", 123 + 456);	// 输出表达式 123+456 的结果
> ```
>
>  
>
> 输出字符宽度为m的整数a：`printf("%md", a);`
>
> ```C++
> int a;
> cin >> a;
> printf("%8d", a);	// 输出宽度为8位整数的整数a
> ```
>
>  
>
> <img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726224028647.png" alt="image-20220726224028647" style="zoom:35%;" />
>
> 
>
> 输出保留m位小数的实数a：`printf("%.mf",a);`
>
> > 实数包括：小数（浮点数）和整数
>
> ```C++
> double a;
> cin >> a;
> printf("%.12f", a);	// 输出保留12位小数的实数a
> ```

>
>
>还有其他的格式控制符：
>
><img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726230842932.png" alt="image-20220726230842932" style="zoom:35%;" />



练习（用`printf`完成）

1. 【题目要求】输出5行 “`Hello, World!`”

   【样例输入】无

   【样例输出】

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726211413353.png" alt="image-20220726211413353" style="zoom:50%;" />

2. 【题目要求】输入一个双精度浮点数，输出这个数（保留3位小数）

​		【样例输入1】3.1415926535

​		【样例输出1】3.141

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726220813002.png" alt="image-20220726220813002" style="zoom:50%;" />

​		【样例输入2】0.1234567890

​		【样例输出2】0.123

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726220832767.png" alt="image-20220726220832767" style="zoom:50%;" />

3. 【题目要求】输入一个整数，输出这个数（字符宽度为8）

​		【样例输入1】12345678

​		【样例输出1】12345678

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726221124389.png" alt="image-20220726221124389" style="zoom:50%;" />

​		【样例输入2】8

​		【样例输出2】               8

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726221147089.png" alt="image-20220726221147089" style="zoom:50%;" />

​		【样例输入3】-1

​		【样例输出3】              -1

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726221202515.png" alt="image-20220726221202515" style="zoom:50%;" />

4. 输出三角形

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726222657578.png" alt="image-20220726222657578" style="zoom:50%;" />

5. 输出1+2

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726222729949.png" alt="image-20220726222729949" style="zoom:67%;" />



6. 输出1+2的结果

<img src="/Users/wyrm/Library/Application Support/typora-user-images/image-20220726224326944.png" alt="image-20220726224326944" style="zoom:60%;" />



**混合输出（多个变量+其他字符串）**

```C++
printf("字符串+格式控制符1+字符串+格式控制符2", 数据1, 数据2);
```

> 【题目要求】输入一个长方形的长和宽（整数），输出该长方形的周长C和面积S，要求格式如例
>
> 【样例输入】2 5
>
> 【样例输出】
>
> ```
> C:14
> S:10
> ```

> 【样例程序】
>
> ```C++
> int a, b;
> cin >> a >> b;
> printf("C:%d\nS:%d", (a+b)*2, a*b);
> ```



练习（用`printf`完成）

【第二章 顺序结构程序设计】

1026：空格分隔输出

1010：计算分数的浮点数值

1027：输出浮点数

1028：字符菱形



**cout、printf的区别：**cout能够自动识别数据的变量类型，printf在输出时需要指定变量类型。