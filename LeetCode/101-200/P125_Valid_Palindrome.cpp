/*
 * https://leetcode.com/problems/valid-palindrome/description/
 * 判断给定字符串是否为回文字符串
 * 同类题目 P125
 * 
 * 
 * 思路: 先对输入的字符串进行过滤
 * 构造新的字符串, 只留下原字符串中的 alphanum, 并且统一变成小写
 * 再检查新的字符串是否回文
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	bool isPalindrome(string s) {
		if( s.size() == 0 ){
			return true;
		}

		vector<char> v;
		for(auto ch : s){
			if( isalpha(ch) ){
				v.push_back( tolower(ch) );
			}else if( isdigit(ch) ){
				v.push_back( ch );
			}else{
				// continue;
			}
		}

		int len = v.size();
		int half = len / 2;
		bool ans = true;
		for( int i = 0; i < half; i++ ){
			if( v[i] != v[len-1-i] ){
				ans = false;
			}
		}
		return ans;
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	string s1 = "A man, a plan, a canal: Panama";
// 	cout<<s.isPalindrome(s1)<<'\n';	// 1

// 	string s2 = "race a car";
// 	cout<<s.isPalindrome(s2)<<'\n';	// 0

// 	return 0;
// }