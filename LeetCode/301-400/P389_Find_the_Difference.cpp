/*
https://leetcode.com/problems/find-the-difference/description/
map查找与计数
同类题目 P383, P349, P350, P389

*/

#include <iostream>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int letterCnt[128] = {0};
		for( char ch : t ){
			letterCnt[ch]++;
		}

		for( char ch : s ){
			letterCnt[ch]--;
		}

		for( int i = 'a'; i <= 'z'; i++ ){
			if( letterCnt[i] == 1 ){
				return (char)i;
			}
		}
		return 0;
	}
};


/* 更快的Solution */
class Solution2 {
public:
	char findTheDifference(string s, string t) {
		char ans = 0;	// 0 与 ch 异或，得到的是 ch, 即 0 ^ ch -> ch
		
		for( char ch : s ){
			ans ^= ch;
		}

		for( char ch : t ){
			ans ^= ch;
		}
		// 首先与 s 的每一个字符异或
		// 再与 t 的每一个字符异或
		// 就可以把 t 中与 s 相同的字符去掉，因为 0 ^ ch ^ ch -> 0
		// 最后剩下的就是 t 独有，而 s 没有的字符了

		return ans;
	}
};
