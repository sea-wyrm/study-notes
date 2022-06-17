## 第五章《循环和关系表达式》笔记

#### 使用`cin.get()`实现循环输入

```C++
#include <iostream>
using namespace std;

int main(){
    char ch;
    string s;
    while (ch != '\n'){
        cin.get(ch);
        s += ch;
    }
    cout << s;
    return 0;
}
```



##### 两种`cin.get()`用法

函数重载允许创建多个同名函数，条件是它们 的参数列表不同。例如，如果在C++中使用 `cin.get(name，ArSize)`， 则编译器将找到使用 `char*` 和 `int` 作为参数的 `cin.get()` 版本；如果使用 `cin.get(ch)`，则编译器将使用接受一个 `char` 参数的版本；如果没有提供参数，则编译器将使用不接受任何参数的`cin.get()` 版本。函数重载允许对多个相关的函数使用相同的名称，这些函数以不同方式或针对不同类型执行相同的基本任务。

```C++
cin.get(ch, 8); // input char[8](*char)
```

```C++
cin.get(ch);	// input a char
```



##### 文件尾条件

如果输入来自于文件，则可以使用一种功能更强大的技术—检测文件尾（EOF）。C++输入工具和操作系统协同工作，来检测文件尾并将这种信息告知程序。

检测到EOF后，cin将两位（eofbit和failbit）都设置为1。可以通过成员函数`eof( )`来查看eofbit是否被设置；如果检测到EOF，则`cin.eof( )`将返回bool值true，否则返回false。同样，如果eofbit或failbit被设置为1， 则fail( )成员函数返回true，否则返回false。

```C++
if (cin.fail() == false) // test EOF
```

为成功地使用cin.get( )，需要知道其如何处理EOF条件。当该函数到达EOF时，将没有可返回的字符。相反，`cin.get( )`将返回一个用符号常量`EOF`表示的特殊值。该常量是在头文件iostream中定义的。EOF值必须不同于任何有效的字符值，以便程序不会将EOF与常规字符混淆。 通常，EOF被定义为值−1，因为没有ASCII码为−1的字符，但并不需要知道实际的值，而只需在程序中使用EOF即可。

```C++
if ((ch = cin.get()) != EOF) // test for end of file
```



##### 另一个cin.get( )版本

上述程序中使用了`ch = cin.get()`这种方式。以下是它们的区别：

![image-20220617134342951](/Users/wyrm/Library/Application Support/typora-user-images/image-20220617134342951.png)

那么应使用cin.get( )还是cin.get(char)呢？使用字符参数的版本更符合对象方式，因为其返回值是istream对象。这意味着可以将它们拼接起来。例如，下面的代码将输入中的下一个字符读入到ch1中，并将接下 来的一个字符读入到ch2中:

```Cpp
cin.get(ch1).get(ch2);
```



#### vector创建二维数组

