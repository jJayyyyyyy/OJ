/*
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?goto=old

同类题目 P1160

思路
map
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> charCnt(128, 0);
		int ans = 0;
		for (char ch : chars) {
			charCnt[ch]++;
		}

		for (string word : words) {
			vector<int> tmpCharCnt = charCnt;
			for (char ch : word) {
				tmpCharCnt[ch]--;
			}
			int len = word.size();
			for (int ch = 'a'; ch <= 'z'; ch++) {
				if (tmpCharCnt[ch] < 0) {
					len = 0;
					break;
				}
			}
			ans += len;
		}
		return ans;
	}
};

int main() {
	Solution s;
	string wordlist[] = {"cat","bt","hat","tree"};
	vector<string> words(wordlist, wordlist + 4);
	string chars = "atach";//"welldonehoneyr"
	s.countCharacters(words, chars);
	return 0;
}