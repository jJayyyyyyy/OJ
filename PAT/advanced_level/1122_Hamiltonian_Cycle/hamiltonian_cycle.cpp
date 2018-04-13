#include <iostream>
#include <vector>
#define MAXSIZE 204
using namespace std;

bool G[MAXSIZE][MAXSIZE] = {false};

bool isHamilton(int n, int len, vector<int> & queryList){
	if( len != n + 1 ){
		return false;
	}else if( queryList[0] != queryList[len-1] ){
		return false;
	}else{
		for( int i = 1; i < len - 1; i++ ){
			if( queryList[i] == queryList[0] ){
				return false;
			}
		}
		return true;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, v1, v2;
	cin>>n>>m;
	for( int i = 0; i < m; i ++ ){
		cin>>v1>>v2;
		G[v1][v2] = G[v2][v1] = true;
	}

	int q, len, v;
	cin>>q;
	for( int i = 0; i < q; i++ ){
		cin>>len;
		vector<int> queryList;
		for( int j = 0; j < len; j++ ){
			cin>>v;
			queryList.push_back(v);
		}
		if( isHamilton(n, len, queryList) ){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}


	return 0;
}