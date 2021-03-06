##	[原题](https://www.patest.cn/contests/pat-b-practise/1024)： 1024. 科学计数法 (20)

科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

###	输入格式

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

###	输出格式

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

###	输入样例1

	+1.23400E-03

###	输出样例1

	0.00123400

###	输入样例2

	-1.2E+10

###	输出样例2

	-12000000000

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： HOU, Qiming

<br/><br/>

#	题目分析

1.	思路

	Python source file is quite self-explanatory.

2.	cpp实现

	思路同python，不过需要实现部分函数。

	首先是将数字字符串转为整型的`str2num()`，对应于python中的`int()`，借助`stringstream`类即可实现。

	其次是切片。cpp的string类与python字符串的切片略有不同。

	```cpp
	string slice(string s, int begin, int end=-1){
		if( -1!=end )
			return s.substr(begin, end-begin);
		else
			return s.substr(begin);
	}
	```

	注意python从下标n切片到末尾可以直接用`s[n:]`，即不需要写末尾下标。而这里cpp的`slice()`利用了默认参数来省略末尾下标。

	最后是复制字符。python可以用`'0'*5`的方法创造`"00000"`，cpp则可用如下方法

	```cpp
	string nString(char ch, int n){
		string s(ch, n);
		return s;
	}
	```

	这样就可以用 `nString('0', 5)` 来构造`"00000"`了。注意第一个参数不能是字符串，否则含义不同。

3.	注意符号号

	正数不需要正号，负数需要负号`-`

#	部分测试用例

*	test1

		输入
		+1.23400E-03
		
		输出
		0.00123400

*	test2

		输入
		-1.2E+10

		输出
		-12000000000

#	其他参考

	// TOTO
	// 同类题目整理汇总
