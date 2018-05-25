/*
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * 给定一个字符串，求出最长的，不含重复字母的子串的长度（也就是最长不会超过26）
 * 答案参考了[这里](https://discuss.leetcode.com/topic/24739/c-code-in-9-lines)
 * 1. 使用滑动窗口，而不是每次从头开始
 * 2. 字符hash
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> Hash(256, -1);
		int maxLen = 0, start = -1;
		for (int i = 0; i < s.size(); i++) {
			char ch = s[i];
			if (Hash[ch] > start)
				start = Hash[ch];
			Hash[ch] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};
