/*
https://leetcode.com/problems/reverse-vowels-of-a-string/description/
给定字符串，反转其中的元音
同类题目 P344, P345


*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		bool vs[128] = {false};
		vs['a'] = true;
		vs['A'] = true;
		vs['e'] = true;
		vs['E'] = true;
		vs['i'] = true;
		vs['I'] = true;
		vs['o'] = true;
		vs['O'] = true;
		vs['u'] = true;
		vs['U'] = true;

		int i = 0, j = s.size() - 1;
		while( i < j ){

			if( vs[ s[i] ] == false ){
				i++;
			}
			if( vs[ s[j] ] == false ){
				j--;
			}
			if( vs[s[i]] == true && vs[ s[j] ] == true ){
				swap(s[i], s[j]);
				i++;
				j--;
			}
		}
		return s;
	}
};


int main(){
	Solution s;
	cout<<s.reverseVowels("hello")<<'\n';
	cout<<s.reverseVowels("aA")<<'\n';	// 注意大小写

	return 0;
}