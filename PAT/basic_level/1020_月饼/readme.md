##	[原题](https://www.patest.cn/contests/pat-b-practise/1020)： 1020. 月饼 (25)

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

###	输入格式

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

###	输出格式

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

###	输入样例

	3 20
	18 15 10
	75 72 45

###	输出样例

	94.50

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	思路

	*	首先按照单价降序排列

		```cpp
		getCakes(cakes, usN);
		sort(cakes, cakes+usN, decCmp);	//降序排列
		```

	*	然后优先卖出单价高的月饼

		```cpp
		//maxPrice为最大收益
		double maxPrice=0.0;
		for( int i=0; i<usN; i++ ){
			if( demand>=cakes[i].stock ){
				maxPrice += cakes[i].totalPrice;
				demand -= cakes[i].stock;
			}else{
				maxPrice += demand * cakes[i].unitPrice;
				break;
			}
		}
		```

2.	存储结构

	```cpp
	struct Cake{
		double stock;		//库存量
		double totalPrice;	//每类月饼的总价
		double unitPrice;	//每类月饼的单价
	};
	```

	注意题目所述`库存量`可能为小数，因此需要用`double`类型存储。

#	部分测试用例

*	test1

		输入
		3 20
		18 15 10
		75 72 45

		输出
		94.50

#	其他参考

*	设置cout能够输出小数

	[link1](http://c.biancheng.net/cpp/biancheng/view/2227.html), [link2](http://www.cnblogs.com/devymex/archive/2010/09/06/1818754.html)

	```cpp
	#include <iostream>
	#include <iomanip>
	using namespace std;

	int main(){
		cout.setf(ios::fixed);
		cout<<setprecision(2)<<12.1567;
	}
	```

	不过仍然推荐使用更方便的`printf()`