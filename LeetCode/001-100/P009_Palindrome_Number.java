/*
https://leetcode.com/problems/palindrome-number/description/
给定一个整数, 判断它是不是回文数
先转为字符串, 然后对其reverse, 最后判断内容是否相同

输入参数 x 的范围
-2^31 <= x <= 2^31 - 1
如果使用 reverse 数字的方法, 可能会出现溢出 (参考 P007 ), 需要用 long 来存 reverse 之后的数字

*/

class Solution {
    public boolean isPalindrome(int x) {
        if ( x < 0 ) {
            return false;
        }
        long a = x;
        long b = 0;
        while ( x > 0 ) {
            b = b * 10 + x % 10;
            x /= 10;
        }
        return a == b;
    }

    public boolean isPalindrome2(int x) {
        if ( x < 0 ) {
            return false;
        }
        String s = Integer.toString(x);
        int left = 0, right = s.length() - 1;
        while ( left < right ) {
            if ( s.charAt(left) != s.charAt(right) ) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public boolean isPalindrome1(int x) {
        if ( x < 0 ) {
            return false;
        }
        String s1 = Integer.toString(x);
        String s2 = new StringBuilder(s1).reverse().toString();
        return s1.equals(s2);
    }
}