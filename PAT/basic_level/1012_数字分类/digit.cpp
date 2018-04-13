#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char * argv[]){
	int us_N=0, us_input=0;
	int a[5]={0}, cnt[5]={0};
	int i=0,  multi=1;

	cin>>us_N;
	while( i++<us_N ){
		cin>>us_input;
		if( 0==us_input%10 ){
			a[0] += us_input;
			cnt[0]++;
		}
		if( 1==us_input%5 ){
			a[1] += us_input * multi;
			multi = -multi;
			cnt[1]++;
		}
		if( 2==us_input%5 ){
			a[2]++;
			cnt[2]++;
		}
		if( 3==us_input%5 ){
			a[3] += us_input;
			cnt[3]++;
		}
		if( 4==us_input%5 ){
			if( a[4]<us_input )
				a[4] = us_input;
			cnt[4]++;
		}
	}

	if(0 == cnt[0])
		cout<<"N ";
	else
		cout<<a[0]<<' ';

	if(0 == cnt[1])
		cout<<"N ";
	else
		cout<<a[1]<<' ';

	if(0 == cnt[2])
		cout<<"N ";
	else
		cout<<a[2]<<' ';

	if(0 == cnt[3])
		cout<<"N ";
	else
		printf("%.1f ", a[3]*1.0/cnt[3]);

	if(0 == cnt[4])
		cout<<"N";
	else
		cout<<a[4];

	return 0;
}
