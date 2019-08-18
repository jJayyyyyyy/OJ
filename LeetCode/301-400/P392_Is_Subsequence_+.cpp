/*
https://leetcode.com/problems/is-subsequence/description/
子序列
同类题目 P392

参考思路
https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C++-solution

*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
解法1
双指针
时间复杂度：O(max(s.size(), t.size()))
*/
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0, j = 0;
		int len1 = s.size(), len2 = t.size();
		while( i < len1 && j < len2) {
			if(s[i] == t[j]) {
				i++;
			}
			j++;
		}
		return i == len1;
	}
};
