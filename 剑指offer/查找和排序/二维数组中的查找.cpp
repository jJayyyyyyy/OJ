/*
https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?answerType=1&f=discussion

二维有序数组中的查找

输入：二维数组 arr (且 arr 每一列都是自上而下递增, 每一行都是从左到右递增), 目标值 target
过程：在 arr 中查找 target
输出：若找到 target 则返回 true, 否则返回 false

思路:
https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?answerType=1&f=discussion

假设 arr 如下
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7

1. 从最左下方开始查找, val = arr[3][3] 是这一行中最小的, 也是这一列中最大的, i = 3, j = 0
2. 如果 val > target, 那么 target 如果存在于 arr, 则一定在 val 的【上面】，不可能在 【左边/右边/下面】, 因此进行 i-- 后继续查找
3. 如果 val < target, 那么 target 如果存在, 则一定在 val 【右边】, 不可能在 【上面/下面/左边】, 因此进行 j++ 后继续查找
4. 重复 1-3 直到找到 target 或者 i, j 超出边界

时间复杂度: O(nrow + ncol)
空间复杂度: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// io加速
static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

class Solution {
public:
    bool Find(int target, vector<vector<int> > arr) {
        int nrow = arr.size();
        if ( nrow == 0 ) {
            return false;
        }
        int ncol = arr[0].size();
        if ( ncol == 0 ) {
            return false;
        }

        int i = nrow - 1;
        int j = 0;
        while ( i >= 0 && j < ncol ) {
            int val = arr[i][j];
            if ( val > target ) {
                i--;
            }
            else if ( val < target ) {
                j++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};


int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    Solution s;
    s.Find(arr, 7);
    s.Find(arr, 0);
    return 0;
}