##	[原题](https://www.patest.cn/contests/pat-b-practise/1005)： 1005. 继续(3n+1)猜想 (25)

卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

###	输入格式

每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

###	输出格式

每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

###	输入样例

	6
	3 5 6 7 8 11

###	输出样例

	7 6

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	一种思路

	抽象结构体，包含两个变量，其一是输入的数字`value`，其二是标志符`key`，用于标明这个数是否为`关键数`

	```c
	typedef struct{
		int value;
		int key;
	}Number;
	```

	将输入存为一个数组`num[]`。首先假设每个数都是关键数`TRUE`，

	```c
	int init_num(Number *num, const int us_N);
	```

	然后从第一个数开始遍历数组`num`，若在`卡拉兹`运算过程中，出现的数字与`num`中的数字相同，则将该数字的`key`标为`FALSE`。

	在第一个数完成`卡拉兹`过程后，对第二个数进行同样处理。但若第二个数的`key`为`FALSE`，则直接跳过。因为根据定义，第二个数不是关键数。后面以此类推。

	```c
	int filter_keys(Number *num, const int us_N);
	```

2.	抽象

	首先是抽象出上述结构体。
	
	写完以后发现代码略长，因此可以试着抽象出每一个步骤，成为子函数，便于阅读。

3.	打印输出

	由于行尾不能有空格，引入一个`is_start`标志。第一次出现关键数时用`"%d"`，并把`is_start`置零。后续的关键数则用`" %d"`

3.	其他

	利用预定义，使逻辑和代码更清晰

	```c
	#define TRUE	1
	#define FALSE	0
	```

4.	更新1---增加cpp的实现

	*	根据C++ Primer 4th Edition 中文版

		关键字【class】和【struct】定义【类】的唯一差别在于默认访问级别。默认情况下，struct的成员为【public】，而class的成员为【private】.

	*	两种方式进行递减快排：利用兼容C的`<cstdlib>`之`qsort()`；利用`<algorithm>`之`sort()`。

		*	qsort()

			```c
			#include <cstdlib>
			//...

			int cmp_dec_c_qsort(const void *p1, const void *p2){
				const Number *a1 = (const Number *)p1;
				const Number *a2 = (const Number *)p2;

				return a1->value < a2->value;
			}
			//...

			qsort(num, us_N, sizeof(Number), cmp_dec_c_qsort);
			```

		*	sort()

			```cpp
			#include <algorithm>
			//...

			int cmp_dec_cpp_sort(const Number p1, const Number p2){
				return p1.value > p2.value;
			}
			//...

			sort(num, num+us_N, cmp_dec_cpp_sort);
			//sort(num.begin*(), num.end(), cmp);
			//sort(&num[0], &num[us_N], cmp);
			```
	
			注意
			1.	两个cmp()要求返回值相反。
			2.	C++的cmp()要求传递变量的值，而C的cmp()传入的是指针(地址)。
			3.	sort()和qsort()的接口不同。  
			第2点，有的地方会写成引用形参【&】的形式，但由于cmp()的不改变实参的值，所以和只传值效果相同。
  
			以上作为[1015_德才论](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1015_%E5%BE%B7%E6%89%8D%E8%AE%BA#题目分析)的补充。

#	部分测试用例

*	test1

		输入
		6
		3 5 6 7 8 11

		输出
		7 6

#	其他参考

*	`free()`一个没有没有`malloc()`的指针会出现 `Segmentation fault(core dumped)`。小心指针的使用，指向未经授权的地点，很容易出现上述`段错误`。必须确保声明了权限，也就是必须分配足够内存。

*	`char *strcat(char * s1, const char * s2);`

	s2指向的字符串，贴到s1指向字符串的结尾，并覆盖s1所指字符串结尾的空字符。返回值是是s1。

*	`char *strchr(const char * s, int c);`

	c对应一个字符，该函数在s所指的字符串中寻找c，并返回第一个c的地址。若找不到，则返回空指针。

	用法：`fgets()`会保留行尾输入的`'\0'`，可以利用`strchr()`将换行符去掉。

	```c
	char us_input[40];
	char *findLF;

	fgets(us_input, 40, stdin);
	findLF = strchr(us_input, '\n');
	if(findLF)
		*findLF = '\0';
	```

*	[C Primer Plus](http://faculty.euc.ac.cy/scharalambous/csc131/books/C%20book%201.pdf)

---更新cpp参考---

*	[Beginners guide to the std::sort() function](http://www.cplusplus.com/articles/NhA0RXSz/)

*	[1015_德才论](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1015_%E5%BE%B7%E6%89%8D%E8%AE%BA)

