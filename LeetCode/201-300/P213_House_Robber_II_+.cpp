/*
https://leetcode.com/problems/house-robber-ii/description/
题目与 P198 类似, 不过这次换成了环状数组, 也就是第一个房子和最后一个房子相连, 因此把数组分为 [0, n-2], [1, n-1] 两个部分, 题目便转换成了 P198
因此我们按照 P198 的解法, 分别找出 ans1 = rob_house(0, n-1), ans2 = rob_house(1, n)
最后返回 max(ans1, ans2) 即可
同类题目
P213, P198
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums)
	{
		int len = nums.size();
		if( len == 0 )
		{
			return 0;
		}
		else if( len == 1 )
		{
			return nums[0];
		}
		else if( len == 2 )
		{
			return max( nums[0], nums[1] );
		}
		else
		{
			int ans1 = rob_house(nums, 0, len - 1, len - 1);
			int ans2 = rob_house(nums, 1, len, len - 1);
			return max(ans1, ans2);
		}
	}
	int rob_house(vector<int> & nums, int left, int right, int size)
	{
		vector<int> f(size, 0);
		f[0] = nums[left];
		f[1] = max( nums[left], nums[left + 1] );
		for( int i = 2; i < size; i++ )
		{
			f[i] = max( f[i - 2] + nums[left + i], f[i - 1] );
		}
		return f[size - 1];
	}
};
