#include <iostream>
#include <string>
#define MAX 40
using namespace std;

int main(){
	int us_N=0, sigma=0, i=0, j=0, cnt=0, is_start=1;
	int id[MAX]={0}, output_list[MAX]={0};
	string str_num;

	cin>>us_N;
	for( i=0; i<us_N; i++ ){
		cin>>str_num;
		sigma = 0;
		for( j=0; j<str_num.size(); j++ )
			sigma += str_num[j]-'0';
		id[sigma]++;
	}

	for( i=1; i<MAX; i++ ){
		if( id[i]>0 )
			output_list[cnt++] = i;
	}

	cout<<cnt<<'\n';
	for( i=0; i<cnt; i++ ){
		if(is_start){
			cout<<output_list[i];
			is_start = 0;
		}else
			cout<<' '<<output_list[i];
	}

	return 0;
}
// 21min
