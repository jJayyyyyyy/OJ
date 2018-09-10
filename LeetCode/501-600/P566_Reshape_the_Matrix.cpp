/*
https://leetcode.com/problems/reshape-the-matrix/description/
调整矩阵nums, 生成新的矩阵ans, 
同类题目 P561

思路，排序，i+2求和
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector< vector<int> > matrixReshape(vector< vector<int> > & nums, int r, int c) {
		if( nums.size() == 0 ){
			return nums;
		}

		int oriRow = nums.size();
		int oriCol = nums[0].size();
		if( oriRow * oriCol != r * c ){
			return nums;
		}

		vector< vector<int> > ans;
		vector<int> line;
		int cnt = 0;
		for( int i = 0; i < oriRow; i++ ){
			for( int j = 0; j < oriCol; j++ ){
				line.push_back(nums[i][j]);
				cnt++;

				if( cnt == c ){
					ans.push_back(line);
					line.clear();
					cnt = 0;
				}
			}
		}

		return ans;
	}
};
