STL 是“Standard Template Library”的缩写，中文译为“标准模板库”。

STL 是 C++ 标准库的一部分，不用单独安装。

C++ 对模板（Template）支持得很好，STL 就是借助模板把常用的[数据结构](http://data.biancheng.net/)及其算法都实现了一遍，并且做到了数据结构和算法的分离。例如，vector 的底层为顺序表（数组），list 的底层为双向链表，deque 的底层为循环队列，set 的底层为红黑树，hash_set 的底层为哈希表。

> 可以说，STL 基本上达到了各种存储方法和相关算法的高度优化。

C++ 标准模板库的核心包括以下三个组件：

| 组件                | 描述                                                         |
| :------------------ | :----------------------------------------------------------- |
| 容器（Containers）  | 容器是用来管理某一类对象的集合。C++ 提供了各种不同类型的容器，比如 deque、list、vector、map 等。 |
| 算法（Algorithms）  | 算法作用于容器。它们提供了执行各种操作的方式，包括对容器内容执行初始化、排序、搜索和转换等操作。 |
| 迭代器（iterators） | 迭代器用于遍历对象集合的元素。这些集合可能是容器，也可能是容器的子集。 |



#### 向量 vector

```C++
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   // 创建一个向量存储 int
   vector<int> vec; 
   int i;
 
   // 显示 vec 的大小
   cout << "vector size = " << vec.size() << endl;
 
   // 推入 5 个值到向量中
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
 
   // 访问向量中的 5 个值
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
 
   // 使用迭代器 iterator 访问值
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
 
   return 0;
}
```

> 关于上面实例中所使用的各种函数，有几点要注意：
>
> - push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
> - size( ) 函数显示向量的大小。
> - begin( ) 函数返回一个指向向量开头的迭代器。
> - end( ) 函数返回一个指向向量末尾的迭代器。
> - 迭代器可以看作一种类似于指针的数据类型，写作： `vector<int>::iterator`



