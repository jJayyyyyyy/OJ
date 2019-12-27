/*
https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
输入：一个数组 position=[...]，长度为 n+1，其中 position[i] 代表了第i个硬币所在的位置，1 <= position[i] <= n
过程：将所有硬币移动到一起。注意，硬币每次只能移动1个单位距离（成本为1）或者2个单位距离（成本为0）。
输出：将所有硬币移动到一起所需的最小成本
同类题目 P1217

参考思路：
https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/solution/
由于硬币每次只能移动1个单位距离或者2个单位距离，且移动两个单位距离的时候成本为0，又因为题目要求最小成本，所以，我们可以先把所有在奇数位置的硬币移动到位置1上，把所有在偶数位置的硬币移动到位置2上，这样移动过后，成本仍然为0，而此时所有硬币的最大间隔是1个单位距离，因此最小成本就是把两堆硬币中数量较少的一堆移动到数量讲多的一堆所需要的成本。

*/

#include <vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int> & position)
    {
        int ans = 0;
        int cnt1 = 0, cnt2 = 0;
        for ( int pos : position )
        {
            if ( pos % 2 == 1 )
            {
                cnt1 ++;
            }
            else
            {
                cnt2 ++;
            }
        }
        ans = min(cnt1, cnt2);
        return ans;
    }
};