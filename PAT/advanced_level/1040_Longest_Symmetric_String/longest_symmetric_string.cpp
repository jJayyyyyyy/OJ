#include <iostream>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);

	int len = s.size();
	int i, offset, lenOdd, lenEven, lenMax=1;

	for( i=0; i<len; i++ ){
		lenOdd = 1;
		for( offset=1; offset<len; offset++ ){
			if( i-offset<0 || i+offset>len || s[i-offset]!=s[i+offset] ){
				break;
			}else{
				lenOdd += 2;
			}
		}
		if( lenOdd > lenMax ){
			lenMax = lenOdd;
		}

		lenEven = 0;
		for( offset=0; offset<len; offset++ ){
			if( i-offset<0 || i+offset+1>len || s[i-offset]!=s[i+offset+1] ){
				break;
			}else{
				lenEven += 2;
			}
		}
		if( lenEven > lenMax ){
			lenMax = lenEven;
		}
	}
	cout<<lenMax;

	return 0;
}