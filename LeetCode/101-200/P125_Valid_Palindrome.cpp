/*
https://leetcode.com/problems/valid-palindrome/description/?goto=old
判断给定字符串是否为回文字符串(仅考虑alphanumeric，且忽略大小写)
同类题目 P125, P680

思路: 先对输入的字符串进行过滤
构造新的字符串, 只留下原字符串中的 alphanum, 并且统一变成小写
再检查新的字符串是否回文
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// io加速
static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
} ();

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if( len <= 1 ){
            return true;
        }

        int i = 0, j = len - 1;
        char ch1, ch2;
        while ( i < j ) {
            while ( i < j ) {
                ch1 = s[i];
                if ( isalpha(ch1) || isdigit(ch1) ){
                    break;
                }
                else {
                    i++;
                }
            }
            while ( i < j ) {
                ch2 = s[j];
                if ( isalpha(ch2) || isdigit(ch2) ) {
                    break;
                }
                else {
                    j--;
                }
            }

            if ( i < j && tolower(ch1) != tolower(ch2) ) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};

int main(){
    Solution s;

    string s1 = "A man, a plan, a canal: Panama";
    cout<<s.isPalindrome(s1)<<'\n';  // 1

    string s2 = "race a car";
    cout<<s.isPalindrome(s2)<<'\n';  // 0

    return 0;
}