#include <iostream>
#include <algorithm>
#define MAXSIZE 1000002
#define DMAXSIZE 2000004
typedef long long ll;
using namespace std;

ll a[MAXSIZE], b[MAXSIZE];
ll c[DMAXSIZE];

int mergeArray(ll a[], int lenA, ll b[], int lenB, ll tmp[]){
	int i=0, j=0, k=0;

	while( i<lenA && j<lenB ){
		if( a[i] < b[j] ){
			tmp[k++] = a[i++];
		}else{
			tmp[k++] = b[j++];
		}
	}

	while( i < lenA ){
		tmp[k++] = a[i++];
	}
	while( j < lenB ){
		tmp[k++] = b[j++];
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

	mergeArray(a, lenA, b, lenB, c);

	cout<<c[ (lenA + lenB - 1) / 2 ]<<'\n';

	return 0;
}
