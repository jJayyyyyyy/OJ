#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	vector<int> us_vec;
	int us_N=0, us_shift=0, num=0, r_shift=0, is_start=1;

	cin>>us_N>>us_shift;
	for(int i=0; i<us_N; i++){
		cin>>num;
		us_vec.push_back(num);
	}

	us_shift = us_shift % us_N;
	r_shift = us_N - us_shift;

	for(int i=r_shift; i<us_N; i++){
		if(is_start){
			cout<<us_vec[i];
			is_start = 0;
		}else
			cout<<' '<<us_vec[i];
	}

	for(int i=0; i<r_shift; i++){
		if(is_start){
			cout<<us_vec[i];
			is_start = 0;
		}else
			cout<<' '<<us_vec[i];
	}


	return 0;
}
