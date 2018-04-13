##	[原题](https://www.patest.cn/contests/pat-b-practise/1063)： 1063. 计算谱半径(20)

在数学中，矩阵的“谱半径”是指其特征值的模集合的上确界。换言之，对于给定的n个复数空间的特征值{a1+b1i, ..., an+bni}，它们的模为实部与虚部的平方和的开方，而“谱半径”就是最大模。

现在给定一些复数空间的特征值，请你计算并输出这些特征值的谱半径。

###	输入格式

输入第一行给出正整数N（<= 10000）是输入的特征值的个数。随后N行，每行给出1个特征值的实部和虚部，其间以空格分隔。注意：题目保证实部和虚部均为绝对值不超过1000的整数。

###	输出格式

在一行中输出谱半径，四舍五入保留小数点后2位。

###	输入样例

	5
	0 1
	2 0
	-1 0
	3 3
	0 -3

###	输出样例1

	4.24

###	注意

	时间限制： 200 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	获取最大值

	每次都计算出谱半径`radius`，然后与前序的最大谱半径比较`max_radius`，从而更新最大谱半径`max_radius`

2.	四舍五入保留小数点后2位

	判断小数点后第3位是否会造成进位，采用了与[1026 程序运行时间](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1026_%E7%A8%8B%E5%BA%8F%E8%BF%90%E8%A1%8C%E6%97%B6%E9%97%B4)类似的思路

	```cpp
	if( (int)(max_radius*100+0.5)==(int)(max_radius*100) )
		printf("%.2f", max_radius);
	else
		printf("%.2f", max_radius+0.005);
	```

#	部分测试用例

同测试用例

#	其他参考

*	[1026 程序运行时间](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1026_%E7%A8%8B%E5%BA%8F%E8%BF%90%E8%A1%8C%E6%97%B6%E9%97%B4)
