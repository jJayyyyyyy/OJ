#include <iostream>
#define MAX 100008
using namespace std;

int exits[MAX] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, m, exitA, exitB, sigma, halfway, start, end, result, dis;

	cin>>n;
	for( i=1; i<=n; i++ ){
		cin>>dis;
		// exits[n]里面存储了出口n到出口1的距离，而不是 n 与 n+1 之间的距离。以此减少后续计算。
		exits[i+1] = dis + exits[i];
	}
	sigma = exits[i];
	halfway = sigma / 2;

	cin>>m;
	for( i=0; i<m; i++ ){
		cin>>exitA>>exitB;
		if( exitA < exitB ){
			start = exitA;
			end = exitB;
		}else{
			start = exitB;
			end = exitA;
		}
		result = exits[end] - exits[start];
		
		if( result > halfway ){
			cout<<(sigma - result)<<'\n';
		}else{
			cout<<result<<'\n';
		}
	}

	return 0;
}