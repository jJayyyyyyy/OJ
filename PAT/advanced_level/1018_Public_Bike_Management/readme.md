*   Dijkstra + DFS, 背模板, 会应用

*	初始化全部放在init()

*	首先 Dijkstra 模板 ---> 算出并保存所有最短路径

	```cpp
	void Dijkstra(){
		dist[srcID] = 0;
		while( vis[destID] == false ){
			int minDist = INF, midV = -1;
			for( int i = 0; i <= n; ++i ){
				if( vis[i] == false && dist[i] < minDist ){
					minDist = dist[i];
					midV = i;
				}
			}
			if( midV == -1 )	return;
			vis[midV] = true;
	
			for( int i = 0; i <= n; ++i ){
				if( vis[i] == false && G[midV][i] != INF ){
					if( dist[midV] + G[midV][i] < dist[i] ){
						dist[i] = dist[midV] + G[midV][i];
						pre[i].clear();
						pre[i].push_back(midV);
					}else if( dist[midV] + G[midV][i] == dist[i] ){
						pre[i].push_back(midV);
					}
				}
			}
		}
	}
	```

*	由于最短路径可能不唯一，接着使用 DFS 模板 ---> 遍历这些最短路径，得到满足第2、第3、标尺的最优解

	```cpp
	void DFS(int v){
		if( v == srcID ){
			tmpPath.push_back(v);
			calc();	// 详见cpp文件，不同题目，calc有所区别
			tmpPath.pop_back();
			return;
		}
	
		tmpPath.push_back(v);
		for( int i = 0; i < pre[v].size(); ++i ){
			DFS( pre[v][i] );
		}
		tmpPath.pop_back();
	}
	```

*   同类题目
    
    *   1003, 1018, 1030, 1072, 1087, 1111

