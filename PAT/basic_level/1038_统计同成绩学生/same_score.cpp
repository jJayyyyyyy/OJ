#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int us_N=0, i=0, n_score[101]={0}, temp_score;
	cin>>us_N;

	for( i=0; i<us_N; i++ ){
		cin>>temp_score;
		n_score[temp_score]++;
	}

	int is_start=1, us_K=0;
	cin>>us_K;
	for( i=0; i<us_K; i++ ){
		cin>>temp_score;
		if(is_start){
			cout<<n_score[temp_score];
			is_start = 0;
		}else{
			cout<<' '<<n_score[temp_score];
		}

	}

	return 0;
}
