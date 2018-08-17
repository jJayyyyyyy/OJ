/*
https://leetcode.com/problems/assign-cookies/description/
排序问题
同类题目: P455

父母给孩子分饼干, 每个孩子要么得到一块饼干, 要么没有饼干
一共有 g.size() 个孩子, 每个孩子都有一个最低需求度 g[i], 
一共有 s.size() 块饼干, 每块饼干大小是 s[j]
只有当 s[j] >= g[i] 的时候, 孩子才会吃饱
问最多能让几个孩子吃饱


思路: 对 g, s 排序, 然后双指针前进

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int len = nums.size();
		for(int i=0; i<len; i++) {
			int m = abs(nums[i])-1; // index start from 0
			nums[m] = nums[m]>0 ? -nums[m] : nums[m];
		}
		vector<int> res;
		for(int i = 0; i<len; i++) {
			if(nums[i] > 0) res.push_back(i+1);
		}
		return res;
	}
};
