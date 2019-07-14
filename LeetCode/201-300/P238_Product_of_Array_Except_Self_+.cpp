/*
https://leetcode.com/problems/product-of-array-except-self/description/
给定一个数组 nums[], 返回一个数组 ans[], 要求 ans[i] = nums[] 所有元素的乘积(但不包含 nums[i])
比如 nums.size() == 4, 则
ans[0] = nums[1] * nums[2] * nums[3]

同类题目 P238

解题思路:
https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space

首先用 ans[i] 记录 nums[0] ~ nums[i-1] 的乘积, i = [1, n-1]
此时 nums[n-1] 还未被记录
此时完成从左向右的记录
注意此时 ans[i] 不包含 nums[i]

然后用临时变量 tmp = 1
结合 ans 进行从右向左的记录, i = [n-1, 0]
更新 ans[]

ans[i] *= tmp;
tmp *= nums[i];

额外的空间复杂度 O(1),
时间复杂度 O(2n)
*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> ans(len);
		ans[0] = 1;
		for( int i = 1; i < len; i++ ){
			ans[i] = ans[i-1] * nums[i-1];
		}

		int tmp = 1;

		for( int i = len - 1; i >= 0; i--){
			ans[i] *= tmp;
			tmp *= nums[i];
		}
		return ans;
	}
};