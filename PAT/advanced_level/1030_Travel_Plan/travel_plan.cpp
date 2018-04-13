#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3fffff00
#define MAXSIZE 504
using namespace std;

int n, srcID, destID, minCost = INF;
int dist[MAXSIZE], G[MAXSIZE][MAXSIZE], GCost[MAXSIZE][MAXSIZE];
bool vis[MAXSIZE];
vector<int> pre[MAXSIZE], tmpPath, path;

void init(){
	fill( G[0], G[0] + MAXSIZE * MAXSIZE, INF );
	fill( GCost[0], GCost[0] + MAXSIZE * MAXSIZE, INF );
	fill( dist, dist + MAXSIZE, INF );
	fill( vis, vis + MAXSIZE, false);
}

void Dijkstra(){
	dist[srcID] = 0;
	while( vis[destID] == false ){
		int minDist = INF, midV = -1;
		for( int i = 0; i < n; ++i ){
			if( vis[i] == false && dist[i] < minDist ){
				minDist = dist[i];
				midV = i;
			}
		}
		if( midV == -1 )	return;
		vis[midV] = true;

		for( int i = 0; i < n; ++i ){
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

void calCost(){
	int tmpCost = 0;
	for( int i = tmpPath.size() - 1; i > 0; --i ){
		int v = tmpPath[i];
		int nextV = tmpPath[i - 1];
		tmpCost += GCost[v][nextV];
	}
	if( tmpCost < minCost ){
		minCost = tmpCost;
		path = tmpPath;
	}
}

void DFS(int v){
	if( v == srcID ){
		tmpPath.push_back(v);
		calCost();
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for( int i = 0; i < pre[v].size(); ++i ){
		DFS( pre[v][i] );
	}
	tmpPath.pop_back();
}

int main(){
	int m, i, v1, v2, len, cost;
	init();
	cin>>n>>m>>srcID>>destID;	
	for( i = 0; i < m; ++i ){
		cin>>v1>>v2>>len>>cost;
		G[v1][v2] = G[v2][v1] = len;
		GCost[v1][v2] = GCost[v2][v1] = cost;
	}
	Dijkstra();
	DFS(destID);
	for( i = path.size() - 1; i >= 0; --i ){
		cout<<path[i]<<' ';
	}
	cout<<dist[destID]<<' '<<minCost<<'\n';
	return 0;
}