/*
https://leetcode-cn.com/classic/problems/two-sum/description/
反转整数, 溢出则返回 0

*/

class Solution{
	public int reverse(int x) {
		String s = Integer.toString(x);
		// String s = String.valueOf(x);
		// int to String https://www.geeksforgeeks.org/different-ways-for-integer-to-string-conversions-in-java/
		// 效率对比, https://juejin.im/post/58f45d18a22b9d006cffdfcf
		if( s.charAt(0) == '-' ){
			StringBuilder sb = new StringBuilder( s.substring(1) );
			s = "-" + sb.reverse().toString();
		}
		else{
			StringBuilder sb = new StringBuilder( s );
			s = sb.reverse().toString();
		}
		long ans = Long.parseLong(s);
		if( ans < -0x7fffffff - 1 || ans > 0x7fffffff ){
			return 0;
		}
		else{
			return (int)ans;
		}
	}
}

public class Main{
	public static void main(String args[]) {
		Solution s = new Solution;
		int ans = s.reverse(-1563847412);
		System.out.println(ans);
	}
}