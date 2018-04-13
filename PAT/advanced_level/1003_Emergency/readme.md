参考这里: [shortest_path](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/graph/shortest_path)

*   本题的第一个重点是Dijkstra，第二个重点是要计算出最短路径的个数(可能不止一条最短路径)
*   算出这些最短路径中，能召集到的最大数量的队伍
*   题目保证起点到终点之间有路可走。

##  update:
    
删除原来的代码，替换为统一的Dijkstra模板

*   用Dijkstra找出所有最短路径
*   从destID到srcID，用DFS遍历所有最短路径
*   统计最短路径条数
*   统计最短路径上，可以召集到的最大队伍数量