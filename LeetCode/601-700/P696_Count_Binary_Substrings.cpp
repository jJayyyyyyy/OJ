/*
https://leetcode.com/problems/count-binary-substrings/description/

同类题目 P696

参考思路
https://leetcode.com/problems/count-binary-substrings/solution/

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int countBinarySubstrings(string s) {
		int len = s.size();
		vector<int> group(len, 1);
		int cursor = 0;
		for( int i = 1; i < len; i++ ){
			if( s[i-1] != s[i] ){
				group[++cursor] = 1;
			}else{
				group[cursor]++;
			}
		}
		int ans = 0;
		for( int i = 1; i <= cursor; i++ ){
			int v1 = group[i-1];
			int v2 = group[i];
			if( v1 < v2 ){
				ans += v1;
			}else{
				ans += v2;
			}
		}
		return ans;
	}
};