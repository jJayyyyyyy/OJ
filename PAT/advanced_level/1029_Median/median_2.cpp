#include <iostream>
#define MAXSIZE 1000004
typedef long long ll;
using namespace std;

ll a[MAXSIZE], b[MAXSIZE];

int mergeArray(ll a[], int lenA, ll b[], int lenB, int mid){
	int i=0, j=0, k=0;

	while( k < mid ){
		if( a[i] < b[j] ){
			i++;
		}else{
			j++;
		}
		k++;
	}

	if( a[i] < b[j] ){
		cout<<a[i]<<'\n';
	}else{
		cout<<b[j]<<'\n';
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int lenA, lenB, i, j;
	cin>>lenA;
	for(i=0; i<lenA; ++i){
		cin>>a[i];
	}
	cin>>lenB;
	for(j=0; j<lenB; ++j){
		cin>>b[j];
	}

	int mid = (lenA + lenB - 1) / 2;

	mergeArray(a, lenA, b, lenB, mid);

	return 0;
}
