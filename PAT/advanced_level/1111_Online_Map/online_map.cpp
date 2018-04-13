#include <iostream>
#include <algorithm>
#include <vector>
#define MAXSIZE 504
#define INF 0x3fffffff
using namespace std;

int n, srcID, destID, minTime=INF, minInter=INF;
int GLen[MAXSIZE][MAXSIZE], GTime[MAXSIZE][MAXSIZE];
int distLen[MAXSIZE], distTime[MAXSIZE];
bool visLen[MAXSIZE] = {false}, visTime[MAXSIZE] = {false};
vector<int> pre0[MAXSIZE], pre1[MAXSIZE];
vector<int> tmpPath, path0, path1;

int init(){
	fill(GLen[0], GLen[0] + MAXSIZE*MAXSIZE, INF);
	fill(GTime[0], GTime[0] + MAXSIZE*MAXSIZE, INF);
	fill(distLen, distLen + MAXSIZE, INF);
	fill(distTime, distTime + MAXSIZE, INF);
}

void Dijkstra(int (& G)[MAXSIZE][MAXSIZE], int (& dist)[MAXSIZE], bool (& vis)[MAXSIZE], vector<int> (& pre)[MAXSIZE]){
	dist[srcID] = 0;
	while( vis[destID] == false ){
		int minDist=INF, midV=-1;
		for( int i = 0; i < n; ++i ){
			if( vis[i] == false && dist[i] < minDist ){
				minDist = dist[i];
				midV = i;
			}
		}
		if( midV == -1 )   return;
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

void fuck0(){
	int tmpTime = 0;
	for( int i = tmpPath.size() - 1; i > 0; --i ){
		int id = tmpPath[i];
		int nextID = tmpPath[i - 1];
		tmpTime += GTime[id][nextID];
	}
	if( tmpTime < minTime ){
		minTime = tmpTime;
		path0 = tmpPath;
	}
}

void fuck1(){
	if( tmpPath.size() < minInter ){
		minInter = tmpPath.size();
		path1 = tmpPath;
	}
}

void DFS(int v, bool flag, vector<int> (& pre)[MAXSIZE]){
	if( v == srcID ){
		tmpPath.push_back(v);
		if( flag == 0 ){
			fuck0();
		}else{
			fuck1();
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for( int i = 0; i < pre[v].size(); ++i ){
		DFS(pre[v][i], flag, pre);
	}
	tmpPath.pop_back();
}

void fkout(vector<int> & path){
	for( int i = path.size() - 2; i >= 0; --i ){
		cout<<" -> "<<path[i];
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(); // 初始化一定不能忘！！！
	int m, u, v, oneWay, l, t;
	cin>>n>>m;
	for(int i = 0; i < m; ++i ){
		cin>>u>>v>>oneWay;
		cin>>GLen[u][v]>>GTime[u][v];
		if( oneWay == 0 ){
			GLen[v][u] = GLen[u][v];
			GTime[v][u] = GTime[u][v];
		}
	}
	cin>>srcID>>destID;

	Dijkstra(GLen, distLen, visLen, pre0);
	Dijkstra(GTime, distTime, visTime, pre1);
	DFS(destID, 0, pre0);
	tmpPath.clear();
	DFS(destID, 1, pre1);
	
	if( path0 != path1 ){
		cout<<"Distance = "<<distLen[destID]<<": "<<path0[path0.size() - 1];
		fkout(path0);
		cout<<"Time = "<<distTime[destID]<<": "<<path1[path1.size() - 1];
		fkout(path1);
	}else{
		cout<<"Distance = "<<distLen[destID]<<"; Time = "<<distTime[destID]<<": "<<path0[path0.size() - 1];
		fkout(path0);
	}
	return 0;
}