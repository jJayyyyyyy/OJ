/*
https://leetcode.com/problems/palindrome-number/description/
给定一个整数, 判断它是不是回文数
先转为字符串, 然后对其reverse, 最后判断内容是否相同

输入参数 x 的范围
-2^31 <= x <= 2^31 - 1
如果使用 reverse 数字的方法, 可能会出现溢出 (参考 P007 ), 需要用 long long 来存 reverse 之后的数字
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool isPalindrome(int x) {
        if ( x < 0 ) {
            return false;
        }

        long long a = x;
        long long b = 0;
        while ( x > 0 ) {
            b = b * 10 + x % 10;
            x /= 10;
        }
        return a == b;
    }

    bool isPalindrome1(int x) {
        if ( x < 0 ) {
            return false;
        }
        string s = to_string(x);
        int left = 0, right = s.size() - 1;
        while ( left < right ) {
            if ( s[left] != s[right] ) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindromeBF1(int x) {
        if ( x < 0 ) {
            return false;
        }

        string s1 = to_string(x);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }

    bool isPalindromeBF2(int x) {
        if ( x < 0 ) {
            return false;
        }

        string s1, s2;
        stringstream ss;
        ss << x;
        ss >> s1;
        s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};


int main(){
    Solution s;
    cout<<s.isPalindrome(1)<<'\n';
    cout<<s.isPalindrome(121)<<'\n';
    cout<<s.isPalindrome(2147483647)<<'\n';

    return 0;
}
