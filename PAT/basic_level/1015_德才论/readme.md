##	[原题](https://www.patest.cn/contests/pat-b-practise/1015)： 1015. 德才论 (25)

宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

###	输入格式

输入第1行给出3个正整数，分别为：

*	N（<=10^5），即考生总数；
*	L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
*	H（<100），为优先录取线。

考生排名规则如下：

*	德分和才分均不低于H的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
*	才分不到H但德分到H线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
*	德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
*	其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

###	输出格式

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。

当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

###	输入样例

	14 60 80
	10000001 64 90
	10000002 90 60
	10000011 85 80
	10000003 85 80
	10000004 80 85
	10000005 82 77
	10000006 83 76
	10000007 90 78
	10000008 75 79
	10000009 59 90
	10000010 88 45
	10000012 80 100
	10000013 90 99
	10000014 66 60

###	输出样例

	12
	10000013 90 99
	10000012 80 100
	10000003 85 80
	10000011 85 80
	10000004 80 85
	10000007 90 78
	10000006 83 76
	10000005 82 77
	10000002 90 60
	10000014 66 60
	10000008 75 79
	10000001 64 90

###	注意

	时间限制： 200 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Li

<br/><br/>

#	题目分析

1.	`理解题意，拆分题目`

	*	确定存储结构
	*	首先获取合格考生(德和才都>=L)
	*	考生分类
	*	确定排序规则cmp()

2.	`存储结构`

	```c
	typedef struct{
		int id;	
		int moral;
		int talent;	
		int sum;
	}Student;
	```

	另外可再设临时变量`int id, moral, talent, sum;`让代码更加清晰简洁。

3.	`获取合格考生`

	为了减少重复循环，我们在第一次输入的时候就进行分配，将考生成绩分为`不合格`，`Student *stu_a, *stu_b, *stu_c, *stu_d;`，而不是第一遍循环先筛掉不合格的，另外再来一遍循环进行分类。

	同时可以记录合格考生总数，及各类考生人数`int num_pass, num_a, num_b, num_c, num_d;`

	考虑到内存很充足，采取空间换时间的策略。每一类考生数量都在一开始就分配`us_num=N`的空间，而不是每次输入的时候单独分配`size=1`的空间，可以部分提高效率。

	```c
	stu_a = (Student *)malloc( us_num * sizeof(Student) );
	stu_b = (Student *)malloc( us_num * sizeof(Student) );
	stu_c = (Student *)malloc( us_num * sizeof(Student) );
	stu_d = (Student *)malloc( us_num * sizeof(Student) );
	```

	注意最后要进行`free(stu_a);`等操作。

4.	`考生分类`

	按照题目逻辑即可，最好在纸上用伪代码写下，比原题一坨文字要清晰，免得出错。
	
