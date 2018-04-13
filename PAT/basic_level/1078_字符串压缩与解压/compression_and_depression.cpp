#include <iostream>
#include <cctype>
#include <string>
#define MAXSIZE 104
using namespace std;

void compress(string & s){
	int len = s.size();
	s.append("#");
	for( int i = 0; i < len; i++ ){
		int cnt=1;
		while( s[i] == s[i+1] ){
			cnt++;
			i++;
		}
		if( cnt == 1 ){
			cout<<s[i];
		}else{
			cout<<cnt<<s[i];
		}
	}
}

void decompress(string & s){
	int len = s.size();
	for( int i = 0; i < len; i++ ){
		int len2 = 0;
		if( isdigit(s[i]) ){
			while( isdigit(s[i]) ){
				len2 = len2*10 + s[i] - '0';
				i++;
			}
			for( int j = 0; j < len2; j++ ){
				cout<<s[i];
			}
		}else{
			cout<<s[i];
		}

	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	char method;
	string s;

	cin>>method;
	getline(cin, s);
	getline(cin, s);

	if( method == 'C' ){
		compress(s);
	}else{
		decompress(s);
	}

	return 0;
}
