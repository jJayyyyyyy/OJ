/*
https://leetcode.com/problems/4sum-ii/description/
给定四个长度相同的数组 A, B, C, D
对于任意的 a∈A, b∈B, c∈C, d∈D
统计有多少种 (a, b, c, d) 的组合, 使得 a+b+c+d == 0
同类题目: P454, P018, P015

最基本的想法是四重循环
但是这种算法的时间复杂度是 O(N^4), 原因之一进行了很多重复计算
比如 A[0] + B[0] 就会在 C 和 D 的循环中重复计算 N^2 次

我们对此进行优化, 可以将时间复杂度降至 O(N^2)
参考答案
https://leetcode.com/problems/4sum-ii/discuss/93925/Concise-C++-11-code-beat-99.5

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> m;
		for( int a : A ){
			for( int b : B ){
				int sum = a + b;
				++m[sum];
			}
		}

		int ans = 0;
		for( int c : C ){
			for( int d : D ){
				int negsum = -(c + d);
				if( m.find(negsum) != m.end() ){
					ans += m[negsum];
				}
			}
		}
		return ans;
	}
};