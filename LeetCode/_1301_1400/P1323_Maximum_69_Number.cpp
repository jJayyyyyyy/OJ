/*
https://leetcode.com/problems/maximum-69-number/
输入：一个数字 num，数字中只包含 6 或 9
过程：最多替换一个数字（只能将6变成9或者9变成6）得到 ans，要求ans是所有结果中最大的数
输出：（替换后）最大的数字
同类题目 P1323

思路：
将第一个 6 替换为 9

http://www.cplusplus.com/reference/string/string/replace/
*/
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for ( int i = 0; i < s.size(); i++ )
        {
            char digit = s[i];
            if ( digit == '6' )
            {
                s.replace(i, 1, "9");
                break;
            }
        }
        return stoi(s);
    }
};