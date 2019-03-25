/*
https://leetcode.com/problems/find-common-characters/description/
给一个字符串数组, 求出所有公共的字符, 注意结果应包含重复多次的字符, 比如 l 在 ["bella","label","roller"] 都出现了 2 次, 则结果应包含 2 个 l, 即 ans = ["e","l","l"]
同类题目 P1002

参考思路 https://leetcode.com/problems/find-common-characters/discuss/247573/C++-O(n)-or-O(1)-two-vectors
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> commonChars(vector<string> & A) {
		// 首先假设所有字符都是重复出现的, 且重复次数为 INF = 0x3fffffff 无穷大
		vector<int> cnt_char(26, 0x3fffffff);
		// 对于每个字符串
		for( string s : A )
		{
			vector<int> tmp_cnt_char(26, 0);
			// 记录每个字符出现的次数
			for( char ch : s )
			{
				tmp_cnt_char[ch - 'a']++;
			}
			for( char ch = 0; ch < 26; ch++ )
			{
				// 然后更新 cnt_char
				// 如果出现次数变少了, 则更新为更小的值
				// 也就是取公共的部分
				cnt_char[ch] = min(cnt_char[ch], tmp_cnt_char[ch]);
			}
		}
		vector<string> ans;
		for( char ch = 0; ch < 26; ch++ )
		{
			string s(1, ch + 'a');
			int len = cnt_char[ch];
			for( int i = 0; i < len; i++ )
			{
				ans.push_back(s);
			}
		}
		return ans;
	}
};
