#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100004
using namespace std;

int origin[MAX], ordered[MAX];
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, isFirst=1, cntAns=0;
	cin>>n;
	for( int i = 0; i < n; ++i ){
		cin>>origin[i];
		ordered[i] = origin[i];
	}

	sort( ordered, ordered + n );

	int maxOfLeft=0;
	for( int i = 0; i < n; ++i ){
		if( origin[i] == ordered[i] && origin[i] > maxOfLeft ){
			ans.push_back(origin[i]);
		}
		maxOfLeft = max( origin[i], maxOfLeft );	// 动态更新 主元 左边的 最大值，而不是每次从头开始数
	}

	cout<<ans.size()<<'\n';
	for( int i = 0; i < ans.size(); ++i ){
		if( isFirst ){
			cout<<ans[i];
			isFirst = 0;
		}else{
			cout<<' '<<ans[i];
		}
	}
	cout<<'\n';				// 格式要求，若 ans.size() 为 0 ，需要新的空行
	return 0;
}
