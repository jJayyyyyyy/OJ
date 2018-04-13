*   若使用邻接矩阵，顶点i的度，可以通过遍历G[i][j]得到，j 范围是[1, n]

	三种情况
	
	*   所有顶点的度都是偶数    ——  Eulerian
	*   只有2个顶点的度是奇数   ——  Semi-Eulerian
	*   其他                    ——  Non-Eulerian
	
*   以上方法，仍有一个case无法通过，猜测是给定的所有顶点形成了多个（互不连通的）图，所以需要先检查图的连通性。

*	原解法基于BFS，本题与1013 Battle Over Cities类似

*	20170818增加DFS解法。

	推荐使用 `邻接链表` + `DFS` 的形式，代码简洁好记。

	```cpp
	/* DFS
	** param @v --- 节点ID, 也可写成vid
	*/
	void DFS(int v){
		vis[v] = true;
		for( int i = 0; i < G[v].size(); i++ ){
			int nextV = G[v][i];
			if( vis[nextV] == false ){
				DFS(nextV);
			}
		}
	}
	
	/* 只看是否连同
	** param @n --- 总的节点数, [1, n]
	*/
	bool isConn(int n){
		DFS(1);
		for( int i = 1; i <= n; i++ ){
			if( vis[i] == false ){
				return false;
			}
		}
		return true;
	}
	```
