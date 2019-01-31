##	[原题](https://www.patest.cn/contests/pat-b-practise/1018)： 1018. 锤子剪刀布 (20)

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

![rules](https://www.patest.cn/upload/7r_muvaqb4myb9.jpg)

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

###	输入格式

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

###	输出格式

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

###	输入样例

```
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
```

###	输出样例

```
5 3 2
2 3 5
B B
```

###	注意

```
时间限制： 100 ms
内存限制： 65536 kB
代码长度限制： 8000 B
判题程序： Standard
作者： CHEN, Yue
```

<br>

#	题目分析

1.	存储结构

	结构体中应当记录各自胜平负的次数，以及各种手势的胜利次数。

	```c
	typedef struct{
		int win, tie, lose;
		int option_wincnt[128];
	} Player;
	```

#	部分测试用例

*	test1

	```
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
	```

#	其他参考

*	注意如果用

	```c
	char a, b;
	scanf("%c %c", &choice_a , &choice_b);
	```

	则b会读入空格。 有三种解决方案

	*	1. 使用其他语言, 如 `C++`

	*	2. 用 `scanf("%c")` 读取多余的 `空格` 和 `换行符`

		```c
		int n, i;
		char tmp, option1;
		scanf("%d%c", &n, &tmp);
		for( i = 0; i < n; i++ )
		{
			scanf("%c%c%c%c", &option1, &tmp, &option2, &tmp);
			/// ...
		}
		```

	*	3. 使用 `fgets()` 读取整行

		```c
		int n, i;
		char option1, option2, line[8];
		scanf("%d", &n);
		fgets(line, 8, stdin);
		for( i = 0; i < n; i++ )
		{
			fgets(line, 8, stdin);
			option1 = line[0];
			option2 = line[2];
			// ...
		}
		```
