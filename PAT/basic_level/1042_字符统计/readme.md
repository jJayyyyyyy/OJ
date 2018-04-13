##	[原题](https://www.patest.cn/contests/pat-b-practise/1042)： 1042. 字符统计 (20)

请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

###	输入格式

输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。

###	输出格式

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

###	输入样例

	This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

###	输出样例

	e 7

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	标准库

	在`<cctype>`中有`tolower()`，`isalpha()`等用于处理字符的函数。

2.	存储

	用数组的0~25号空间存储英文字母出现的次数。注意只统计英文字母，大写计入小写。

3.	输出

	格式化输出时可用`printf("%c", ch)`，其中ch是字母的ascii码。

	若用`cout`，则可用`ix+'a'`的方式，其中ix对应0~25。

#	部分测试用例

	输入
	This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

	输出
	e 7

#	其他参考

