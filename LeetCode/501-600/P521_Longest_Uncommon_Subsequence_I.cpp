/*
https://leetcode.com/problems/detect-capital/description/
最长不相同序列
同类题目 P521

Solution 中的评论区已经很好地说明了本题, 其实本题是个文字游戏，就看有没有理解题意了
https://leetcode.com/problems/longest-uncommon-subsequence-i/solution/

*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
	int findLUSlength(string a, string b) {
		if( a == b ){
			return -1;
		}

		return max(a.size(), b.size());
	}
};