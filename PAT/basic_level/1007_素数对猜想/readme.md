##	[原题](https://www.patest.cn/contests/pat-b-practise/1007)： 1007. 素数对猜想 (20)

让我们定义 d<sub>n</sub> 为：d<sub>n</sub> = p<sub>n+1</sub> - p<sub>n</sub>，其中 p<sub>i</sub> 是第i个素数。显然有 d<sub>1</sub>=1 且对于n>1有 d<sub>n</sub> 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 10<sup>5</sup>)，请计算不超过N的满足猜想的素数对的个数。

###	输入格式

每个测试输入包含1个测试用例，给出正整数N。

###	输出格式

每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

###	输入样例1

	20

###	输出样例1

	4

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	孪生素数对

	题目中的素数对，指的是孪生素数对，即差为2的一对素数。结合样例，在N<=20的时候，有如下孪生素数对

		[3 5], [5 7], [11 13], [17 19]

2.	寻找素数

	请参考[1013_数素数： 题目分析](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1013_%E6%95%B0%E7%B4%A0%E6%95%B0#题目分析)

#	部分测试用例

*	test1

		输入
		20

		输出
		4

#	其他参考

*	[维基百科：孪生素数](https://zh.wikipedia.org/zh-hans/%E5%AD%AA%E7%94%9F%E7%B4%A0%E6%95%B0)

*	[果壳：孪生素数猜想---张益唐究竟做了一个什么研究？](http://www.guokr.com/article/437023/)

*	[1013_数素数](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1013_数素数)
