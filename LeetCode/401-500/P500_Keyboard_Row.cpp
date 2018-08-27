/*
https://leetcode.com/problems/next-greater-element-i/description/
给定一组单词，判断每个单词能否只由键盘上的一行字母组成
同类题目: P500

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
	vector<string> findWords(vector<string>& words) {
		unordered_set<char>  s1( { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' } );
		unordered_set<char>  s2( { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L' } );
		unordered_set<char>  s3( { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M' } );

		vector<string> ans;
		for( string str : words ){
			bool ins1 = false, ins2 = false, ins3 = false;
			for( auto ch : str ){
				if( s1.find(ch) != s1.end() ){
					ins1 = true;
				}else if( s2.find(ch) != s2.end() ){
					ins2 = true;
				}else if( s3.find(ch) != s3.end() ){
					ins3 = true;
				}
			}
			if( (ins1 && !ins2 && !ins3) || (!ins1 && ins2 && !ins3) || (!ins1 && !ins2 && ins3) ){
				ans.push_back(str);
			}
		}
		return ans;
	}
};
