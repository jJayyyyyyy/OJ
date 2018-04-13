#include <iostream>
using namespace std;

int main(){
	int us_N=0;
	int num[10];
	int i=0, j=0;
	int sigma=0;

	cin>>us_N;
	for(i=0; i<us_N; i++){
		cin>>num[i];
	}

	for(i=0; i<us_N; i++){
		for(j=i+1; j<us_N; j++){
			sigma += num[i]*10 + num[j] + num[j]*10 + num[i];
		}
	}

	cout<<sigma<<'\n';
	return 0;
}
