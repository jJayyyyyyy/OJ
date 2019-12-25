/*
https://leetcode.com/problems/split-a-string-in-balanced-strings/
输入：一个字符串 s，其中只包含字符 L 或者 R，且两者的数量相同（这样的s被称为平衡的字符串）
过程：将 s 分成 n 个子串（顺序不变，且连续），要求每个子串中 L 和 R 的数量相同
输出：n的最大值，即求 s 最多可以分成多少个平衡的子串
同类题目 P1221

思路：从示例可知，分割只能连续进行，不能从这里切一段然后拼到另一段上。此外，由于题目要求n的最大值，所以要尽量把字符串切成小段，使总的数量最大。
因此，基本思路就是，设置两个计数器，分别统计L和R，当两者非零且相等时，ans++，并且清空计数器并重新开始计数。

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cntL = 0, cntR = 0;
        int ans = 0;
        for ( char ch : s )
        {
            if ( ch == 'L' )
            {
                cntL++;
            }
            else if ( ch == 'R' )
            {
                cntR++;
            }
            
            if ( cntL == cntR && cntL != 0 )
            {
                ans++;
                cntL = 0;
                cntR = 0;
            }
        }
        return ans;
    }
};