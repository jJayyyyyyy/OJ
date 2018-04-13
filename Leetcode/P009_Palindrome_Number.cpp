/*
 * https://leetcode.com/problems/palindrome-number/description/
 * 给定一个整数, 判断它是不是回文数
 * 先转为字符串, 然后对其reverse, 最后判断内容是否相同
*/

// #include <iostream>
// #include <string>
// #include <sstream>
// #include <algorithm>
// using namespace std;

class Solution {
public:
	string num2str(int x){
		stringstream ss;
		ss<<x;
		string s;
		ss>>s;
		return s;
	}

	bool isPalindrome(int x) {
		string s, s1;
		s = s1 = num2str(x);
		reverse(s.begin(), s.end());
		return s == s1;
	}
};


// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	cout<<s.isPalindrome(1)<<'\n';
// 	cout<<s.isPalindrome(121)<<'\n';
// 	cout<<s.isPalindrome(2147483647)<<'\n';

// 	return 0;
// }
