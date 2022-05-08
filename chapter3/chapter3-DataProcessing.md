# chapter3-DataProcessing

### 第三章 《处理数据》 编程练习题



## 3.1

**题：**

> 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。	

**解：**

```c++
#include <iostream>
using namespace std;

const int change_inch = 12;

int main(){
    int heigth;
    cout << "Please input you height in inch: __\b\b";
    cin >> heigth;
    cout << heigth / change_inch << ' ' << heigth % change_inch << endl;
}
```



## 3.2

**题：**

> 编写一个小程序，要求以几英尺<kbd>foot</kbd> 几英寸<kbd>inch</kbd>的方式输入其身高，并以磅<kbd>pound</kbd>为单位输入其体重。（使用3个变量来存储这些信息。）该程序报告其BMI（Body Mass Index，体重指数）。
>
> 为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸），并将以英寸为单位的身高转换为以米为单位的身高（1英寸=0.0254米）。
>
> 然后，将以磅为单位的体重转换为以千克为单位的体重（1千克=2.2磅）。
>
> 最后，计算相应的BMI—体重（千克）除以身高（米）的平方。用符号常量表示各种转换因子。

**解：**

```c++
#include <iostream>
#include <cmath>
using namespace std;

const double foot_to_Meter = 0.0254;
const double kg_to_pound = 2.2;

int main(){
    double height_foot = 0;
    double height_inch = 0;
    double weight_pound = 0;
    
    cin >> height_foot >> height_inch >> weight_pound;
      
    double height_meter = (height_foot * 12 + height_inch) * foot_to_Meter;
    double weight_kg = weight_pound * kg_to_pound;
    double BMI = pow(weight_kg / height_meter, 2);
    
    cout << BMI;
}
```



## 3.3

**题：** 

> 编写一个程序，要求用户以度<kbd>degrees</kbd>、分<kbd>minutes</kbd>、秒<kbd>sceonds</kbd>的方式输入一个纬度<kbd>latitude</kbd>，然后以度为单位显示该纬度。
>
> 1度为60分，1分等于60秒，请以符号常量的方式表示这些值。
>
> 对于每个输入值，应使用一个独立的变量存储它。 

下面是该程序运行时的情况：

```
Enter a latitude in degree, minutes, and seconds:
First, enter the degree: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19

37 degrees, 51 minutes, 19 seconds = 37.8553 degrees.
```

**解：**

```c++
#include <iostream>
using namespace std;

const double degree_to_minutes = 60;
const double minutes_to_seconds = 60;

int main(){
    cout << "Enter a latitude in degree, minutes, and seconds:" << endl;
    
    cout << "First, enter the degree:";
    int degrees;
    cin >> degrees;
    
    cout << "Next, enter the minutes of arc:";
    int minutes;
    cin >> minutes;
    
    cout << "Finally, enter the seconds of arc:";
    int seconds;
    cin >> seconds;
    
    double all_degrees = degrees + minutes / degree_to_minutes + seconds / minutes_to_seconds / degree_to_minutes;
    
    printf("%d degrees, %d minutes, %d seconds = %.4f degrees." , degrees, minutes, seconds, all_degrees);
}
```



# 3.4

**题：**

> 编写一个程序，要求用户以**整数**方式输入秒数（使用long或long long变量存储），然后以天<kbd>day</kbd>、小时<kbd>hour</kbd>、分钟<kbd>minutes</kbd>和秒<kbd>second</kbd>的方式显示这段时间。
>
> 使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。该程序的输出应与下面类似：

```
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds.
```

**解：**

