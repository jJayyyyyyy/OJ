##	[原题](https://www.patest.cn/contests/pat-b-practise/1021)： 1021. 个位数统计 (15)

给定一个k位整数N = d<sub>k-1</sub>*10<sup>k-1</sup> + ... + d<sub>1</sub>*10<sup>1</sup> + d<sub>0</sub> (0<=d<sub>i</sub><=9, i=0,...,k-1, d<sub>k-1</sub>>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

###	输入格式

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

###	输出格式

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

###	输入样例

	100311

###	输出样例

	0:2
	1:3
	3:1

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	输入与存储

	将输入作为字符串，并根据ASCII码进行hash存储

	```c
	char us_strNum[MAX];
	int cnt[10]={0};
	scanf("%s", us_strNum);
	while( us_strNum[i]!='\0' ){
		n = us_strNum[i++] - '0';
		cnt[n]++;
	}
	```

2.	输出

	遍历`cnt[]`数组。如果`cnt[i]`非零，表示存在相应的数字`i`，且次数为`cnt[i]`。

	```c
	for(i=0; i<10; i++){
		if( cnt[i] )
			printf("%d:%d\n", i, cnt[i]);
	}
	```

#	部分测试用例

*	test1

		输入
		100311

		输出
		0:2
		1:3
		3:1

#	其他参考

	// TOTO
	// 同类题目整理汇总