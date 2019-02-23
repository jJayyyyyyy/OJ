/*
https://leetcode.com/problems/rotate-image/description/
旋转图像(旋转矩阵)
同类题目 P048

参考思路
https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image

// clockwise rotate
// first reverse up to down, then swap the symmetry 
// 1 2 3     7 8 9     7 4 1
// 4 5 6  => 4 5 6  => 8 5 2
// 7 8 9     1 2 3     9 6 3
void rotate(vector<vector<int> > &matrix) {
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i + 1; j < matrix[i].size(); ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
}

// anticlockwise rotate
// first reverse left to right, then swap the symmetry
// 1 2 3     3 2 1     3 6 9
// 4 5 6  => 6 5 4  => 2 5 8
// 7 8 9     9 8 7     1 4 7
void anti_rotate(vector<vector<int> > &matrix) {
	for (auto vi : matrix) reverse(vi.begin(), vi.end());
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i + 1; j < matrix[i].size(); ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
}

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// io加速
static const auto io_speed_up = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

// clockwise rotate
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());
		int row = matrix.size();
		int col = matrix[0].size();
		for( int i = 0; i < row; i++ )
		{
			for( int j = i + 1; j < col; j++ )
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};

