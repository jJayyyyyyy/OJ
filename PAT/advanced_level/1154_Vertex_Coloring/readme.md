##	1154 Vertex Coloring(25)

A proper vertex coloring is a labeling of the graph's vertices with colors such that no two vertices sharing the same edge have the same color. A coloring using at most k colors is called a (proper) k-coloring.

Now you are supposed to tell if a given coloring is a proper `k-coloring`.

<br>

##	Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers `N` and `M` (both no more than `10^4`), being the total numbers of vertices and edges, respectively. Then `M` lines follow, each describes an edge by giving the indices (from `0` to `N − 1`) of the two ends of the edge.

After the graph, a positive integer `K ( ≤ 100 )` is given, which is the number of colorings you are supposed to check. Then `K` lines follow, each contains `N` colors which are represented by non-negative integers in the range of int. The `i-th` color is the color of the `i-th` vertex.

<br>

##	Output Specification:

For each coloring, print in a line `k-coloring` if it is a proper `k-coloring` for some positive `k`, or `No` if not.

<br>

##	Sample Input:

```
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 8 9
```

<br>

##	Sample Output:

```
4-coloring
No
6-coloring
No
```

<br>

##	Info

```
作者: 陈越
单位: 浙江大学
时间限制: 900 ms
内存限制: 64 MB
代码长度限制: 16 KB
```
