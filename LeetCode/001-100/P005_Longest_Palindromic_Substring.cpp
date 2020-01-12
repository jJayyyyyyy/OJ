/*
https://leetcode.com/problems/longest-palindromic-substring/description/
找出最长回文子串
同类题目 P005, P647

参考思路
https://leetcode.com/problems/longest-palindromic-substring/solution/

从中间向外延伸, expandFromCenter
*/


#include <iostream>
#include <string>

class Solution {
public:
    int getPalindLength( const string & s, int left, int right, int rightBound ) {
        // Expand from center
        while ( left >= 0 && right < rightBound ) {
            if( s[left] != s[right] ){
                break;
            }
            left--;
            right++;
        }
        int length = (right - 1) - (left + 1) + 1;
        return length;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int size = s.size();
        if ( size < 1 ) {
            return ans;
        }
        int maxlen = 0;
        int start = 0;
    
        for ( int i = 0; i < size; i++ ) {
            int lenOdd = getPalindLength(s, i, i, size);
            int lenEven = getPalindLength(s, i, i + 1, size);
            if ( lenOdd > lenEven ) {
                if( lenOdd > maxlen ) {
                    maxlen = lenOdd;
                    start = i - lenOdd / 2;
                }
            }
            else {
                if( lenEven > maxlen ) {
                    maxlen = lenEven;
                    start = i - lenEven / 2 + 1;
                }
            }
        }
        ans = s.substr(start, maxlen);

        return ans;
    }
};


int main(){
    Solution s;
    s.longestPalindrome("cbbd");    // bb
    s.longestPalindrome("ababa");   // aba, bab
    return 0;
}
