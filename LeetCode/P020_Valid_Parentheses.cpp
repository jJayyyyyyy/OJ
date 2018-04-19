/*
 * https://leetcode.com/problems/valid-parentheses/description/
 * 括号匹配
 * stack, 栈的使用
*/

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for( auto ch : s ){
			if( ch == ')' ){
				if( stk.size() == 0 || stk.top() != '(' ){
					return false;
				}else{
					stk.pop();
				}
			}else if( ch == ']' ){
				if( stk.size() == 0 || stk.top() != '[' ){
					return false;
				}else{
					stk.pop();
				}
			}else if( ch == '}' ){
				if( stk.size() == 0 || stk.top() != '{' ){
					return false;
				}else{
					stk.pop();
				}
			}else{
				stk.push(ch);
			}
		}

		if( stk.size() != 0 ){
			return false;
		}else{
			return true;
		}
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	cout<<s.isValid("]")<<'\n';
// 	cout<<s.isValid("()")<<'\n';
// 	cout<<s.isValid("()[]{}")<<'\n';
// 	cout<<s.isValid("(]")<<'\n';
// 	cout<<s.isValid("([)]")<<'\n';
// 	cout<<s.isValid("{[]}")<<'\n';
// 	return 0;
// }
