#include <iostream>
#include <vector>
using namespace std;

vector<int> v1;

void mergeArray(int len1, int len2, int mid){
	int i=0, j=0, k=0;

	int val;
	cin>>val;
	while( k < mid ){
		if( i < len1 && v1[i] < val ){
			i++;
		}else{
			j++;
			if( j < len2 ){
				cin>>val;
			}
		}
		k++;
	}


	if( i < len1 && v1[i] < val ){
		cout<<v1[i]<<'\n';
	}else{
	  cout<<val<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len1, len2;
	
	cin>>len1;
	v1.resize(len1);
	for( int i = 0; i < len1; i++ ){
		cin>>v1[i];
	}
	
	cin>>len2;
	int mid = (len1 + len2 - 1) / 2;

	mergeArray(len1, len2, mid);

	return 0;
}
