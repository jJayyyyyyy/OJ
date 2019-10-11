/*
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?goto=old

同类题目 P1351

一个矩阵，每行和每列的数都是非增的，找出矩阵中负数的个数

思路
二分查找

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510217/C++-Three-Methods
http://www.cplusplus.com/reference/algorithm/upper_bound/

*/

#include <iostream>
#include <vector>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
};

class Solution {
public:
    int countNegatives(vector<vector<int> > & grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        if ( grid[0][0] < 0 ) {
            return nRow * nCol;
        }

        int res = 0;
        for ( vector<int> & row : grid ) {
            // 当想不起如何写 comp 时，可以用 rbegin(), rend() 巧妙替代
            res += lower_bound(row.rbegin(), row.rend(), 0) - row.rbegin();
        }
        return res;
    }
};
