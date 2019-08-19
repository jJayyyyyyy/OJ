/*
https://leetcode.com/problems/is-subsequence/description/
子序列
同类题目 P392

参考思路

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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


/*
解法2
follow-up
由于 T 可能很长
需要利用邻接链表存储 T 每个字母所在的位置
然后用二分查找去 T 中找字母，而不是线性查找
复杂度 O( max( s.size(), log(t.size()) ) )

参考思路
https://leetcode.com/problems/is-subsequence/discuss/87302/Binary-search-solution-for-follow-up-with-detailed-comments

但是实际上，对于本题的用例来说，还是解法1更快，也更直观
*/
class Solution{
public:
	bool isSubsequence(string s, string t) {
		vector< vector<int> > hashmap(26, vector<int>());
		int len = t.size();
		for (int i = 0; i < len; i++) {
			char ch = t[i];
			hashmap[ch - 'a'].push_back(i);
		}
		// 这之后，每个槽里面的 vector 的 index 都不一样
		// 且每个槽的 vector 都是升序的

		int preIndex = -1;
		for ( char ch : s) {

			vector<int> indexListOfCh = hashmap[ch - 'a'];
			if (indexListOfCh.size() == 0) {
				return false;
			}

			// 用二分查找看看能不能在 (preIndex, t.size()) 范围内找到 ch
			auto it = upper_bound(indexListOfCh.begin(), indexListOfCh.end(), preIndex);
			if (it == indexListOfCh.end()) {
				// 没找到
				return false;
			}
			preIndex = *it;
		}
		return true;
	}
};