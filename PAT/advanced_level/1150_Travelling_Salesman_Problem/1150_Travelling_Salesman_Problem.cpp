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
#define MAXSIZE 201
#define INF 0x3fffffff
using namespace std;

unsigned char G[MAXSIZE][MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;
	for( int i = 0; i < m; i++ ){
		int v1, v2, d;
		cin>>v1>>v2>>d;
		G[v1][v2] = G[v2][v1] = d;
	}

	int k;
	int minIx = INF, minDist = INF;
	cin>>k;
	for( int i = 1; i <= k; i++ ){
		int q;
		cin>>q;

		int v1, v2, first=0, last=0;
		int dist = 0;
		bool noPath = false;

		cin>>v1;
		first = v1;
		unordered_set<int> s;
		s.insert(v1);
		for( int j = 1; j < q; j++ ){
			cin>>v2;
			last = v2;
			s.insert(v2);
			if( G[v1][v2] != 0 ){
				dist += G[v1][v2];
			}else{
				noPath = true;
			}
			v1 = v2;
		}
		if( noPath == true ){
			cout<<"Path "<<i<<": NA (Not a TS cycle)\n";
		}else if( s.size() == n ){
			if( q == n ){
				cout<<"Path "<<i<<": "<<dist<<" (Not a TS cycle)\n";
			}else if( first == last ){
				if( q == n + 1 ){
					cout<<"Path "<<i<<": "<<dist<<" (TS simple cycle)\n";
				}else if( q > n + 1 ){
					cout<<"Path "<<i<<": "<<dist<<" (TS cycle)\n";
				}
				if( dist < minDist ){
					minDist = dist;
					minIx = i;
				}
			}else{
				cout<<"Path "<<i<<": "<<dist<<" (Not a TS cycle)\n";
			}
		}else{
			cout<<"Path "<<i<<": "<<dist<<" (Not a TS cycle)\n";
		}
	}
	cout<<"Shortest Dist("<<minIx<<") = "<<minDist<<'\n';

	return 0;
}
