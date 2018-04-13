##	[原题](https://www.patest.cn/contests/pat-b-practise/1039)： 1039. 到底买不买（20）

小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

![balls](https://www.patest.cn/upload/gx_nkqhj1eeck3.jpg)

###	输入格式

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

###	输出格式

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

###	输入样例1

	ppRYYGrrYBR2258
	YrR8RrY

###	输出样例1

	Yes 8

###	输入样例2

	ppRYYGrrYB225
	YrR8RrY

###	输出样例2

	No 2

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	建立索引

	根据字符对应ascii码进行hash存储，建立数组`offer[]`和`need[]`。

	```cpp
	int offer[160]={0}, need[160]={0}, i=0;
	char ch;
	for( i=0; i<len1; i++ ){
		ch = s1[i];
		offer[ch]++;
	}
	for( i=0; i<len2; i++ ){
		ch = s2[i];
		need[ch]++;
	}
	```

2.	确定珠串是否满足要求

	题目给定用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。首先在[0-9]范围内判断

	```cpp	
	for( i='0'; i<='9'; i++ ){
		if( offer[i]>=need[i] ){
			// 供大于求。
			// cnt_excess 记录多余的珠子数量。
			cnt_excess += offer[i] - need[i];
		}else{
			is_ok = 0;						// 初始值为1
			cnt_lack += need[i] - offer[i];	// 缺了多少颗珠子
		}
	}
	```

	然后对[a-z],[A-Z]进行类似的检查。

3.	输出

	```cpp
	if(is_ok)
		cout<<"Yes "<<cnt_excess;			// is_ok为1，满足要求，同时输出多的数量。
	else
		cout<<"No "<<cnt_lack;				// 不满足要求，同时输出缺的数量。
	```

#	部分测试用例

*	test1

		输入
		ppRYYGrrYBR2258
		YrR8RrY

		输出
		Yes 8

*	test2

		输入
		ppRYYGrrYB225
		YrR8RrY

		输出
		No 2

#	其他参考

*	[1029 旧键盘](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1029_%E6%97%A7%E9%94%AE%E7%9B%98)
*	[1033 旧键盘打字](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1033_%E6%97%A7%E9%94%AE%E7%9B%98%E6%89%93%E5%AD%97)
*	[1042 字符统计](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1042_%E5%AD%97%E7%AC%A6%E7%BB%9F%E8%AE%A1)
*	[1025 反转链表](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1025_%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8)
*	[1002 写出这个数](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1002_%E5%86%99%E5%87%BA%E8%BF%99%E4%B8%AA%E6%95%B0)

