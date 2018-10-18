/*
https://leetcode.com/problems/letter-case-permutation/description/
输入一个字符串 S , 里面只有字母和数字
不改变 S 的顺序, 但是可以改变其所有字母的大小写, 也就是, 假设有 n 个字母, 那么就有 2^n 种组合
返回一个数组, 包含所有组合

同类题目 P784, P077
*/

#include <string>
#include <cctype>
#include <vector>
using namespace std;

class Solution{
public:
	vector<string> ans;
	string s;
	int size;

	void dfs(int cur, string & tmpStr){
		if( cur == size ){
			ans.push_back(tmpStr);
			return;
		}

		char ch = s[cur];
		if( isalpha(ch) ){
			tmpStr.push_back(tolower(ch));
			dfs(cur+1, tmpStr);
			tmpStr.pop_back();

			tmpStr.push_back(toupper(ch));
			dfs(cur+1, tmpStr);
			tmpStr.pop_back();
		}else{
			tmpStr.push_back(ch);
			dfs(cur+1, tmpStr);
			tmpStr.pop_back();
		}
	}

	vector<string> letterCasePermutation(string S) {
		size = S.size();
		s = S;
		string tmpStr = "";
		if( size != 0 ){
			dfs(0, tmpStr);
		}else{
			ans.push_back("");
		}
		return ans;
	}
};

class Solution2 {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> result;
		letterCasePermutation(S, 0, result);
		return result;
	}
	
	void letterCasePermutation(string S, int idx, vector<string> &result) {
		if(idx == S.size()) {
			result.push_back(S);
			return;
		}
		letterCasePermutation(S, idx+1, result);
		if(isalpha(S[idx])) {
			S[idx] ^= (1 << 5);
			letterCasePermutation(S, idx+1, result);
		}
	}
};

int main() {
	Solution s;
	s.letterCasePermutation("a1b2");
	
	return 0;
}


