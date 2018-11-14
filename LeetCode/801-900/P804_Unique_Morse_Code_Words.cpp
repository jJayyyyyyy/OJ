/*
https://leetcode.com/problems/shortest-distance-to-a-character/description/
给定一个字符串 S, 一个字符 C, 求 S 中每一个字符到 C 的最短距离
同类题目 P821


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