/*
https://leetcode.com/problems/find-and-replace-pattern/description/

同类题目 P890

参考答案
https://leetcode.com/problems/find-and-replace-pattern/solution/
*/


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

static int ioSpeedUp=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	bool isMatch(string word, string pattern, int len){
		char mapOf[160] = {0};
		char mapFrom[160] = {0};
		bool match = true;
		for( int i = 0; i < len; i++ ){
			char ch = word[i];
			char p = pattern[i];
			if( mapOf[ch] == 0 ){
				mapOf[ch] = p;
			}
			if( mapFrom[p] == 0 ){
				mapFrom[p] = ch;
			}
			if( mapOf[ch] != p || mapFrom[p] != ch ){
				match = false;
				break;
			}
		}
		return match;
	}

	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> ans;
		for( string word : words ){
			int len1 = word.size();
			int len2 = pattern.size();
			if( len1 == len2 ){
				if( isMatch(word, pattern, len1) ){
					ans.push_back(word);
				}
			}
		}
		return ans;
	}
};
