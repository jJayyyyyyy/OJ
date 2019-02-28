*	[万妖穴](https://logn.me/problem/1011)

*	本题考察拓扑排序

*	如果存在多个入度为0的顶点，则先访问序号较小的顶点

	此时可以使用 set, 或者使用 priority_queue. 对于本题的测试用例，两者耗费时间差不多。不过用 set 更加简洁顺手

*	模版

	```cpp
	/*
	拓扑排序
	构建有向图时需要记录两个信息
	1. 结点 v 指向哪些结点, 由此建立邻接表 graph[v]
	2. 结点 v 的入度是多少, 得到 in_degree[v]
	   拓扑排序时, 每一次都是从 入度为零 的结点出发的
	
	*/
	#include <iostream>
	#include <vector>
	#include <set>
	#define MAXSIZE 1004
	using namespace std;

	vector<int> graph[MAXSIZE], ans_list;	// G是邻接表
	int in_degree[MAXSIZE] = {0};    	// 入度表
	int n, m, cnt=0;

	bool is_topo(){
		set<int> s;
		for( int v = 0; v < n; v++ )
		{
			if( in_degree[v] == 0 )
			{
				s.insert(v);        // 先访问序号较小的
			}
		}

		while( s.size() != 0 ){
			int now = *s.begin();
			ans_list.push_back(now);
			s.erase(now);

			for( int next : graph[now] )
			{
				in_degree[next]--;
				if( in_degree[next] == 0 )
				{
					s.insert(next);
				}
			}
			graph[now].clear();
			cnt++;
		}
		return cnt == n;
	}

	int main(){
		ios::sync_with_stdio(false);
		cin.tie(0);

		cin >> n >> m;
		int v1, v2;

		for( int i = 0; i < m; i++ )
		{
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			in_degree[v2]++;
		}

		if( is_topo() == true )
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
			cout << (n - cnt) << '\n';
		}

		return 0;
	}
	```
