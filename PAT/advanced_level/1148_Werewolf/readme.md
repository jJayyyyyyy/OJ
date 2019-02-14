##	1148 Werewolf - Simple Version (20)

Werewolf（狼人杀） is a game in which the players are partitioned into two parties: the werewolves and the human beings. Suppose that in a game,

```
player #1 said: "Player #2 is a werewolf.";
player #2 said: "Player #3 is a human.";
player #3 said: "Player #4 is a werewolf.";
player #4 said: "Player #5 is a human."; and
player #5 said: "Player #4 is a human.".
```

Given that there were `2 werewolves` among them, `at least one but not all the werewolves were lying`, and there were `exactly 2 liars`. Can you point out the werewolves?

Now you are asked to solve a harder version of this problem: given that there were N players, with 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. You are supposed to point out the werewolves.

<br>

##	Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (5≤N≤100). Then N lines follow and the i-th line gives the statement of the i-th player (1≤i≤N), which is represented by the index of the player with a positive sign for a human and a negative sign for a werewolf.

<br>

##	Output Specification:

If a solution exists, print in a line in ascending order the indices of the two werewolves. The numbers must be separated by exactly one space with no extra spaces at the beginning or the end of the line. If there are more than one solution, you must output the smallest solution sequence -- that is, for two sequences A=a[1],...,a[M] and B=b[1],...,b[M], if there exists 0≤k<M such that a[i]=b[i] (i≤k) and a[k+1]<b[k+1], then A is said to be smaller than B. In case there is no solution, simply print No Solution.

<br>

##	Sample Input 1:

```
5
-2
+3
-4
+5
+4
```

<br>

##	Sample Output 1:

```
1 4
```

<br>

##	Sample Input 2:

```
6
+6
+3
+1
-5
-2
+4
```

<br>

##	Sample Output 2 (the solution is not unique):

```
1 5
```

<br>

##	Sample Input 3:

```
5
-2
-3
-4
-5
-1
```

<br>

##	Sample Output 3:

```
No Solution
```

<br>

##	Info

```
作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB
```
	
<br>
