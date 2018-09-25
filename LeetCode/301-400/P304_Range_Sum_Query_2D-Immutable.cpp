/*
https://leetcode.com/problems/range-sum-query-2d-immutable/description/
矩阵区域求和
同类题目 P303, P304, P307

注意:
本题可以假设矩阵不会改变，可以假设 (row1, col1) 和 (row2, col2) 不会超出矩阵下标范围
一组测试中会多次调用 sumRange(), 因此需要一个数组存储 从 0 到 cur 的和 curSum[j+1]，这样可以直接用 curSum[j+1] - curSum[i] 来获得答案，而不是每次重新累加

思路同 303，不过这次从 1D 的数组换成了 2D 的矩阵
注意使 每一行的第一个元素为 0，只缓存每一行的累加和(Caching Rows), 因为 curSum[i][col2+1] - curSum[i][col1] 会把 curSum[i][col1] 之前重叠的部分全都去掉，所以没必要存储上一行的数据

参考:
https://leetcode.com/problems/range-sum-query-2d-immutable/solution/

*/

#include <vector>
#include <iostream>
using namespace std;

static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class NumMatrix{
private:
	vector< vector<int> > curSum;
	int colsize, rowsize;
public:
	NumMatrix(vector< vector <int> > matrix){
		rowsize = matrix.size();
		if( rowsize > 0 ){
			colsize = matrix[0].size();
			curSum.resize(rowsize, vector<int>(colsize+1, 0));		// 1. 重新调整大小，并让每个元素为0，2. 每一行的第一个元素为 0，只缓存每一行的累加和(Caching Rows)

			curSum[0][0] = 0;
			for( int i = 0; i < rowsize; i++ ){
				for( int j = 0; j < colsize; j++ ){
					curSum[i][j+1] = curSum[i][j] + matrix[i][j];	// 局部性
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2){
		int sum = 0;
		for( int i = row1; i <= row2; i++ ){
			sum += curSum[i][col2+1] - curSum[i][col1];
		}
		return sum;
	}
};

int main(int argc, char *argv[]){
	// test case 1
	// vector< vector<int> > matrix;
	// matrix.resize(1, vector<int>(2, 0));
	// matrix[0][0] = -4;
	// matrix[0][1] = -5;
	
	// NumMatrix nm(matrix);

	// cout<<nm.sumRegion(0, 0, 0, 0)<<'\n';
	// cout<<nm.sumRegion(0, 0, 0, 1)<<'\n';
	// cout<<nm.sumRegion(0, 1, 0, 1)<<'\n';


	// test case 2
	vector< vector<int> > matrix;
	matrix.resize(2, vector<int>(1, 0));
	matrix[0][0] = 1;
	matrix[1][0] = -7;
	
	NumMatrix nm(matrix);

	cout<<nm.sumRegion(0, 0, 0, 0)<<'\n';
	cout<<nm.sumRegion(1, 0, 1, 0)<<'\n';
	cout<<nm.sumRegion(0, 0, 1, 0)<<'\n';

	return 0;
}

