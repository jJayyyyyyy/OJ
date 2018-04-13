#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#define INF 0x3fffffff
#define MAXSIZE 204
using namespace std;

// int G[MAXSIZE][MAXSIZE];
vector<int> G[MAXSIZE];
bool vis[MAXSIZE] = {false};

bool isInSet[MAXSIZE] = {false};

void init(){
	fill( vis, vis + MAXSIZE, false );
}

void init2(){
	fill( isInSet, isInSet + MAXSIZE, false);
}

void BFS(int v){
	init();
	vis[v] = true;
	for( int i = 0; i < G[v].size(); i++ ){
		int next = G[v][i];
		vis[next] = true;
	}
}

bool checkSet(vector<int> & nodeList){
	for( int i = 0; i < nodeList.size(); i++ ){
		int v = nodeList[i];
		if( vis[v] == false ){
			return false;
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
		G[v2].push_back(v1);
	}

	int cntQ, k;
	cin>>cntQ;
	for( int i = 0; i < cntQ; i++ ){
		cin>>k;
		vector<int> nodeList;
		init2();
		for( int j = 0; j < k; j++ ){
			cin>>v1;
			nodeList.push_back(v1);
			isInSet[v1] = true;
		}

		bool flag = true;
		for( int k = 0; k < nodeList.size(); k++ ){
			int v = nodeList[k];
			BFS(v);
			if( checkSet(nodeList) == false ){
				flag = false;
				break;
			}
		}

		if( flag == false ){
			cout<<"Not a Clique\n";
		}else{
			bool flag2 = false;
			for( int k = 1; k <= n; k++ ){
				if( isInSet[k] == false ){
					nodeList.push_back(k);
					BFS( k );
					if( checkSet(nodeList) == true ){
						cout<<"Not Maximal\n";
						flag2 = true;
						break;
					}else{
						nodeList.pop_back();
					}
				}
			}
			if( flag2 == false ){
				cout<<"Yes\n";
			}
		}
	}

	return 0;
}

