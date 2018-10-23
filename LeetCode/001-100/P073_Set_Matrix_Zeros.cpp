/*
https://leetcode.com/problems/set-matrix-zeroes/description/
给定一个矩阵 A, 如果某个元素 A[i][j] == 0, 则把第 i 行和第 j 列均置为 0
同类题目 P73

样例
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]


Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
注意, 若 A[x][y] != 0, 但是被其他元素如 A[i][j] 置零了, 那么 A[x][x] 不会引发连锁反应, 即不会将第 x 行和第 y 列置零


参考思路
https://leetcode.com/problems/set-matrix-zeroes/solution/

遍历矩阵,
对于第 0 列, 只记录其中有没有 0,
if( A[i][0] == 0 ){
	colZero = 0
}

而对于第一列及后面列向量
[0, 1] -> [0, n-1]
[1, 1] -> [1, n-1]
...
[m-1, 1] -> [m-1, n-1]

若 A[i][j] == 0, 则置 A[i][0] = A[0][j] = 0
这样, 我们就用 A[i][0] 记录了该行有没有 0, 用 A[0][j] 记录了该列有没有 0

设去掉第 0 行和第 0 列的矩阵为 B, 
遍历 B, 若 A[i][0] || A[0][j] == 0, 
则 A[i][j] = 0
这样就完成了 B 的置零

最后是判断第 0 行, 第 0 列 是否需要置零
分两种情况, A[0][0] 是否为 0

若 A[0][0] == 0, 则 A[0][0] 可能是被第 0 行其他元素置 0 的, 也有可能 A[0][0] 本身就是 0
总之, 原来的第 0 行肯定存在元素为 0, 因此要把第 0 行置 0

若 A[0][0] != 0, 由上面的分析可以知道, 第 0 行肯定没有 0, 所以剩下的任务就是判断第 0 列是否需要置零



再遍历矩阵的第 0 行和第 0 列, 若 A[i][0] == 0, 则将整行置零, 若 A[0][j] == 0, 则将整列置零
由于我们在第一次遍历的时候就记录了第 0 列是否存在 0, 并将结果保存在了 colZero,
所以 if( colZero == 1 ){ // set A[i][0] to 0; }

*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	void setZeroes(vector<vector<int> > & matrix) {
		int cntRow = matrix.size();
		if( cntRow == 0 ){
			return;
		}
		int cntCol = matrix[0].size();

		int colZero = 0;
		for( int i = 0; i < cntRow; i++ ){
			if( matrix[i][0] == 0 ){
				colZero = 1;
			}
			for( int j = 1; j < cntCol; j++ ){
				if( matrix[i][j] == 0 ){
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for( int i = 1; i < cntRow; i++ ){
			for( int j = 1; j < cntCol; j++ ){
				if( matrix[i][0] == 0 || matrix[0][j] == 0 ){
					matrix[i][j] = 0;
				}
			}
		}

		if( matrix[0][0] == 0 ){
			for( int j = 1; j < cntCol; j++ ){
				matrix[0][j] = 0;
			}
		}

		if( colZero == 1 ){
			for( int i = 0; i < cntRow; i++ ){
				matrix[i][0] = 0;
			}
		}
	}
};
