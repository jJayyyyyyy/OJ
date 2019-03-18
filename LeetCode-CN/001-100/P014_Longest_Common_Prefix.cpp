/*
https://leetcode.com/problems/longest-common-prefix/description/
https://leetcode-cn.com/classic/problems/longest-common-prefix/description/
给定一个数组, 元素都是字符串
找出最长的公共前缀, 若为空则返回""
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> & strs) {
		int len_strs = strs.size();
		if( len_strs == 0 )
		{
			return "";
		}
		else if( len_strs == 1 )
		{
			return strs[0];
		}
		else
		{
			int len_prefix = 0x3fffffff;
			for( string s : strs )
			{
				if( len_prefix > s.size() )
				{
					len_prefix = s.size();
				}
			}

			string ans = "";
			for( int i = 0; i < len_prefix; i++ )
			{
				char ch = strs[0][i];
				bool is_prefix = true;
				for( int j = 1; j < len_strs; j++ )
				{
					if( strs[j][i] != ch )
					{
						is_prefix = false;
						break;
					}
				}
				if( is_prefix == true )
				{
					ans += ch;
				}
				else
				{
					break;
				}
			}
			return ans;
		}
	}
};

int main(){
	Solution s;
	vector<string> strs1, strs2;

	// case 1 ---> "fl"
	strs1.push_back("flower");
	strs1.push_back("flow");
	strs1.push_back("flight");
	cout<<s.longestCommonPrefix(strs1)<<'\n';

	// case 2 ---> ""
	strs2.push_back("dog");
	strs2.push_back("racecar");
	strs2.push_back("car");
	cout<<s.longestCommonPrefix(strs2)<<'\n';

	return 0;
}
