#include <iostream>
#define MAXSIZE 200004
#define ll long long
using namespace std;

ll a[MAXSIZE], b[MAXSIZE];

void mergeArray(int lenA, int lenB, int mid){
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
	for( int j = 0; j < lenB; j++){
		cin>>b[j];
	}

	int mid = (lenA + lenB - 1) / 2;

	mergeArray(lenA, lenB, mid);

	return 0;
}
