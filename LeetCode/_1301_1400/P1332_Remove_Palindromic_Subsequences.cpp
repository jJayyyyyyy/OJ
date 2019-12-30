/*
https://leetcode.com/problems/remove-palindromic-subsequences/
输入：一个字符串 s，里面只包含字符 'a' 或者 'b'
过程：每次从 s 中删除一个回文字符子序列，直到 s 为空，此时一共操作了 n 次
输出：操作次数 n，且 n 为最少需要操作的次数
注意：子序列(subsequence)不同于子串(substring)，前者可以不连续，后者要求连续
同类题目 P1332

参考思路：
分类讨论
1. 当 s 为空，那么 n => 0
2. 当 s 为回文串，那么 n => 1
3. 当 s 不是以上两种情况时，n不可能为0或者1，此时最小可能的值是2，且这是可以实现的，方法是，先删除所有的a，再删除所有的b，反之亦可，总次数为2。理由是，如果子序列中所有的字符都相同，那么不管子序列长度是奇数还是偶数，肯定是个回文串

https://leetcode.com/problems/remove-palindromic-subsequences/discuss/490352/Java-Use-the-Trick-%3A-the-input-string-only-consists-of-letters-'a'-and-'b'!!
http://cplusplus.com/reference/algorithm/reverse/?kw=reverse
*/
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if ( s == "" )
        {
            return 0;
        }
        string s1 = s;
        reverse( s1.begin(), s1.end());
        if ( s == s1 )
        {
            return 1;
        }
        
        return 2;
    }
};