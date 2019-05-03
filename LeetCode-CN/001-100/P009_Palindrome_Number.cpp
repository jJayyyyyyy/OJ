/*
https://leetcode.com/problems/palindrome-number/description/
给定一个整数, 判断它是不是回文数
先转为字符串, 然后对其reverse, 最后判断内容是否相同

*/

#include <iostream>
#include <string>
#include <sstring>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if( x < 0 )
		{
			return false;
		}
		else if( x == 0 )
		{
			return true;
		}
		else
		{
			string s1, s2;
			stringstream ss;
			ss << x;
			ss >> s1;
			s2 = s1;
			reverse(s2.begin(), s2.end());
			return s1 == s2;
		}
	}
};