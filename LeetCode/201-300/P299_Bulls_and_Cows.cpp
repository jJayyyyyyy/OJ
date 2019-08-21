/*
https://leetcode.com/problems/bulls-and-cows/description/
猜数字
A 表示有多少个数字既猜中了数值又猜中了位置
B 表示有多少个数字只猜中了数值但是没猜中位置(已经在A中统计过的，就不在B中统计了)
同类题目 P299

参考：
A 比较好确定，直接按位比较就可以了
至于 B, 我的思路是用 hash
*/

#include <iostream>
#include <string>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	string getHint(string secret, string guess) {
		int cntA = 0;
		int cntB = 0;
		int hashSecret[10] = {0};
		int hashGuess[10] = {0};
		int len = secret.size();
		for (int i = 0; i < len; i++) {
			char s = secret[i];
			char g = guess[i];
			if (s == g) {
				cntA++;
			}
			else {
				hashSecret[s - '0']++;
				hashGuess[g - '0']++;
			}
		}

		for (int i = 0; i < 10; i++) {
			int g = hashGuess[i];
			int s = hashSecret[i];
			if (g <= s) {
				cntB += g;
			}
			else {
				cntB += s;
			}
		}
		string ans = to_string(cntA) + 'A' + to_string(cntB) + 'B';
		return ans;
	}
};
