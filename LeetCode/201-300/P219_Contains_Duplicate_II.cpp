/*
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 * 判断数组中是否存在【临近的】重复元素
 * 同类题目 P217, P219
 * 
 * 首先判断是否存在重复元素, 再看重复元素的下标之差小于等于 k
 * 
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	bool containsDuplicate(vector<int>& nums){
		unordered_set<int> s;
		for( auto n : nums ){
			if( s.find(n) == s.end() ){
				s.insert(n);
			}else{
				return true;
			}
		}
		return false;
	}

	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if( containsDuplicate(nums) == false ){
			return false;
		}else{
			int len = nums.size();

			if( k >= len ){
				return true;
			}

			for( int i = 0; i < len; i++ ){
				for( int j = 1; j <= k; j++ ){
					if( i + j < len ){
						if( nums[i] == nums[i + j] ){
							return true;
						}
					}else{
						break;
					}
				}
			}
			return false;
		}
	}
};

