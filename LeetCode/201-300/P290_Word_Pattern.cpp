/*
https://leetcode.com/problems/word-pattern/description/
给定一个pattern，判断str是否符合pattern
比如 pattern = "abba", 如果str = "dog cat cat dog", 那么就是符合的，相当于pattern的每一个字符对应str中的一个单词
同类题目 P290

参考：
https://leetcode.com/problems/word-pattern/discuss/73409/Short-C++-read-words-on-the-fly

关键1：map映射
关键2: istringstream in(str); in >> word; 可以按照空格进行切分读入
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, int> p2i;
		unordered_map<string, int> w2i;
		istringstream in(str);
		int i = 0, n = pattern.size();
		for (string word; in >> word; ++i) {
			if (i == n || p2i[pattern[i]] != w2i[word])
				return false;
			p2i[pattern[i]] = w2i[word] = i + 1;
		}
		return i == n;
	}
};
int main(){
	Solution s;
	cout<<s.wordPattern("abba", "dog cat cat dog")<<'\n';

	return 0;
}


