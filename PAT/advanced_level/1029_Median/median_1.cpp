#include <iostream>
#include <algorithm>
#define MAXSIZE 1000002
#define DMAXSIZE 2000004
#define ll long long
using namespace std;

ll a[MAXSIZE], b[MAXSIZE];
ll c[DMAXSIZE];

void mergeArray(int lenA, int lenB){
	int i=0, j=0, k=0;

	while( i < lenA && j < lenB ){
		if( a[i] < b[j] ){
			c[k++] = a[i++];
		}else{
			c[k++] = b[j++];
		}
	}

	while( i < lenA ){
		c[k++] = a[i++];
	}
	while( j < lenB ){
		c[k++] = b[j++];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int lenA, lenB;
	
	cin>>lenA;
	for( int i = 0; i < lenA; i++ ){
		cin>>a[i];
	}
	
	cin>>lenB;
	for(int j = 0; j < lenB; j++ ){
		cin>>b[j];
	}

	mergeArray(lenA, lenB);

	cout<<c[ (lenA + lenB - 1) / 2 ]<<'\n';
	return 0;
}
