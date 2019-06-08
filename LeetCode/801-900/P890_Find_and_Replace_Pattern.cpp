/*
https://leetcode.com/problems/find-and-replace-pattern/description/

同类题目 P890

参考答案
https://leetcode.com/problems/find-and-replace-pattern/solution/
使用两个map, 第一个 mapOf 保存 ch = word[i] 到 p = pattern[i] 的映射, 第二个 mapFrom 保存 p 到 ch 的映射
如果 mapOf[ch] 为空则 mapOf[ch] = p
如果 mapFrom[p] 为空则 mapFrom[p] = ch
然后检查 mapOf 和 mapFrom, 如果 mapOf[ch] != p || mapFrom[p] != ch , 说明出现了不匹配
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
