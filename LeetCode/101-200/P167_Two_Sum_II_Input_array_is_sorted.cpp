/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?goto=old

双指针 同类题目 P167, P633, P345, P680, P088, P141, P524, P653

输入：数组 numbers[] 已排序（升序），target
过程：找 x, y，使得 x + y = target
输出：[i, j]，其中 i, j 分别是 x, y 的下标（从1开始），即 numbers[i-1] = x, numbers[j-1]=y
注：题目保证有且仅有一个答案

思路: 双指针左右夹逼

*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i = 0, j = len - 1;
        while ( i != j ) {
            int x = numbers[i];
            int y = numbers[j];
            int sum = x + y;
            if ( sum > target ) {
                j--;
            }
            else if ( sum < target ) {
                i++;
            }
            else {
                break;
            }
        }
        vector<int> ans = {i + 1, j + 1};
        return ans;
    }
};
