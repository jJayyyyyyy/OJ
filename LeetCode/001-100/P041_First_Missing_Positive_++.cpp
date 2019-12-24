/*
https://leetcode.com/problems/first-missing-positive/description/?goto=old

同类题目 P041

给一个无序整数数组，求出其中缺失的最小的正整数

参考思路
https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c++-solution-O(1)-space-and-O(n)-time


*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t n = nums.size();
        if ( n == 0 )
        {
            return 1;
        }
        // 对于 val = nums[i]，len = n
        // 如果 0 < val <= n 它应当存放的位置是 i = val - 1
        // 比如 2 应当存放在第 2 个位置，即其下标应当是 1 （下标从0开始）
        // 否则 val 原地不动
        // 以此完成第一次遍历
        // 第二次遍历的时候，找到第一个 i != val - 1 的位置，就是最小的缺失的正整数
        for ( int i = 0; i < n; i ++ )
        {
            int val = nums[i];
            while ( val > 0 && val <= n)
            {
                int real_i = val - 1;
                // int real_val = nums[real_i];
                // if ( val - 1 != i && real_val - 1 != real_i )
                // 可以合并成一步
                if ( nums[i] != nums[real_i]  )
                {
                    swap(nums[i], nums[real_i]);
                    val = nums[i];
                }
                else
                {
                    break;
                }
            }
        }

        for ( int i = 0; i < n; i++ )
        {
            if ( nums[i] - 1 != i )
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main()
{
    // [1, 2, 0] -> 3
    // [1] -> 2
    // [2] -> 1
    // [1, 2] -> 3
    // [-1] -> 1
    // [0, -1, 10] -> 1
    // [] -> 1
    // [1, 1] -> 2
    // [1, 3] -> 2
    // [3, 4, -1, 1] -> 2
    vector<int> vec = {3, 4, -1, 1};
    Solution s;
    cout << s.firstMissingPositive(vec);
    
    return 0;
}
