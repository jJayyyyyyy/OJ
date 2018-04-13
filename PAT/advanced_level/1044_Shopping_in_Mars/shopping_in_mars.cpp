#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
#define INF 10000008
using namespace std;

int sum[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, i, j, k, S, nearS=INF, num, top;
	cin>>n>>S;

	for( i = 1; i <= n; ++i ){
		cin>>num;
		sum[i] = sum[i-1] + num;
	}

	for( i = 1; i <= n; ++i ){
		top = sum[i - 1] + S;
		j = lower_bound(sum + i, sum + n + 1, top) - sum;
		if( sum[j] - sum[i - 1] == S ){
			nearS = S;
			break;
		}else if( j <= n && (sum[j] - sum[i-1] < nearS ) ){
			nearS = sum[j] - sum[i - 1];
		}
	}

	for( i = 1; i <= n; ++i ){
		top = sum[i - 1] + nearS;
		j = lower_bound(sum + i, sum + n + 1, top) - sum;
		if( sum[j] - sum[i - 1] == nearS ){
			cout<<i<<'-'<<j<<'\n';
		}
	}
	return 0;
}