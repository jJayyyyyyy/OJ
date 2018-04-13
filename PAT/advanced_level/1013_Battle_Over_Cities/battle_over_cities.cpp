#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXSIZE 1004
using namespace std;

vector<int> G[MAXSIZE];
bool vis[MAXSIZE] = {false};
int lostCity;

void DFS(int v){
	if( v != lostCity ){
		vis[v] = true;
		// for( int i = 0; i < G[v].size(); ++i ){
		//	int nextV = G[v][i];
		for( const auto & nextV : G[v] ){
			if( vis[nextV] == false ){
				DFS(nextV);
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
			// for( int i = 0; i < G[v].size(); ++i ){
			//	int nextV = G[v][i];
			for( const auto & nextV : G[v] ){
				if( nextV != lostCity && vis[nextV] == false ){
					q.push(nextV);
					vis[nextV] = true;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, v1, v2;
	cin>>n>>m>>k;
	for( int i = 0; i < m; ++i ){
		cin>>v1>>v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	for( int i = 0; i < k; ++i ){
		cin>>lostCity;
		fill(vis, vis + MAXSIZE, false);
		int block = 0;
		for( int v = 1; v <= n; ++v ){
			if( v != lostCity && vis[v] == false ){
				DFS(v);
				// BFS(v);
				++block;
			}
		}
		cout<<block - 1<<'\n';
	}
	return 0;
}