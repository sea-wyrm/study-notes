### 第五章 《循环和关系表达式》复习题

1. 入口条件循环是一轮循环开始前判断循环条件（for、while）

   出口条件循环是一轮循环结束后判断循环条件（do-while）

2. 01234\n

3. 0369\n12\n

4. 6\n8\n

5. k = 8\n

6. ```C++
   #include <iostream>
   using namespace std;
   int main(){
       for (int i = 1; i <= 64; i*=2) {
           cout << i << ' ';
       }
       return 0;
   }
   ```

7. 写大括号

   > 将语句放在一对大括号中将形成一个复合语句或代码块

8. 有效，x为20，y为1。

   > - 第一条语句是有效的。表达式1,024由两个表达式组成——1和024，用逗号运算符连接。值为右侧表达式的值。这是024，八进制为20，因此该声明把值20赋给x。
   >
   > - 第二条语句也是有效的，但运算符优先级会先判定赋值号，因此左侧表达式将y的值设置为1，整个表达式的值没有使用024或20

9. cin不能输入空格/换行符，cin.get(ch)可以输入istream对象，ch=cin.get()输入一个数据（整型ACSII码/EOF），但都可以读入空格/换行符



### 第五章 《循环和关系表达式》编程练习题

1. ```C++
   #include <iostream>
   using namespace std;
   int main(){
       int n1, n2, sum = 0;
       cin >> n1 >> n2;
       for (int i = n1; i <= n2; ++i) {
           sum += i;
       }
       cout << sum;
       return 0;
   }
   ```

2. ```C++
   #include <iostream>
   #include <array>
   using namespace std;
   const int ArSize = 100;
   int main(){
       array<long double, ArSize> f;
       f[1] = f[0] = 1LL;
       for (int i = 2; i < ArSize; ++i)
           f[i] = i * f[i - 1];
       for (int i = 0; i < ArSize; ++i)
           cout << i << " != " << f[i] << endl;
       return 0;
   }
   ```

3. ```C++
   #include <iostream>
   using namespace std;
   int main(){
       double num = -1, sum = 0;
       while (num != 0){
           cin >> num;
           sum += num;
           cout << sum << endl;
       }
       return 0;
   }
   ```

4. ```C++
   #include <iostream>
   using namespace std;
   int main(){
       double D = 100, C = 100;
       int year = 1;
       while (D >= C){
           D = 0.1 * year * 100 + 100;
           C = C * 0.05 + C;
           year++;
       }
       cout << --year << endl;
       cout << C << ' ' << D;
       return 0;
   }
   ```

5. ```C++
   #include <iostream>
   #include <array>
   #include <vector>
   using namespace std;
   int main(){
       array<string, 12> month {"一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "十一", "十二"};
       vector<int> num;
       int n;
       for (int i = 0; i < 12; ++i) {
           cout << "请输入第" << month[i] << "个月的图书销售量：";
           cin >> n;
           num.push_back(n);
       }
       n = 0;
       for (int i = 0; i < 12; ++i) {
           n += num[i];
       }
       cout << "今年图书的销售总数为" << n << "本" << endl;
       return 0;
   }
   ```

6. ```C++
   #include <iostream>
   #include <array>
   #include <vector>
   using namespace std;
   int main(){
       array<string, 12> month {"一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "十一", "十二"};
       array<string, 3> year {"第一年", "第二年", "第三年"};
       vector<int> mon;
       vector<vector<int> > yn;
       int n = 0;
       for (int i = 0; i < 3; ++i) {
           cout << "请输入" << year[i] << "的每月图书销售情况\n";
           for (int j = 0; j < 12; ++j) {
               cout << "请输入第" << month[j] << "个月的图书销售量：";
               cin >> n;
               mon.push_back(n);
           }
           yn.push_back(mon);
           mon.erase(mon.begin(),mon.end());
       }
       for (int i = 0; i < 3; ++i) {
           for (int j = 0; j < 12; ++j) {
               n += yn[i][j];
           }
       }
       cout << "今年图书的销售总数为" << n << "本" << endl;
       return 0;
   }
   ```

7. ```C++
   #include <iostream>
   using namespace std;
   
   struct car{
       string make;
       int year;
   };
   
   int main(){
       int n;
       cout << "How many cars do you wish to catalog? ";
       string s;
       cin >> n;
       getline(cin, s);    // 消除换行符
       car* pc = new car[n];
       for (int i = 0; i < n; ++i) {
           cout << "Please enter the make: ";
           getline(cin, (pc+i)->make);
           cout << "Please enter the year make: ";
           cin >> (pc+i)->year;
           getline(cin, s);    // 消除换行符
       }
       cout << "Here is your collection: " << endl;
       for (int i = 0; i < n; ++i) {
           cout << pc[i].make << ' ' << pc[i].year << endl;
       }
       return 0;
   }
   ```

8. ```C++
   #include <iostream>
   #include <cstring>
   using namespace std;
   int main(){
       char* ch = new char[70];
       char c;
       int count = 0;
       while (1){
           cin >> ch;
           if (strcmp(ch, "done") == 0){
               break;
           }
           count++;
       }
       cout << count << endl;
       return 0;
   }
   ```

9. ```C++
   #include <iostream>
   #include <cstring>
   using namespace std;
   int main(){
       string s;
       int count = 0;
       while (1){
           cin >> s;
           if (s == "done"){
               break;
           }
           count++;
       }
       cout << count << endl;
       return 0;
   }
   ```

10. ```C++
    #include <iostream>
    using namespace std;
    int main(){
        int n;
        cout << "Enter number of rows: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                cout << '.';
            }
            for (int j = i; j < n; ++j) {
                cout << '*';
            }
            cout << endl;
        }
        return 0;
    }
    ```

    

