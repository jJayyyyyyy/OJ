#include <iostream>
#define MAXSIZE 100004
#define MAXNUM 10004
using namespace std;

int hashList[MAXNUM] = {0};
int inputList[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, val, maxVal=0;
	cin>>n;

	for( i = 0; i < n; ++i ){
		cin>>val;
		inputList[i] = val;
		hashList[val]++;
		if( val > maxVal ){
			maxVal = val;
		}
	}

	for( i = 0; i < n ; ++i ){
		val = inputList[i];
		if( hashList[val] == 1 ){
			cout<<val<<'\n';
			return 0;
		}
	}
	cout<<"None\n";
	return 0;
}
