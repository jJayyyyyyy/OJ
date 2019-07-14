/*
https://leetcode.com/problems/generate-parentheses/description/
输出所有的, 含有 n 个左括号的, 左右括号组合
如 n = 3, 则输出含有三个左括号的所有匹配组合
[
  "( ( ( ) ) )",
  "( ()() )",
  "(( )) ()",
  "() (( ))",
  "() () ()"
]

参考思路:
https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C++-solution
记录
剩下的 左括号 ( 的数量
和 剩下的 右括号 ) 的数量

1. Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added.
2. At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0.
3. Append the result and terminate recursive calls when both m and n are zero.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	vector<string> ans;
	vector<string> generateParenthesis(int n)
	{
		string str = "";
		// left 是剩下的 左括号 ( 的数量
		// right 是剩下的 右括号 ) 的数量
		int left = n;
		int right = 0;
		addParenthesis(n, 0, str);
		return ans;
	}

	void addParenthesis(int left, int right, string str)
	{
		if( left == 0 && right == 0 )
		{
			ans.push_back(str);
		}
		if( right > 0 )
		{
			// right > 0, 可以加一个 右括号 )
			// 然后使 right - 1
			addParenthesis(left, right - 1, str + ")");
		}

		if( left > 0 )
		{
			// left > 0 可以加一个 左括号 (
			// 然后使 left - 1
			// 同时, 由于要匹配这个左括号, 所以右括号数量要+1, 即 right + 1
			addParenthesis(left - 1, right + 1, str + "(");
		}
	}
};
