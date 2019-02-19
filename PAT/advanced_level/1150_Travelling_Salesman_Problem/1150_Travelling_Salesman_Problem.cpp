/*
1. 首先建立无向图 G[v1][v2], 并保存权值(dist)
2. 读取一组路径, 如果存在 G[v1][v2] == 0 的情况, 说明 v1->v2不通, 这条路径非法 NA (Not a TS cycle)
3. 将路径存入 hash 表 unordered_set<int> s, 用于去重，如果 s.size() < n, 说明没有遍历所有结点
4. 如果 s.size() == n, 再判断起点和终点是否相同, 若起点终点不相同, 则 Not a TS cycle
5. 如果起点终点相同, 则判断有没有重复访问的结点, 无 -> simple
6. 最后, 本题是找出 the one that is the closest to the solution of a travelling salesman problem.
   只要路径短，重不重复没关系, 如样例中的 path 4 就有重复访问结点的情况, 但是总路径更短, 这也是可行的
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define MAXSIZE 201
#define INF 0x3fffffff
using namespace std;

unsigned char graph[MAXSIZE][MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int v1, v2, dist;
	for( int i = 0; i < m; i++ )
	{
		cin >> v1 >> v2 >> dist;
		graph[v1][v2] = graph[v2][v1] = dist;
	}

	int ttl_path;
	int min_path_ix = INF, min_dist = INF;
	cin >> ttl_path;
	for( int path_ix = 1; path_ix <= ttl_path; path_ix++ )
	{
		int ttl_vertex;
		cin >> ttl_vertex;

		int first=0, last=0;
		int dist = 0;
		bool no_path = false;

		cin >> v1;
		first = v1;
		unordered_set<int> s;
		s.insert(v1);
		for( int j = 1; j < ttl_vertex; j++ )
		{
			cin >> v2;
			last = v2;
			s.insert(v2);
			if( graph[v1][v2] != 0 )
			{
				dist += graph[v1][v2];
			}
			else
			{
				no_path = true;
			}
			v1 = v2;
		}

		if( no_path == true )
		{
			cout<<"Path "<<path_ix<<": NA (Not a TS cycle)\n";
		}

		else if( s.size() == n )
		{
			if( ttl_vertex == n )
			{
				// ttl_vertex == n + 1 才能成为一个圈
				cout<<"Path "<<path_ix<<": "<<dist<<" (Not a TS cycle)\n";
			}
			else if( first == last )
			{
				// 起点和终点一样才能成为一个圈
				if( ttl_vertex == n + 1 )
				{
					cout << "Path " << path_ix << ": " << dist << " (TS simple cycle)\n";
				}
				else if( ttl_vertex > n + 1 )
				{
					cout << "Path " << path_ix << ": " << dist << " (TS cycle)\n";
				}
				if( dist < min_dist )
				{
					min_dist = dist;
					min_path_ix = path_ix;
				}
			}
			else
			{
				cout << "Path " << path_ix << ": " << dist << " (Not a TS cycle)\n";
			}
		}
		else
		{
			cout<<"Path "<<path_ix<<": "<<dist<<" (Not a TS cycle)\n";
		}
	}
	cout<<"Shortest Dist("<<min_path_ix<<") = "<<min_dist<<'\n';

	return 0;
}
