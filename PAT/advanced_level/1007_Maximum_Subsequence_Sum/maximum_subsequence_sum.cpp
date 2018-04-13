#include <iostream>
#define MAXSIZE 10004
using namespace std;

int a[MAXSIZE] = {0};
int dp[MAXSIZE] = {0};
int startIx[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i;
	bool allNegative = true;
	
	cin>>n;
	for(i=0; i<n; i++){
		cin>>a[i];
		if( a[i] >= 0 ){
			allNegative = false;
		}
	}

	if( allNegative == true ){
		cout<<"0 "<<a[0]<<' '<<a[n-1]<<'\n';
		return 0;
	}

	dp[0] = a[0];

	// state transition equation
	for( i=1; i<n; i++ ){
		if(dp[i-1] + a[i] > a[i]){
			dp[i] = dp[i-1] + a[i];
			startIx[i] = startIx[i-1];
		}else{
			dp[i] = a[i];
			startIx[i] = i;
		}
	}

	int maxIx = 0;
	int maxDP = dp[maxIx];
	for( i=1; i<n; i++ ){
		if(dp[i] > maxDP){
			maxDP = dp[i];
			maxIx = i;
		}
	}

	int beginIndex = startIx[maxIx];
	int beginValue = a[beginIndex];
	int endValue = a[maxIx];
	
	cout<<maxDP<<' '<<beginValue<<' '<<endValue<<'\n';

	return 0;
}