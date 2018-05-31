/*
 * https://leetcode.com/problems/majority-element/description/
 * 给定一个数组 nums, 返回其中出现次数最多的元素 majority element. 题目保证 majority element 出现次数超过 n/2 次, 题目保证 nums 不为空
 * 同类题目 P169
 * 
 * 
 * 思路1: 对数组排序, 下标为 n/2 的元素即为 majority element (因为题目保证 majority element 出现次数超过 n/2 次)
 * 时间复杂度 O(nlgn)
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size()/2];
	}
};