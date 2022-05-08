# Markdown 标题

我展示的是一级标题=
=================

我展示的是二级标题-  
-----------------  
----

# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题

# Markdown 段落
段落的换行是使用两个以上空格加上回车

也可以在段落后面使用一个空行来表示重新开始一个段落

# 字体
*斜体文本*

_斜体文本_

**粗体文本**

__粗体文本__

***粗斜体文本***

___粗斜体文本___

# 分隔线
***

* * *

*****

- - -

----------

# 删除线
~~BAIDU.COM~~

# 下划线
<u>带下划线文本</u>

# 脚注
[^要注明的文本]

### 实例
创建脚注格式类似这样 [^RUNOOB]。

[^RUNOOB]: 菜鸟教程 -- 学的不仅是技术，更是梦想！！！

# Markdown 列表
* 第一项
* 第二项
* 第三项

+ 第一项
+ 第二项
+ 第三项


- 第一项
- 第二项
- 第三项

1. 第一项
2. 第二项
3. 第三项
- [ ] a
- [ ] b

***
1. 第一项：
    - 第一项嵌套的第一个元素
    - 第一项嵌套的第二个元素
2. 第二项：
    - 第二项嵌套的第一个元素
    - 第二项嵌套的第二个元素
***

# Markdown 区块
> 区块引用

> 菜鸟教程

> 学的不仅是技术更是梦想

> 最外层
> > 第一层嵌套
> > > 第二层嵌套
***
### 区块中使用列表

> 区块中使用列表
> 1. 第一项
> 2. 第二项
> + 第一项
> + 第二项
> + 第三项

### 列表中使用区块
* 第一项
    > 菜鸟教程
    > 学的不仅是技术更是梦想
* 第二项
***
# Markdown 代码
`printf()` 函数

### 代码区块
> 代码区块使用 4 个空格或者一个制表符（Tab 键）。

    <?C++>
    #inclde <iostream>
    using namespace std;
    int main(){
        cout<<"hello, world!";
    }

> 你也可以用 ``` 包裹一段代码，并指定一种语言（也可以不指定）：

```javascript
    $(document).ready(function () {
        alert('RUNOOB');
    });
```
***
```C++
    #inclde <iostream>
    using namespace std;
    int main(){
        cout<<"hello, world!";
    }
```
***

# Markdown 链接
> [链接名称](链接地址)
>  或者
> <链接地址>

1. > 这是一个链接 [菜鸟教程](https://www.runoob.com)
2. > <https://www.runoob.com>

### 高级链接

> 我们可以通过变量来设置一个链接，变量赋值在文档末尾进行：

这个链接用 1 作为网址变量 [Google][1]

这个链接用 runoob 作为网址变量 [Runoob][runoob]

> 然后在文档的结尾为变量赋值（网址）

[1]: http://www.google.com/
[runoob]: http://www.runoob.com/

***

# Markdown 图片
> Markdown 图片语法格式如下：
> ![alt 属性文本](图片地址)
> ![alt 属性文本](图片地址 "可选标题")

- 开头一个感叹号 !
- 接着一个方括号，里面放上图片的替代文字
- 接着一个普通括号，里面放上图片的网址，最后还可以用引号包住并加上选择性的 'title' 属性的文字。

![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png)

![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png "RUNOOB")

这个链接用 1 作为网址变量 [RUNOOB][1].
然后在文档的结尾为变量赋值（网址）

[1]: http://static.runoob.com/images/runoob-logo.png

> Markdown 还没有办法指定图片的高度与宽度,如果你需要的话，你可以使用普通的 \<img> 标签。

<img src="http://static.runoob.com/images/runoob-logo.png" width="50%">

***

# Markdown 表格
> Markdown 制作表格使用 | 来分隔不同的单元格，使用 - 来分隔表头和其他行。

语法格式如下：

|  表头   | 表头  |
|  ----  | ----  |
| 单元格  | 单元格 |
| 单元格  | 单元格 |

### 对齐方式
1. > -: 设置内容和标题栏居右对齐。

2. > :- 设置内容和标题栏居左对齐。

3. > :-: 设置内容和标题栏居中对齐。

| 左对齐 | 右对齐 | 居中对齐 |
| :-----| ----: | :----: |
| 单元格 | 单元格 | 单元格 |
| 单元格 | 单元格 | 单元格 |

***

# Markdown 高级技巧
### 支持的 HTML 元素
> 不在 Markdown 涵盖范围之内的标签，都可以直接在文档里面用 HTML 撰写。

> 目前支持的 HTML 元素有：\<kbd> \<b> \<i> \<em> \<sup> \<sub> \<br>等

使用 <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Del</kbd> 重启电脑

### 转义
> Markdown 使用了很多特殊符号来表示特定的意义，如果需要显示特定的符号则需要使用转义字符，Markdown 使用反斜杠转义特殊字符

**文本加粗** 

\*\* 正常显示星号 \*\*

### 公式
 Markdown Preview Enhanced 使用 KaTeX 或者 MathJax 来渲染数学表达式。

默认下的分隔符：

- $...$ 或者 \(...\) 中的数学表达式将会在行内显示。
- \$$...$$ 或者 \[...\] 或者 ```math 中的数学表达式将会在块内显示。

$$
\begin{Bmatrix}
   a & b \\
   c & d
\end{Bmatrix}
$$
$$
\begin{CD}
   A @>a>> B \\
@VbVV @AAcA \\
   C @= D
\end{CD}
$$

