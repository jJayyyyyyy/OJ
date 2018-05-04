/*
 * https://leetcode.com/problems/count-and-say/description/
 * 浙大2018考研PAT甲级A题. 当时没刷LeetCode, 真是xx
 *
 * 每一个数都是对前面那个数的一种描述
 *
 * to_string() 是 C++11 新增加的函数, 可以把数字转成字符串, 比 stringstream 的 num2str 要快一些
 * http://www.cplusplus.com/reference/string/to_string/?kw=to_string
 */

// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if( n < 1 ){
			return "";
		}else{
			string s1 = "1";
			for( int i = 1; i < n; i++ ){
				string s2 = "";
				char ch = s1[0];
				int cnt = 0;
				for( int j = 0; j < s1.size(); j++ ){
					if( s1[j] == ch ){
						cnt++;
					}else{
						s2 += to_string(cnt) + ch;
						ch = s1[j];
						cnt = 1;
					}
				}
				s2 += to_string(cnt) + ch;
				s1 = s2;
			}
			return s1;
		}
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

	// cout<<s.countAndSay(1)<<'\n';	// 1
	// cout<<s.countAndSay(2)<<'\n';	// 11
	// cout<<s.countAndSay(3)<<'\n';	// 21
	// cout<<s.countAndSay(4)<<'\n';	// 1211
	
// 	return 0;
// }
