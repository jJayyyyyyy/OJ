/*
https://leetcode.com/problems/power-of-four/description/
判断一个正整数( [0, 2^32] ) 是否为 4 的指数
同类题目 P342

思路:
1. num 是正数
2. num 是 2 的指数
3. num 是 4 的指数
*/

#include <iostream>
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
