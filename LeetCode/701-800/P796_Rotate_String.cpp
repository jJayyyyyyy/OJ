/*
https://leetcode.com/problems/rotate-string/description/
判断字符串 A 在经过循环移位后能否变成字符串 B
同类题目 P796
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
	bool rotateString(string A, string B) {
		int len1 = A.size();
		int len2 = B.size();
		if( len1 != len2 ){
			return false;
		}
		else{
			A = A + A.substr(0, len2);
			return A.find(B) != string::npos;
		}
	}
};