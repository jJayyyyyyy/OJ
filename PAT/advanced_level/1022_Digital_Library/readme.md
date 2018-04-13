##	[原题](https://www.patest.cn/contests/pat-a-practise/1022)：1022. Digital Library (30)

A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

###	Input Specification

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

*	Line #1: the 7-digit ID number;
*	Line #2: the book title -- a string of no more than 80 characters;
*	Line #3: the author -- a string of no more than 80 characters;
*	Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
*	Line #5: the publisher -- a string of no more than 80 characters;
*	Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].

It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

*	1: a book title
*	2: name of an author
*	3: a key word
*	4: name of a publisher
*	5: a 4-digit number representing the year

###	Output Specification

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

###	Sample Input

	3
	1111111
	The Testing Book
	Yue Chen
	test code debug sort keywords
	ZUCS Print
	2011
	3333333
	Another Testing Book
	Yue Chen
	test code sort keywords
	ZUCS Print2
	2012
	2222222
	The Testing Book
	CYLL
	keywords debug book
	ZUCS Print2
	2011
	6
	1: The Testing Book
	2: Yue Chen
	3: keywords
	4: ZUCS Print
	5: 2011
	3: blablabla

###	Sample Output

	1: The Testing Book
	1111111
	2222222
	2: Yue Chen
	1111111
	3333333
	3: keywords
	1111111
	2222222
	3333333
	4: ZUCS Print
	1111111
	5: 2011
	1111111
	2222222
	3: blablabla
	Not Found

###	注意

	时间限制： 1000 ms
	内存限制： 65536 kB
	代码长度限制： 16000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	使用`STL`中的`map`和`set`

	由于用户的输入指明了进行搜索的类别，因此，对于`标题`，`作者`，`关键词`，`出版社`，`年份`这五个类别，因此可以相应地建立五个类别的索引数据类型采用map，其中key为类型，value为包含索引的id的集合set，注意set会自动去重和排序。

	```cpp
	map<string, set<string> > mTitle, mAuthor, mKeyword, mPublisher, mYear;
	```
	
2.	输入

	在每一个区块中，首先读取id，然后读取title，并更新对应的存储结构

	```
	mTitle[title].insert(id);
	```

	其余的几个类别也做类似处理。

3.	处理空白字符

	值得注意的是，不管是`scanf()`还是`cin`，不只是以空白字符作为输入间隔，而且会把空白字符留在输入流中。由于本题的keyword可能会有多个，即在一行中用空格分开

	```
	test code debug sort keywords
	```

	因此为了准确读取keyword，需要配合`getchar()`之类的函数，筛除输入流中多余的空白字符，对应本题即去掉` `和`\n`

	另一方面，`getline(cin, str)`会读取正行，而且不会把这一行中的空格` `和行尾的`\n`放回输入流。

4.	输出

	根据输入的最后n行数据，到对应的map中利用迭代器进行检索就可以了。由于map内部是二叉查找树，所以检索起来很快。

	```cpp
	int search(set<string> &qWord){
		if( qWord.size()==0 ){
			cout<<"Not Found\n";
			return 0;
		}

		for( it=qWord.begin(); it!=qWord.end(); it++ ){
			cout<<*it<<'\n';
		}
		
		return 0;
	}
	```

5.	优化运行用时

	测试点4数据量很大，为避免超时，需要进行一些优化。晴神宝典里面说时间主要消耗在3中`search()`的参数传递，要改成引用参数，其实主要的耗时点在于输入输出。由于`cin/cout`比`scanf()/printf()`有更多特性，必然带来性能损失。一般来说可以加上这么两行，屏蔽cin/cout的许多特性以换取时间:
	
	```cpp
	ios::sync_with_stdio(false);
	cin.tie(0);
	```

	然而我们我们用到了`getchar()`来过滤空字符，这是标准输入输出流中的函数，在添加上述代码之后再混用，就会产生问题。具体表现为`g++`(考试服务器所用编译器)编译后的程序无法退出，导致运行超时。

	这样我们就面临两种选择：1.取消上述两行代码；2.不用标准输入输出流函数。两者的代码分别在本文件夹的两个文件中。至于第2种选择，我们借用了`getline()`实现`getchar()`的功能。具体做法如下。

	建立string类型变量`newline`，然后用如下方法即可读取输入流中，n后面的换行符`\n`

	```
	cin>>n;
	getline(cin, whiteline);
	```

	对于keyword的获取，可以借助stringstream对象。首先用getline把正行读入keywords，然后转为ss对象，接着使用`getline(ss, keyword, ' ')`即可以空格为界，分别读取单独的keyword。代码如下

	```cpp
	// get keyword(s)
	getline(cin, keywords);
	stringstream ss(keywords);
	while( !ss.eof() ){
		getline(ss, keyword, ' ');
		mKeyword[keyword].insert(id);
	}
	```

#	部分测试用例

同输入样例

#	其他参考

*	[cpp reference: map](http://www.cplusplus.com/reference/map/map/?kw=map)

*	[cpp reference: set](http://www.cplusplus.com/reference/set/set/?kw=set)

*	晴神宝典

*	同类题目互联

	[PAT_A_1054](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1054_The_Dorminat_Color)  
	[PAT_A_1071](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1071_Speech_Patterns)  
	[PAT_A_1022](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1022_Digital_Library)

*	// TODO 更多同类题目互联