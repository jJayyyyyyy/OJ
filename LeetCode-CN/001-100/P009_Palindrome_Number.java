/*
https://leetcode.com/problems/palindrome-number/description/
给定一个整数, 判断它是不是回文数
先转为字符串, 然后对其reverse, 最后判断内容是否相同

*/

class Solution{
	public boolean isPalindrome(int x) {
		if( x < 0 ){
			return false;
		}
		else if( x == 0 ){
			return true;
		}
		else{
			String s1 = Integer.toString(x);
			StringBuilder sb = new StringBuilder(s1);
			String s2 = sb.reverse().toString();
			if( s1 == s2 ){
				return true;
			}
			else{
				return false;
			}
		}
	}
}

public class Main{
	public static void main(String args[]) {
		Solution s = new Solution();
		boolean ans = s.isPalindrome(121);
		System.out.println(ans);
	}
}