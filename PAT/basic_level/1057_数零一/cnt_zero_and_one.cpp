#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	int sigma=0, len=0, i=0, base='a'-1, cnt_one=0, cnt_zero=0;
	string us_str;
	getline(cin, us_str);
	len = us_str.size();

	for( i=0; i<len; i++ ){
		if( isalpha(us_str[i]) ){
			sigma += tolower(us_str[i]) - base;
		}
	}

	while( sigma!=0 ){
		if( sigma&0x0001==1 ){
			cnt_one++;
		}else{
			cnt_zero++;
		}
		sigma = sigma>>1;
	}

	cout<<cnt_zero<<' '<<cnt_one;
	return 0;
}
// 15min
