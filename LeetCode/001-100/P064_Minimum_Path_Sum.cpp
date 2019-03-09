/*
https://leetcode.com/problems/minimum-path-sum/description/
同类题目: P062, P063, P064, P174
动态规划

基本思路参考 P062
注意更新边界条件, 即第一行和第一列
for( int j = 1; j < col; j++ )
{
	grid[0][j] += grid[0][j - 1];
}

for( int i = 1; i < row; i++ )
{
	grid[i][0] += grid[i - 1][0];
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minPathSum(vector< vector<int> > & grid) {
		int row = grid.size();
		int col = grid[0].size();
		for( int j = 1; j < col; j++ )
		{
			grid[0][j] += grid[0][j - 1];
		}

		for( int i = 1; i < row; i++ )
		{
			grid[i][0] += grid[i - 1][0];
		}
		for( int i = 1; i < row; i++ )
		{
			for( int j = 1; j < col; j++ )
			{
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[row - 1][col - 1];
	}
};
