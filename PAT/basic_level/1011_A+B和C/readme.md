#	[原题](https://www.patest.cn/contests/pat-b-practise/1011)： 1011. A+B和C (15)

给定区间[-2<sup>31</sup>, 2<sup>31</sup>]内的三个整数A，B，C，请判断A+B>C是否成立。

###	输入格式

输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。

###	输出格式

对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

###	输入样例

	4
	1 2 3
	2 3 4
	2147483647 0 2147483646
	0 -2147483648 -2147483647

###	输出样例

	Case #1: false
	Case #2: true
	Case #3: true
	Case #4: false

###	注意

	时间限制： 150 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： HOU, Qiming

<br/><br/>

#	考察点

1.	审题

	*	[-2<sup>31</sup>, **2<sup>31</sup>]**，其中的**2<sup>31</sup>**超出int范围，因此变量应该用`long int`。

	*	应当考虑到把测试输入限制在区间内，否则视作`false`。

2.	编译

	gcc abc.c -o abc

	make abc

	vs2012, `F7`编译, `^+F5`运行

3.	确定int位数

	```c
	#include <stdlib.h>
	printf("%ld", sizeof(int));
	```

4.	`C`, 输入输出

	```c
	#include <stdio.h>

	scanf("%ld%ld%ld", &a, &b, &c);
	printf("%ld %ld %ld", a, b, c);
	```

5.	`python2.7`

	考虑到考场环境，如无特殊说明，以后均以`python2.7`为例。

	`输入` 若一行内有多个输入，则用`split()`方法

	```python
	a, b, c = raw_input().split()
	a, b, c = int(a), int(b), int(c)
	```

	`输出` `print()`原型如下

	```python
	from __future__ import print_function	
	
	print(*objects, sep=' ', end='\n', file=sys.stdout)
	```

6.	返回值

	主函数返回值应为`0`

#	部分测试用例

*	test1

		输入
		4
		1 2 3
		2 3 4
		2147483647 0 2147483646
		0 -2147483648 -2147483647

		输出
		Case #1: false
		Case #2: true
		Case #3: true
		Case #4: false

*	test2

		输入
		2
		546 647 78767
		353456 75656757 3342542356

		输出
		Case #1: false
		Case #2: false

*	test3

		输入
		1
		2147483648 2147483648 2147483648

		输出
		Case #1: true

*	test4

		输入
		3
		1 2 3
		2 3 4
		2147483647 0 2147483646

		输出
		Case #1: false
		Case #2: true
		Case #3: true

#	其他

*	本页内包含的**.c**，**.py**为通过测试的代码。另外由于测试用的[牛客网](https://www.nowcoder.com/pat)和[pat官网](https://www.patest.cn/contests/pat-b-practise)服务器不一样，用时和内存标准也不同，因此`尽量选C`以防超时。

*	65536*65536/2 = 2147483648

#	参考

*	[python-docs](https://docs.python.org/2.7/library/functions.html#print)

