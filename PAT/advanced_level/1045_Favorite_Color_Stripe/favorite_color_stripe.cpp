#include <iostream>
#include <algorithm>
#define MAXLEN1 204
#define MAXLEN2 10004
using namespace std;

int s1[MAXLEN1] = {0};
int s2[MAXLEN2] = {0};
int dp[MAXLEN1][MAXLEN2] = {0};

int main(){
	int n, len1, len2, i, j;
	cin>>n;
	cin>>len1;
	for( i = 1; i <= len1; ++i ){
		cin>>s1[i];
	}
	cin>>len2;
	for( j = 1; j <= len2; ++j ){
		cin>>s2[j];
	}

	for( i = 0; i <= len1; ++i ){
		dp[i][0] = 0;
	}
	for( j = 0; j <= len2; ++j ){
		dp[0][j] = 0;
	}

	for( i = 1; i <= len1; ++i ){
		for( j = 1; j <= len2; ++j ){
			int tmpMAX = max(dp[i-1][j], dp[i][j-1]);
			if( s1[i] == s2[j] ){
				dp[i][j] = tmpMAX + 1;
			}else{
				dp[i][j] = tmpMAX;
			}
		}
	}

	cout<<dp[len1][len2]<<'\n';

	return 0;
}