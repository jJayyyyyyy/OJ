#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;
int num[MAXSIZE]={0};

int cmp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin>>n;
	for( i = 1; i <= n; ++i ){
		cin>>num[i];
	}
	sort(num + 1, num + n + 1, cmp);	// 关键在这里，没说要按照日期来，只是说给定这么一段时间，求出爱丁顿数e就好了
										// 因此不妨从大到小排序

	int e = 0;
	while( e < n && num[e+1] > e+1 ){
		++e;
	}
	cout<<e<<'\n';

	return 0;
}