/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?goto=old

双指针 同类题目 P167, P633, P345, P680, P088, P141, P524, P653

输入：target
过程：找 x, y，使得 x^2 + y^2 = target
输出：true / false, 是否存在这样的 x 和 y

思路: 双指针左右夹逼, 为了剪少搜索空间，右边指针可以从 sqrt(target) 向左靠拢

*/

#include <iostream>
#include <cmath>
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
    bool judgeSquareSum(int target) {
        // 使用long long避免int乘法溢出
        long long x = 0;
        long long y = (long long) sqrt(target);
        while ( x <= y ) {
            long long pow_sum = x * x + y * y;
            if ( pow_sum == target ) {
                return true;
            }
            else if ( pow_sum < target ) {
                x++;
            }
            else {
                y--;
            }
        }
        return false;
    }
};

