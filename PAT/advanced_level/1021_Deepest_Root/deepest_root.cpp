#include <iostream>
#include <vector>
#include <algorithm>
#define MAXSIZE 10004
using namespace std;

bool vis[MAXSIZE] = {false};
int maxHeight = 0;
int father[MAXSIZE];
vector<int> G[MAXSIZE], tmp, ans;

void init(){
	for( int i = 0; i < MAXSIZE; ++i ){
		father[i] = i;
	}
}

int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if( faA < faB ){
		father[faB] = faA;
	}else{
		father[faA] = faB;
	}
}

int cntBlock(int n){
	int block = 0;
	for( int i = 1; i <= n; ++i ){
		int root = findFather(i);
		vis[root] = true;
	}
	for( int i = 1; i <= n; ++i ){
		if( vis[i] == true ){
			++block;
		}
	}
	return block;
}

void DFS(int v, int height, int pre){
	if( height > maxHeight ){
		tmp.clear();
		tmp.push_back(v);
		maxHeight = height;
	}else if( height == maxHeight ){
		tmp.push_back(v);
	}

	for( const auto & nextV : G[v] ){
		if( nextV != pre ){
			DFS(nextV, height + 1, v);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n;
	cin>>n;
	if( n == 1 ){
		cout<<"1\n";
	}else{
		for( int i = 1; i < n; ++i ){
			int v1, v2;
			cin>>v1>>v2;
			G[v1].push_back(v2);
			G[v2].push_back(v1);
			Union(v1, v2);
		}
		int block = cntBlock(n);
		if( block != 1 ){
			cout<<"Error: "<<block<<" components\n";
		}else{
			DFS(1, 1, 0);
			ans = tmp;
			DFS(ans[0], 1, 0);
			ans.insert( ans.end(), tmp.begin(), tmp.end() );
			sort(ans.begin(), ans.end());
			cout<<ans[0]<<'\n';
			for( int i = 1; i < ans.size(); ++i ){
				if( ans[i] != ans[i - 1] ){
					cout<<ans[i]<<'\n';
				}
			}
		}
	}
	return 0;
}