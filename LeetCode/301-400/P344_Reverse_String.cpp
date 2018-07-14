/*
https://leetcode.com/problems/reverse-string/description/
反转字符串
同类题目 P344, P345

*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		reverse(s.begin(), s.end());
		return s;
	}
};

class Solution2 {
public:
	string reverseString(string s) {
		int i = 0;
		int j = s.size() - 1;
		while( i < j ){
			swap(s[i++], s[j--]);
		}
		return s;
	}
};
