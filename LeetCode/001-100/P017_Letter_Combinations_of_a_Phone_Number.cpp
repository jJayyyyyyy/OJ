/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?goto=old

同类题目 P17

按下九宫格的数字，求所有可能的输出
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string phonePanel[10];
	vector<string> ans;

	void init(){
		phonePanel[2] = "abc";
		phonePanel[3] = "def";
		phonePanel[4] = "ghi";
		phonePanel[5] = "jkl";
		phonePanel[6] = "mno";
		phonePanel[7] = "pqrs";
		phonePanel[8] = "tuv";
		phonePanel[9] = "wxyz";
		ans.push_back("");
	}

	void updateAns(string newStr) {
		vector<string> tmp;
		for (string oldStr : ans) {
			for (char ch : newStr) {
				tmp.push_back(oldStr + ch);
			}
		}
		ans = tmp;
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() > 0) {
			init();
			for (char digit : digits) {
				int index = digit - '0';
				string newStr = phonePanel[index];
				updateAns(newStr);
			}
		}

		return ans;
	}
};

int main(){
	Solution s;

	s.letterCombinations("23");
	s.letterCombinations("");
	return 0;
}
