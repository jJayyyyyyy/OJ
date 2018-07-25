/*
https://leetcode.com/problems/find-the-difference/description/
map查找与计数
同类题目 P383, P349, P350, P389, P387

*/

#include <iostream>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution{
public:
	int firstUniqChar(string s) {
		int charCnt[128] = {0};
		for( char ch : s ){
			charCnt[ch]++;
		}

		for( int i = 0; i < s.size(); i++ ){
			char ch = s[i];
			if( charCnt[ch] == 1 ){
				return i;
			}
		}

		return -1;
	}
};