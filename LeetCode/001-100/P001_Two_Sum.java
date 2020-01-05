/*
https://leetcode.com/problems/two-sum/description/
输入:   一个数组 nums, 一个目标元素 target, 其中
        2 <= nums.length <= 10^4
        -10^9 <= nums[i] <= 10^9
        -10^9 <= target <= 10^9

输出:   一个数组 res[], 其中
        res.length == 2

要求:   数组 res[] 包含 2 个元素 {i, j}, 其中
        i != j, 且 nums[i] + nums[j] == target
        题目的输入 nums[] 可以保证存在这样的 i 和 j
        i, j 顺序可以随意

思路1:  双循环暴力搜索, T = O(n^2)
*/

import java.util.HashMap;

class Solution {
    public int[] twoSum_bruteForce(int[] nums, int target) {
        int[] res = new int[2];
        int length = nums.length;
        for ( int i = 0; i < length; i++ ) {
            for ( int j = i + 1; j < length; j++ ) {
                if ( nums[i] + nums[j] == target ) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};
