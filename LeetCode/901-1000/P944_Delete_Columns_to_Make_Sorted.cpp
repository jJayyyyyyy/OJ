/*
https://leetcode.com/problems/delete-columns-to-make-sorted/description/
删除最少的列，使得剩下的列都是升序排列
同类题目 P894
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string> & A) {
		int row = A.size();
		int col = A[0].size();
		int cnt = 0;
		for( int j = 0; j < col; j++ ){
			for( int i = 1; i < row; i++ ){
				if( A[i][j] < A[i-1][j] ){
					cnt++;
					break;
				}
			}
		}
		return cnt;
	}
};
