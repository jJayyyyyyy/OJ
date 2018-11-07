/*
https://leetcode.com/problems/flipping-an-image/description/
给定一个矩阵 A, 要求将其每一行 row 进行反转 invert, 然后
若 row[i] == 1, 则使 row[i] = 0
若 row[i] == 0, 则使 row[i] = 1
同类题目 P832
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector< vector<int> > flipAndInvertImage(vector< vector<int> > & A) {
		vector< vector<int> > ans;
		for( vector<int> row : A ){
			reverse(row.begin(), row.end());
			int len = row.size();
			for( int i = 0; i < len; i++ ){
				if( row[i] == 1 ){
					row[i] = 0;
				}else{
					row[i] = 1;
				}
			}
			ans.push_back(row);
		}
		return ans;
	}
};
