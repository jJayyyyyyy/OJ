##	[原题](https://www.patest.cn/contests/pat-b-practise/1002)： 1002. 写出这个数 (20)

读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

###	输入格式

每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10<sup>100</sup>。

###	输出格式

在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

###	输入样例

	1234567890987654321123456789

###	输出样例

	yi san wu

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	输入

	输入视作字符串，而不是整数

	*	因为输入上限是10^100，所以字符串长度最大为100

	*	将每个字符转化为数字，求和得到sigma  
		由于字符串长度最大为100，每一位最大数字是9，可得sigma最大为9×100=900

2.	输出

	建立一个字符串数组`num_pinyin`，每个元素是0~9的拼音

	```c
	const char *num_pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	```

3.	普通解法

	输入求和得到sigma

	```c
	scanf("%s", us_num);
	while( us_num[i]!='\0' ){
		sigma += (us_num[i++]-'0');
	}
	```

	获取sigma各数位的数字

	```c
	p_hundreds = sigma / 100;
	sigma = sigma - p_hundreds*100;
	p_tens = sigma / 10;
	sigma = sigma - p_tens*10;
	p_units = sigma;
	```

	输出逻辑

	*	a. 从高到低，
	*	b. 高位非零，低位全打
	*	c. 高位为零，内嵌if，下一位作为高位，回到b

	```c
	if( 0!=p_hundreds )
		printf("%s %s %s", num_pinyin[p_hundreds], num_pinyin[p_tens], num_pinyin[p_units]);
	else
		if( 0!=p_tens )
			printf("%s %s", num_pinyin[p_tens], num_pinyin[p_units]);
		else
			printf("%s", num_pinyin[p_units]);
	```

4.	<b>高阶写法</b>

	参考[这里](https://www.nowcoder.com/profile/243727/codeBookDetail?submissionId=3313687)，如果掌握了`int(), str(), map(), sum()`，则可以用python写出更<b>精妙</b>的代码：

	```python
	num_pinyin = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
	us_num = raw_input()

	us_num = map(int, us_num)
	sigma = sum(us_num)
	sigma = str(sigma)

	for i in range(len(sigma)):
		print num_pinyin[int(sigma[i])],
	```

	只有10行左右，而且逻辑清晰。我们也可以参考这个思路，改写C的代码。对应`sigma = str(sigma)`

	```c
	sprintf(us_num, "%d", sigma);
	```

	对应后两行，则有

	```c
	while(us_num[i+1]!='\0')
		printf("%s ", num_pinyin[us_num[i++]-'0']);
	printf("%s", num_pinyin[us_num[i]-'0']);
	```

5.	更新1---增加cpp的实现

	*	时间效率略逊于C，但是属于同一数量级，应该说是几乎相同。

	*	用`string类`代替`char数组`，以保存字符串。会根据需要自动分配内存空间，不需要手动申请最大空间。自带多种操作方法，如`.size()`等。注意`string类`不是以`'\0'`结尾，用长度`.size()`判断结尾。

	*	`stringstream`代替`sprintf()`，将数字转变成字符串

		```cpp
		#include <sstream>

		string num2string(int num){
			stringstream ss;
			ss << num;

			return ss.str();
		}
		```

	*	附加两个将字符串变成数字的方法。第一个需要在编译的时候加上 `-std=c++11`
		
		```cpp
		int num=0;
		string us_str="123";

		num = stoi(us_str);
		```

		第二个则仍是利用`sstream`库

		```cpp
		#include <sstream>

		int string2num(string us_str){
			int num=0;
			stringstream ss;
			ss << us_str;
			// stringstream ss(us_str);

			ss >> num;
			return num;
		}
		```

#	部分测试用例:

*	test1

	```
	测试用例
	1234567890987654321123456789

	输出
	yi san wu
	```

*	test2

	```
	测试用例:
	1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890

	输出:
	si wu ling
	```

*	test3

	```
	测试用例：
	999999999999

	输出：
	yi ling ba
	```

#	参考

*	[Yaicky提交的代码](https://www.nowcoder.com/profile/243727/codeBookDetail?submissionId=3313687)

*	[The C Library Reference Guide](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/?)

*	字符串数组的声明与初始化

	```c
	const char *num[]={"one", "two", "three"};
	```

*	获取字符串输入

	```c
	char num[10];
	gets(num);				//可能溢出
	fgets(num, 10, stdin);	//会保存作为输入确认的'\n'
	scanf("%s", num);		//遇到空格结束
	```

	python中字符串可以用单引号`'`，也可以用双引号`"`。

	用惯了python，就容易忘记C的语法要求。。C中单引号只能包裹字符，双引号包裹的是字符串。字符串是以空字符`'\0'`结尾的`char数组`。

*	`sprintf()`

	在`stdio.h`中声明。原型为
	
	```c
	int sprintf(char *str, const char *format, ...);
	```

	不同于`printf()`的打印输出，它的作用是将内容保存为字符串，类似于python中的`str()`函数，比如

	```c
	char us_num[10];
	int sigma = 12345;
	sprintf(us_num, "%d", sigma);
	printf("%s", us_num);
	```

	则`us_num`的内容就变成了"12345"。

---更新cpp参考---

*	[cplusplus.com, std::stoi](http://www.cplusplus.com/reference/string/stoi/)

*	[Stack Overflow, num2string using sstream](http://stackoverflow.com/questions/11751486/qt-c-aggregate-stdstringstream-ss-has-incomplete-type-and-cannot-be-define)

*	[cplusplus.com, Converting numbers to strings and strings to numbers](http://www.cplusplus.com/forum/articles/9645/)

