##	[原题](https://www.patest.cn/contests/pat-a-practise/1049)：1049. Counting Ones (30)

The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

###	Input Specification

Each input file contains one test case which gives the positive N (<=2<sup>30</sup>).

###	Output Specification

For each test case, print the number of 1's in one line.

###	Sample Input

	12

###	Sample Output

	5

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 16000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

####	1. 题意

在十进制下给定一个正整数n，输出[1, n]之间所有的数字中出现`1`的次数总和。

举例：`n=12`，则输出`5`，因为`[1, 12]`之间包含`1`的数字有`1`，`10`，`11`，`12`，其中`11`有2个`1`，因此一共出现了5个`1`。

<br/>

####	2.1 穷举法

把[1, n]中的每个整数都写出来，然后数一数有多少个`1`。由于输入上限是2<sup>30</sup>，此方法很容易超时。不过30分中可以获得22分，也不失为一个快速拿分的途径。

####	2.2 排列组合法

本思路只考虑当前位置为1时，会出现多少种可能的组合。代码很简练，不过需要配合几个case进行思路理解。

假设输入是`32017`

*	当mid指向1，此时

		left = 320
		right = 7
		expo = 10

		ans += left*expo + right + 1;

	解释一下最后一行，当mid=1时，需要统计一共有多少个

		xxx1y

	此时需要分段。首先当xxx处于[0, 319]，即[0, left)，这时右边的y可以取[0, 9]，即[0, expo)，因此有left * expo这一项。

		而当xxx=320，这时右边只能取到[0, 7]，也就是(right + 1)项

*	当mid指向0，此时

		left = 32
		right = 17
		expo = 100

		ans += left * expo;

	解释一下最后一行。当mid=0时，需要向高位借位才能使其为1，即将32017降级为31199，并统计一共有多少个

		xx1yy

	其中，xx取值范围是[0, 31]，也就是[0, left)，无法取到32是因为被0借去了高位。而yy的范围是[0, 99]，即[0, expo)。因此有left * expo这一项。

*	当mid指向2时

		left = 3
		right = 017
		expo = 1000

		ans += (left + 1) * expo;

	解释一下最后一行。当mid=2时，需要舍弃1以上的部分，也就是将32017降级为31999，也即统计有多少个

		x1yyy

	其中，x的取值范围是[0, 3]，也就是[0, left+1)，yyy的取值范围是[0, 999]，即[0, expo)。因此有(left + 1) * expo这一项。

####	2.3 分段累加法

思路1包含了很多重复的工作，我们将其分层化简。

稍加分析即可得出，在每一个区间中出现`1`的最大次数是固定的且有规律的。即

	[0, 99]		一共有20个1
	[0, 999]	一共有300个1
	依此类推，可以得到
	[0, 9999]	4000
	[0, 99999]	50000
	[0, 999999]	600000
	...

举个例子，比如给定输入`313`，那么我们可以将其分为

	{ [0, 99], [100, 199], [200, 299] }, 
	{ [300, 313] }

两个大区间，四个小区间。在各个区间对1进行统计，可以得到
	
	[0, 99]		20
	[100, 199]	20+100（想想为什么）
	[200, 299]	20

	[300, 313]	6

由于已经统计完[0, 300]中的`1`，故最后一个区间相当于是统计[0, 13]中的`1`，也就是可以交给下一层函数。

#	部分测试用例

*	case 1

		输入
		313
		输出
		166

*	case 2

		输入
		734678505
		输出
		694841601

*	case 3

		输入
		565105412
		输出
		556058098
