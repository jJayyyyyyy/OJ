/*
https://leetcode.com/problems/zigzag-conversion/description/?goto=old

ZigZag Conversion
输入： "PAYPALISHIRING", numRows
输出： 先转换成如下的形式 (ZigZag)

P   A   H   N
A P L S I I G
Y   I   R

|  +  +  +
| /| /| /|
|/ |/ |/ |

然后逐行输出（不要空格）

同类题目 P006

思路： https://leetcode.com/problems/zigzag-conversion/solution/
寻找数学规律
一个完整的 zig-zag-cycle, 包含了 cycleLen = nR + nR - 2 = 2nR - 2 个字符
找到有多少个这样完整的 cycle
在这样的 cycle 中: 
r = 第 0 行的下标:      [(2nR - 2) * k] + 0
r = 第 nR - 1 行的下标: [(2nR - 2) * k] + nR - 1
r = 其他情况, r > 0 && r < numRows - 1
第 i 行的下标:      [(2nR - 2) * k] + r, 以及 [(2nR - 2) * (k - 1)] - r

综合一下就是, 在第 k 个 cycle
第 r 行都是在 ans 后面追加下标为 [(2nR-2) * k] + r 的字符
而在中间行, 即当 r > 0 && r < numRows - 1 时, 还要再追加下标为 [(2nR - 2) * (k - 1)] - r 的字符

得到这样的规律后即可逐行追加字符

*/

#include <iostream>
#include <string>
using namespace std;

// static const auto io_speed_up = []() {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// } ();

class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows <= 1 ) {
            // 只有 1 行, 也就没有 zigzag, 边界情况单独考虑
            return s;
        }
        int size = s.size();
        int cycleLen = 2 * numRows - 2;
        string ans = "";
        
        /*
        for ( int r = 0; r < numRows; r++ ) {
            for ( int ix = 0; ix < size; ix += cycleLen ) {
                // 第 0 行
                if ( r == 0 && ix + r < size ) {
                    ans += s[ix + r];
                }
                // 第 numRow - 1 行
                else if ( r == numRows - 1 && ix + r < size ) {
                    ans += s[ix + r];
                }
                // 中间行, r > 0 && r < numRows - 1
                else if ( r > 0 && r < numRows - 1 && ix + r < size ) {
                    ans += s[ix + r];
                    if ( ix + cycleLen - r < size ) {
                        ans += s[ix + cycleLen - r];
                    }
                }
            }
        }
        */

        // 上述过程可以合并简化
        for ( int r = 0; r < numRows; r++ ) {
            for ( int ix = 0; ix + r < size; ix += cycleLen ) {
                ans += s[ix + r];
                if ( r > 0 && r < numRows - 1 && ix + cycleLen - r < size ) {
                    ans += s[ix + cycleLen - r];
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    s.convert("PAYPALISHIRING", 3);
    return 0;
}