#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAXSIZE 204
#define INF 0x3fffff00
using namespace std;

int cntPath = 0, maxHappy = 0, srcID, destID, n;
double maxAvg = 0.0;
bool vis[MAXSIZE];
int happyList[MAXSIZE], dist[MAXSIZE], G[MAXSIZE][MAXSIZE];
map<string, int> city2Index;
string index2City[MAXSIZE];
vector<int> tmpPath, path, pre[MAXSIZE];

void init(){
	fill( vis, vis + MAXSIZE, false );
	fill( dist, dist + MAXSIZE, INF );
	fill( G[0], G[0] + MAXSIZE*MAXSIZE, INF);
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

void calcHappy(){
	int tmpHappy = 0, cntCity = tmpPath.size() - 1;
	for( int i = cntCity; i >= 0; --i ){
		int v = tmpPath[i];
		tmpHappy += happyList[v];
	}
	double tmpAvg = 1.0 * tmpHappy / cntCity;

	if( tmpHappy > maxHappy ){
		maxHappy = tmpHappy;
		maxAvg = tmpAvg;
		path = tmpPath;
	}else if( tmpHappy == maxHappy ){
		if( tmpAvg > maxAvg){
			maxAvg = tmpAvg;
			path = tmpPath;
		}
	}
}

void DFS(int v){
	if( v == srcID ){
		tmpPath.push_back(v);
		++cntPath;
		calcHappy();
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for( int i = 0; i < pre[v].size(); ++i ){
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}

int main(){
	string sCity, s1, s2;
	int m, i, v1, v2, len, happy;
	cin>>n>>m>>sCity;
	city2Index[sCity] = 0;
	index2City[0] = sCity;
	happyList[0] = 0;
	
	for( i = 1; i < n; ++i ){
		cin>>sCity>>happy;
		city2Index[sCity] = i;
		index2City[i] = sCity;
		happyList[i] = happy;
	}
	
	init();
	srcID = 0;						// 记得初始化
	destID = city2Index["ROM"];		// 记得初始化
	
	for( i = 0; i < m; ++i ){
		cin>>s1>>s2>>len;
		v1 = city2Index[s1];
		v2 = city2Index[s2];
		G[v1][v2] = G[v2][v1] = len;
	}
	Dijkstra();
	DFS(destID);
	
	cout<<cntPath<<' '<<dist[destID]<<' '<<maxHappy<<' '<<int(maxAvg)<<'\n';
	for( i=path.size() - 1; i>0; --i ){
		cout<<index2City[ path[i] ]<<"->";
	}
	cout<<index2City[ path[0] ]<<'\n';
	return 0;
}