/*
https://leetcode.com/problems/image-smoother/description/
对图像进行平滑处理, 也就是取像素点周围一圈的格子(含自身)的平均值
同类题目 P661
*/

#include <iostream>
using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	vector<vector<int>> imageSmoother( vector< vector<int> > & M ) {
		int row = M.size();
		int col = M[0].size();
		vector< vector<int> > ans(row, vector<int>(col, 0));

		for( int i = 0; i < row; i++ ){
			for( int j = 0; j < col; j++ ){
				int cnt = 0;
				for( int x = i - 1; x <= i + 1; x++ ){
					for( int y = j - 1; y <= j + 1; y++ ){
						if( x >= 0 && x < row && y >= 0 && y < col ){
							ans[i][j] += M[x][y];
							cnt++;
						}
					}
				}
				ans[i][j] /= cnt;
			}
		}

		return ans;
	}
};

// 如果 row >= 3 && col >= 3 根据 CSAPP - Code Optimization, 将上述代码展开成如下形式会得到更好的时间效率(减少了判断条件分支)
// 但是题目不保证上面的前提条件, 这就要求我们考虑很多繁琐的边界条件, 略
class Solution {
public:
	vector<vector<int>> imageSmoother( vector< vector<int> > & M ) {
		int row = M.size();
		int col = M[0].size();
		vector< vector<int> > ans(row, vector<int>(col, 0));

		
		for( int i = 1; i < row - 1; i++ ){
			for( int j = 1; j < col - 1; j++ ){
				ans[i][j] = ( M[i-1][j-1] + M[i-1][j] + M[i-1][j+1]
				          + M[i][j-1] + M[i][j] + M[i][j+1]
				          + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1] ) / 9;
			}
		}
		// upper without corner
		for( int j = 1; j < col - 1; j++ ){
			ans[0][j] = ( M[0][j-1] + M[0][j] + M[0][j+1]
			          + M[1][j-1] + M[1][j] + M[1][j+1] ) / 6;
		}


		// lower without corner
		for( int j = 1; j < col - 1; j++ ){
			ans[row-1][j] = ( M[row-2][j-1] + M[row-2][j] + M[row-2][j+1]
			          + M[row-1][j-1] + M[row-1][j] + M[row-1][j+1] ) / 6;
		}

		// left without corner
		for( int i = 1; i < row - 1; i++ ){
			ans[i][0] = ( M[i-1][0] + M[i-1][1]
			          + M[i][0] + M[i][1]
			          + M[i+1][0] + M[i+1][1] ) / 6;
		}

		// right without corner
		for( int i = 1; i < row - 1; i++ ){
			ans[i][col-1] = (M[i-1][col-2] + M[i-1][col-1]
			          + M[i][col-2] + M[i][col-1]
			          + M[i+1][col-2] + M[i+1][col-1] ) / 6;
		}

		ans[0][0] = ( M[0][0] + M[0][1] + M[1][0] + M[1][1] ) / 4;
		ans[0][col-1] = ( M[0][col-2] + M[0][col-1] + M[1][col-2] + M[1][col-1] ) / 4;
		ans[row-1][0] = ( M[row-2][0] + M[row-2][1] + M[row-1][0] + M[row-1][1] ) / 4;
		ans[row-1][col-1] = ( M[row-2][col-2] + M[row-2][col-1] + M[row-1][col-2] + M[row-1][col-1] ) / 4;

		return ans;
	}
};