/*
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 * 给定一个有序数组 numbers, 以及一个目标值 target, 问 numbers 里面的某两个元素之和能否等于 target
 * 同类题目 P167
 * 
 * 
 * 思路: 左右夹逼
 * 注意, 题目的测试输入保证有 Solution
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
	// assume that each input has an answer, not null
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left=0, right=numbers.size()-1;
		while( true ){
			int temp = numbers[left] + numbers[right];
			if( temp == target ){
				break;
			}else if( temp < target ){
				left++;
			}else{
				right--;
			}
		}

		vector<int> ans;
		ans.push_back(left+1);
		ans.push_back(right+1);
		return ans;
	}
};
