/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
含有n个整数的数组，每个元素的值取值范围是 [1, n]，有的数可能重复，有的数可能缺失。找出缺失的数
同类题目 P448, 

附加要求: 时间复杂度 O(n), 空间复杂度 O(1)


思路: 一个整数其实包含了两个信息，一个是值，一个是【符号】
题目限定了【原始数组 1<= nums[i] <= m】，
所以后者可以用作 标记符，而不会和原来的值混淆，用于判断该元素是否被访问过
一个数组，可用的信息也有两个，元素的值，元素的【下标】


首先遍历数组，记 m = abs(nums[i]) - 1
找到以 m 为下标的元素

如果 nums[m] > 0 (还未被标记)，则在它前面加个负号
如果 nums[m] <= 0, 说明下标为 [m] 的数已经被标记(访问)，那么就略过

这样一遍循环过后，数组中符合题目要求的数都变成了 <= 0 的值
对数组再进行一次遍历，找到那些 > 0 的数，它的下标就是 未出现过的数
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
