/*
https://leetcode.com/problems/di-string-match/description/

同类题目 P942

参考答案
https://leetcode.com/problems/di-string-match/solution/

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	vector<int> diStringMatch(string S) {
		int len = S.size();
		int left = 0;
		for( int i = 0; i < len; i++ ){
			if( S[i] == 'D' ){
				left++;
			}
		}
		int right = left;
		vector<int> res = {left};
		for( char ch : S ){
			if( ch == 'I' ){
				right++;
				res.push_back(right);
			}else{
				left--;
				res.push_back(left);
			}
		}
		return res;
	}
};
