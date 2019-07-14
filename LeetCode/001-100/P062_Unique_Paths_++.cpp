/*
https://leetcode.com/problems/unique-paths/description/
同类题目: P062, P063, P064, P174
动态规划
坐标 [i, j] 只能通过 [i - 1, j] 或者 [i, j - 1] 到达
所以状态转移方程是 dp[i][j] = dp[i - 1, j] + dp[i, j - 1];
由于最上面一行只能通过左边到达, 最左边一列只能通过上面到达
因此 dp[0][j] = dp[i][0] = 1;

参考思路
https://leetcode.com/problems/unique-paths/discuss/22954/0ms-5-lines-DP-Solution-in-C++-with-Explanations
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n)
	{
		vector< vector<int> > path( m, vector<int>(n, 1) );
		for( int i = 1; i < m; i++ )
		{
			for( int j = 1; j < n; j++ )
			{
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}

		return path[m - 1][n - 1];
	}
};

int main() {
	Solution s;
	int ans = s.uniquePaths(3, 2);
	cout << ans << '\n';
	return 0;
}
