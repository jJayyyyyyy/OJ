/*
https://leetcode.com/problems/projection-area-of-3d-shapes/description/
求三视图的投影面积
同类题目 P883
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int projectionArea(vector< vector<int> > & grid) {
		int top = 0;
		int front = 0;
		int side = 0;
		int row = grid.size();
		int col = grid[0].size();
		// top = col * row; // 不能直接用size, 因为存在 val == 0 的情况, 即高度为 0

		for( int i = 0; i < row; i++ ){
			int tmpFront = 0;
			int tmpSide = 0;
			for( int j = 0; j < col; j++ ){
				// 行优先
				int heightFront = grid[i][j];

				// 由于是 N x N 的矩阵, 所以不用重新进行 列优先循环
				int heightSide = grid[j][i];

				if( heightFront > 0 ){
					top++;
				}

				if( tmpFront < heightFront ){
					tmpFront = heightFront;
				}

				if( tmpSide < heightSide ){
					tmpSide = heightSide;
				}
			}
			front += tmpFront;
			side += tmpSide;
		}

		return top + front + side;
	}
};

int main(){
	Solution s;
	vector<vector<int> > grid(2, vector<int>(2));
	grid[0][0] = 1;
	grid[0][1] = 2;
	grid[1][0] = 3;
	grid[1][1] = 4;
	
	cout<<s.projectionArea(grid);
	
	return 0;
}