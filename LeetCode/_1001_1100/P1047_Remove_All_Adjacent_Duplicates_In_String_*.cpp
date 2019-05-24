/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

同类题目 P1047

参考思路
栈的思想
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
	string removeDuplicates(string S) {
		string ans = "";
		for(char ch : S){
			if( ans.size() > 0 && ans.back() == ch ){
				ans.pop_back();
			}
			else{
				ans.push_back(ch);
			}
		}
		return ans;
	}
};
