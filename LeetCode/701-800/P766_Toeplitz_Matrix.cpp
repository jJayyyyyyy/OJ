/*
https://leetcode.com/problems/toeplitz-matrix/description/
判断一个矩阵是否为常对角矩阵(toeplitz matrix)
同类题目 P766

参考思路
https://leetcode.com/problems/toeplitz-matrix/solution/

#2 Compare With Top-Left Neighbor
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector< vector<int> > & matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for( int r = 0; r < row ; r++ ){
			for( int c = 0; c < col; c++ ){
				if( r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c] ){
					return false;
				}
			}
		}
		return true;
	}
};
