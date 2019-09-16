/*
https://leetcode.com/problems/surface-area-of-3d-shapes/description/
求表面积
同类题目 P892

凸形比较直观
凹形内部的表面积容易遗漏
最直接的方法是从三个方向一个个去数
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
	int surfaceArea(vector<vector<int>> & grid) {
		int row = grid.size();
		int col = grid[0].size();

		int top = 0;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				int height = grid[r][c];
				if (height != 0) {
					top += 2;
				}
			}
		}
 
		int left = 0;
		for (int r = 0; r < row; r++) {
			int pre = grid[r][0];
			int now = grid[r][col-1];
			left += pre;
			for (int c = 1; c < col; c++) {
				now = grid[r][c];
				left += abs(pre - now);
				pre = now;
			}
			left += now;
		}

		int front = 0;
		for (int c = 0; c < col; c++) {
			int pre = grid[0][c];
			int now = grid[row-1][c];
			front += pre;
			for (int r = 0; r < row; r++) {
				now = grid[r][c];
				front += abs(pre - now);
				pre = now;
			}
			front += now;
		}
		int area = top + left + front;
		return area;
	}
};

vector<vector<int>> get_grid0(){
	vector<vector<int>> grid(1, vector<int>(1));
	grid[0][0] = 2;
	return grid;
}

vector<vector<int>> get_grid1(){
	vector<vector<int>> grid(2, vector<int>(2));
	grid[0][0] = 1;
	grid[0][1] = 2;
	grid[1][0] = 3;
	grid[1][1] = 4;
	return grid;
}

vector<vector<int>> get_grid2(){
	vector<vector<int>> grid(2, vector<int>(2));
	grid[0][0] = 1;
	grid[0][1] = 0;
	grid[1][0] = 0;
	grid[1][1] = 2;
	return grid;
}

vector<vector<int>> get_grid3(){
	vector<vector<int>> grid(3, vector<int>(3));
	grid[0][0] = 1;
	grid[0][1] = 1;
	grid[0][2] = 1;

	grid[1][0] = 1;
	grid[1][1] = 0;
	grid[1][2] = 1;

	grid[2][0] = 1;
	grid[2][1] = 1;
	grid[2][2] = 1;
	return grid;
}

int main(){
	Solution s;
	vector<vector<int>> grid;
	grid = get_grid3();

	cout << s.surfaceArea(grid);

	return 0;
}