5.	`排序` <b>(非常重要)</b>

	C中提供了快排，不需要我们重复造轮子了，但是要掌握原型和接口。ANSI C的`qsort()`原型如下：

	```c
	void qsort( void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *) );
	```
	
	结合本题就是

	```c
	#inlcude <stdlib.h>
	qsort(stu_a, num_a, sizeof(Student), cmp);
	```

	`关键点1`：`cmp`是一个指向函数的指针。在`C Primer Plus`的例程中，如果按照升序排序，则可以这样

	```c
	int cmp1(const void *p1, const void *p2){
		const int *a1 = (const int *)p1;
		const int *a2 = (const int *)p2;

		if(*a1 < *a2) //a1<a2 and a1排在a2前面
			return -1;
		else if(*a1 == *a2)
			return 0;
		else
			return 1;
	}
	```

	可以总结出如下规律：

	```c
	if a1<a2 and 升序(a1 排在 a2 之前):
		return -1;

	if a1<a2 and 降序(a1 排在 a2 之后):
		return 1;
	```

	`关键点2`：用于排序的`cmp()`比较的是一个总体的权重。自己以前的思维固化了。。一开始是这么想的，第一遍先根据`sum`排序，然后以`moral`进行第二遍排序，etc...然后导致逻辑混乱。

	殊不知应该把`Student`作为一个整体，其中的四项内容各有权重，应当根据加权之后的结果确定每一个`Student`的次序。结合题意可得

	```c
	int cmp2(const void *p1, const void *p2){
		const Student *a1 = (const Student *)p1;
		const Student *a2 = (const Student *)p2;

		if(a1->sum < a2->sum)
			return 1;
		else if(a1->sum > a2->sum)
			return -1;
		else{
			if(a1->moral < a2->moral)
				return 1;
			else if(a1->moral > a2->moral)
				return -1;
			else{
				if(a1->id < a2->id)
					return -1;
				else
					return 1;
			}
		}
	}
	```

	再参考[这里](https://github.com/liuchuo/PAT/blob/master/PAT%E4%B9%99%E7%BA%A7(Basic%20Level)/1015.%20%E5%BE%B7%E6%89%8D%E8%AE%BA%20(25).cpp)，我们就可以得到精简后的`cmp()`如下

	```c
	int cmp(const void *p1, const void *p2){
		const Student *a1 = (const Student *)p1;
		const Student *a2 = (const Student *)p2;

		if(a1->sum != a2->sum)
			return a1->sum < a2->sum;
		else if(a1->moral != a2->moral)
			return a1->moral < a2->moral;
		else
			return a1->id > a2->id;
	}
	```	

	<h6>PS：C++中的`sort()`和C中的`qsort()`有所区别，两者对`cmp()`的返回值的要求是相反的。更多内容可以参考<a href="https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1005_%E7%BB%A7%E7%BB%AD(3n%2B1)%E7%8C%9C%E6%83%B3">1005 继续(3n+1)猜想</a></h6>

#	部分测试用例

*	test1
	
		5 60 60
		10000001 10 10
		10000002 40 60
		10000011 85 80
		10000003 85 50
		10000013 85 70

*	test2

		14 60 80
		10000001 64 90
		10000002 90 60
		10000011 85 80
		10000003 85 80
		10000004 80 85
		10000005 82 77
		10000006 83 76
		10000007 90 78
		10000008 75 79
		10000009 59 90
		10000010 88 45
		10000012 80 100
		10000013 90 99
		10000014 66 60

#	其他参考

*	[结构体赋值](http://blog.csdn.net/li698753214/article/details/17450707)
>结构和数组在定义时赋值叫做初始化，能用一个{}整体赋值，而定义以后再想要赋值则只能一次给一个成员赋值，不能用{}。

*	python可以考虑用面向对象的方法，比用list+dict方便，效率和内存待考证。

*	[1005 继续(3n+1)猜想](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/basic_level/1005_%E7%BB%A7%E7%BB%AD(3n%2B1)%E7%8C%9C%E6%83%B3)

<!-- 
	考虑速度，用dict？ 空间换时间
	不是简单的

for i in range(us_Num):
	us_input = input().split()
	stu['id'] = us_input[0]
	stu['s_moral'] = us_input[1]
	stu['s_talent'] = us_input[2]
	stu_list.append(stu)

	stu_list[i]指向地址stu，不是创建新对象并返回，stu只有一个，后面的内容会覆盖前面的内容，所以最后stu_list[i]都会变成stu_list[-1]

	需要 新对象
	stu_list.append({'id':us_input[0], 's_moral':us_input[1], 's_talent':us_input[2]})

	但是换成变量就可以，为啥？
	stu['id'] = us_input[0]
	stu['s_moral'] = us_input[1]
	stu['s_talent'] = us_input[2]

	一级入口，二级入口？

	stu_list.append(stu)
	->stu ->stu['id']->存储输入的地址
			->stu['s_moral']->存储输入的地址
			->stu['s_talent']->存储输入的地址
-->
