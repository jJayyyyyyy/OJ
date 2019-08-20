/*
https://leetcode.com/problems/license-key-formatting/description/

同类题目: P485

参考思路
原本的想法是，首先统计有多少个 '-', 即 cntDash = count('-'), 
然后 cntAlphaNum = s.size() - cntDash
接着, 第一个 dash 之前是 cntAlphaNum % k 个字符
也就是从前往后构造License

但是实际写过之后会发现，第一种思路很麻烦，因此我们采用第二种思路，即从后往前


思路2，从后往前 !!!!
https://leetcode.com/problems/license-key-formatting/discuss/96506/4-line-C++-concise-solution-to-scan-string-backward
因为题目要求除了第一组，后面的每个组都要求是满 k 个，所以直接从后往前 k 个一组得到 License，最后 reverse 一下即可

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string ans = "";
		int completeGroupSize = k + 1;
		for (auto rit = s.rbegin(); rit != s.rend(); rit++) {
			if (*rit != '-') {
				if (ans.size() % completeGroupSize == k) {
					ans += '-';
				}
				ans += toupper(*rit);
			}
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main () {
	string str = "5F3Z-2e-9-w";
	int k = 4;
	Solution s;
	s.licenseKeyFormatting(str, k);
}