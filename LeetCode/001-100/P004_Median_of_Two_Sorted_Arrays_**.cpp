/*
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
输入两个升序数组, 找出中位数

最直接的方法是合并数组, 排序, 找中位数

不过题目还有一个附加要求, 就是时间复杂度为 O( log(m, n) )

题解比较复杂, 可以参考这里
https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
*/

#include <iostream>
#include <vector>
#include <algorithm>

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		nums1.insert(nums1.end() + 1, nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());
		int m = nums1.size();
		int n = nums2.size();
		int sum = m + n;
		int mid = sum / 2;
		double ans = 0;
		if( sum % 2 == 0 )
		{
			ans = (nums1[mid-1] + nums1[mid]) / 2.0;
		}
		else
		{
			ans = nums1[mid];
		}
		return ans;
	}
};
