#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define INF 0x3fffff00
#define MAXSIZE 504
using namespace std;

int Cmax, n, srcID, destID, minSend=INF, minTakeBack=INF;
int Bike[MAXSIZE], dist[MAXSIZE], G[MAXSIZE][MAXSIZE];
bool vis[MAXSIZE];
vector<int> pre[MAXSIZE], tmpPath, path;

void init(){
	fill( G[0], G[0] + MAXSIZE * MAXSIZE, INF );
	fill( dist, dist + MAXSIZE, INF );
	fill( vis, vis + MAXSIZE, false);
}

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

void calc(){
	int tmpSend = 0, tmpTakeBack = 0;
	for( int i = tmpPath.size() - 1; i >= 0; --i ){
		int v = tmpPath[i];
		if( Bike[v] > 0 ){
			tmpTakeBack += Bike[v];
		}else{
			if( tmpTakeBack > abs(Bike[v]) ){
				tmpTakeBack -= abs(Bike[v]);
			}else{
				tmpSend += abs(Bike[v]) - tmpTakeBack;
				tmpTakeBack = 0;
			}
		}
	}

	if( tmpSend < minSend ){
		minSend = tmpSend;
		minTakeBack = tmpTakeBack;
		path = tmpPath;
	}else if( tmpSend == minSend ){
		if( tmpTakeBack < minTakeBack ){
			minTakeBack = tmpTakeBack;
			path = tmpPath;
		}
	}
}

void DFS(int v){
	if( v == srcID ){
		tmpPath.push_back(v);
		calc();
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
	int m, i, v1, v2, len;
	init();
	srcID = 0;
	cin>>Cmax>>n>>destID>>m;
	for( i = 1; i <= n; ++i ){
		cin>>Bike[i];
		Bike[i] -= Cmax / 2;
	}

	for( i = 0; i < m; ++i ){
		cin>>v1>>v2>>len;
		G[v1][v2] = G[v2][v1] = len;
	}
	Dijkstra();
	DFS(destID);

	cout<<minSend<<" ";
	for( i = path.size() - 1; i > 0; --i ){
		cout<<path[i]<<"->";
	}
	cout<<path[i]<<" "<<minTakeBack<<"\n";
	return 0;
}