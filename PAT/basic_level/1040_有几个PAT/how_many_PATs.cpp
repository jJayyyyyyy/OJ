#include <iostream>
#include <string>
#include <algorithm>
#define DIV 1000000007
using namespace std;

int main(){
	string us_str;
	cin>>us_str;

	int i=0, cnt_P=0, cnt_pat=0;
	int cnt_T=count(us_str.begin(), us_str.end(), 'T');
	int len=us_str.size();

	for( i=0; i<len; i++ ){
		if( us_str[i]=='P' )
			cnt_P++;
		else if( us_str[i]=='T' )
			cnt_T--;
		else{
			cnt_pat += cnt_P*cnt_T;
			if( cnt_pat>DIV )
				cnt_pat = cnt_pat % DIV;
		}
	}

	cout<<cnt_pat;
	return 0;
}


