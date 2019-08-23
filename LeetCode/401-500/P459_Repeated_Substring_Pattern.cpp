/*
https://leetcode.com/problems/repeated-substring-pattern/description/

同类题目: P459, P686, P796

思路1
https://leetcode.com/problems/repeated-substring-pattern/discuss/94334/Easy-python-solution-with-explaination

如果 s 可以由 substr 重复多次拼接而成，那么相当于 s 可以在循环移位 substr.size()的长度后变回自身
利用这个思路，我们只需要看看 s 是否能在 n 次循环移位后变回自身，

为此，我们可以用类似于 P796的方法, 构造 s2 = s + s
然后让 s 在 s2 上进行滑动，观察是否完全重合，如果是，则说明能在 n 此循环移位后变回自身

注意要去掉一头一尾，也就是 max(n) = s.size() - 2，因为 s 循环移位 s.size() 长度后肯定是变回自身的


思路2, kmp
https://leetcode.com/problems/repeated-substring-pattern/discuss/94397/C++-O(n)-using-KMP-32ms-8-lines-of-code-with-brief-explanation.


*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.empty()) {
			return false;
		}
		string s2 = s + s;
		int len = s2.size() - 2;
		s2 = s2.substr(1, len);
		if (s2.find(s) != string::npos) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution s;
	s.repeatedSubstringPattern("aba");
	return 0;
}