/*
https://leetcode.com/problems/edit-distance/description/
编辑距离
同类题目 P72, 华为 20190508 笔试第三题

参考思路（动态规划）
https://leetcode.com/problems/edit-distance/discuss/25846/C++-O(n)-space-DP
设 dp[i][j] 是把 s1[:i] 变成 s2[:j] 需要的最少的操作数
1. 首先对 dp[i][j] 进行初始化, 由于要求最少的操作数, 所以我们把它初始化为最大值
也就是从 s1[:i] 变成空字符串 "" 的操作数

2. 接着, 考虑子问题, 假设已经做好了 s1[:i-1] 到 s[:j-1] 的变换, 也就是得到了 dp[i-1][j-1]
接下来分两种情况, s1[i] == s2[j] , 或者 s1[i] != s2[j]

2.1 s1[i] == s2[j], 那么不需要额外的操作 dp[i][j] = dp[i-1][j-1]

2.2 s1[i] != s2[j], 那么又可以分三种情况

2.2.1, case1
s1[i] 需要替换为 s2[j], 那么 dp[i][j] = dp[i-1][j-1] + 1

2.2.2, case2
s2 已经结束了, s2[j] 为空, 那么 s1[i] 需要被删除, 那么 dp[i][j] = dp[i-1][j] + 1

2.2.3, case3
s1 已经结束了, s1[i] 为空, 那么要把 s2[j] 插到 s1[i], 那么 dp[i][j] = dp[i][j-1] + 1

对于 2.2, 我们需要求出 case1, case2, case3 中的最小值作为 dp[i][j]

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int j = 1; j <= n; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					int case1 = dp[i - 1][j - 1] + 1;
					int case2 = dp[i][j - 1] + 1;
					int case3 = dp[i - 1][j] + 1;
					dp[i][j] = min( case1, min(case2, case3) );
				}
			}
		}
		return dp[m][n];
	}
};
