/*
https://leetcode.com/problems/jewels-and-stones/description/
统计 S 中有多少个 ch 是 J 中出现过的 ch
同类题目 P771

*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int numJewelsInStones(string J, string S) {
		int ans = 0;
		bool jewel[160] = {0};
		for( char ch : J ){
			jewel[ch] = true;
		}
		for( char ch : S ){
			if( jewel[ch] == true ){
				ans++;
			}
		}
		return ans;
	}
};