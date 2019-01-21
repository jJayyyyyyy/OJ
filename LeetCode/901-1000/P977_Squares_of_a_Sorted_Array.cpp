/*
https://leetcode.com/problems/squares-of-a-sorted-array/description/
给定数组, 取每个元素的平方, 然后从小到大排序

同类题目 P977
*/

#include <iostream>
#include <vector>
#include <algoritm>
#include <cmath>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	vector<int> sortedSquares(vector<int> & A) {
		int len = A.size();
		for( int i = 0; i < len; i++ ){
			A[i] *= A[i];
		}
		sort(A.begin(), A.end());
		return A;
	}
};