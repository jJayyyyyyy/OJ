/*
https://leetcode.com/problems/unique-paths-ii/description/
同类题目: P062, P063, P064, P174
动态规划

基本思路参考 P062
本题主要增加了一个【障碍物矩阵】, 即某些坐标是不可达的
因此需要改变 dp 边界的初始化
详细思路请看代码中的注释

参考思路
https://leetcode.com/problems/unique-paths-ii/solution/
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid)
	{
		if( obstacleGrid[0][0] == 1 )
		{
			return 0;
		}

		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		// 使用 unsigned int, 是因为本题新增了部分样例, 使得 dp[i][j] 超过 int 范围
		vector< vector<unsigned int> > dp(row, vector<unsigned int>(col));
		dp[0][0] = 1;

		for( int i = 1; i < row; i++ )
		{
			if( obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1 )
			{
				// 最左边一列 [i, 0], 无法从左边到达
				// 只能通过上面一格 [i - 1, 0] 到达 [i, 0]
				dp[i][0] = 1;
			}
			else
			{
				// 如果 obstacleGrid[i][0] 本身就是障碍物
				// 或者 上面一格 [i - 1, 0] 无法到达
				// 那么 dp[i][0] 无法到达
				dp[i][0] = 0;
			}
		}

		for( int j = 1; j < col; j++ )
		{
			if( obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1 )
			{
				// 同理, 最上边一行 [0, j], 无法从上边到达
				dp[0][j] = 1;
			}
			else
			{
				dp[0][j] = 0;
			}
		}

		// 同 P062
		for( int i = 1; i < row; i++ )
		{
			for( int j = 1; j < col; j++ )
			{
				if( obstacleGrid[i][j] == 0 )
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else
				{
					// 如果 [i, j] 是障碍物, 那么 dp[i][j] 无法到达
					dp[i][j] = 0;
				}
			}
		}
		return dp[row - 1][col - 1];
	}
};