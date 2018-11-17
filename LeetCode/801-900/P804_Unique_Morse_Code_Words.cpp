/*
https://leetcode.com/problems/unique-morse-code-words/description/
输入一组单词, 进行 Morse 编码, 统计最后有多少组不同的 Morse 码 (不同的单词, 可能得到相同的Morse码)
同类题目 P804
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int uniqueMorseRepresentations(vector<string> & words) {
		string letters[32] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

		unordered_set<string> s;
		for( string word : words ){
			string trans = "";
			for( char ch : word ){
				trans += letters[ch - 'a'];
			}
			s.insert(trans);
		}
		return s.size();
	}
};