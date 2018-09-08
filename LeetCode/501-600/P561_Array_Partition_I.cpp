/*
https://leetcode.com/problems/array-partition-i/description/
给定一个数组，两两分组，得到 <a[i], a[j]>, 求 max[ ∑ min(ai, aj) ]
同类题目 P561

思路，排序，i+2求和
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int arrayPairSum(vector<int> & nums){
		sort(nums.begin(), nums.end());
		int ans = 0;
		for(int i = 0; i < nums.size(); i += 2){
			ans += nums[i];
		}
		return ans;
	}
};