##	[原题](https://www.patest.cn/contests/pat-b-practise/1012)： 1012. 数字分类 (20)

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

*	A1 = 能被5整除的数字中所有偶数的和；
*	A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
*	A3 = 被5除后余2的数字的个数；
*	A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
*	A5 = 被5除后余4的数字中最大数字。

###	输入格式

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

###	输出格式

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

###	输入样例1

	13 1 2 3 4 5 6 7 8 9 10 20 16 18

###	输出样例1

	30 11 2 9.7 9

###	输入样例2

	8 1 2 4 5 6 7 9 16

###	输出样例2

	N 11 2 N 9

<br/><br/>

#	易错点

注意审题与本地测试(有很多陷阱)

1.	`分配内存`

	可以一次性分配长度为1000的内存空间给数组。

	也可以根据用户输入确定数组长度。参见<C Primer Plus 5th Edition>中文版第341页

	```c
	#include <stdio.h>
	#include <stdlib.h>

	int *us_input_arr;
	int us_input_size;
	scanf("%d", &us_input_size);
	us_input_arr = (int *)malloc(us_input_size*sizeof(int));
	if( us_input_arr == NULL ){
		printf("Memory allocation failed!");
		exit(EXIT_FAILURE);
	}

	/*
	do_sth
	*/

	free(us_input_arr);	//注意释放内存
	```

2.	`输入输出`

	首先需要合理安排变量名、数据类型和结构，便于调试。

	输入为空的时候退出

	```c
	if( scanf("%d", &us_input_arr[us_input_i])==1 )
	```
	
	输出浮点数，保留一位小数

	```c
	printf("%.1f", num);
	```

3.	审题与语法的结合

	注意到A4含有小数，因此最后输出的时候要变为double类型，否则可能造成精度丢失，影响结果。

	```c
	printf("%.1f", a[4]*1.0/cnt[4]);
	```

	python中保留一位小数

	```python
	a[4] = round(a[4]*1.0/cnt[4], 1)
	```

4.	防止除数为0，处理好输出逻辑。

5.	本地测试注意点 1

	**注意移除测试用的print()代码！！！**

	**注意移除测试用的print()代码！！！**

	**注意移除测试用的print()代码！！！**

6.	本地测试注意点 2

	根据提交后提示的错误，在本机进行进一步测试，而不是改完后马上再次提交。

7.	返回值为0，是正常退出

8.	更新1---增加cpp的实现

	*	思路相同，精简代码

	*	cpp的格式化输出比较麻烦，直接`#include <cstdio>`，用c的`printf()`

#	部分测试用例

*	test1

		输入
		20 231 463 724 981 284 851 14 638 824 277 731 37 426 86 570 697 853 130 966 50

		输出
		750 676 3 651.3 824

*	test2

		输入
		10 348 344 986 351 131 514 50 162 126 768

		输出
		50 640 1 558.0 514

#	其他参考

*	[python保留两位小数](http://www.cnblogs.com/Raymon-Geng/p/5784290.html)

*	[python中保留两位小数](http://www.cnblogs.com/harvey888/p/5954268.html)

*	`python`不换行输出还可以这样

	```python
	import sys

	sys.stderr.write('hello, world')
	```

*	`python`

	```python
	from __future__ import print_function
	```

	使py2与py3的`print()`代码一致
