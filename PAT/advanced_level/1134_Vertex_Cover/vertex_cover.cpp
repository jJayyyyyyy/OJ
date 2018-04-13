#include <iostream>
#include <algorithm>
#include <vector>
#define MAXSIZE 10004
using namespace std;

vector<int> edgeOfV[MAXSIZE];
bool visE[MAXSIZE];

void init(){
	fill(visE, visE + MAXSIZE, false);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin>>n>>m;
	
	int v1, v2;
	for( int eID = 0; eID < m; ++eID ){
		cin>>v1>>v2;
		
		// 给每条边编号, [0, m-1]
		edgeOfV[v1].push_back(eID);	// 保存与节点v1相连的边
		edgeOfV[v2].push_back(eID);
	}
	
	int cntQuery, k, v3;
	cin>>cntQuery;
	for( int q = 0; q < cntQuery; q++ ){
		// 初始化，使每条边的状态为未访问
		init();
		
		cin>>k;
		for( int i = 0; i < k; i++ ){
			cin>>v3;
			for( auto eID : edgeOfV[v3] ){
				// 标记与顶点vid相连的每条边eid
				visE[eID] = true;
			}
		}
		
		bool isCover = true;
		for( int eID = 0; eID < m; eID++ ){
			// 如果还存在没有没有被访问过的边，说明不能cover
			if( visE[eID] == false ){
				isCover = false;
				break;
			}
		}
		if( isCover == true ){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}