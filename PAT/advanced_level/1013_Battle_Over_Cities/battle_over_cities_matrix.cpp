#include <iostream>
#include <algorithm>
#include <queue>
#define MAXSIZE 1004
using namespace std;

bool G[MAXSIZE][MAXSIZE] = {false};
bool vis[MAXSIZE] = {false};
int lostCity, n;

void DFS(int v){
	if( v != lostCity ){
		vis[v] = true;
		for( int i = 1; i <= n; ++i ){
			if( G[v][i] == true && vis[i] == false ){
				DFS(i);
			}
		}
	}
}

void BFS(int v){
	if( v != lostCity ){
		queue<int> q;
		q.push(v);
		vis[v] == true;
		while( q.size() ){
			v = q.front();
			q.pop();
			for( int i = 1; i <= n; ++i ){
				if( G[v][i] == true && i != lostCity && vis[i] == false ){
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, k, v1, v2;
	cin>>n>>m>>k;
	for( int i = 0; i < m; ++i ){
		cin>>v1>>v2;
		G[v1][v2] = G[v2][v1] = true;
	}
	for( int i = 0; i < k; ++i ){
		cin>>lostCity;
		fill(vis, vis + MAXSIZE, false);
		int block = 0;
		for( int v = 1; v <= n; ++v ){
			if( v != lostCity && vis[v] == false ){
				BFS(v);
				++block;
			}
		}
		cout<<block - 1<<'\n';
	}
	return 0;
}