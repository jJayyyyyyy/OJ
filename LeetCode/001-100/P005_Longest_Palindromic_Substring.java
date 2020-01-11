/*
https://leetcode.com/problems/longest-palindromic-substring/description/
找出最长回文子串
同类题目 P005, P647

参考思路
https://leetcode.com/problems/longest-palindromic-substring/solution/

从中间向外延伸, ExpandFromCenter
*/

class Solution {
    private int getPalindLength(String s, int left, int right, int rightBound) {
        // Expand from center
        while ( left >= 0 && right < rightBound ) {
            if ( s.charAt(left) != s.charAt(right) ) {
                break;
            }
            left--;
            right++;
        }
        int length = (right - 1) - (left + 1) + 1;
        return length;
    }

    public String longestPalindrome(String s) {
        String ans = "";
        int length = s.length();
        if ( length < 1 ) {
            return ans;
        }
        int maxLen = 0;
        int start = 0;

        for ( int i = 0; i < length; i++ ) {
            int lenOdd = getPalindLength(s, i, i, length);
            int lenEven = getPalindLength(s, i, i + 1, length);
            if ( lenOdd > lenEven ) {
                if ( lenOdd > maxLen ) {
                    maxLen = lenOdd;
                    start = i - lenOdd / 2;
                }
            }
            else {
                if ( lenEven > maxLen ) {
                    maxLen = lenEven;
                    start = i - lenEven / 2 + 1;
                }
            }
        }
        // String.substring(int startIndex, int endIndex)
        ans = s.substring(start, start + maxLen);
        return ans;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestPalindrome("cbbd"));    // bb
        System.out.println(s.longestPalindrome("ababa"));   // aba, bab
    }
}
