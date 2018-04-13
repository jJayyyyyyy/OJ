##	[原题](https://www.patest.cn/contests/pat-b-practise/1022)： 1022. D进制的A+B (20)

输入两个非负10进制整数A和B(<=2<sup>30</sup>-1)，输出A+B的D (1 < D <= 10)进制数。

###	输入格式

输入在一行中依次给出3个整数A、B和D。

###	输出格式

输出A+B的D进制数。

###	输入样例

	123 456 8

###	输出样例

	1103

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	输入输出范围

	令`sigma=a+b`，根据题意可得 sigma <= 2<sup>31</sup>-2 < 2^<sup>31</sup>-1

	得到两个推论：

	*	可用`int`类型保存输入
	*	输出的数字位数最多为`32位`（转为2进制）

2.	计算

	建立`output[]`数组逆序保存输出，长度取40即可。然后进行进制转换

	```cpp
	while( sigma!=0 ){
		remain = sigma % baseD;
		output[i++] = remain;
		
		sigma /= baseD;
	}
	```

	最后逆序输出`output[]`即可

	```
	while( i!=0 ){
		i--;
		printf("%d", output[i]);
	}
	```

#	部分测试用例

*	test1

		输入
		0 0 2

		输出
		0

*	test2

		输入
		123 456 10

		输出
		579

#	其他参考

	// TOTO
	// 同类题目整理汇总