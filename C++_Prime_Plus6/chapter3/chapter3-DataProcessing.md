# chapter3-DataProcessing

### 第三章 《处理数据》 编程练习题



## 3.1

**题：**

编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。	

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
    return 0;
}
```



## 3.2

**题：**

编写一个小程序，要求以几英尺<kbd>foot</kbd> 几英寸<kbd>inch</kbd>的方式输入其身高，并以磅<kbd>pound</kbd>为单位输入其体重。（使用3个变量来存储这些信息。）该程序报告其BMI（Body Mass Index，体重指数）。

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
    return 0;
}
```



## 3.3

**题：** 

编写一个程序，要求用户以度<kbd>degrees</kbd>、分<kbd>minutes</kbd>、秒<kbd>sceonds</kbd>的方式输入一个纬度<kbd>latitude</kbd>，然后以度为单位显示该纬度。

1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。 

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
    return 0;
}
```



## 3.4

**题：**

编写一个程序，要求用户以**整数**方式输入秒数（使用long或long long变量存储），然后以天<kbd>day</kbd>、小时<kbd>hour</kbd>、分钟<kbd>minutes</kbd>和秒<kbd>second</kbd>的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。

该程序的输出应与下面类似：

```
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds.
```

**解：**

```c++
#include <bits/stdc++.h>
using namespace std;

const int day_to_hour = 24;
const int hour_to_minute = 60;
const int minute_to_second = 60;

int main(){
	int total_seconds, days, hours, minutes, seconds;
	cout << "Enter the number of seconds: ";
	cin >> total_seconds;
	
	seconds = total_seconds % minute_to_second;
	minutes = total_seconds / minute_to_second % hour_to_minute;
	hours = total_seconds / minute_to_second / hour_to_minute % day_to_hour;
	days = total_seconds / minute_to_second / hour_to_minute / day_to_hour;
	
	printf("%d seconds = %d days, %d hours, %d minutes, %d seconds.", total_seconds, days, hours, minutes, seconds);
	return 0;
}
```



## 3.5

**题：**

编写一个程序，要求用户输入全球当前的人口<kbd>population</kbd>和中国当前的人口（或其他国家的人口）。将这些信息存储在long long变量中，并让程序显示中国（或其他国家）的人口占全球人口的百分比。

该程序的输出应与下面类似：

```
Enter the world's population: 7850176700
Enther the population of China: 1411780000
The population of the China is 17.9841% of the world population.
```

**解：**

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long world_population, china_population;
	cout << "Enter the world's population: ";
	cin >> world_population;
	
	cout << "Enther the population of China: ";
	cin >> china_population;
	
	double china_of_world = (double)china_population / world_population *100;
	printf("The population of the China is %.4f%% of the world population.", china_of_world);
	
	return 0;
}
```



## 3.6

**题：**

编写一个程序，要求用户输入驱车里程（英里<kbd>mile</kbd>）和使用汽油量（加仑<kbd>gallon</kbd>），然后指出汽车耗油量为一加仑的里程。如果愿意，也可以让程序要求用户以公里<kbd>kilometer</kbd>为单位输入距离，并以升<kbd>liter</kbd>为单位输入汽油量，然后指出欧洲风格的结果：即每100公里的耗油量（升）。1公里等同于0.6214 英里。

[^英里]:mile
[^加仑]:gallon
[^公里]:kilometer
[^升]:liter

**解：**

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
	int mile, gallon;
	cin >> mile >> gallon;
	cout << (double)mile / gallon;
	return 0;
}
```



## 3.7

**题：**

编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）），然后将其转换为美国风格的耗油量—每加仑多少英里。

> 注意，除了使用不同的单位计量外，美国方法（距离/燃 料）与欧洲方法（燃料/距离）相反。100公里等于62.14英里，1加仑等于3.875升。因此，19mpg[^mpg]大约合12.4l/100km，27mpg[^mpg]大约合 8.71/100km。

[^mpg]:一加仑油跑多少英里

**解：**

```c++
#include <bits/stdc++.h>
using namespace std;

const double km_to_mi = 62.14 / 100;
const double gallon_to_liter = 3.875;

int main(){
	double uk_mpg, us_mgp;
	cin >> uk_mpg;
	
	us_mgp = (100 * km_to_mi) / (uk_mpg / gallon_to_liter);
	
	cout << us_mgp;
	return 0;
}
```

