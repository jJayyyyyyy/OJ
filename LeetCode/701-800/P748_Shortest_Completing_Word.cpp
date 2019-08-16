/*
https://leetcode.com/problems/shortest-completing-word/description/?goto=old
哈希水题
同类题目 P746

*/

#include <iostream>
#include <vector>

using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

// 解法1
class Solution1 {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int> cnt(26, 0);
		for (char ch : licensePlate) {
			if (ch >= 'a' && ch <= 'z') {
				cnt[ch - 'a']++;
			}
			else if ( ch >= 'A' && ch <= 'Z') {
				cnt[ch - 'A']++;
			}
		}

		string ans = "some_place_holder";
		for (string word : words) {
			vector<int> tmpCnt = cnt;
			for (char ch : word) {
				tmpCnt[ch - 'a']--;
			}
			bool flag = true;
			for (char ch = 0; ch < 26; ch++) {
				if (tmpCnt[ch] > 0) {
					flag = false;
					break;
				}
			}
			if (flag == true && word.size() < ans.size()) {
				ans = word;
			}
		}
		return ans;
	}
};

// 解法2, 对于本题用例, 速度稍快
class Solution2 {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		string pattern = "";
		for (char ch : licensePlate) {
			if (isalpha(ch)) {
				pattern.push_back(tolower(ch));
			}
		}

		string ans = "some_place_holder";
		for (string word : words) {
			vector<int> cnt(26, 0);
			for (char ch : word) {
				cnt[ch - 'a']++;
			}
			for (char ch : pattern) {
				cnt[ch - 'a']--;
			}
			bool flag = true;
			for (char ch = 0; ch < 26; ch++) {
				if (cnt[ch] < 0) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				if (word.size() < ans.size()) {
					ans = word;
				}
			}
		}
		return ans;
	}
};
