/*
https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?goto=old

如果 S = T + ... + T，那么称 S 能被 T "整除"，T 是 S 的因子
现在给 s1, s2, 寻找这俩字符串的最大公因数

同类题目 P1071

参考思路
https://leetcode.com/problems/greatest-common-divisor-of-strings/discuss/303759/My-4-Lines-C++-Solution

如果 s1, s2 存在最大公因数 T，那么
s1 = nT
s2 = mT
注意，S 肯定是 T 的循环，"ABC" 是 "ABCABC" 的因子，而
但 "ABC" 不是 "ABCA" 或者 "ABCDBC" 的因子

因此可以使用辗转相除的思路，我们来做辗转相减
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string gcdOfStrings(string s1, string s2) {
		int len1 = s1.size();
		int len2 = s2.size();
		if (len1 < len2) {
			return gcdOfStrings(s2, s1);
		}

		if (len2 == 0) {
			return s1;
		}

		// 如果有最大公因数，那么 s1, s2 前半段 (0, len2) 肯定是重合的
		if (s1.substr(0, len2) != s2) {
			return "";
		}

		// 取 s1 的后半段
		s1 = s1.substr(len2);
		return gcdOfStrings(s1, s2);
	}
};