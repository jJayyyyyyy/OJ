#include <iostream>
#include <string>
using namespace std;

int main(){
	int d, n;
	cin>>d>>n;

	if( n == 1 ){
		cout<<d<<'\n';
		return 0;
	}

	string s = to_string(d) + '#';
	string res;
	for( int i = 1; i < n; i++ ){
		res = "";
		int cnt = 1;
		for( int j = 1; j < s.size(); j++ ){
			if( s[j] == s[j - 1] ){
				cnt++;
			}else{
				res += s[j - 1] + to_string(cnt);
				cnt = 1;
			}
		}
		s = res + '#';
	}

	cout<<res<<'\n';
	return 0;
}

/*
加后缀, EOF, #

本题即甲级题目 1140 Look-and-say Sequence

也即 LeetCode P038 Count and Say
https://leetcode.com/problems/count-and-say/

*/