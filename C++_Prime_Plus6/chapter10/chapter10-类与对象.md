# 第十章 对象和类

本章内容包括：

- 过程性编程和面向对象编程；
- 类概念；
- 如何定义和实现类；
- 公有类访问和私有类访问；
- 类的数据成员；
- 类方法（类成员函数）；
- 创建和使用类对象；
- 类的构造函数和析构函数；
- const 成员函数；
- this 指针；
- 创建对象数组；
- 类作用域；
- 抽象数据类型。

面向对象编程（OOP）是一种特殊的、设计程序的概念性方法，OOP的最终特性是：

- 抽象；
- 封装和数据隐藏；
- 多态；
- 继承；
- 代码的可重用性。

为了实现这些特性并将它们组合在一起，C++所做的最重要的改进是提供了类。



## 10.1 过程性编程和面向对象编程

采用过程性编程方法时，首先考虑要遵循的步骤，然后考虑如何表示这些数据。
如果换成一位OOP程序员，又将如何呢？首先考虑数据——不仅要考虑如何表示数据，还要考虑如何使用数据。
用户与数据交互的方式有三种：初始化、更新和报告——这就是用户接口。

总之，采用OOP方法时，首先从用户的角度考虑对象——描述对象 所需的数据以及描述用户与数据交互所需的操作。完成对接口的描述 后，需要确定如何实现接口和数据存储。最后，使用新的设计方案创建出程序。

***



## 10.2 抽象和类

生活中充满复杂性，处理复杂性的方法之一是简化和抽象。



### 10.2.1 类型是什么

首先，倾向于根据数据的外观（在内存中如何存储）来考虑数据类型。但是稍加思索就会发现，也可以根据要对它执行的操作来定义数据类型。总之，指定基本类型完成了三项工作：

- 决定数据对象需要的内存数量；
- 决定如何解释内存中的位（`long` 和 `float`在内存中占用的位数相同，但将它们转换为数值的方法不同）；
- 决定可使用数据对象执行的操作或方法。



### 10.2.2 C++中的类

类是一种将抽象转换为用户定义类型的C++工具，它将数据表示和操纵数据的方法组合成一个整洁的包。

定义类时，一般来说，类规范由两个部分组成：

- 类声明：以数据成员的方式描述数据部分，以成员函数（称为方法）的方式描述共有接口；
- 类方法定义：描述如何类成员函数。

简单地说，类声明提供了类的蓝图，而方法定义则提供了细节。例子：

```Cpp
// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock  // class declaration
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};    // note semicolon at the end

#endif
```

首先， C++关键字class指出这些代码定义了一个类设计。

1．访问控制

关键字 `private` 和 `public` 也是新的，它们描述了对类成员的访问控制。使用类对象的程序都可以直接访问公有部分，但只能通过公有成员函数（或友元函数，参见第11章）来访问对象的私有成员。

因此，公有成员函数是程序和对象的私有成员之间的桥梁，提供了对象和程序之间的接口。防止程序直接访问数据被称为**数据隐藏**（参见图10.1）。C++还提供了第三个访问控制关键字`protected`，第13章介绍类继承时将讨论该关键字。

