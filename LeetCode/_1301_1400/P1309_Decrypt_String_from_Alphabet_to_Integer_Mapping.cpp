/*
https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
输入：一个字符串 s，其中只包含字符 '0'~'9' 以及 '#'
过程：s代表了编码过后的字符串，编码之前的字符串只包含 'a'~'z'，编码规则为
     1. 字符 ('1' to '9') 分别代表 ('a' to 'i')
     2. 字符串 ('10#' to '26#') 分别代表 ('j' to 'z')
输出：将 s 解码为原字符串
同类题目 P1309

思路：
按照题意，遍历 s ，当遇到s[i] 为 '1' 或 '2' 时，查看 s[i+2]是否为 '#'，然后分别按照规则1和2进行解码
*/
#include <string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int size = s.size();
        string ans = "";
        for ( int i = 0; i < size; i++ )
        {
            // suppose that s is a correctly-encoded string and can be decoded
            char ch = s[i];
            if ( ch == '1' || ch == '2' )
            {
                if ( i + 2 < size && s[i + 2] == '#' )
                {
                    int num = (ch - '0') * 10 + (s[i + 1] - '0');
                    ch = 'a' + num - 1;
                    i += 2;
                }
                else
                {
                    int num = ch - '0';
                    ch = 'a' + num - 1;
                }
            }
            else
            {
                int num = ch - '0';
                ch = 'a' + num - 1;
            }
            ans += ch;
        }
        return ans;
    }
};