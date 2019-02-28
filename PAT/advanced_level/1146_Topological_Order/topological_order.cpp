/*
拓扑排序
构建有向图时需要记录两个信息
1. 结点 v 指向哪些结点, 由此建立邻接表 graph[v]
2. 结点 v 的入度是多少, 得到 in_degree[v]
   拓扑排序时, 每一次都是从 入度为零 的结点出发的

*/
#include <iostream>
#include <vector>
#define MAXSIZE 1004
using namespace std;

int in_degree[MAXSIZE] = {0}, in_degree_backup[MAXSIZE];
int query_list[MAXSIZE];
vector<int> graph[MAXSIZE];

void init(int n)
{
	for( int i = 1; i <= n; i++ )
	{
		in_degree_backup[i] = in_degree[i];
	}
}

bool is_topo(int n){
	// 由于会进行多次查询, 所以每一次判断之前, 需要初始化结点的入度信息
	init(n);

	for( int q = 0; q < n; q++ )
	{
		int now = query_list[q];
		if( in_degree_backup[now] != 0 )
		{
			return false;
		}
		for( auto next : graph[now] )
		{
			in_degree_backup[next]--;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int v1, v2;
	for( int i = 0; i < m; i++ ){
		cin >> v1 >> v2;
		graph[v1].push_back(v2);	// 从 v 出发可以到哪些结点
		in_degree[v2]++;        	// 有多少个结点可以到 v
	}

	int ttl_query;
	bool is_first = true;
	cin >> ttl_query;
	for( int i = 0; i < ttl_query; i++ )
	{
		for( int q = 0; q < n; q++ )
		{
			cin >> query_list[q];
		}
		if( is_topo(n) == false )
		{
			if( is_first == true )
			{
				cout << i;
				is_first = false;
			}
			else
			{
				cout << ' ' << i;
			}
		}
	}
	cout << '\n';
	return 0;
}


/*

6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6


*/