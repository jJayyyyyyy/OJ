##	[原题](https://www.patest.cn/contests/pat-b-practise/1014)： 1014. 福尔摩斯的约会 (20)

大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

###	输入格式

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

###	输出格式

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

###	输入样例

	3485djDkxh4hhGE 
	2984akDfkkkkggEdsb 
	s&hgsfdk 
	d&Hyscvnm

###	输出样例

	THU 14:04

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	星期几

	对比第一行和第二行，找到第一对【下标相同】的【大写】字母。

	注意大写字母的范围在 `'A' ~ 'G'` 之间，分别对应 `星期一 ~ 星期日`。

	同时记录此时的下标`ix`，下一步寻找【钟头】应该从这个下标往后数。

2.	钟头

	基本与第1点相同，注意【大写】字母范围在 `'A' ~ 'N'` 之间，分别对应 10点~23点。

	还有一种情况，`ix`之后第一对相同的字符是数字，这也是一种合法的情况， `'0' ~ '9'`分别对应 `0点 ~ 9点`。此时为了格式化输出，还要在前面加上字符`'0'`。

	此外，钟头后面还要输出 冒号`':'`，作为分隔符。

3.	分钟

	对比第三行和第四行，寻找第一对【下标相同】的【英文字符】，将其下标作为分钟。

	注意分钟在 `0 ~ 9` 时，需要在前面补`'0'`。

#	部分测试用例

养成好的测试习惯

*	test1

		输入
		3485djDkxh4hhGE 
		2984akDfkkkkggEdsb 
		s&hgsfdk 
		d&Hyscvnm

		输出
		THU 14:04

*	test2

		输入
		3485djEkxh4hhGE 
		2984akEfkkkkggEdsb 
		s&hgsfdk 
		d&Hyscvnm

		输出
		FRI 14:04

#	其他参考

*	字符处理函数

	*	C

		```c
		#include <ctype.h>
		int isalnum(int c);
		int isdigit(int c);
		int isalpha(int c);
		int islower(int c);
		int isupper(int c);
		int tolower(int c);
		int toupper(int c);
		```
	
	*	C++

		同C，将头文件换成`<cctype>`即可

	*	Python

		字符串的成员函数

		```python
		str.isalnum()
		str.isdigit()
		str.isalpha()
		str.islower()
		str.isupper()
		str.lower()
		str.upper()
		```



