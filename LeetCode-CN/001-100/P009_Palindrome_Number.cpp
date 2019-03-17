/*
https://leetcode-cn.com/classic/problems/two-sum/description/
在遍历的过程中, 查找另一个数是否出现过

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