/*
https://leetcode.com/problems/ransom-note/description/
map查找与计数
同类题目 P383, P349, P350, P389

注意:
*/

#include <iostream>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int letterCnt[128] = {0};
		for( char ch : magazine ){
			letterCnt[ch]++;
		}

		for( char ch : ransomNote ){
			letterCnt[ch]--;
			if( letterCnt[ch] < 0 ){
				return false;
			}
		}
		return true;
	}
};
