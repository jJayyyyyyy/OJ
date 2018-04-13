#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100004
using namespace std;

vector<int> a(MAX);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i;
	cin>>n>>m;
	for( i=0; i<n; i++ ){
		cin>>a[i];
	}

	sort(a.begin(), a.begin() + n);

	if( n < 2 ){
		cout<<"No Solution";
		return 0;
	}

	if( a[0] + a[1] > m || a[n-1] + a[n-2] < m ){
		cout<<"No Solution";
		return 0;
	}
	
	int iV1, iV2, v1, v2, key;
	for( iV1=0; iV1<n; iV1++ ){
		v1 = a[iV1];
		key = m - v1;
		iV2 = upper_bound( a.begin()+iV1+1, a.begin()+n, key ) - a.begin();

		if( iV1 + 1 == iV2 ){
			cout<<"No Solution";
			break;
		}

		v2 = a[iV2 - 1];

		if( v2 == key ){
			cout<<v1<<' '<<v2;
			return 0;
		}
		
	}
	
	return 0;
}
