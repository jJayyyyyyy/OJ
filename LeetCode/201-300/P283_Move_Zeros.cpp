/*
https://leetcode.com/problems/move-zeroes/description/
给定一个数组，把所有非0元素移到0前面，同时不改变非0元素之间的相对顺序
同类题目 P283

参考：
https://leetcode.com/problems/move-zeroes/discuss/72005/My-simple-C++-solution

关键：move all the nonzero elements advance, 0元素的相对顺序不用管
*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance, 关键
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};


