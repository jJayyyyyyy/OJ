##	[原题](https://www.patest.cn/contests/pat-b-practise/1033)： 1033. 旧键盘打字 (20)

旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

###	输入格式

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

###	输出格式

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

###	输入样例

	7+IE.
	7_This_is_a_test.

###	输出样例

	_hs_s_a_tst

###	注意

	时间限制： 200 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	建立索引

	存储字符的下标是字符对应的ascii码，字母全部转为小写。标记s1中出现的字符。

	```cpp
	// int broken[160]={0};
	int get_broken_keys(string s1, int broken[]){
		int len1=s1.size(), i=0;
		char ch=0;
		for( i=0; i<len1; i++ ){
			ch = tolower(s1[i]);
			broken[ch] = 1;
		}

		return 1;
	}
	```

2.	分类

	对于非字母`ch`，即`[0-9]`, `-`, `_`, `,`, `.` —— `broken[ch]`非零即可输出

	若`ch`属于字母：

	*	小写字母，`broken[ch]`非零即可输出

	*	大写字母，则输出`ch`的条件是
		*	小写非零
		*	`shift`可用

	这样已经能拿到19分了，最后一分则与审题有关。

3.	如果没有一个字符能被打出，则输出空行。

	利用`has_output`变量，记录是否有可打印字符。

	```cpp
	int has_output=0;
	// ...

	if(has_output==0)
		cout<<'\n';
	```

4.	题目只保证第2行输入的文字串非空。（第一行可能为空，即键盘是好的。）

	使用`getline()`得到`s1`，`s2`；

	```cpp
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if( s1.size()==0 ){
		cout<<s2;
		return 0;
	}
	```

#	部分测试用例

*	test1

		输入
		7+IE.
		7_This_is_a_test.

		输出
		_hs_s_a_tst

*	test2

		输入
			(空行)
		7_This_is_a_test.

		输出
		7_This_is_a_test.

*	test3

		输入
		7_This_is_a_test.	(并非规范输入，只是为了更方便地看出问题)
		7_This_is_a_test.

		输出
			(空行)

#	其他参考

*	[1029 旧键盘](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1029_%E6%97%A7%E9%94%AE%E7%9B%98)

