##	[原题](https://www.patest.cn/contests/pat-a-practise/1071)：1071. Speech Patterns (25)

People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

###	Input Specification

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

###	Output Specification

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

###	Sample Input

	Can1: "Can a can can a can?  It can!"

###	Sample Output

	can 5

###	注意

	时间限制： 300 ms
	内存限制： 65536 kB
	代码长度限制： 16000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	输入

	根据题意，一个`word`仅由字母/数字组成，其他的可见/非可见字符可以等效为空格/分隔符。
	
	为保证速度，需要关闭cin/cout的部分特性
	
	```cpp
	ios::sync_with_stdio(false);
	cin.tie(0);
	```

	但是这样就不能混用`cstdio`了，那我们如何像`getchar()`一样获取单个字符呢？
	
	这里就要用到`cin.get()`了。根据参考链接和测试，`cin.get() in cpp is equivalent to getchar() in c`，因此可以这样获取单个字符。
	
	```cpp
	char ch;
	cin.get(ch);
	```

2.	其他

	有了上面的步骤，剩下的工作就简单了。对于字母/数字的处理可以用
	
	```cpp
	#include <cctype>
	
	isalnum(ch)			//判断是否为字母/数字
	tolower(ch)			//变为小写字母
	```
	
	另外注意每次循环清空`string s`后，要在下一次使用`s.length()>0`作为填入`map`的条件，否则会填入空的`key`。关于`map`的使用，可以参考[PAT_A_1054](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1054_The_Dorminat_Color)和[cpp reference: map](http://www.cplusplus.com/reference/map/map/?kw=map)

#	参考用例

*	case1

		输入：
		can 5

		输出：
		5 1

*	case2

		输入：
		a 123# 123 123 a
		
		输出：
		123 3

#	其他参考

*	[cpp reference: map](http://www.cplusplus.com/reference/map/map/?kw=map)

*	[cpp reference: cin.get()](http://www.cplusplus.com/reference/istream/istream/get/?kw=cin.get)

*	[cpp reference forum: Equivalent of cin.getline for one char?](http://www.cplusplus.com/forum/beginner/34329/)

*	[quora: What-is-the-C++-equivalent-of-get-char-in-C](https://www.quora.com/What-is-the-C++-equivalent-of-get-char-in-C)


*	晴神宝典

*	同类题目互联

	[PAT_A_1054](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1054_The_Dorminat_Color)  
	[PAT_A_1071](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1071_Speech_Patterns)  
	[PAT_A_1022](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1022_Digital_Library)

*	// TODO 更多同类题目互联
