#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;

int a[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, n1, n2, s1, s2, i;
	cin>>n;

	for( i=0; i<n; i++ ){
		cin>>a[i];
	}

	if( n % 2 == 0 ){
		n1 = n2 = n / 2;
	}else{
		n1 = n / 2;
		n2 = n1 + 1;
	}

	sort(a, a+n);
	
	s1 = s2 = 0;

	for( i=0; i<n1; i++ ){
		s1 += a[i];
	}

	for( ; i<n; i++ ){
		s2 += a[i];
	}
	cout<<(n2 - n1)<<' '<<(s2 - s1)<<'\n';

	return 0;
}