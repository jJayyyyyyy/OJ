/*
https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
增加 grid[i][j], 且使得从四个方向观察得到的最高轮廓不变, 问一共最多能增加多少高度
同类题目 P807

参考思路
https://leetcode.com/problems/max-increase-to-keep-city-skyline/solution/
1. 找到每一行的最大值
2. 找到每一列的最大值
3. 对于每一个点 h = grid[i][j], h 不能超过它所在行的最大值, 也不能超过它所在列的最大值
4. 所以 grid[i][j] 能增加的高度是 min(rh, ch) - grid[i][j], 其中 rh 是该行最大值, ch 是该列最大值
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int nRows = grid.size();
		int nCols = grid[0].size();
		int maxRowList[nRows] = {0};
		int maxColList[nCols] = {0};

		for( int i = 0; i < nRows; i++ ){
			for( int j = 0; j < nCols; j++ ){
				maxRowList[i] = max(maxRowList[i], grid[i][j]);
				maxColList[j] = max(maxColList[j], grid[i][j]);
			}
		}

		int ans = 0;
		for( int i = 0; i < nRows; i++ ){
			int rh = maxRowList[i];
			for( int j = 0; j < nCols; j++ ){
				int ch = maxColList[j];
				int limit = min(rh, ch);
				ans += limit - grid[i][j];
			}
		}
		return ans;
	}
};