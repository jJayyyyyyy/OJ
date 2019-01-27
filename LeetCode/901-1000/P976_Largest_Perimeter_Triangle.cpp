/*
https://leetcode.com/problems/largest-perimeter-triangle/description/
给定一个数组, 判断其能否组成三角形(面积大于 0)
若能, 则输出三角形最大可能的周长
若不能组成三角形, 则输出 0

同类题目 P976

思路:
先从大到小排序
然后利用三角形两边之和大于第三边的特性, 对排序后的数组进行遍历和判断
*/

#include <iostream>
#include <vector>
#include <algoritm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end(), greater<int>());
		int len = A.size();
		
		for( int i = 2; i < len; i++ ){
			int a = A[i - 2];
			int b = A[i - 1];
			int c = A[i];
			if( c + b > a ){
				return a + b + c;
			}
		}
		return 0;
	}
};