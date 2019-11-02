/*
https://leetcode.com/problems/non-overlapping-intervals/description/?goto=old

贪心，求不重叠区间 同类题目 P435

输入：二维数组 intervals
过程：计算最少需要移除的区间ans，使得剩下的区间不会重叠
输出：ans

思路:
https://cyc2018.github.io/CS-Notes/#/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E8%B4%AA%E5%BF%83%E6%80%9D%E6%83%B3

遇到"最少"问题，有时候可以转换成"总数-最多"问题

题目要求最少移除的区间数，因为区间总数 intervals.size() 是固定的，那么换个思路，可以先求出最多能组成多少个没有交集的区间 cnt，那么 ans = intervals.size() - cnt

在每次选择中，区间的结尾最为重要，选择的区间结尾越小，留给后面的区间的空间越大，那么后面能够选择的区间个数也就越大。

0. 先对区间按照区间右边界由小到大排序
   左边界不用管，如果右边界相同，最终只保留一个即可，如下
   1:  [   ]  [     ]
   2:           [   ]
   ->: [   ]  [     ] 可以
   ->: [   ]    [   ] 也可以，因为影响后面i区间的只有i-1的右边界
                  [    ]   i左边界在i-1右边界之前，那就会有重叠


1. 先记录最小的区间的右边界 pre_right = itv[0][1]，计数置1
2. 然后逐个比较后面的区间 itv[i], 如果和前一个区间有重叠(itv[i][0] < pre_right, 其中 pre_right = itv[i-1][1]), 则抛弃 itv[i];
3. 反之, 如果没有重叠, 则更新 pre_right, 并且计数+1
4. 最后得到 ans = intervals.size() - cnt

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
private:
    static bool cmp(vector<int> & a, vector<int> & b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if ( len <= 1 ) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);

        int pre_right = intervals[0][1];
        int cnt = 1;
        for ( int i = 1; i < len; i++ ) {
            int now_left = intervals[i][0];
            if ( now_left < pre_right ) {
                // overlap
                continue;
            }
            else {
                // update pre_right
                pre_right = intervals[i][1];
                cnt++;
            }
        }
        return len - cnt;
    }
};

int main() {
    Solution s;
    vector<vector<int> > intervals = {{1, 2}, {1, 2}, {1, 2}};
    s.eraseOverlapIntervals(intervals);
    vector<vector<int> > intervals2 = {{1, 2}, {1, 3}, {2, 4}};
    s.eraseOverlapIntervals(intervals2);
    return 0;
}
