# chapter4-CompositeType

### 第四章 《复合类型》复习题

1. 在函数内声明下列数据（自动存储：栈空间）

   ```C++
   char actor[30];
   ```

   ```C++
   short betsie[100];
   ```

   ```C++
   float chuck[13];
   ```

   ```C++
   long double dipsea[64];
   ```

2. 使用模版类`array`来完成上述数据的声明（静态存储：栈空间）

   ```C++
   array<char, 30> actor;
   ```

   ```C++
   array<short, 100> betsie;
   ```

   ```C++
   array<float, 13> chuck;
   ```

   ```C++
   array<long double, 64> dipsea;
   ```

3. int数组5个元素，初始化为前5个正奇数

   ```C++
   vector<int> num;
   for (int i = 1; i < 10; i+=2) num.push_back(i);
   ```

4. 将num的第一个和最后一个赋给变量even

   ```C++
   int even = num.at(0) + num.back();
   ```

   ```C++
   int even = *num.begin() + num.back();
   ```

5. ```C++
   float ideas[3] = {0, 1, 2};
   cout << idea[1];
   ```

6. ```C++
   char chs[100] = "cheeseburger";
   ```

7. ```C++
   string s = "Waldorf Salad";
   ```

8. ```C++
   struct fish{
       string type;
       int weight;
       double inch;
   };
   ```

9. ```C++
   fish f1 = {"FISH", 10, 3.14};
   ```

10. ```C++
    enum Responce{No, Yes, Maybe};
    ```

11. ```C++
    double ted = 1.2345;
    double* pt = &ted;
    cout << *pt;
    ```

12. ```C++
    vector<float> treacle;
    treacle.assign(10, 1);
    treacle.at(0) = 0;
    treacle.at(9) = 9;
    vector<float>* ptr = &treacle;
    cout << *ptr->begin() << ' ' << ptr->back();
    ```

    ```C++
    float ar[10] = {1};
    cout << ar[0] << ' ' << ar[9];
    ```

13. `new`:

    ```C++
    int n;
    cin >> n;
    int* pn = new int[n](); // (): init to zero
    ```

    `vector`:

    ```C++
    int n;
    cin >> n;
    vector<int> ar;
    ar.assign(n, 1);
    cout << ar.at(0);
    ```

14. 打印出地址

15. ```C++
    fish* pf = new fish[3]{{"A", 10, 1.11}, {"B", 20, 2.22}, {"C", 30, 3.33}};
    for (int i = 0; i < 3; ++i) {
        cout << pf->type << ' ' << (*pf).weight << pf->inch << endl;
        pf++;
    }
    ```

16. 若字符串中有空格或换行符，cin将不能读取空格或换行符后面的数据；若一直没有空格，cin会读取超过80个字符数据

17. ```C++
    #include <vector>
    #include <array>
    
    const int nv = 10, na = 20;
    
    int main(){
        std::vector<std::string> sv[nv];
        std::array<std::string, na> sa;
        return 0;
    }
    ```



### 第四章《复合类型》编程练习题

1. ```C++
   #include <iostream>
   #include <string>
   using namespace std;
   
   int main(){
       string name, last_name;
       char letter_grade;
       int age;
       cout << "What is your first name? ";
       getline(cin, name);
   
       cout << "What is your last name? ";
       cin >> last_name;
   
       cout << "What is your letter grade? ";
       cin >> letter_grade;
   
       cout << "What is your age? ";
       cin >> age;
   
       cout << "Name: " << last_name << ", " << name << endl;
       printf("Grade: %c\nAge: %d", letter_grade + 1, age); // printf 不能输出string
       return 0;
   }
   ```

2. ```C++
   #include <iostream>
   using namespace std;
   
   int main(){
       const int ar_size = 20;
       string name, dessert;
       cout << "enter your name: \n";
       cin >> name;
       cout << "enter your favourite dessert: \n";
       cin >> dessert;
       cout << "I have some dessert " << dessert << endl;
       cout << "For you, " << name << endl;
       return 0;
   }
   ```

3. ```C++
   #include <iostream>
   using namespace std;
   
   int main(){
       string first_name, last_name;
       cin >> first_name >> last_name;
       cout << first_name << ", " << last_name;
       return 0;
   }
   ```

4. ```C++
   #include <iostream>
   using namespace std;
   
   int main(){
       string first_name, last_name;
       cin >> first_name >> last_name;
       first_name += ", ";
       first_name += last_name;
       cout << first_name;
       return 0;
   }
   ```

5. ```C++
   #include <iostream>
   using namespace std;
   
   struct candy_bar{
       string name;
       double weight;
       int calories;
   };
   
   int main(){
       candy_bar snack = {"Mocha Munch",2.3,350};
       cout << snack.name << ' ' << snack.weight << ' ' << snack.calories;
       return 0;
   }
   ```

6. ```C++
   #include <iostream>
   using namespace std;
   
   struct candy_bar{
       string name;
       double weight;
       int calories;
   };
   
   int main(){
       candy_bar snack[3] = {{"Mocha Munch",2.3,350},{"a",1.1,1},{"b",2.2,2}};
       for (int i = 0; i < 3; ++i) {
           cout << snack[i].name << ' ' << snack[i].weight << ' ' << snack[i].calories << endl;
       }
       return 0;
   }
   ```

7. ```C++
   #include <iostream>
   using namespace std;
   
   struct pizza{
       string name;
       double weight;
       double d;
   };
   
   int main(){
       pizza p;
       cin >> p.name >> p.d >> p.weight;
       cout << p.name << ' ' << p.d << ' ' << p.weight;
       return 0;
   }
   ```

8. ```C++
   #include <iostream>
   using namespace std;
   
   struct pizza{
       string name;
       double weight;
       double d;
   };
   
   int main(){
       pizza* p = new pizza;
       cin >> p->d >> p->name >> p->weight;
       cout << p->name << ' ' << (*p).d << ' ' << p->weight;
       return 0;
   }
   ```

9. ```C++
   #include <iostream>
   using namespace std;
   
   struct pizza{
       string name;
       double weight;
       double d;
   };
   
   int main(){
       pizza* p = new pizza[3];
       cin >> p->d >> p->name >> p->weight;
       cout << p->name << ' ' << (*p).d << ' ' << p->weight;
       return 0;
   }
   ```

10. ```C++
    #include <iostream>
    #include <array>
    using namespace std;
    
    int main(){
        array<double, 3> score;
        for (int i = 0; i < 3; ++i) {
            cin >> score[i];
        }
        double* ps = new double;
        *ps = score[0] + score[1] + score[2];
        *ps /= 3;
        cout << 3 << ' ' << *ps;
        return 0;
    }
    ```

    
