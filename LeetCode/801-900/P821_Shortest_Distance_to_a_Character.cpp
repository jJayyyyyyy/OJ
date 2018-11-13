/*
https://leetcode.com/problems/shortest-distance-to-a-character/description/
给定一个字符串 S, 一个字符 C, 求 S 中每一个字符到 C 的最短距离
同类题目 P821

好题
参考思路
https://leetcode.com/problems/shortest-distance-to-a-character/discuss/125788/C++JavaPython-2-Pass-with-Explanation
Initial result array.
Loop twice on the string S.
First forward pass to find shortest distant to character on left.
Second backward pass to find shortest distant to character on right.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> shortestToChar(string S, char C) {
		int len = S.size();
		vector<int> ans(len, len);
		int pos = len;
		for( int i = 0; i < len; i++){
			if( S[i] == C ){
				pos = i;
			}
			ans[i] = min(ans[i], abs(i - pos));
		}
		for( int i = len-1; i >= 0; i-- ){
			if( S[i] == C ){
				pos = i;
			}
			ans[i] = min(ans[i], abs(i - pos));
		}
		return ans;
	}
};