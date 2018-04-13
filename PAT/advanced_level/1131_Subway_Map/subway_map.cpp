#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>
#define MAXSIZE 10004
#define INF 0x3fff0000
using namespace std;

int n, srcID, destID, minTrans;
int dist[MAXSIZE];
bool vis[MAXSIZE];
vector<int> G[MAXSIZE];
int line[MAXSIZE][MAXSIZE];
vector<int> pre[MAXSIZE], tmpPath, path, path2;
set<int> station;

void init(){
	minTrans = INF;
	fill(vis, vis + MAXSIZE, false);
	fill(dist, dist + MAXSIZE, INF);
	path.clear();
	tmpPath.clear();
	for( size_t i = 0; i < MAXSIZE; ++i ){
		pre[i].clear();
	}
}

void Dijkstra(){
	dist[srcID] = 0;
	while( vis[destID] == false ){
		int minDist=INF, midID = -1;
		for(set<int>::iterator it = station.begin(); it != station.end(); ++it ){
			int nextV = *it;
			if( vis[nextV] == false && dist[nextV] < minDist ){
				minDist = dist[nextV];
				midID = nextV;
			}
		}
		if( midID == -1 )   return;
		vis[midID] = true;

		for( int i = 0; i < G[midID].size(); ++i ){
			int nextV = G[midID][i];
			if( vis[nextV] == false ){
				if( dist[midID] + 1 < dist[nextV] ){
					dist[nextV] = dist[midID] + 1;
					pre[nextV].clear();
					pre[nextV].push_back(midID);
				}else if( dist[midID] + 1 == dist[nextV] ){
					pre[nextV].push_back(midID);
				}
			}
		}
	}
}

void calCost(){
	int tmpTrans = -1, lineID = 0;
	for( int i = tmpPath.size(); i > 0; --i ){
		int v = tmpPath[i];
		int nextV = tmpPath[i - 1];
		if( line[v][nextV] != lineID ){
			++tmpTrans;
		}
		lineID = line[v][nextV];
	}
	if( tmpTrans < minTrans ){
		minTrans = tmpTrans;
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
	for(int i = 0; i < pre[v].size(); ++i ){
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}

void getRoute(){
	reverse(path.begin(), path.end());
	int v1 = path[0], v2 = path[1];
	int i = 0, len = path.size();
	int lineID = line[v1][v2];

	cout<<"Take Line#"<<lineID<<" from ";
	cout<<setfill('0')<<setw(4)<<v1<<" to ";
	for( int j = 0; j < minTrans; ++j ){
		while( i < len - 1 ){
			if( lineID != line[v1][v2] ){
				break;
			}
			v1 = path[i];
			v2 = path[i + 1];
			++i;
		}
		cout<<setfill('0')<<setw(4)<<v1<<".\n";
		lineID = line[v1][v2];
		cout<<"Take Line#"<<lineID<<" from ";
		cout<<setfill('0')<<setw(4)<<v1<<" to ";
	}
	v2 = path[len - 1];
	cout<<setfill('0')<<setw(4)<<v2<<".\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, v1, v2, i, j, k;
	cin>>n;
	for( i = 1; i <= n; ++i ){
		cin>>m>>v1;
		for( j = 1; j < m; ++j ){
			cin>>v2;
			G[v1].push_back(v2);
			G[v2].push_back(v1);
			line[v1][v2] = line[v2][v1] = i;
			station.insert(v1);
			station.insert(v2);
			v1 = v2;
		}
	}
	n = station.size();
	cin>>k;

	for( i = 0; i < k; ++i ){
		init();
		cin>>srcID>>destID;
		Dijkstra();
		DFS(destID);
		cout<<dist[destID]<<'\n';
		getRoute();
	}
	return 0;
}
