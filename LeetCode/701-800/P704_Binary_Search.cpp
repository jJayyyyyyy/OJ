/*
https://leetcode.com/problems/design-hashmap/description/
实现二分查找
同类题目 P704

TODO:
学习 STL 中 bsearch, upper_bound 等函数的实现
/usr/include/c++/4.8.4/bits/stl_algo.h
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int search(vector<int> & nums, int target) {
		int len = nums.size();
		int left = 0, right = len-1;
		while( left <= right ){
			int mid = (left + right) / 2;
			int midVal = nums[mid];
			if( target < midVal ){
				right = mid - 1;
			}else if( target > midVal ){
				left = mid + 1;
			}else{
				return mid;
			}
		}

		return -1;
	}
};