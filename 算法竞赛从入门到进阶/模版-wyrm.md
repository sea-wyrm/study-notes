# 算法

框架思维：在顺序、链表、二叉树、n叉树的框架基础上增删改查

算法的本质是穷举。关键点：无遗漏、无冗余
1. 如何无遗漏地穷举
2. 如何聪明地穷举

## 数组

数组遍历：双指针、滑动窗口

```cpp
// 迭代遍历数组框架
void traverse1_1(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        // todo
    }
}

// 递归遍历数组框架
void traverse1_2(vector<int> &arr, int i) {
    if (i == arr.size()) return;
    // 前序位置
    traverse1_2(arr, i + 1);
    // 后序位置
}

// 双指针：滑动窗口框架【快慢指针】
void slidingWindow(string s) {
    // 哈希表（字典）
    unordered_map<char, int> window;
    int left = 0, right = 0;
    while (right < s.size()) {
        char c = s[right];
        window.emplace(c); // 扩大窗口
        right++;
        // 更新窗口数据
        while (left < right && window need shrink) {
            char d = s[left];
            window.erase(d);
            left++;
            // 更新窗口数据
        }
    }
}

// 双指针：二分搜索【左右指针】
// 二分搜索一个数
int binarySearch1(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止 left + right 数据溢出
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// 二分搜索左边界
int binarySearch1_1(vector<int>& nums, int target) {
    // [left, right]
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) right = mid - 1; // [left, mid - 1]
        else if (nums[mid] < target) left = mid + 1; // [mid + 1, right]
        else if (nums[mid] > target) right = mid - 1; // [left, mid - 1]
    }
    return left;
}

int binarySearch1_2(vector<int>& nums, int target) {
    // [left, right)
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) right = mid; // [left, mid)
        else if (nums[mid] < target) left = mid + 1; // [mid + 1, right)
        else if (nums[mid] > target) right = mid; // [left, mid)
    }
    if (left == target) return left;
    else return -1;
}

// 二分搜索右边界
int binarySearch2_1(vector<int>& nums, int target) {
    // [left, right]
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) left = mid + 1;
        else if (nums[mid] < target) left = mid + 1;
        else if (nums[mid] > target) right = mid;
    }
    return left - 1;
}

int binarySearch2_2(vector<int>& nums, int target) {
    // [left, right)
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) left = mid + 1; // [mid + 1, right)
        else if (nums[mid] < target) left = mid + 1; // [mid + 1, right)
        else if (nums[mid] > target) right = mid; // [left, mid)
    }
    if (nums[left - 1] == target) return left;
    else return -1;
}
```

## 单链表

单链表：双指针、前缀和、差分

```cpp
struct ListNode {
    int val;
    ListNode *next;
};

// 迭代遍历链表框架1
void traverse2_1(ListNode *head) {
    for (ListNode *node = head; node != nullptr; node = node->next) {
        // todo
    }
}

// 递归遍历链表框架2
void traverse2_2(listNode *head) {
    if (head == nullptr) return;
    // 前序位置
    traverse2_1(head->next);
    // 后序位置
}
```

## 二叉树

二叉树解题的思维模式：

1. 遍历一遍二叉树（回溯）
2. 通过分解问题计算答案（动态规划）

> 思考：如果单独抽出一个二叉树节点，它需要做什么事情？需要在什么时候（前/中/后序位置）做？
> `traverse` 函数是一个能够遍历二叉树所有节点的函数

二叉树这种结构是二叉链表，一般说二叉树的遍历框架都是指递归的形式。只要是递归形式的遍历，都可以有前序位置和后序位置，分别在递归之前和递归之后。

前序位置的代码在刚刚进入一个二叉树节点的时候执行；
后序位置的代码在将要离开一个二叉树节点的时候执行；
中序位置的代码在一个二叉树节点左子树都遍历完，即将开始遍历右子树的时候执行。

<img decoding="二叉树的前中后序三个位置" src="https://labuladong.gitee.io/algo/images/%e4%ba%8c%e5%8f%89%e6%a0%91%e6%94%b6%e5%ae%98/2.jpeg" width="50%">

二叉树的所有问题，就是在前中后序位置注入巧妙的代码逻辑，我们只需要单独思考每一个节点应该做什么，其他不需要管。抛给二叉树遍历框架，递归会在所有节点上做相同操作。

> 函数命名习惯：
> - 二叉树中用遍历思路解决问题时函数签名一般为 `void traverse()`，没有返回值，靠更新外部变量来计算结果。
> - 用分解问题思路解题时函数名根据该函数的功能而定，而且一般有返回值，返回值是子问题的计算结果。
> - 回溯：`void backtrack()`
> - 动态规划：带有返回值的 `dp` 函数

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 二叉树遍历框架
void traverse3(TreeNode *root) {
    // 前序位置
    traverse3(root->left);
    // 中序位置
    traverse3(root->right);
    // 后序位置
}

