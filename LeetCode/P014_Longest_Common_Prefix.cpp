/*
 * https://leetcode.com/problems/longest-common-prefix/description/
 * 给定一个数组, 元素都是字符串
 * 找出最长的公共前缀, 若为空则返回""
 * 
 * */

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans = "";
		if( strs.size() == 1 )
		{
			ans = strs[0];
		}

		else if( strs.size() > 1 )
		{
			int len = 0x3fff0000;
			for( string s : strs )
			{
				if( len > s.size() )
				{
					len = s.size();
				}
			}

			for( int i = 0; i < len; i++ )
			{
				char ch = strs[0][i];
				bool isPrefix = true;
				for( int j = 1; j < strs.size(); j++ )
				{
					if( strs[j][i] != ch )
					{
						isPrefix = false;
						break;
					}
				}
				if( isPrefix == true )
				{
					ans += ch;
				}
				else
				{
					break;
				}
			}

		}

		return ans;
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	vector<string> strs1, strs2;

// 	// case 1 ---> "fl"
// 	strs1.push_back("flower");
// 	strs1.push_back("flow");
// 	strs1.push_back("flight");
// 	cout<<s.longestCommonPrefix(strs1)<<'\n';

// 	// case 2 ---> ""
// 	strs2.push_back("dog");
// 	strs2.push_back("racecar");
// 	strs2.push_back("car");
// 	cout<<s.longestCommonPrefix(strs2)<<'\n';

// 	return 0;
// }
