##	[原题](https://www.patest.cn/contests/pat-b-practise/1016)： 1016. 部分A+B (15)

正整数A的“D<sub>A</sub>（为1位整数）部分”定义为由A中所有D<sub>A</sub>组成的新整数P<sub>A</sub>。例如：给定A = 3862767，D<sub>A</sub> = 6，则A的“6部分”P<sub>A</sub>是66，因为A中有2个6。

现给定A、D<sub>A</sub>、B、D<sub>B</sub>，请编写程序计算P<sub>A</sub> + P<sub>B</sub>。

###	输入格式

输入在一行中依次给出A、D<sub>A</sub>、B、D<sub>B</sub>，中间以空格分隔，其中0 < A, B < 10<sup>10</sup>。

###	输出格式

在一行中输出P<sub>A</sub> + P<sub>B</sub>的值。

###	输入样例1

	3862767 6 13530293 3

###	输出样例1

	399

###	输入样例2

	3862767 1 13530293 8

###	输出样例2

	0

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

先把所有内容当做字符串处理。

1.	Python

	利用`.count()`方法统计出D<sub>A</sub>出现的次数cnt。

	```python
	cnt_Da = A.count(Da)
	```

	再用`*`直接拼接n次，得到P<sub>A</sub>，并用`int()`将其转为整数。注意cnt为0的情况。

	```python
	if cnt_Da:
		Pa = int(Da * cnt_Da)
	else:
		Pa = 0
	```

	对B作相同处理，然后两者相加即可。

2.	C++

	引入`<algorithm>`，即可得到`std::count()`

	```cpp
	string A;
	char a;		//注意a的类型
	//...

	cnt_a = count(A.begin(), A.end(), a);
	```

	接着根据D<sub>A</sub>和cnt_a计算P<sub>A</sub>即可。注意cnt_a为0的情况。

#	部分测试用例

*	test1

		输入
		3862767 6 13530293 3

		输出
		399

*	test2

		输入
		3862767 1 13530293 8

		输出
		0

#	其他参考

*	[NobodyKnow提交的代码](https://www.nowcoder.com/profile/2974017/codeBookDetail?submissionId=8275686)

	<!-- str.count() -->

*	[python-docs](https://docs.python.org/3/library/stdtypes.html#str.count)

	<!-- str.count() -->

*	[std::count(), count string](http://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string)

*	[std::count() can also count int](http://www.cplusplus.com/reference/algorithm/count/)

