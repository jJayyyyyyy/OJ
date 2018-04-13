#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;

int miles[MAXSIZE];

int cmp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for( int i = 1; i <= n; i++ ){
		cin>>miles[i];
	}

	// 关键在这里，没说要按照日期来，只是说给定这么一段时间，求出爱丁顿数e就好了
	// 因此从大到小排序
	sort(miles+1, miles+n+1, cmp);
		
	int e;
	for( e = 1; e <= n; e++ ){
		if( miles[e] > e ){
			continue;
		}else{
			break;
		}
	}

	cout<<e-1<<'\n';
	return 0;
}
