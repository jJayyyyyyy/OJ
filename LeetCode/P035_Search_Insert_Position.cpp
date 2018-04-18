/*
 * https://leetcode.com/problems/search-insert-position/description/
 * 将target插入有序序列
 *
*/

// #include <iostream>
// #include <vector>
// using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0;
		for( i = 0; i < nums.size(); i++ ){
			if( target <= nums[i] ){
				break;
			}
		}
		return i;
	}
};

// TODO
// 二分查找