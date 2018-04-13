##	[原题](https://www.patest.cn/contests/pat-b-practise/1010)： 1010. 一元多项式求导 (25)

设计函数求一元多项式的导数。（注：x<sup>n</sup>（n为整数）的一阶导数为n*x<sup>n-1</sup>。）

###	输入格式

以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

###	输出格式

以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

###	输入样例1

	3 4 -5 2 6 1 -2 0

###	输出样例1

	12 3 -10 1 6 0

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard

<br/><br/>

#	题目分析

本题的题意不明确，至少题意、输入输出样例与测试点之间有矛盾，不进行过多分析。

1.	AC代码

	网上流传的大部分是这个思路的代码(可以通过测试)

	```c
	#include<stdio.h>

	int main(){
		int coe=0, exp=0, is_start=1;

		while( scanf("%d%d", &coe, &exp)==2 ){
			if( coe*exp ){
				if( is_start==0 )
			    	printf(" ");
				else{
			    	is_start = 0;
				}
				printf("%d %d",n*e,e-1);
			}
		}
		if( is_start )	//trick
			printf("0 0");

		return 0;	
	}
	```

	最后那段应该是个trick，专门应对某个测试用例的。这是我猜的，因为与题目逻辑不符。如有错误请指正。

#	测试结果描述

*	test1

		两者非零 打印 [coe*exp, exp-1]，否则打印 [0 0]
		通过测试2 3 5
		//然而这和输入样例明显不符，输入-2 0，输出应该是空。

*	test2

		exp 非零 就打印 [coe*exp, exp-1]
		通过测试 1 2 4

*	test3

		两者非零 打印 [coe*exp, exp-1]， 两者全零，打印[0 0]，退出循环后如果发现还没有输出，则打印[0 0]
		通过全部测试
		//然而这也和输入样例不符，输入[-2 0]，输出应该是空。

*	test4(牛客网测试用例)

		输入
		353 1000 -335 -1000

		输出
		353000 999 335000 -1001

		输入:
		-2 0

		对应输出应该为:
		0 0

		这对应了那个trick。但我觉得明显不符合题目描述啊。。。

#	其他参考

*	[scanf](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.12.html#scanf)

	`scanf("%s", str)`直到空格等字符结束，不会读取空格

	`gets()`直到换行符才结束，结束时增加`\0`

	`fgets(str, MAX, stdin)`直到换行符才结束，或者读到MAX-1个字符结束，末尾添加`\0`

	`getchar()`逐个读取字符，不会跳过空格，换行符等字符。

*	[int getchar(void);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.12.html#getchar)
	
	Gets a character (an unsigned char) from stdin. On success the character is returned. If the end-of-file is encountered, then EOF is returned and the end-of-file indicator is set. If an error occurs then the error indicator for the stream is set and EOF is returned.

*	[int atoi(const char *str);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.13.html#atoi)

	`atoi()`的原型在`stdlib.h`中声明。将字符串(0-9)转变成数字，可识别负号`-`

	The string pointed to by the argument str is converted to an integer (type int). Any initial whitespace characters are skipped (space, tab, carriage return, new line, vertical tab, or formfeed). The number may consist of an optional sign and a string of digits. Conversion stops when the first unrecognized character is reached.
On success the converted number is returned. If the number cannot be converted, then 0 is returned.

*	[int ungetc(int char, FILE *stream);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.12.html#ungetc)

	将字符char扔回stream流，比如把`'a'`放回输入流，这样下次用scanf()，getchar()等函数获取输入的时候首先会读到这个字符。

	Pushes the character char (an unsigned char) onto the specified stream so that the this is the next character read. The functions fseek, fsetpos, and rewind discard any characters pushed onto the stream.

	Multiple characters pushed onto the stream are read in a FIFO manner (first in, first out).

	On success the character pushed is returned. On error EOF is returned.

*	似乎不能在无限循环中用`scanf()`的返回值决定是否跳出。因为scanf()会自动跳过空格和换行符。

	gcc 4.8.4，vs2012， vc6.0 的编译器无法跳出循环，除非给一个类似`^+d`的EOF输入流结束标志

	但是pat的gcc 4.7.2可以跳出循环，如上那段程序可以通过所有测试用例。	某个online c complier用的是gcc 5.4.0，也可以跳出循环。是不是测试程序自动加的EOF？还是不同编译器对于C标准的实现不同？

