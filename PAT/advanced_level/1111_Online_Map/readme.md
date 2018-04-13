*   思路：

    1. 建立两个图，一个是长度 GLen , 另一个是时间 GTime 
    2. 用 Dijkstra 找出起点到终点的最短路，preLen[] 保存了长度最小的路径上的结点信息， preTime[] 保存了时间最短的路径上的结点信息
    3. 只有一个标尺时，路径可能有多条，因此分别用 DFS 找出符合题意的最短的 pathLen ,  pathTime 
    4. 对比 pathLen 和 pathTime ，若不同，则xxx，若相同则ooo

*   Dijkstra一定记得`初始化`！！！（就因为这个浪费了一小时。。

*   没有vs的情况下，充分利用`dist[v]`进行调试

*   函数中，多维数组，作为引用参数，要写成这种形式 `int (& a)[MAXSIZE][MAXSIZE]`

    ```cpp
    // int a[MAXSIZE][MAXSIZE];
    
    void foo(int (& a)[MAXSIZE][MAXSIZE]){
        
    }
    ```

    引用多维vector也类似
    
    ```cpp
    // vector<int> v[MAXSIZE];
    
    void foo(vector<int> (& v)[MAXSIZE]){
        
    }
    ```

*   TODO

    更新所有最短路径的题目，使用统一模板
    
    1003, 1018, 1030, 1072, 1087, 1111