// 计算二叉树最大深度
class Solution {
public:
    int depth = 0;
    int res = 0;

    int maxDepth(TreeNode *root) {
        traverse(root);
        return res;
    }

    int maxDepth2(TreeNode *root) { // 动态规划
        if (root == NULL) return 0;
        int res;
        int leftMax = maxDepth2(root->left);
        int rightMax = maxDepth2(root->right);
        res = max(leftMax, rightMax) + 1;
        return res;
    }

    void traverse(TreeNode *root) { // 回溯
        if (root == NULL) {
            res = max(res, depth);
            return;
        }
        depth++;
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
}
```

#### 前序遍历

##### 快速排序

```cpp
void quickSort(int l, int r) {
    if (l >= r) return;

    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}
```

#### 后序遍历

##### 归并排序

```cpp
void mergeSort(int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; i++, j++) {
        a[i] = tmp[j];
    }
}
```


## n叉树

```cpp
class TreeNode_N {
    public:
        int val;
        vector<int> children;
};

// n叉树遍历框架
void traverse4(TreeNode_N *root) {
    for (TreeNode_N *child: root->children) {
        traverse4(child);
    }
}

class Solution_Dfs {
public:
    vector<vector<int> > res;
    vector<int> track;

    vector<vector<int> > permute(vector<int> &nums) {
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int> &nums) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 查找 num[i] 是否被枚举 （!= 表示已被枚举，可以找到）
            if (find(track.begin(), track.end(), nums[i]) != track.end()) continue;
            track.push_back(nums[i]);
            backtrack(nums);
            track.pop_back();
        }
    }
}
```

### 回溯算法

回溯算法和 `DPS` 算法的轻微区别：回溯算法是在遍历「树枝」，`DFS` 算法是在遍历「节点」

解决一个回溯问题，实际上就是一个决策树的遍历过程，站在回溯树的一个节点上，只需要思考 3 个问题：
1. 路径：已经做出的选择
2. 选择列表：当前可以做的选择
3. 结束条件：到达决策树底层，无法再做选择的条件

```cpp
result = [];
def backtrack(路径，选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

**其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后撤销选择。**

回溯算法实际上是个多叉树的遍历问题，关键就是在前序遍历和后序遍历的位置上做一些操作，算法框架如下：

```cpp
def backtrack(...) {
    for 选择 in 选择列表 {
        做选择
        backtrack(...);
        撤销选择
    }
}
```

写 `backtrack` 函数时，需要维护走过的「路径」和当前可以做的「选择列表」，当触发「结束条件」时，将「路径」记入结果集；

### 动态规划算法

**动态规划的一般形式是求最值，而求解动态规划的核心问题是穷举。**

穷举所有可行解是不容易的，需要列出 **正确的「状态转移方程」**，才能正确地穷举。而且需要判断算法是否 **具备「最优子结构」**，是否能够通过子问题的最值得到原问题的最值。另外，动态规划问题 **存在「重叠子问题」**，如果暴力穷举的话效率会很低，需要使用「备忘录」或者「DP table」来优化穷举过程，避免不必要的计算。

状态转移方程实际上是描述问题结构的数学形式。

#### 方法论

动态规划中每一个状态一定是由上一个状态推导出来的，这一点与贪心区别，贪心没有状态推导，而是从局部直接选最优的。

> **动态规划五部曲**
> 1.  $dp$ 数组（dp table）以及下标的含义
> 2. 递推公式
> 3. $dp$ 数组初始化
> 4. 遍历顺序
> 5. 举例推导 $dp$ 数组
>> 1 和 4 的作用越往后越体现重要性，4 的重要性在背包问题中尤为重要
>> 2 在 3 之前是因为有些情况，递推公式决定了 $dp$ 数组要如何初始化
>> 最好在写代码之前，手动模拟一遍 $dp$ 数组，看是否符合预期

##### dp debug 方法

打印 dp 数组日志，并查看与自己想模拟的 dp 值是否一致：
- 若 dp 值与自己模拟的结果一致，说明是 dp 五部曲中的 2、3、4 步骤出现问题
- 若 dp 值与自己模拟的结果不一致，说明是自己代码细节有问题

```cpp
// 自顶向下递归的动态规划
int dp(状态1, 状态2, ...) {
    for 选择 in 所有可能的选择 {
        // 此时的状态已经因为做了选择而改变
        result = 求最值(result, dp(状态1, 状态2, ...));
    }
    return result;
}

// 自底向上迭代的动态规划
// 初始化 base case
dp[0][0][...] = base case;
// 进行状态转移
for 状态1 in 状态1的所有取值 {
    for 状态2 in 状态2的所有取值 {
        for ...
            dp[状态1][状态2][...] = 求最值(选择1, 选择2, ...);
    }
}
```