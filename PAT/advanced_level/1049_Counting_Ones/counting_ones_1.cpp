#include <iostream>
#include <sstream>
#include <string>
using namespace std;

long long getCnt(string s){
	int len = s.size();
	long long cnt = 0;
	for( int i=0; i<len; i++ ){
		if( '1' == s[i] ){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i=0;
	cin>>n;

	long long cnt=0;
	string str;
	for( i=1; i<=n; i++ ){
		stringstream ss;
		ss<<i;
		ss>>str;
		cnt += getCnt(str);
	}

	cout<<cnt<<'\n';

	return 0;
}