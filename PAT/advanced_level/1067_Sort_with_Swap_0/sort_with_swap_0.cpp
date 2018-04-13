#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;

int num2Index[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, k=1, ixZero, cnt=0, num, tmpIx;
	cin>>n;

	int remain = n - 1;
	for( i = 0; i < n; ++i ){
		cin>>num;
		num2Index[num] = i;
		if( num == i && num != 0 ){
			--remain;
		}
	}

	while( remain > 0 ){
		while( num2Index[0] != 0 ){
			tmpIx = num2Index[0];
			swap(num2Index[0], num2Index[tmpIx]);
			++cnt;
			--remain;
		}
		if( num2Index[0] == 0 ){
			while( k < n ){
				if( num2Index[k] != k ){
					swap(num2Index[0], num2Index[k]);
					++cnt;
					break;
				}
				++k;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}