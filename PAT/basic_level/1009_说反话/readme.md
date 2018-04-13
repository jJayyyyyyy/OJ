##	[原题](https://www.patest.cn/contests/pat-b-practise/1009)： 1009. 数组元素循环右移问题 (20)

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

###	输入格式

测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

###	输出格式

每个测试用例的输出占一行，输出倒序后的句子。

###	输入样例1

	Hello World Here I Come

###	输出样例1

	Come I Here World Hello

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, YUE

<br/><br/>

#	题目分析

本题时间要求不高，可以考虑用python，配合`split()`和`reverse()`，4行代码就够了。下面分析一下如何用C完成题目。

1.	思路

	假设一共有n个空格，我们先找到结束符`'\0'`（或`'\n'`），将其替换为`'_'`

	```
	Hello World Here I Come_
	```

	再向前找到第n个空格`' '`，替换为`'_'`。然后以下一个`'_'`为终点，这样我们就得到了最后一串字符。

	```
	Hello World Here I_Come_
	```

	重复以上步骤。最后再输出第一串字符即可。

2.	获取输入

	使用`fgets()`来获取整行输入。由于总长度不超过80，我们选取`MAX=81`

	```c
	fgets(str, 81, stdin);
	```

3.	获取一个单词

	*	起点：空格`' '`

		我们使用`strrchr()`从后往前寻找空格。

		```c
		strrchr(str, ' ');
		```

	*	终点:下划线`'_'`

		```c
		while( '_'!=p_find[i] )
			printf("%c", p_find[i++]);
		```

	*	词间空格
		
		```c
		printf(" ");
		```

4.	测试点

	至少要对这几种情况进行测试：

	*	样例测试
	*	只有一个单词，即输入的字符串无空格
	*	字符串长度为80

	注意：因为我们使用的是`fgets()`，字符串的结尾可能是`'\n'``'\0'`，也可能是`'\0'`，需要设置对应的判断条件。

5.	更新1---增加cpp的实现

	*	思路是这样，将输入拆分成字串后，逐个压入stack栈，然后LIFO出栈直到栈为空。压入的操作是`.push()`。出栈时先读顶部元素`.top()`，然后`.pop()`弹出栈顶，以此循环直到栈为空`.empty()`。

	*	`cin`和`scanf()`一样，如果作为退出循环的条件，本地测试时需要`^+d`作为输入流的`EOF`。但是OJ上会自动添加结束标志（猜测）。

		我们也可先用`getline()`读取整行，再转化为`stringstream ss`对象，再次调用等效于split的`getline(ss, sub_str, ' ')`，从而取出sub_str。代码段如下

		```cpp
		string us_str, sub_str;
		getline(cin, us_str);
		stringstream ss(us_str);

		while( !ss.eof() ){
			getline(ss, sub_str, ' ');
			str_stack.push(sub_str);
		}
		```

#	部分测试用例

*	test1

		输入
		Hello World Here I Come

		输出
		Come I Here World Hello

*	test2

		输入
		Hello

		输出
		Hello

#	其他参考

*	[char *fgets(char *str, int n, FILE *stream);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.12.html#fgets)

	`fgets()`最多读取`MAX-1`长度的字符串，包括作为输入确认的`'\n'`。末尾会和`gets()`一样，加上`'\0'`。

	由于输入中包含空格，而字符串总段数未知，用`scanf()`会比较麻烦。

	为防止内存溢出，尽量不要用`gets()`。

*	[char *strrchr(const char *str, int c);](https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/2.14.html#strrchr)

	`strrchr()`的原型在`string.h`中声明。该函数会返回字符串s中最后一次出现字符c的地址。若没找到则返回空指针。

---更新cpp参考---

*	[how to split a string in cpp](http://www.cplusplus.com/faq/sequences/strings/split/)

	注意，使用`istringstream`和`streamstring`类型都要`#include <sstream>`

