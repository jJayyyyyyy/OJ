#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > edge_of_vertex;
vector<bool> visited_edge;

inline void check(int m)
{
	bool ans = true;
	for( int edge : visited_edge )
	{
		// 如果还存在没有没有被访问过的边，说明不能 cover
		if( edge == false )
		{
			ans = false;
			break;
		}
	}
	if( ans == true )
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	edge_of_vertex.resize(n);
	visited_edge.resize(m);

	// vertex_id
	int v1, v2;
	// 给每条边编号, eid = [0, m-1]
	for( int eid = 0; eid < m; eid++ )
	{
		cin >> v1 >> v2;
		// 保存与顶点 v1 相连的边
		edge_of_vertex[v1].push_back( eid );
		edge_of_vertex[v2].push_back( eid );
	}

	int k;
	cin >> k;
	for( int query = 0; query < k; query++ )
	{
		// 初始化, 使每条边的状态为未访问
		fill(visited_edge.begin(), visited_edge.end(), false);
		int ttl;
		cin >> ttl;
		for( int i = 0; i < ttl; i++ )
		{
			int v;
			cin >> v;
			for( int eid : edge_of_vertex[v] )
			{
				// 标记与顶点 v 相连的每条边 eid
				visited_edge[eid] = true;
			}
		}

		check(m);
	}

	return 0;
}
