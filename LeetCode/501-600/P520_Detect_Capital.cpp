/*
https://leetcode.com/problems/detect-capital/description/
判断一个单词的大小写是否符合规范
同类题目 P520

*/

#include <iostream>
#include <cctype>
using namespace std;

class Solution{
public:
	bool detectCapitalUse(string word) {
		bool ans = true;


		bool hasUpper = false, hasLower = false;
		for( int i = 1; i < word.size(); i++ ){
			if( isupper(word[i]) ){
				hasUpper = true;
			}
			if( islower(word[i]) ){
				hasLower = true;
			}
		}

		if( hasUpper == false ){
			ans = true;
		}else if( hasLower == false && isupper(word[0]) ){
			ans = true;
		}else{
			ans = false;
		}

		return ans;
	}
};
