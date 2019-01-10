/*
https://leetcode.com/problems/4sum/description/
从一个数组中选4个数, 使这 4 个数的和等于 target
问有多少种不同的组合

注解
[-3,0,1,2], [-3,0,1,2] 应该归为同一条记录, 因为不考虑集合内部的顺序

参考思路
https://leetcode.com/problems/4sum/discuss/8714/4Sum-C++-solution-with-explanation-and-comparison-with-3Sum-problem.-Easy-to-understand.

同类题目: P018, P015, P454
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<vector<int>> ans;
		if( len >= 4 ){
			sort(nums.begin(), nums.end());
			for( int i = 0; i < len; i++ ){
				int a = nums[i];
				int target_3 = target - a;

				for( int j = i + 1; j < len; j++ ){
					int b = nums[j];
					int target_2 = target_3 - b;

					int left = j + 1;
					int right = len - 1;
					while( left < right ){
						int two_sum = nums[left] + nums[right];
						if( two_sum < target_2 ){
							left++;
						}else if( two_sum > target_2 ){
							right--;
						}else{
							int c = nums[left];
							int d = nums[right];
							vector<int> record(4);
							record[0] = a;
							record[1] = b;
							record[2] = c;
							record[3] = d;
							ans.push_back(record);

							// skip duplicated left
							while( left < right && nums[left] == c ){
								left++;
							}

							// skip duplicated right
							while( left < right && nums[right] == d ){
								right--;
							}
						}
					}
					// skip duplicated j
					while( j + 1 < len && nums[j + 1] == b ){
						j++;
					}
				}
				// skip duplicated i
				while( i + 1 < len && nums[i + 1] == a ){
					i++;
				}
			}
		}
		
		return ans;
	}
};


int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	Solution s;
	vector<int> v(6);
	v[0] = 1;
	v[1] = 0;
	v[2] = -1;
	v[3] = 0;
	v[4] = -2;
	v[5] = 2;
	s.fourSum(v, 0);

	return 0;
}

