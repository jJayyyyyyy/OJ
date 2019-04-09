/*
https://leetcode.com/problems/remove-outermost-parentheses/description/
移除最外层的括号
同类题目 P1021

参考思路
https://leetcode.com/problems/remove-outermost-parentheses/discuss/270022/JavaC++Python-Count-Opened-Parenthesis
*/

#include <iostream>
#include <string>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	string removeOuterParentheses(string S) {
		string ans;
		int cnt_left = 0;
		for( char ch : S ){
			if( ch == '(' ){
				if( cnt_left > 0 ){
					ans += ch;
				}
				cnt_left++;
			}
			if( ch == ')' ){
				if( cnt_left > 1 ){
					ans += ch;
				}
				cnt_left--;
			}
		}
		return ans;
	}
};
