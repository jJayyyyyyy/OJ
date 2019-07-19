/*
https://leetcode.com/problems/occurrences-after-bigram/description/?goto=old

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]

在 text 中寻找这样的 pattern
【first second (third)】
其中，third 后面要么是空格，要么是末尾

同类题目 P1078

参考思路
https://leetcode.com/problems/occurrences-after-bigram/discuss/308314/C++-Search-for-Bigram
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> ans;
		string bigram = first + " " + second + " ";
		int span = bigram.size();
		int len = text.size();
		int p1 = text.find(bigram);
		while (p1 != string::npos) {
			p1 += span;
			int p2 = p1;
			while (p2 < len && text[p2] != ' ') {
				p2++;
			}
			ans.push_back(text.substr(p1, p2 - p1));
			p1 = text.find(bigram, p1 - 1);
		}
		return ans;
	}
};
