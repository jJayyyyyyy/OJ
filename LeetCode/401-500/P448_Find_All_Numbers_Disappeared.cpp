/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

同类题目 P448, 
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
