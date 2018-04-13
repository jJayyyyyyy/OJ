##	[原题](https://www.patest.cn/contests/pat-b-practise/1018)： 1018. 锤子剪刀布 (20)

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

![rules](https://www.patest.cn/upload/7r_muvaqb4myb9.jpg)

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

###	输入格式

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

###	输出格式

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

###	输入样例

	10
	C J
	J B
	C B
	B B
	B C
	C C
	C B
	J B
	B C
	J J

###	输出样例

	5 3 2
	2 3 5
	B B

###	注意

	时间限制： 100 ms
	内存限制： 65536 kB
	代码长度限制： 8000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析

1.	存储结构

	结构体中应当记录各自胜平负的次数，以及各种手势的胜利次数。

	```c
	typedef struct{
		int cnt_Win;
		int cnt_Tie;
		int cnt_Lose;
		int cnt_Bu_Win;
		int cnt_Chui_Win;
		int cnt_Jian_Win;
	}Player;
	```

2.	输入

	每输入一行，就进行胜平负的判断与记录。

	```c
	for(i=0; i<us_N; i++){
		scanf("%s %s", choice_a , choice_b);
		judge(a, choice_a[0], b, choice_b[0]);
	}
	```

2.	输出

	从结构体中读出甲乙各自的胜平负次数，再从结构体中读出胜利次数最多的手势。

	```c
	printf("%d %d %d\n", a->cnt_Win, a->cnt_Tie, a->cnt_Lose);
	printf("%d %d %d\n", b->cnt_Win, b->cnt_Tie, b->cnt_Lose);
	printf("%c %c\n", how_to_win(a), how_to_win(b));
	```

#	部分测试用例

*	test1

		输入
		10
		C J
		J B
		C B
		B B
		B C
		C C
		C B
		J B
		B C
		J J

		输出
		5 3 2
		2 3 5
		B B

#	其他参考

*	注意如果用

	```c
	char a, b;
	scanf("%c %c", &choice_a , &choice_b);
	```

	则b会读入空格，因此需要用其他方法读取输入。

