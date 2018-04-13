#include <iostream>
#include <string>
#define MAXSIZE 160
using namespace std;

int hashList[MAXSIZE] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	for( int i = 0; i < s2.size(); ++i ){
		char ch = s2[i];
		hashList[ch] = 1;
	}

	for( int i = 0; i < s1.size(); ++i ){
		char ch = s1[i];
		if( hashList[ch] == 0 ){
			cout<<ch;
		}
	}
	cout<<'\n';
	return 0;
}
