/*
https://leetcode.com/problems/missing-number/description/
一个无序数组, 包含了0到n的所有不同的数字, 且每个数字仅出现一次, 仅有一个数字是缺失的, 找出这个数字
同类题目 P268

思路:
将1~n相加, 有公式 sum1 = (1+n)n/2, 再将所有给进来的数字相加得到 sum2, 从而sum1 - sum2 就是缺失的数字
*/

#include <iostream>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();


class Solution {
public: 
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int sum1 = (1 + n) * n / 2;
		int sum2 = 0;
		for( int i = 0; i < n; i++ ){
			sum2 += nums[i];
		}
		return sum1 - sum2;
	}
};


