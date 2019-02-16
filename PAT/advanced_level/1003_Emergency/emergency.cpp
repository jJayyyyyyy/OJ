/*
求 src 到 dest 的最短路径, 如果最短路径不唯一, 则求其中路径结点权值之和最大的路径
同类题目 1003, 1018, 1030, 1072, 1087, 1111
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define MAXSIZE 504
#define INF 0x3fffffff
using namespace std;

int n, m, src, dest;
int max_cost=0;
int cnt_path=0;
bool vis[MAXSIZE] = {false};
int graph[MAXSIZE][MAXSIZE];
int dist[MAXSIZE];	// dist[ix] == dist from src to ix
int team[MAXSIZE];
vector<int> pre_list[MAXSIZE], tmp_path, ans_path;

void init_graph_and_dist()
{
	fill(dist, dist + MAXSIZE, INF);
	fill(graph[0], graph[0] + MAXSIZE * MAXSIZE, INF);
}

void Dijkstra()
{
	dist[src] = 0;
	while( vis[dest] == false )
	{
		int mid = -1;
		int minDist = INF;
		for( int i = 0; i < n; i++ )
		{
			if( vis[i] == false && dist[i] < minDist )
			{
				mid = i;
				minDist = dist[i];
			}
		}

		if( mid == -1 )
		{
			return;	// dest 无法到达
		}

		vis[mid] = true;
		for( int i = 0; i < n; i++ )
		{
			if( vis[i] == false && graph[mid][i] != INF )
			{
				if( dist[mid] + graph[mid][i] < dist[i] )
				{
					dist[i] = dist[mid] + graph[mid][i];
					pre_list[i].clear();
					pre_list[i].push_back(mid);
				}
				else if( dist[mid] + graph[mid][i] == dist[i] )
				{
					pre_list[i].push_back(mid);
				}
			}
		}
	}
}

void calc_cost()
{
	int tmp_cost = 0;
	for( int i = tmp_path.size() - 1; i >= 0; i-- )
	{
		int now = tmp_path[i];
		// int next = tmp_path[i-1];
		tmp_cost += team[now];
	}
	if( tmp_cost > max_cost )
	{
		max_cost = tmp_cost;
		ans_path = tmp_path;
	}
}

void DFS(int now)
{
	if( now == src )
	{
		tmp_path.push_back(now);
		calc_cost();
		tmp_path.pop_back();
		cnt_path++;
		return;
	}

	tmp_path.push_back(now);
	for( int pre : pre_list[now] )
	{
		DFS(pre);
	}
	tmp_path.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> src >> dest;
	for( int i = 0; i < n; i++ )
	{
		cin >> team[i];
	}

	init_graph_and_dist();
	int v1, v2, weight;
	for( int i = 0; i < m; i++ )
	{
		cin >> v1 >> v2 >> weight;
		graph[v1][v2] = graph[v2][v1] = weight;
	}

	Dijkstra();
	DFS(dest);
	cout << cnt_path << ' ' << max_cost << '\n';

	return 0;
}