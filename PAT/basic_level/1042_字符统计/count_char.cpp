#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	string us_str;
	getline(cin, us_str);

	int cnt[32]={0}, len=us_str.size(), i=0;
	char ch;

	for( i=0; i<len; i++ ){
		ch = tolower(us_str[i]);
		if( isalpha(ch) ){
			cnt[ ch-'a' ]++;
		}
	}

	int n_max=0, ix_max=0;
	for( i=0; i<26; i++ ){
		if( cnt[i]>n_max ){
			n_max = cnt[i];
			ix_max = i;
		}
	}

	ch = ix_max + 'a';
	cout<<ch<<' '<<n_max;

	return 0;
}
