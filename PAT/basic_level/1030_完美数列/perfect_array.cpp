#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;

long long num[MAXSIZE]={0};

int main(){
	int n, i, maxCnt=1, iMin, iMax;;
	long long p, mp;
	cin>>n>>p;

	for( i=0; i<n; i++ ){
		cin>>num[i];
	}
	sort(num, num+n);

	for( iMin=0; iMin<n; iMin++ ){
		mp = num[iMin] * p;
		iMax = upper_bound(num+iMin+1, num+n, mp) - num;
		maxCnt = max( maxCnt, iMax - iMin );
	}

	cout<<maxCnt<<'\n';
	return 0;
}
