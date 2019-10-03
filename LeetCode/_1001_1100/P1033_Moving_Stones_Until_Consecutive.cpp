/*
https://leetcode.com/problems/moving-stones-until-consecutive/description/?goto=old

题目保证 a, b, c 互不相等

同类题目 P1033

思路：

https://leetcode.com/problems/moving-stones-until-consecutive/discuss/282836/C++Java-4-lines

先从小到大排序, 然后分类讨论

Scenario1: x+2 == z
此时已经 consecutive 不用移动， min = max = 0

Scenario2: x+1 == y, y < z-1, 或者 x+1 < y, y == z - 1,
也就是说， 如果 xy 相邻或者 yz 相邻， 
此时只要把 z 挪到 y+1，或者把 x 挪到 y-1 即可，min=1
而 max = z-x-2 ，即 x, z 之间去掉 y 之后有多少个 position

Scenario3: x+2 == y, 或者 y+2 == z
此时只要把 z 挪到 x y 之间，或者把 x 挪到 y z 之间即可，min = 1
而 max = z-x-2

Scenario4: 其他情况
此时 min = 2, 因为只要把 y 先挪到 x+1, 再把 z 挪到 y+1 即可
而 max = z-x-2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// static const auto io_speed_up = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// } ();

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int z = max(a, max(b, c));
        int x = min(a, min(b, c));
        int y = a + b + c - x - z;
        cout << x << y << z;
        if ( x + 2 == z ) {
            return {0, 0};
        }
        else if ( y - x <= 2 || z - y <= 2 ) {
            return {1, z-x-2};
        }
        else {
            return {2, z-x-2};
        }
    }
};

int main(){
    Solution s;
    s.numMovesStones(7, 4, 1);
    return 0;
}