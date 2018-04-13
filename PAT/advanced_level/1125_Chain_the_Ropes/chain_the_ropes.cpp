#include <iostream>
#include <algorithm>
#define MAXSIZE 10004
using namespace std;

int ropeList[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total;
	cin>>total;
	for( int i = 0; i < total; i++ ){
		cin>>ropeList[i];
	}

	sort(ropeList, ropeList+total);

	double sum = ropeList[0];
	for( int i = 1; i < total; i++ ){
		sum = sum/2.0 + ropeList[i]/2.0;
	}
	cout<<int(sum)<<'\n';

	return 0;
}