/*
https://leetcode.com/problems/number-of-segments-in-a-string/description/
实现字符串的 split()
同类题目 P434

*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int countSegments(string s) {
		int cnt = 0;
		bool isSpace = false;
		bool hasChar = false;
		for( char ch : s ){
			if( ch != ' ' ){
				isSpace = false;
				hasChar = true;
			}else{
				if( isSpace == false && hasChar == true ){
					cnt++;
				}
				isSpace = true;
			}
		}
		if( isSpace == false && hasChar == true){
			cnt++;
		}
		return cnt;
	}
};

int main(){
	Solution s;
	cout<<s.countSegments("                ")<<'\n';
	
	return 0;
}