*	主要考点：图的遍历，计算连通块

*	晴神宝典用的是邻接链表 + DFS

*	补充了BFS遍历的解法（参考1126 Eulerian Path）

*	新增了邻接矩阵的实现 (DFS + BFS)

*	晴神在本题的解法中增加了并查集的实现，不过个人认为，

    由于每次查询都要去掉一个顶点，也就是结构会变，并且重新findFather()和Union()
        
    无法在输入时完成就确定区块结构，无法重用
        
    这样的题目，不要用并查集（较复杂，还要写路径压缩，否则会超时），直接用图的DFS, BFS模板就好了

    请参考[并查集的readme](https://github.com/jJayyyyyyy/cs/tree/master/data%20structure/union_find_set)