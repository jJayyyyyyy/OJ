/*
https://leetcode-cn.com/classic/problems/two-sum/description/
在遍历的过程中, 查找另一个数是否出现过

*/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

const static auto spd = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int size = nums.size();
		unordered_map<int, int> hash;
		vector<int> ans;
		for( int i = 0; i < size; i++ )
		{
			int val1 = nums[i];
			int val2 = target - val1;
			auto it = hash.find(val2);
			if( it != hash.end() )
			{
				ans = vector<int>{it->second, i};
			}
			else
			{
				hash[val1] = i;
			}
		}
		return ans;
	}
};
