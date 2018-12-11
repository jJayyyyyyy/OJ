/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
画图观察，总结规律

1. 首先遍历图, 检查是否存在 graph[v1][v2], 使得 color[v1] == color[v2]
   如果存在, 则返回 false, 即这个图不是 k-coloring
2. 如果返回的是 true, 再遍历所有结点, 将其 color 输入一个 set<int> s
   最后得到的 s.size() 就是 k-coloring 中的 k
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool valid;
vector< vector<int> > graph;
vector<int> color;

void bfs(int n){
	for( int i = 0; i < n; i++ ){
		for( int j : graph[i] ){
			if( color[i] == color[j] ){
				valid = false;
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, v1, v2;
	cin>>n>>m;
	graph.resize(n);
	color.resize(n);
	for( int i = 0; i < m; i++ ){
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		// 下面这行注释掉也可以, 也就是检查完 graph[v1][v2] 后不用重复检查 graph[v2][v1]
		// graph[v2].push_back(v1);
	}

	cin>>k;
	for( int i = 0; i < k; i++ ){
		for( int v = 0; v < n; v++ ){
			cin>>color[v];
		}
		valid = true;
		bfs(n);
		if(valid == true){
			set<int> s;
			for( int v = 0; v < n; v++ ){
				s.insert(color[v]);
			}
			cout<<s.size()<<"-coloring\n";
		}else{
			cout<<"No\n";
		}
	}

	return 0;
}
