##	[原题](https://www.patest.cn/contests/pat-b-practise/1067)： 1067. 试密码(25)

当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。

###	输入格式

输入在第一行给出一个密码（长度不超过20的、不包含空格、Tab、回车的非空字符串）和一个正整数N（<= 10），分别是正确的密码和系统允许尝试的次数。随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个#字符时，输入结束，并且这一行不是用户的输入。

###	输出格式

对用户的每个输入，如果是正确的密码且尝试次数不超过N，则在一行中输出“Welcome in”，并结束程序；如果是错误的，则在一行中按格式输出“Wrong password: 用户输入的错误密码”；当错误尝试达到N次时，再输出一行“Account locked”，并结束程序。

###	输入样例1

	Correct%pw 3
	correct%pw
	Correct@PW
	whatisthepassword!
	Correct%pw
	#

###	输出样例1

	Wrong password: correct%pw
	Wrong password: Correct@PW
	Wrong password: whatisthepassword!
	Account locked

###	输入样例2

	cool@gplt 3
	coolman@gplt
	coollady@gplt
	cool@gplt
	try again
	#

###	输出样例2

	Wrong password: coolman@gplt
	Wrong password: coollady@gplt
	Welcome in

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	数据结构

	对应到题目，由于转发获奖者不能重复，所以本题需要借助`set`，它是一种数据结构，其中不会有重复的内容。对于Python，set和dict类似，也是一组key的集合，但不存储value。由于key不能重复，所以，在set中，没有重复的key。

	顺便说一句，PAT的考纲的更新时间显示为2015-07-03，可以视为已经过期了，因为其中对于乙级的要求中，要求的数据结构仅为数组和链表。

2.	正确与错误

	题目说法有点绕，整理一下就是

	*	有正确的输入，且该输入之前的错误少于n次，则可登录
	*	没有正确的输入，则输出错误信息。若错误达到n次，则锁定。

3.	陷阱

	首先是用户直接输入`#`的情况，这时候应当没有输出，而且没有空行。这点体现于`测试点2`。

	其次是用户尝试的密码可能带有空格，如果用C/C++，需要处理这种情况。可能需要结合`getchar()`与`ungetc()`进行处理。

	还需要注意的是，因为`正整数N<=10`，所以应当借助`split(' ')`获取正确密码和`n`，如果用`[-1]`，则无法获取正确的允许尝试次数。这点体现于`测试点5`。

#	部分测试用例

*	case1

		输入
		Correct%pw 3
		#

		输出
		
*	case2

		输入
		abc 10
		a a
		b
		b
		b
		b
		b
		b
		b
		b
		c
		abc
		#

		输出
		Wrong password: a a
		Wrong password: b
		Wrong password: b
		Wrong password: b
		Wrong password: b
		Wrong password: b
		Wrong password: b
		Wrong password: b
		Wrong password: b
		Wrong password: c
		Account locked

#	其他参考

*	[liaoxuefeng: python教程](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000)

*	[Python Docs: stdtype---set()](https://docs.python.org/3/library/stdtypes.html#types-set)

*	[int getchar(void);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.12.html#getchar)

*	[int ungetc(int char, FILE *stream);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.12.html#ungetc)

*	// TODO 同类题目互联