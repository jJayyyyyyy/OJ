/*
https://leetcode.com/problems/longest-palindromic-substring/description/
找出最长回文子串
同类题目 P005, P647

参考思路
https://leetcode.com/problems/longest-palindromic-substring/solution/

从中间向外延伸, expand_from_center
*/


#include <iostream>
#include <string>

class Solution {
public:
	int expand_from_center(const string & s, int left, int right, int size){
		while( left >= 0 && right < size ){
			if( s[left] != s[right] ){
				break;
			}
			left--;
			right++;
		}
		return right - left - 1;
	}

	string longestPalindrome(string s) {
		string ans = "";
		int size = s.size();
		int maxlen = 0;
		int maxstart = 0;
		if( size > 0 ){
			for( int i = 0; i < size; i++ ){
				// int start = 0, end = 0;
				int len1 = expand_from_center(s, i, i, size);
				int len2 = expand_from_center(s, i, i + 1, size);
				if( len1 > len2 ){
					if( len1 > maxlen ){
						maxlen = len1;
						maxstart = i - len1/2;
					}
				}
				else{
					if( len2 > maxlen ){
						maxlen = len2;
						maxstart = i - len2/2 + 1;
					}
				}
			}
			ans = s.substr(maxstart, maxlen);
		}
		return ans;
	}
};


int main(){
	Solution s;
	s.longestPalindrome("cbbd");	// bb
	s.longestPalindrome("ababa");	// aba, bab
	return 0;
}
