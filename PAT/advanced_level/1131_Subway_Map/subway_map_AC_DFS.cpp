#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#define MAXSIZE 10004
#define INF 0x3fff0000
using namespace std;

vector<int> G[MAXSIZE];
int line[MAXSIZE][MAXSIZE] = {0};
bool vis[MAXSIZE] = {false};
vector<int> path, tmpPath;
int srcID, destID, minDist, minTrans;

int cntTrans(){
	int cnt = -1, lineID = 0;
	for( int i = 1; i < tmpPath.size(); i++) {
		int v1 = tmpPath[i - 1], v2 = tmpPath[i];
		if( line[v1][v2] != lineID ){
			cnt++;
		}
		lineID = line[v1][v2];
	}
	return cnt;
}

void DFS(int v, int tmpDist){
	if( v == destID ){
		if( tmpDist < minDist || (tmpDist == minDist && cntTrans() < minTrans) ){
			minDist = tmpDist;
			minTrans = cntTrans();
			path = tmpPath;
		}
		return;
	}

	for (int i = 0; i < G[v].size(); i++) {
		int nextV = G[v][i];
		if( vis[nextV] == false && tmpDist <= minDist ){
			vis[nextV] = true;
			tmpPath.push_back(nextV);
			DFS(nextV, tmpDist + 1);
			vis[nextV] = false;
			tmpPath.pop_back();
		}
	}
}

void init(){
	minDist = INF, minTrans = INF;
}

void getRoute(){
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, v1, v2;
	cin>>n;

	for( int i = 1; i <= n; ++i){
		cin>>m>>v1;
		for (int j = 1; j < m; ++j) {
			cin>>v2;
			G[v1].push_back(v2);
			G[v2].push_back(v1);
			line[v1][v2] = line[v2][v1] = i;
			v1 = v2;
		}
	}

	cin>>k;
	for( int i = 0; i < k; ++i){
		cin>>srcID>>destID;
		init();
		tmpPath.push_back(srcID);
		vis[srcID] = true;
		DFS(srcID, 0);
		vis[srcID] = false;
		tmpPath.pop_back();
		cout<<minDist<<'\n';
		getRoute();
	}
	return 0;
}