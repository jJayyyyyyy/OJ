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



/*
可略，我的理解可能是错的

思路2, 结合 kmp 的 prefix table
https://leetcode.com/problems/repeated-substring-pattern/discuss/94397/C++-O(n)-using-KMP-32ms-8-lines-of-code-with-brief-explanation.

这帮家伙是怎么想到这种方法的[捂脸]

kmp 的 prefix table 存放的是 pattern 的最长公共前后缀长度
参考 https://www.youtube.com/watch?v=dgPabAsTFa8

接下来的注释直接放在代码上方了

*/

class Solution2 {
public:
	bool repeatedSubstringPattern1(string str) {
		// begin: 生成前缀表 dp[]
		int i = 1, j = 0, n = str.size();
		vector<int> dp(n+1,0);
		while( i < str.size() ){
			if( str[i] == str[j] ) dp[++i]=++j;
			else if( j == 0 ) i++;
			else j = dp[j];
		}
		// end: 生成前缀表 dp[]

		// 首先, 如果 dp[n] == 0 那么表示str最后一位没有公共前后缀，所以 str 肯定不是由重复的子串构成
		// 比如 str = "abc"


		// 其次, dp[n] % (n-dp[n]) == 0
		// 比如 str = "ababab"
		// dp[n]=4 是str最后一位的最长前后公共前后缀的长度
		// 即前缀是 [abab] (ab) 方括号的部分
		// 后缀是 (ab) [abab] 方括号的部分
		// n - dp 指的是上面 圆括号的部分
		// dp[n] % (n-dp[n]) == 0 表示 [] 可由多个 () 组成
		// n % (n-dp[n]) == 0 表示 str 可由多个 () 组成
		// 即 () 是最长的可以拼接成 str 的 substr
		// 待补充, 只是字面上的理解, 待证明
		return dp[n] && dp[n] % (n-dp[n]) == 0;
		// return dp[n] && n % (n-dp[n]) == 0;
	}

	bool repeatedSubstringPattern2(string str) {
		int len = str.length(), i = 0, j = 1;
		int p[len];
		// begin: 生成前缀表 p[] 
		while (j < len){
			if (str[i] == str[j])
				p[j++] = ++i;
			else {
				if (!i) 
					p[j++] = 0;
				else
					i = p[i - 1];
			}
		}
		// end: 生成前缀表 p[]

		return p[len - 1] && len % (len - p[len - 1]) == 0;
		// return p[len - 1] && p[len - 1] % (len - p[len - 1]) == 0;
	}
};

int main() {
	Solution s;
	s.repeatedSubstringPattern("aba");
	return 0;
}