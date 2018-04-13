##	[原题](https://www.patest.cn/contests/pat-b-practise/1008)： 1008. 数组元素循环右移问题 (20)

一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A<sub>0</sub> A<sub>1</sub>……A<sub>N-1</sub>）变换为（A<sub>N-M</sub> …… A<sub>N-1</sub> A<sub>0</sub> A<sub>1</sub>……A<sub>N-M-1</sub>）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

###	输入格式

每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

###	输出格式

在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

###	输入样例1

	6 2
	1 2 3 4 5 6

###	输出样例1

	5 6 1 2 3 4

###	注意

	时间限制： 400 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard

<br/><br/>

#	题目分析

<b>注意：</b> 题目中右移位数可以大于总位数。即等效移动位数是

```c
M = M % N;
```

1.	方法1

	使用临时变量`tmp`，相邻交换，一次移动一位，移动M遍。

2.	方法2

	变数据结构，使用循环队列，循环链表，空间换时间。其实也没有用太多空间，加了个指针而已。根据需要移动指针头，然后输出即可，数据本身不需要移动。

3.	方法2简化

	借鉴链表的思想，改造数组，使其成为循环数组。

	*	数据结构
	
		```c
		typedef struct Node{
			int data;
			struct Node *next;
		}ListType;
		```

	*	初始化

		```c
		ListType *init_list(ListType arr[], const int us_N){
			int i=0;

			for(i=0; i<us_N; i++){
				scanf("%d", &arr[i].data);
				arr[i].next = &arr[i+1];
			}
			arr[i-1].next = &arr[0];

			return &arr[0];
		}
		```

		这种做法，在已知MAXSIZE时可以快速建立一个循环链表。可以移动头指针head。兼容链表的动态扩展。可以用数组的索引。

	*	移位

			左移 = M % us_N
			左移 + 右移 = us_N

		若用l_shift, r_shift分别代表左移和右移，则有

		```c
		ListType *shift_head(ListType *head, const int us_N, const int us_shift){
			int i=0, r_shift=0;
			// int l_shift=0;

			r_shift = us_N - us_shift%us_N;
			// l_shift = us_shift % us_N;
			for(i=0; i<r_shift; i++){
				head = head->next;
			}

			return head;
		}
		```

	*	输出

		根据右移位数M，移动头指针，然后依次输出数据即可。注意行尾无空格。

		```c
		int print_list(ListType *head, const int us_N){
			int i=0, is_start=1;

			for(i=0; i<us_N; i++){
				if(is_start){
					printf("%d", head->data);
					is_start = 0;
				}else
					printf(" %d", head->data);
				head = head->next;
			}

			return 0;
		}
		```
	
#	部分测试用例

*	test1

		输入
		6 2
		1 2 3 4 5 6

		输出
		5 6 1 2 3 4

#	其他参考

*	[list](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/list)

