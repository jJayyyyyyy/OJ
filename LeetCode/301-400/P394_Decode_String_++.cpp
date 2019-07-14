/*
https://leetcode.com/problems/decode-string/description/
左右括号匹配
同类题目 P394, PAT_A_1130

参考思路
https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C++-solution

*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
	int len;
	int i;

	string helper(const string & s)
	{
		string ans;
		while( i < len && s[i] != ']' )
		{
			if( isdigit(s[i]) == false )
			{
				ans += s[i];
				i++;
			}
			else
			{
				int dup = 0;
				while( i < len && isdigit(s[i]) )
				{
					dup = dup * 10 + s[i] - '0';
					i++;
				}

				i++;	// [
				string tmp = helper(s);
				i++;	// ]

				while( dup > 0 )
				{
					ans += tmp;
					dup--;
				}
			}
		}
		return ans;
	}

	string decodeString(string s)
	{
		len = s.size();
		i = 0;
		string ans = helper(s);
		return ans;
	}
};