/*
https://leetcode.com/problems/transpose-matrix/description/
矩阵转置
同类题目 P867
*/

#include <iostream>
using namespace std;

const static auto c = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
	vector<vector<int> > transpose(vector<vector<int> > & A) {
		int rowA = A.size();
		int colA = A[0].size();
		vector< vector<int> > ans(colA, vector<int>(rowA));
		for( int i = 0; i < rowA; i++ ){
			for( int j = 0; j < colA; j++ ){
				ans[j][i] = A[i][j];
			}
		}
		return ans;
	}
};
