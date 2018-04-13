#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAXSIZEM 10004
#define MAXSIZEN 1004
using namespace std;

int inDegree[MAXSIZEN] = {0}, tmpInDegree[MAXSIZEN];
int queryList[MAXSIZEN];
vector<int> G[MAXSIZEM], ansList;

void init(int n){
	for( int i = 1; i <= n; i++ ){
		tmpInDegree[i] = inDegree[i];
	}
}

bool isTopo(int n){
	init(n);

	for( int i = 0; i < n; i++ ){
		int now = queryList[i];
		if( tmpInDegree[now] != 0 ){
			return false;
		}
		for( auto next : G[now] ){
			tmpInDegree[next]--;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;

	int v1, v2;
	for( int i = 0; i < m; i++ ){
		cin>>v1>>v2;
		G[v1].push_back(v2);
		inDegree[v2]++;
	}

	int cntQuery;
	cin>>cntQuery;

	for( int i = 0; i < cntQuery; i++ ){
		for( int i = 0; i < n; i++ ){
			cin>>queryList[i];
		}

		if( isTopo(n) == false ){
			ansList.push_back(i);
		}
	}

	for( int i = 0; i < ansList.size(); i++ ){
		if( i != 0 ){
			cout<<' ';
		}
		cout<<ansList[i];
	}
	cout<<'\n';

	return 0;
}