![image-20210811220839703](https://static.fungenomics.com/images/2021/08/image-20210811220839703.png)

类设计尽可能将公有接口与实现细节分开。公有接口表示设计的抽 象组件。**将实现细节放在一起并将它们与抽象分开被称为封装。**数据隐藏（将数据放在类的私有部分中）是一种封装，将实现的细节隐藏在私有部分中，就像`Stock`类对`set_tot()` 所做的那样，也是一种封装。封装的 另一个例子是，将类函数定义和类声明放在不同的文件中。

> OOP是一种编程风格，从某种程度说，它用于任何一种语言中。

数据隐藏不仅可以防止直接访问数据，还让开发者（类的用户）无需了解数据是如何被表示的。从使用类的角度看，使用哪种方法没有什么区别。所需要知道的只是各种成员函数的功能；也就是说，需要知道成员函数接受什么样的参数以及返回什么类型的值。原则是将实现细节从接口设计中分离出来。如果以后找到了更好的、实现数据表 示或成员函数细节的方法，可以对这些细节进行修改，而无需修改程序接口，这使程序维护起来更容易。

2．控制对成员的访问：公有还是私有

无论类成员是数据成员还是成员函数，都可以在类的公有部分或私有部分中声明它。但由于隐藏数据是OOP主要的目标之一，因此数据项通常放在私有部分，组成类接口的成员函数放在公有部分；否则，就无法从程序中调用这些函数。



### 10.2.3 实现类成员函数

还需要创建类描述的第二部分：为那些由类声明中的原型表示的成员函数提供代码。成员函数定义与常规函数定义非常相似，它们有函数头和函数体，也可以有返回类型和参数。但是它们还有两个特殊的特征：

- 定义成员函数时，使用作用域解析运算符 `::` 来标识函数所属的类；
- 类方法可以访问类的 `private` 组件。

例如：

```Cpp
void Stock::update(double price) {
    ....
}
```

作用域解析运算符确定了方法定义对应的类的身份。

类方法的第二个特点是，方法可以直接访问类的私有成员，**如同访问一个已经声明好的常用变量一样**。例如，show( ) 方法可以使用这样的代码：

```Cpp
void Stock::show()
{
    std::cout << "Company: " << company
              << "  Shares: " << shares << '\n'
              << "  Share Price: $" << share_val
              << "  Total Worth: $" << total_val << '\n';
}
```

其中，company、shares等都是Stock类的私有数据成员。

另外，类声明常将短小的成员函数作为内联函数在头文件中随类声明一起定义。

> 内联函数的特殊规则要求在每个使用它们的文件中都对其进行定义。确保内联定义对多文件程序中的所有文件都可用的、最简便的方法是：**将内联定义放在定义类的头文件中**。

**所创建的每个新对象都有自己的存储空间，用于存储其内部变量和类成员；但同一个类的所有对象共享同一组类方法，即每种方法只有一个副本**。

例如，假设 `kate` 和 `joe` 都是 `Stock` 对象，则 `kate.shares` 将占据一个 内存块，而 `joe.shares` 占用另一个内存块，但`kate.show()` 和 `joe.show()` 都调用同一个方法，也就是说，**它们将执行同一个代码块**，只是将这些代码用于不同的数据。在OOP中，调用成员函数被称为发送消息，因此将 同样的消息发送给两个不同的对象将调用同一个方法，但该方法被用于两个不同的对象。

![image-20210811222542618](https://static.fungenomics.com/images/2021/08/image-20210811222542618.png)

### 

### 10.2.4 使用类 

使用类与使用基本的内置类型（如`int`和`char`）尽可能相同。要创建类对象，可以声明类变量，也可以使用 `new` 为类对象分配存储空间。可以将对象作为函数的参数和返回值，也可以将一个对象赋给另一个。

要使用新类型，最关键的是要了解成员函数的功能，而不必考虑其实现细节。



### 10.2.5 修改实现



### 10.2.6 小结

指定类设计的第一步是提供类声明。类声明类似结构声明，可以包括数据成员和函数成员。

声明有私有部分，在其中声明的成员只能通过成员函数进行访问；声明还具有公有部分，在其中声明的成员可被使用类对象的程序直接访问。

通常，数据成员被放在私有部分中，成员函数被放在公有部分中，因此典型的类声明的格式如下：

![image-20210811223153090](https://static.fungenomics.com/images/2021/08/image-20210811223153090.png)

## 

***



## 10.3 类的构造函数和析构函数

C++的目标之一是让使用类对象就像使用标准类型一样。

![image-20210811223501009](https://static.fungenomics.com/images/2021/08/image-20210811223501009.png)

一般来说，最好是在创建对象时对它进行初始化。

就`Stock`类当前的实现而言，`gift`对象的`company`成员是没有值的。 类设计假设用户在调用任何其他成员函数之前调用`acquire( )`，但无法强加这种假设。避开这种问题的方法之一是在创建对象时，自动对它进行初始化。为此，C++提供了一个特殊的成员函数——**类构造函数**，专门 用于构造新对象、将值赋给它们的数据成员。名称与类名相同。例如，`Stock`类一个可能的构造函数是名为`Stock( )`的成员函数。

**构造函数的原型和函数头有一个有趣的特征——虽然没有返回值， 但没有被声明为void类型。实际上，构造函数没有声明类型**。

```Cpp
// stock10.h <96> Stock class declaration with constructors, destructor added
#ifndef STOCK1_H_
#define STOCK1_H_
#include <string>
class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);  // reload constructor;
    ~Stock();       // noisy destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif
```

程序声明对象时，将自动调用构造函数。