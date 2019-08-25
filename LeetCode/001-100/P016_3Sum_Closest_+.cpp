/*
https://leetcode.com/problems/3sum-closest/description/?goto=old

同类题目 P16

参考思路
https://leetcode.com/problems/3sum-closest/discuss/7883/C++-solution-O(n2)-using-sort
先从小到大排序
然后用三个指针 first=0, second=first+1, third=len-1
计 curSum = nums[first] + nums[second] + nums[third]
如果 curSum < target, 就把 second 往后挪
如果 curSum > target, 就把 third 往前挪
如果 curSum == target, 那就返回 curSum (题目保证答案唯一)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		if (len < 3) {
			return -1;
		}

		int ansSum = nums[0] + nums[1] + nums[2];
		if (ansSum == target) {
			return ansSum;
		}

		sort(nums.begin(), nums.end());
		for (int first = 0; first < len - 2; first++) {
			int second = first + 1;
			int third = len - 1;
			while (second < third) {
				int curSum = nums[first] + nums[second] + nums[third];
				if (curSum == target) {
					return curSum;
				}

				if (abs(target - curSum) < abs(target - ansSum)) {
					ansSum = curSum;
				}
				if (curSum > target) {
					third--;
				}
				else {
					second++;
				}
			}
		}
		return ansSum;
	}
};