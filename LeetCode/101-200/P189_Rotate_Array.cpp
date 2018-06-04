/*
 * https://leetcode.com/problems/rotate-array/description/
 * 对一个数组进行循环右移
 * 同类题目 P189, P61
 * 
 * TODO: 思考空间复杂度 O(1) 的算法
 * 
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> ans = nums;
		int len = nums.size();
		int cnt = len - k % len;
		for( int i = 0; i < len; i++ ){
			if( cnt == len ){
				cnt = 0;
			}
            ans[i] = nums[cnt++];
		}
		nums = ans;
	}
};
