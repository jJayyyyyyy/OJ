/*
https://leetcode.com/problems/valid-palindrome-ii/description/
判断一个字符串是否为对称的字符串
本题允许删除最多一个字符，如果删除后得到的字符串还是对称的，那么认为原字符串也符合对称要求
如 abca 在本题条件下是合法的对称字符串
同类题目 P680, P167, P345

*/

#include <iostream>
#include <string>
using namespace std;

/*
参考思路
https://leetcode.com/problems/valid-palindrome-ii/solution/
*/
class Solution {
private:
    // 绝对回文
    bool isPalindrome(const string & s, int i, int j){
        while( i < j ){
            if( s[i] != s[j] ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    // 容忍一个字符的回文
    bool validPalindrome(string s) {
        int len = s.size();

        if( len <= 1 ){
            return true;
        }

        int i = 0, j = len - 1;
        while ( i < j ) {
            if ( s[i] != s[j] ) {
                return ( isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1) );
            }
            i++;
            j--;
        }
        return true;
    }
};
